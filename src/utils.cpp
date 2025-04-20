#include "utils.h"

Utils::Utils() {}; //------> check here

std::string Utils::generate_random() {
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	int number = std::rand() % 10000000; 

	char buffer[8]; 
	std::snprintf(buffer, sizeof(buffer), "%07d", number); 

	return std::string(buffer);
}

json Utils::get_json(std::string path) {
	std::ifstream file(path, std::ios::binary);
	if (!file) {
		std::cerr << "Failed to open file.\n";
		return json();
	}
	std::vector<uint8_t> buffer(std::istreambuf_iterator<char>(file), {});
	json j = json::from_bson(buffer);
	return j;
}

void Utils::write_bson(std::vector<std::uint8_t> bson, std::string path) {
	std::ofstream file(path, std::ios::binary);
	file.write(reinterpret_cast<const char*>(bson.data()), bson.size());
	file.close();

	std::cout << "saved bson" << std::endl;
}

std::string Utils::save_json(std::string str, std::string path, std::string name) {

	json j = json::parse(str); 

	j["objectID"] = name;	
	std::vector<std::uint8_t> bson = json::to_bson(j); 

	
	write_bson(bson, path + "/" + name + ".bson");
	return name;
}

void Utils::read_bson(std::string path, std::string name) {

	json j = get_json(path + name + ".bson");
	std::cout << "\033[32m" << j.dump(4) << "\033[0m" << std::endl;
}

void Utils::remove_bson(std::string path, std::string name) {
	json j = get_json(path + "index.bson");
	auto& arr = j["docs"];
	bool flag = false;

	for (auto i = arr.begin(); i != arr.end();i++) {
		if (i->is_string() && *i == name) {
			flag = true;
			arr.erase(i);
			break;
		}
	}
	if (flag == false) return;

	std::vector<std::uint8_t> bson = json::to_bson(j); 
	write_bson(bson, path + "index.bson");

	path = path + name + ".bson";
	std::remove(path.c_str());
}