#include "LexiqueLine.hpp"

LexiqueLine::LexiqueLine() : Lexique()
{
    this->lexiqueLine = {};
}

LexiqueLine::~LexiqueLine()
{
}

std::map<std::string, vector<int, int> > LexiqueLine::getLexiqueLine(void) const
{
    return this->lexiqueLine;
}

void LexiqueLine::addWord(std::string word, int nbLine) override
{
    // If word exist inside the map
    if (this->lexiqueLine.contains(word))
    {
        this->lexiqueLine.at(word).append(nbLine);
    }
    else
    {
        // If it does not exist, insert it.
        this->lexiqueLine.insert({word, [nbLine]});
    }
}

void LexiqueLine::remove(std::string word) override
{
    Lexique::remove(word);
    if (this->lexiqueLine.contains(word))
    {
        for (std::map<std::string, int>::iterator iter = this->lexiqueLine.begin();
             iter != this->lexiqueLine.end();
             ++iter)
        {
            if (iter->first == word)
            {
                this->lexiqueLine.erase(iter);
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
 * @brief Overload of << operand to output the lexicon to the terminal
 *
 * @param os Output stream
 * @param lexique Lexique to display
 * @return std::ostream&
 */

std::ostream &operator<<(std::ostream &os, const LexiqueLine &lex)
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
LexiqueLine &LexiqueLine::operator+=(LexiqueLine &other)
{
    std::map<std::string, std::vector<int> > &current_lex = this->lexiqueLine;
    std::map<std::string, std::vector<int> > other_lex = other.getLexiqueLine();

    for (std::map<std::string, int>::iterator iter_other = other_lex.begin();
         iter_other != other_lex.end();
         ++iter_other)
    {

        // If word already in current_lex
        if (current_lex.contains(iter_other->first))
        {
            for (std::map<std::string, std::vector<int>>::iterator iter_current = current_lex.begin();
                 iter_current != current_lex.end();
                 ++iter_current)
            {
                // If it finds the word
                if (iter_current->first == iter_other->first)
                {
                    // Add the number of occurency
                    for (int i = 0; i < iter_other->second.size(); i++) {
                        
                        for (int j = 0; iter_current->second.size(); j++) {
                            if 
                        }
                    }
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
LexiqueLine &LexiqueLine::operator-=(LexiqueLine &other)
{
    std::map<std::string, int> &current_lex = this->lexiqueLine;
    std::map<std::string, int> other_lex = other.getLexiqueLine();

    for (std::map<std::string, int>::iterator iter_other = other_lex.begin();
         iter_other != other_lex.end();
         ++iter_other)
    {

        this->remove(iter_other->first);
    }

    return *this;
}

std::map<std::string, std::vector<int> > LexiqueLine::getLexiqueLine(void) const
{
    return this.lexiqueLine;
}