#include "Session.h"

Session::Session() : level(TreeLevel::ROOT), currentPath("C:/trialdb/"), dbName("") {}


void Session::useDB(const std::string& name) {
    if (!db.check_db(name)) {
        std::cerr << "db not present" << std::endl;
        return;
    }
    dbName = name;
    currentPath = "C:/trialdb/" + dbName + "/";
    level = TreeLevel::DB;
}

void Session::backToRoot() {
    dbName.clear();
    currentPath = "C:/trialdb/";
    level = TreeLevel::ROOT;
}

TreeLevel Session::getLevel() const {
    return level;
}

std::string Session::getPath() const {
    return currentPath;
}

std::string Session::getDBName() const {
    return dbName;
}



