#include "SymbolTable.h"
#include "Error.h"

SymbolTable::SymbolTable () {
    initailize_predefined_symbols ();
}

void SymbolTable::initailize_predefined_symbols () {

    for (int i = 0; i < 16; i++) {
        table["R" + std::to_string (i)] = i;
    }

    table["SCREEN"] = 16384;
    table["KBD"]    = 24576;
    table["SP"]     = 0;
    table["LCL"]    = 1;
    table["ARG"]    = 2;
    table["THIS"]   = 3;
    table["THAT"]   = 4;
}

void SymbolTable::add_symbol (std::string str, unsigned int value) {
    table[str] = value;

    //    std::cout << "Pair ( " << str << ", " << value << ") has been added to symbol table" << std::endl;
}

bool SymbolTable::contains (std::string str) {
    return table.find (str) != table.end ();
}

unsigned int SymbolTable::get_address (std::string symbol) {
    if (!contains (symbol))
        throw Error ("SymbolTable::get_address() - Symbol does not exist");

    return table[symbol];
}

void SymbolTable::add_variable (std::string str) {
    add_symbol (str, next_variable++);
}

unsigned int SymbolTable::get_next_variable_address () {
    return next_variable;
}
