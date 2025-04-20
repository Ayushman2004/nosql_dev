#include "CommandInterpreter.h"


CommandInterpreter::CommandInterpreter(Session& s) : session(s) {}

std::vector<std::string> CommandInterpreter::split_words(const std::string& input) {
    std::istringstream iss(input);
    std::vector<std::string> words;
    std::string word;
    while (iss >> word) words.push_back(word);
    return words;
}

bool CommandInterpreter::isNumber(const std::string& s) {
    std::stringstream ss(s);
    double d;
    ss >> d;
    return ss.eof() && !ss.fail();
}

bool CommandInterpreter::isBoolean(const std::string& s) {
    return s == "true" || s == "false";  
}

bool CommandInterpreter::isNull(const std::string& s) {
    return s == "null";
}

bool CommandInterpreter::isJSON(const std::string& s) {
    try {
        json::parse(s);
        return true;
    }
    catch (const json::parse_error&) {
        return false;
    }
}

InputType CommandInterpreter::input_type(const std::string& input) {
    if (isBoolean(input)) {
		return InputType::BOOL;
    }
    else if (isNumber(input)) {
		return InputType::INT;
    }
    else if (isNull(input)) {
		return InputType::INULL;
    }
    else if (isJSON(input)) {
		return InputType::OBJ;
    }
    else {
		return InputType::STR;
    }
}



void CommandInterpreter::run() {
    
    std::string input;
    while (true) {
        std::cout << "db" << "/" << session.getDBName() << ">> ";
        std::getline(std::cin, input);
        auto tokens = split_words(input);

        if (tokens.empty()) continue;
        const auto& cmd = tokens[0];

        if (cmd == "exit") return;
        else if (cmd == "useDB" && tokens.size() == 2) session.useDB(tokens[1]);
        else if (cmd == "back") session.backToRoot();
        else if (cmd == "createDB") db.create_db(tokens[1], session.getLevel());
        else if (cmd == "deleteDB") db.delete_db(tokens[1], session.getLevel());
        else if (cmd == "readDOC") {
            if(tokens.size()==2) docm.doc_read(session.getPath(), session.getLevel(), tokens[1]);
            else docm.doc_read(session.getPath(), session.getLevel());
        }
        else if (cmd == "writeDOC") {
            std::cout << "\ndata>> ";
            std::getline(std::cin, input);
            docm.doc_write(input, session.getPath(), session.getLevel());
        }
        else if (cmd == "delDOC") docm.doc_remove(tokens[1], session.getPath(), session.getLevel());
        else if (cmd == "edit") {
            
        }
        else std::cout << "\033[31m" << "Unknown command: " << cmd << "\033[0m" << "\n";
    }
}
