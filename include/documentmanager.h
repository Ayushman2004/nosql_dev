#ifndef DOCUMENT_MANAGER_H
#define DOCUMENT_MANAGER_H

#include "utils.h"
#include "treelevel.h"

class DOC_Manager {
private:
	Utils util;
	std::string index_path = "C:/trialdb/index.bson";

public:
	void doc_read( std::string path, TreeLevel t, std::string name = "index");
	void doc_write(std::string data, std::string path, TreeLevel t);
	void doc_remove(std::string name, std::string path, TreeLevel t);
};

#endif