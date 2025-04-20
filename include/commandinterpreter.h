#ifndef COMMAND_INTERPRETER_H
#define COMMAND_INTERPRETER_H

#include "Session.h"
#include "utils.h"
#include "databasemanager.h"
#include "documentmanager.h"
#include "inputType.h"
//#include <iostream>
#include <sstream>
//#include <string>
//#include <vector>

class CommandInterpreter {
private:
    Session& session;
    std::vector<std::string> split_words(const std::string& input);
    Utils util;
    DB_Manager db;
    DOC_Manager docm;
    bool isNumber(const std::string& s);
    bool isBoolean(const std::string& s);
    bool isNull(const std::string& s);
    bool isJSON(const std::string& s);
    InputType input_type(const std::string& input);

public:
    CommandInterpreter(Session& s);
    void run();
};

#endif