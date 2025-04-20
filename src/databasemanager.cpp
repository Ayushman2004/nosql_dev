#include "databasemanager.h"


DB_Manager::DB_Manager() {};

bool DB_Manager::check_db(std::string name) {

	json j = util.get_json("index_path");
	auto& arr = j["dbs"];
	for (auto i = arr.begin(); i != arr.end();++i) {
		if (i->is_string() && *i == name) {
			return true;
		}
	}
	return false;
}

void DB_Manager::create_db(std::string db, TreeLevel t) {
	if (t != TreeLevel::ROOT) {
		std::cout << "have to be in the root dir to delete a db" << std::endl;
		return;
	}

	json j = util.get_json("index_path");

	auto& arr = j["dbs"];
	arr.push_back(db);

	std::vector<std::uint8_t> bson = json::to_bson(j); 
	util.write_bson(bson, "index_path");

	db = "C:/trialdb/" + db;
	std::string command = "mkdir \"" + db + "\"";
	std::system(command.c_str());
	util.save_json(R"({"docs": []})", db, "index");

	std::cout << "created" << std::endl;

}

void DB_Manager::delete_db(std::string db, TreeLevel t) {
	if (t != TreeLevel::ROOT) {
		std::cout << "have to be in the root dir to delete a db" << std::endl;
		return;
	}

	json j = util.get_json("index_path");
	bool flag = false;

	auto& arr = j["dbs"];
	for (auto it = arr.begin(); it != arr.end(); ++it) {
		if (it->is_string() && *it == db) {
			arr.erase(it);
			flag = true;
			break;
		}
	}

	if (flag == false) {
		std::cout << "db was not found" << std::endl;
		return;
	}

	std::vector<std::uint8_t> bson = json::to_bson(j); 
	util.write_bson(bson, "index_path");

	db = "C:/trialdb/" + db;
	std::string command = "rmdir /S /Q \"" + db + "\"";
	std::system(command.c_str());

	std::cout << "deleted" << std::endl;
}