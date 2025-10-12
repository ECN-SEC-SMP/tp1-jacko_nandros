#ifndef LEXIQUE_HPP
#define LEXIQUE_HPP

#include <iostream>
#include <map>
#include <string>
class Lexique
{

protected:
    /**
     * @brief Contains as key the word and as value the occurency
     *
     */
    std::map<std::string, int> lexique;

public:
    /**
     * @brief Construct a new Lexique object
     *
     */
    Lexique(void);

    /**
     * @brief Destroy the Lexique object
     *
     */
    virtual ~Lexique(void);

    /**
     * @brief Get all words from a book
     * 
     * @param book String of the book
     */
    virtual void readBook(std::string book);

    /**
     * @brief Get the Lexique object
     *
     * @return std::map<std::string, int>
     */
    std::map<std::string, int> getLexique(void) const;

    /**
     * @brief Add a word to the lexicon
     *
     * @param word New word to add to the lexic.
     * If the word already exists in the lexicon, increase its occurency.
     */
    virtual void addWord(std::string word);

    /**
     * @brief Counts the number of occurency of a word
     *
     * @param word Word to count
     * @return Number of occureny of the word
     * @return -1 if word does not exist inside the lexicon
     */
    int nbOfOccurency(std::string word);

    /**
     * @brief Remove a word from the lexicon if it exists
     *
     * @param word Word to remove
     */
    virtual void remove(std::string word);

    /**
     * @brief Get all the content of the lexicon without the occurency
     *
     * @return std::string
     */
    virtual std::string getContent(void);

    /**
     * @brief Retrieve the length of the lexicon
     *
     * @return int
     */
    virtual int length(void);

    // Internal Operand //

    /**
     * @brief Add the lexicon parameter to the caller
     *
     * @param other The other lexicon
     * @return Lexique&
     */
    Lexique &operator+=(Lexique &other);

    /**
     * @brief Substract the paramteter lexicon to the caller
     * It only keep the words from the caller that are not inside the other lexicon
     *
     * @param other The other lexicon
     * @return Lexique&
     */
    Lexique &operator-=(Lexique &other);

    // External Operand //

    /**
     * @brief Overload of << operand to output the lexicon to the terminal
     *
     * @param os Output stream
     * @param lexique Lexique to display
     * @return std::ostream&
     */
    friend std::ostream &operator<<(std::ostream &os, const Lexique &lexique);
};

#endif
