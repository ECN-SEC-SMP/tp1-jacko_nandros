#include "LexiqueLine.hpp"

LexiqueLine::LexiqueLine() : Lexique()
{
    this->lexiqueLine = {};
}

LexiqueLine::~LexiqueLine()
{
}

std::string LexiqueLine::getContent(void)
{
    std::string content = "";
    std::map<std::string, std::vector<int> > lexic = this->getLexiqueLine();

    for (std::map<std::string, std::vector<int> >::iterator iter = lexic.begin();
         iter != lexic.end();
         ++iter)
    {
        std::string vecteur = "[";
        int vecteurSize = static_cast<int>(iter->second.size());

        for (int i = 0; i < vecteurSize; i++)
        {
            vecteur += std::to_string(iter->second[i]);
            if (i == vecteurSize - 1)
                vecteur += "]";
            else
                vecteur += ", ";
        }

        int occurence = this->Lexique::nbOfOccurency(iter->first);

        content += iter->first + " - " + vecteur + " - " + std::to_string(occurence) + "\n";
    }

    return content;
}

void LexiqueLine::readBook(std::string book)
{
}

std::map<std::string, std::vector<int> > LexiqueLine::getLexiqueLine(void) const
{
    return this->lexiqueLine;
}

void LexiqueLine::addWord(std::string word, int nbLine)
{
    Lexique::addWord(word);
    // If word exist inside the map
    if (this->lexiqueLine.contains(word))
    {
        this->lexiqueLine.at(word).push_back(nbLine);
    }
    else
    {
        // If it does not exist, insert it.
        this->lexiqueLine.insert({word, {nbLine}});
    }
}

void LexiqueLine::remove(std::string word)
{
    Lexique::remove(word);
    if (this->lexiqueLine.contains(word))
    {
        for (std::map<std::string, std::vector<int> >::iterator iter = this->lexiqueLine.begin();
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

    std::map<std::string, std::vector<int> > lexic = lex.getLexiqueLine();
    for (std::map<std::string, std::vector<int> >::iterator iter = lexic.begin();
         iter != lexic.end();
         ++iter)
    {
        std::string vecteur = "[";
        int vecteurSize = iter->second.size();

        for (int i = 0; i < vecteurSize; i++)
        {
            vecteur += std::to_string(iter->second[i]);
            if (i == vecteurSize - 1)
                vecteur += "]";
            else
                vecteur += ", ";
        }

        os << "Mot: " << iter->first << " - Lignes: " << vecteur << " - Occurence: " << lex.Lexique::nbOfOccurency(iter->first) << std::endl;
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
    Lexique::operator+=(other);

    std::map<std::string, std::vector<int> > &current_lex = this->lexiqueLine;
    std::map<std::string, std::vector<int> > other_lex = other.getLexiqueLine();

    // Iterate over all words in the other LexiqueLine
    for (std::map<std::string, std::vector<int> >::iterator iter_other = other_lex.begin();
         iter_other != other_lex.end();
         ++iter_other)
    {
        const std::string &word = iter_other->first;
        std::vector<int> &other_lines = iter_other->second;

        // If word exists, append the new line numbers
        if (current_lex.contains(word))
        {
            std::vector<int> &current_lines = current_lex[word];
            for (int i = 0; i < other_lines.size(); i++)
            {
                current_lines.push_back(other_lines[i]);
            }
        }
        else
        {
            // If word does not exist, insert it with all line numbers
            current_lex.insert({word, other_lines});
        }
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
    Lexique::operator-=(other);

    std::map<std::string, std::vector<int> > &current_lex = this->lexiqueLine;
    std::map<std::string, std::vector<int> > other_lex = other.getLexiqueLine();

    for (std::map<std::string, std::vector<int> >::iterator iter_other = other_lex.begin();
         iter_other != other_lex.end();
         ++iter_other)
    {
        this->remove(iter_other->first);
    }

    return *this;
}
