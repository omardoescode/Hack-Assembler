#include "Parser.h"
#include "Error.h"
#include "iostream"
#include <algorithm>
#include <cstring>

Parser::Parser (std::string file_name) : file (file_name) {
}

bool Parser::hasMoreCommands () {
    return !file.eof ();
}

void Parser::advance () {
    std::string currentLine;
    bool commandFound = false;

    while (!commandFound && getline (file, currentLine)) {
        // Erase all white spaces
        currentLine.erase (std::remove_if (currentLine.begin (), currentLine.end (), isspace),
        currentLine.end ());

        // Remove Comments
        auto comment_start = currentLine.find ("//");
        if (comment_start != std::string::npos) {
            currentLine.erase (comment_start, currentLine.length () - comment_start);
        }

        commandFound = !currentLine.empty ();
    }

    current_command = currentLine;
}

bool Parser::isInstructionA () {
    return current_command.find ("@") == 0;
}
bool Parser::isPseudoCommand () {
    return current_command.find ("(") == 0;
}

bool Parser::isInstructionC () {
    return !isInstructionA () && !isPseudoCommand ();
}

void Parser::get_a_fileds (std::string& symbol) {
    if (!isInstructionA ())
        throw Error ("Invalid A Instruction");

    symbol = current_command.substr (1);
}

void Parser::get_c_fields (std::string& dest, std::string& comp, std::string& jmp) {
    if (!isInstructionC ())
        throw Error ("Invalid C Instruction");

    char _dest[10], _comp[10], _jmp[10];

    // Clear the buffers to avoid unexpected behavior
    memset (_dest, 0, sizeof (_dest));
    memset (_comp, 0, sizeof (_comp));
    memset (_jmp, 0, sizeof (_jmp));

    // std::cout << current_command << std::endl;
    if (sscanf (current_command.c_str (), "%[^=]=%[^;];%s", _dest, _comp, _jmp) == 3) {
        dest = _dest, comp = _comp, jmp = _jmp;
    } else if (sscanf (current_command.c_str (), "%[^=]=%[^;];", _dest, _comp) == 2) {
        dest = _dest, comp = _comp, jmp = "null";
    } else if (sscanf (current_command.c_str (), "%[^;];", _comp) == 1) {
        dest = "null", comp = _comp, jmp = "null";
    } else if (sscanf (current_command.c_str (), "%[^;];%s", _comp, _jmp) == 2) {
        dest = "null", comp = _comp, jmp = _jmp;
    } else {
        throw Error ("Invalid C Instruction");
    }
}

void Parser::get_pseudo_fields (std::string& symbol) {
    char _symbol[100];
    if (sscanf (current_command.c_str (), "(%[^)])", _symbol) == 1)
        symbol = _symbol;
    else
        throw Error ("Parser::get_pseudo_fields: Invalid Instruction");
}
