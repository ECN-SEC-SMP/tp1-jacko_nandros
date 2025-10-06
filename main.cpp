#include <iostream>
#include <string>
#include <map>

#include "main.h"
#include "utilitaire.hpp"

std::string lesMiserables;
std::string notreDameDeParis;

int main(int argc, char const *argv[])
{
    bool ret;

    std::cout << "Project Path :" << PROJECT_PATH << "\n";

    std::cout << "Get assets" << "\n";
    std::cout << std::string(PROJECT_PATH) + std::string(LES_MISERABLES_PATH) << "\n";
    std::cout << std::string(PROJECT_PATH) + std::string(NOTRE_DAME_DE_PARIS_PATH) << "\n";
    
    util::readFileIntoString(std::string(PROJECT_PATH) + std::string(LES_MISERABLES_PATH), lesMiserables);
    std::cout << "Les Miserables : " << (ret ? "Success" : "Error") << "\n";
    
    util::readFileIntoString(std::string(PROJECT_PATH) + std::string(NOTRE_DAME_DE_PARIS_PATH), notreDameDeParis);
    std::cout << "Les Miserables length : " << lesMiserables.length() << "\n";


    std::cout << "Notre Dame De Paris : " << (ret ? "Success" : "Error") << "\n";
    std::cout << "Notre Dame De Paris length : " << notreDameDeParis.length() << "\n";

    return 0;
}
