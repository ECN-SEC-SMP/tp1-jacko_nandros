#ifndef LEXIQUE_HPP
#define LEXIQUE_HPP

#include <iostream>
#include <map>
class Lexique {

    private: 
        std::map<std::string, int> lexique;

    public:
        Lexique(void);
        ~Lexique(void);
        void addWord(std::string word);
        void toString(void);
        void exists(std::string word);
        void remove(std::string word);
        int length(void);
};

#endif
