#include "Assembler.h"
#include <iostream>

template <typename T> T return_val (T& val) {
    return val;
}

auto main (int argc, char* argv[]) -> int {
    if (argc != 2 && argc != 3) {
        std::cout << "Invalid number of arguments" << std::endl;
        return -1;
    }

    std::string in_file = argv[1], out_file;
    if (argc == 2) {
        out_file = in_file.substr (0, in_file.length () - 4) + ".hack";
    } else {
        out_file = argv[2];
    }


    Assembler assembler (in_file, out_file);
    assembler.assemble ();
    std::cout << "-- Hack machine code has been written to \"" << out_file
              << "\"" << std::endl;
    return 0;
}
