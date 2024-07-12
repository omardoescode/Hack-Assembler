#include "Assembler.h"
#include "Parser.h"
#include <algorithm>
#include <bitset>
#include <cstdlib>
#include <iostream>

Assembler::Assembler (std::string in_file, std::string out_file)
: in_file (in_file), out_file (out_file) {
}

void Assembler::assemble () {
    first_pass ();
    std::cout << "-- Done with first pass" << std::endl;
    second_pass ();
    std::cout << "-- Done with second pass" << std::endl;
}

void Assembler::first_pass () {
    int line_number = 0;
    Parser parser (in_file);

    while (true) {
        parser.advance ();
        if (!parser.hasMoreCommands ())
            break;

        if (parser.isPseudoCommand ()) {
        std:;
            std::string symbol;
            parser.get_pseudo_fields (symbol);
            if (table.contains (symbol))
                continue;
            table.add_symbol (symbol, line_number);
        } else {
            line_number++;
        }
    }
}


void Assembler::second_pass () {
    Parser parser (in_file);

    // generate the output file
    std::ofstream fout;
    fout.open (out_file);

    if (fout.fail ()) {
        std::cout << "Failed to open the output file";
        std::terminate ();
    }

    while (true) {
        parser.advance ();
        if (!parser.hasMoreCommands ())
            break;
        if (parser.isInstructionA ()) {
            // Write the op code
            fout << '0';

            // Extract the value
            std::string value;
            parser.get_a_fileds (value);

            // If numberic or not
            if (std::all_of (value.begin (), value.end (), ::isdigit)) {

                fout << std::bitset<15> (stoi (value)) << std::endl;
            } else {
                if (!table.contains (value)) {
                    table.add_variable (value);
                }
                fout << std::bitset<15> (table.get_address (value)) << std::endl;
            }
        } else if (parser.isInstructionC ()) {
            std::string dest, comp, jmp;
            parser.get_c_fields (dest, comp, jmp);


            // std::cout << comp << std::endl;
            fout << "111" << encoder.encode_comp (comp) << encoder.encode_dest (dest)
                 << encoder.encode_jmp (jmp) << std::endl;
        }
    }
}
