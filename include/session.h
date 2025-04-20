#ifndef SESSION_H
#define SESSION_H

#include <string>
#include <iostream>
#include "databasemanager.h"
#include "treelevel.h"


class Session {
private:
    TreeLevel level;
    DB_Manager db;
    std::string currentPath;
    std::string dbName;

public:
    Session();
    void useDB(const std::string& name);
    void backToRoot();
    TreeLevel getLevel() const;
    std::string getPath() const;
    std::string getDBName() const;
};

#endif