#include <fstream>
#include <istream>
#include <iterator>
class Parser {
public:
    Parser (std::string);

    // Functionalities
    bool hasMoreCommands ();
    void advance ();
    bool isInstructionA ();
    bool isInstructionC ();
    bool isPseudoCommand ();
    void get_a_fileds (std::string&);
    void get_c_fields (std::string&, std::string&, std::string&);
    void get_pseudo_fields (std::string& Symbol);

private:
    std::ifstream file;
    std::string current_command;
};
