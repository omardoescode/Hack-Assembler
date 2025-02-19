
#include "Encoder.h"
#include "Error.h"

using namespace std::string_literals;

Encoder::Encoder () {
    initialize ();
}

void Encoder::initialize () {
    destTable["null"] = "000";
    destTable["M"]    = "001";
    destTable["D"]    = "010";
    destTable["MD"]   = "011";
    destTable["A"]    = "100";
    destTable["AM"]   = "101";
    destTable["AD"]   = "110";
    destTable["AMD"]  = "111";

    compTable["0"]   = "0101010";
    compTable["1"]   = "0111111";
    compTable["-1"]  = "0111010";
    compTable["D"]   = "0001100";
    compTable["A"]   = "0110000";
    compTable["M"]   = "1110000";
    compTable["!D"]  = "0001101";
    compTable["!A"]  = "0110001";
    compTable["!M"]  = "1110001";
    compTable["-D"]  = "0001111";
    compTable["-A"]  = "0110011";
    compTable["-M"]  = "1110011";
    compTable["D+1"] = "0011111";
    compTable["A+1"] = "0110111";
    compTable["M+1"] = "1110111";
    compTable["D-1"] = "0001110";
    compTable["A-1"] = "0110010";
    compTable["M-1"] = "1110010";
    compTable["D+A"] = "0000010";
    compTable["D+M"] = "1000010";
    compTable["D-A"] = "0010011";
    compTable["D-M"] = "1010011";
    compTable["A-D"] = "0000111";
    compTable["M-D"] = "1000111";
    compTable["D&A"] = "0000000";
    compTable["D&M"] = "1000000";
    compTable["D|A"] = "0010101";
    compTable["D|M"] = "1010101";

    jmpTable["null"] = "000";
    jmpTable["JGT"]  = "001";
    jmpTable["JEQ"]  = "010";
    jmpTable["JGE"]  = "011";
    jmpTable["JLT"]  = "100";
    jmpTable["JNE"]  = "101";
    jmpTable["JLE"]  = "110";
    jmpTable["JMP"]  = "111";
}

std::string Encoder::encode (std::map<std::string, std::string>& table,
std::string str,
std::string error) {
    if (table.find (str) == table.end ())
        throw Error (error);
    return table[str];
}

std::string Encoder::encode_dest (std::string str) {
    return encode (destTable, str, "Encoder::encode_dest() - Invalid Destination: "s + str);
}
std::string Encoder::encode_comp (std::string str) {
    return encode (compTable, str, "Encoder::encode_comp() - Invalid Computation: "s + str);
}
std::string Encoder::encode_jmp (std::string str) {
    return encode (jmpTable, str, "Encoder::encode_jmp() - Invalid Jump: "s + str);
}
