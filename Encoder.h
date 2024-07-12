#include <map>
#include <string>

class Encoder {
public:
    Encoder ();

    std::string encode_dest (std::string);
    std::string encode_comp (std::string);
    std::string encode_jmp (std::string);

private:
    std::string encode (std::map<std::string, std::string>&, std::string, std::string mesg);
    void initialize ();

private:
    std::map<std::string, std::string> destTable, compTable, jmpTable;
};
