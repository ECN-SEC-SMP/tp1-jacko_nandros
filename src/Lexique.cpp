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
                break;
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

    std::cout << "Le lexique a une taille de " << length << std::endl;
    return length;
}

std::string Lexique::getWords(void)
{
    std::string content;
    for (std::map<std::string, int>::iterator iter = this->lexique.begin();
         iter != this->lexique.end();
         ++iter)
    {
        content += iter->first + "\n";
    }
    return content;
}

Lexique::~Lexique() {}

std::ostream &operator<<(std::ostream &os, const Lexique &lex)
{
    std::map<std::string, int> lexic = lex.getLexique();
    for (std::map<std::string, int>::iterator iter = lexic.begin();
         iter != lexic.end();
         ++iter)
    {
        os << iter->first << " : " << iter->second << std::endl;
    }

    return os;
}

Lexique &Lexique::operator+=(Lexique &other)
{
    std::map<std::string, int> &current_lex = this->lexique;
    std::map<std::string, int> other_lex = other.getLexique();

    for (std::map<std::string, int>::iterator iter_other = other_lex.begin();
         iter_other != other_lex.end();
         ++iter_other)
    {

        // If word already in current_lex
        if (current_lex.contains(iter_other->first))
        {
            for (std::map<std::string, int>::iterator iter_current = current_lex.begin();
                 iter_current != current_lex.end();
                 ++iter_current)
            {
                // If it finds the word
                if (iter_current->first == iter_other->first)
                {
                    // Add the number of occurency
                    iter_current->second += iter_other->second;
                    // Break current_lex loop
                    break;
                }
            }
        }
        current_lex.insert({iter_other->first, iter_other->second});
    }

    return *this;
}

Lexique &Lexique::operator-=(Lexique &other)
{
    std::map<std::string, int> &current_lex = this->lexique;
    std::map<std::string, int> other_lex = other.getLexique();

    for (std::map<std::string, int>::iterator iter_other = other_lex.begin();
         iter_other != other_lex.end();
         ++iter_other)
    {

        this->remove(iter_other->first);
    }

    return *this;
}

std::map<std::string, int> Lexique::getLexique(void) const
{
    return this->lexique;
}