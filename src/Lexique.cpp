#include "Lexique.hpp"

Lexique::Lexique(void)
{
    this->lexique = {};
};

/**
 * @brief Add a word to the map, if it already exists increase its occurency
 * 
 * @param word the word to add
 */
void Lexique::addWord(std::string word)
{
    if (this->lexique.contains(word))
    {

        for (std::map<std::string, int>::iterator iter = this->lexique.begin();
             iter != this->lexique.end();
             ++iter)
        {
            if (iter->first == word)
            {
                iter->second++;
            }
        }
    }
    else
    {
        this->lexique.insert({word, 1});
    }
}

/**
 * @brief 
 * 
 */
void Lexique::toString()
{
    for (std::map<std::string, int>::iterator iter = this->lexique.begin();
         iter != this->lexique.end();
         ++iter)
    {
        std::cout << "Mot:" << iter->first << " Occurence: " << iter->second << std::endl;
    }
}