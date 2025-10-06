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

void Lexique::exists(std::string word)
{
    if (this->lexique.contains(word))
    {
        for (std::map<std::string, int>::iterator iter = this->lexique.begin();
             iter != this->lexique.end();
             ++iter)
        {
            if (iter->first == word)
            {
                std::cout << "Le mot '" << iter->first << "' est présent " << iter->second << " fois" << std::endl;
            }
        }
    }
    else
    {
        std::cout << "Le mot '" << word << "' n'existe pas." << std::endl;
    }
}

/**
 * @brief Remove a word from the lexic
 *
 * @param word word to remove
 */
void Lexique::remove(std::string word)
{
    if (this->lexique.contains(word))
    {
        for (std::map<std::string, int>::iterator iter = this->lexique.begin();
             iter != this->lexique.end();
             ++iter)
        {
            if (iter->first == word)
            {
                this->lexique.erase(iter);
            }
        }
    }
    else
    {
        std::cout << "Le mot '" << word << "' n'existe pas dans le lexique." << std::endl;
    }
}

int Lexique::length(void)
{
    int length = 0;
    for (std::map<std::string, int>::iterator iter = this->lexique.begin();
         iter != this->lexique.end();
         ++iter)
    {
        length++;
    }

    std::cout << "Le lexic a une taille de " << length << std::endl;

}