#include <iostream>
#include "Session.h"
#include "CommandInterpreter.h"

int main() {
    Session session;
    CommandInterpreter cli(session);
    cli.run();
    return 0;
}