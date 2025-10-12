#ifndef LEXIQUELINE_HPP
#define LEXIQUELINE_HPP

#include <vector>

#include "Lexique.hpp"

class LexiqueLine : public Lexique
{

private:
    std::map<std::string, std::vector<int> > lexiqueLine;

public:
    LexiqueLine();
    ~LexiqueLine() override;

    /**
     * @brief Get the Lexique object
     *
     * @return std::map<std::string, int>
     */
    std::map<std::string, vector<int, int> > getLexiqueLine(void) const;

    /**
     * @brief Add a word to the lexicon
     *
     * @param word New word to add to the lexic.
     * @param nbline Number of the line where the word was find.
     * If the word already exists in the lexicon, increase its occurency.
     */
    void addWord(std::string word, int nbLine) override;

    /**
     * @brief Remove a word from the lexicon if it exists
     *
     * @param word Word to remove
     */
    void remove(std::string word) override;

    /**
     * @brief Get all words from a book
     *
     * @param book String of the book
     */
    void readBook(std::string book) override;

    /**
     * @brief Get all the content of the lexicon without the occurency
     *
     * @return std::string
     */
    std::string getContent(void);

    /**
     * @brief Retrieve the length of the lexicon
     *
     * @return int
     */
    int length(void);

    // Internal Operand //

    /**
     * @brief Add the lexicon parameter to the caller
     *
     * @param other The other lexicon
     * @return LexiqueLine&
     */
    LexiqueLine &operator+=(LexiqueLine &other);

    /**
     * @brief Substract the paramteter lexicon to the caller
     * It only keep the words from the caller that are not inside the other lexicon
     *
     * @param other The other lexicon
     * @return LexiqueLine&
     */
    LexiqueLine &operator-=(LexiqueLine &other);

    // External Operand //

    /**
     * @brief Overload of << operand to output the lexicon to the terminal
     *
     * @param os Output stream
     * @param lexique LexiqueLine to display
     * @return std::ostream&
     */
    friend std::ostream &operator<<(std::ostream &os, const LexiqueLine &lexique);
};

#endif