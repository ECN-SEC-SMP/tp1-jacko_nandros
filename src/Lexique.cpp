#include "Lexique.hpp"

#include <cstring>
#include <iostream>
#include <cinttypes>

#include "utilitaire.hpp"

/**
 * @brief Construct a new Lexique object
 *
 */
Lexique::Lexique(void)
{
    this->lexique = {};
};

void Lexique::readBook(std::string book)
{
    util::remove_punctuation(book);
    char *book_char = (char *)book.c_str();
    char *tok;
    std::string word;

    tok = strtok(book_char, " \n");
    while (tok != NULL)
    {
        word = std::string(tok);
        util::trim_punctuation(word);
        util::to_lower(word);
        this->addWord(word);

        // Get next token
        tok = strtok(NULL, " \n\r");
    }

    return;
}

/**
 * @brief Add a word to the lexicon
 *
 * @param word New word to add to the lexic.
 * If the word already exists in the lexicon, increase its occurency.
 */
void Lexique::addWord(std::string word)
{
    // If word exist inside the map
    if (this->lexique.contains(word))
    {
        this->lexique.at(word) += 1;
    }
    else
    {
        // If it does not exist, insert it.
        this->lexique.insert({word, 1});
    }
}

/**
 * @brief Counts the number of occurency of a word
 *
 * @param word Word to count
 * @return Number of occureny of the word
 * @return -1 if word does not exist inside the lexicon
 */
int Lexique::nbOfOccurency(std::string word)
{
    if (this->lexique.contains(word))
    {
        for (std::map<std::string, int>::iterator iter = this->lexique.begin();
             iter != this->lexique.end();
             ++iter)
        {
            if (iter->first == word)
            {
                return iter->second;
            }
        }
    }
    return -1;
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

/**
 * @brief Retrieve the length of the lexicon
 *
 * @return int
 */
int Lexique::length(void)
{
    int length = 0;
    for (std::map<std::string, int>::iterator iter = this->lexique.begin();
         iter != this->lexique.end();
         ++iter)
    {
        length++;
    }

    return length;
}

/**
 * @brief Get all the content of the lexicon without the occurency
 *
 * @return std::string
 */
std::string Lexique::getContent(void)
{
    std::string content;
    for (std::map<std::string, int>::iterator iter = this->lexique.begin();
         iter != this->lexique.end();
         ++iter)
    {
        content += iter->first + ": " + std::to_string(iter->second) + "\n";
    }
    return content;
}

/**
 * @brief Destroy the Lexique object
 *
 */
Lexique::~Lexique() {}

/**
 * @brief Overload of << operand to output the lexicon to the terminal
 *
 * @param os Output stream
 * @param lexique Lexique to display
 * @return std::ostream&
 */

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

/**
 * @brief Add the lexicon parameter to the caller
 *
 * @param other The other lexicon
 * @return Lexique&
 */
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

/**
 * @brief Substract the paramteter lexicon to the caller
 * It only keep the words from the caller that are not inside the other lexicon
 *
 * @param other The other lexicon
 * @return Lexique&
 */
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

/**
 * @brief Get the Lexique object
 *
 * @return std::map<std::string, int>
 */
std::map<std::string, int> Lexique::getLexique(void) const
{
    return this->lexique;
}