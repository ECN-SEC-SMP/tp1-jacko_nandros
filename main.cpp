#include <iostream>
#include <string>
#include <map>

int main(int argc, char const *argv[])
{
    
    std::cout << "===== CPP TP1" << "\n";

    std::map<std::string, int> myMap;

    myMap["one"] = 1;
    myMap["two"] = 2;
    myMap["three"] = 3;

    for ( const auto &[key, value]: myMap ) {
        std::cout << key << " : " << value << '\n';
    }

    return 0;
}
