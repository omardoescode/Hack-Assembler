#include "Encoder.h"
#include "SymbolTable.h"
#include <istream>
#include <ostream>
class Assembler {

public:
    Assembler (std::string, std::string);
    void assemble ();
    void first_pass ();
    void second_pass ();

private:
    std::string in_file, out_file;
    SymbolTable table;
    Encoder encoder;
};
