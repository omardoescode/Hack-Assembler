#include <map>
#include <string>
class SymbolTable {
public:
    SymbolTable ();
    void initailize_predefined_symbols ();

    void add_symbol (std::string, unsigned int);
    void add_variable (std::string);
    bool contains (std::string);
    unsigned int get_address (std::string);
    unsigned int get_next_variable_address ();


private:
    std::map<std::string, unsigned int> table;
    unsigned int next_variable = 16;
};
