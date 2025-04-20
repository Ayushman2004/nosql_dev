#ifndef DATABASE_MANAGER_H
#define DATABASE_MANAGER_H

#include "iostream"
#include "utils.h"
#include "treelevel.h"

class DB_Manager {
private:
	Utils util;

public:
	DB_Manager();
	void create_db(std::string db, TreeLevel t);
	void delete_db(std::string db, TreeLevel t);
	bool check_db(std::string name);
};



#endif
