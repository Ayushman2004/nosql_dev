#ifndef UTILS_H
#define UTILS_H

#include <nlohmann/json.hpp>
#include <string>
#include <fstream>
#include <iostream>

using json = nlohmann::json;

class Utils {
private:
	static std::string generate_random();
public:	
	Utils();
	json get_json(std::string path);
	void write_bson(std::vector<std::uint8_t> bson, std::string path);
	std::string save_json(std::string str, std::string path, std::string name = generate_random());
	void read_bson(std::string path, std::string name);
	void remove_bson(std::string path, std::string name);
};

#endif