#ifndef LEXIQUE_HPP
#define LEXIQUE_HPP

#include <iostream>
#include <map>
class Lexique
{

private:
    std::map<std::string, int> lexique;

public:
    Lexique(void);
    ~Lexique(void);
    std::map<std::string, int> getLexique(void) const;
    void addWord(std::string word);
    void toString(void);
    void exists(std::string word);
    void remove(std::string word);
    std::string getWords(void);
    int length(void);

    // Opérateur Interne //
    Lexique &operator+=(Lexique &other);
    Lexique &operator-=(Lexique &other);

    // Operateur Externe //
    friend std::ostream &operator<<(std::ostream &os, const Lexique &lexique);
};

#endif
