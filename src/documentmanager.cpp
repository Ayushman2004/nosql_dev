#include "documentmanager.h"

void DOC_Manager::doc_read(std::string path, TreeLevel t, std::string name) {
	if (t == TreeLevel::ROOT) {
		std::cerr << "doc cannot be read in root" << std::endl;
		return;
	}
	util.read_bson(path, name);
}

void DOC_Manager::doc_write(std::string data, std::string path, TreeLevel t) {
	if (t == TreeLevel::ROOT) {
		std::cerr << "doc cannot be written in root" << std::endl;
		return;
	}
	util.save_json(data, path);
}

void DOC_Manager::doc_remove(std::string name, std::string path, TreeLevel t) {
	if (t == TreeLevel::ROOT) {
		std::cerr << "doc cannot be removed in root" << std::endl;
		return;
	}
	util.remove_bson(name, path);
}