#include <iostream>
#include <string>
#include <map>
#include <assert.h>

#include "main.h"
#include "utilitaire.hpp"
#include "Lexique.hpp"

std::string lesMiserables;
std::string notreDameDeParis;

void test_ReadingWriting(void);
void test_addWordLexique(void);
void test_removeWordLexique(void);
void test_nbOfOccurencyLexique(void);
void test_lengthLexique(void);
void test_getContentLexique(void);
void test_operatorOutLexique(void);
void test_operatorAddLexique(void);
void test_operatorSubLexique(void);
int main(int argc, char const *argv[])
{

    // test_addWordLexique();
    // test_removeWordLexique();
    // test_nbOfOccurencyLexique();
    // test_lengthLexique();
    // test_getContentLexique();
    // test_operatorOutLexique();
    // test_operatorAddLexique();
    test_operatorSubLexique();
    // bool ret;

    // // Tests
    // test_ReadingWriting();

    // // Reading lesMiseables
    // std::cout << "===== Get lesMiserables" << "\n";
    // ret = util::readFileIntoString(std::string(PROJECT_PATH) + std::string(LES_MISERABLES_PATH), lesMiserables);
    // assert(ret);

    // std::cout << "===== Create Lexique Object" << "\n";
    // Lexique lexique;
    // std::cout << "===== Lexique Read book" << "\n";
    // lexique.readBook(lesMiserables);
    // std::cout << "===== Print lexique" << "\n";
    // std::cout << "Length of Lexique : " << lexique.length() << "\n";

    // // std::cout << lexique.getContent() << "\n";
    // util::writeStringIntoFile(std::string(PROJECT_PATH) + std::string(LES_MISERABLES_LEXIQUE_PATH), lexique.getContent());

    return 0;
}

void test_ReadingWriting(void)
{
    bool ret;

    std::cout << "Project Path :" << PROJECT_PATH << "\n";

    std::cout << "===== Reading Files" << "\n";
    std::cout << std::string(PROJECT_PATH) + std::string(LES_MISERABLES_PATH) << "\n";
    std::cout << std::string(PROJECT_PATH) + std::string(NOTRE_DAME_DE_PARIS_PATH) << "\n";

    ret = util::readFileIntoString(std::string(PROJECT_PATH) + std::string(LES_MISERABLES_PATH), lesMiserables);
    std::cout << "Les Miserables : " << (ret ? "Success" : "Error") << "\n";

    ret = util::readFileIntoString(std::string(PROJECT_PATH) + std::string(NOTRE_DAME_DE_PARIS_PATH), notreDameDeParis);
    std::cout << "Les Miserables length : " << lesMiserables.length() << "\n";

    std::cout << "Notre Dame De Paris : " << (ret ? "Success" : "Error") << "\n";
    std::cout << "Notre Dame De Paris length : " << notreDameDeParis.length() << "\n";

    std::cout << "===== Writing Files" << "\n";
    std::string testWrite = "JACKOOODFSFDSJAKFHSDKJGFBULDGHBSR\nwagyula\n[esdfds,fdss fdsdfs, 125]";
    std::cout << "Write into " << std::string(PROJECT_PATH) + TEST_LEXIQUE_PATH << "\n";
    ret = util::writeStringIntoFile(std::string(PROJECT_PATH) + TEST_LEXIQUE_PATH, testWrite);
    std::cout << "Write Success : " << (ret ? "Success" : "Error") << "\n";

    return;
}

void test_addWordLexique(void)
{

    Lexique l1 = Lexique();
    l1.addWord("Mot_1");
    l1.addWord("Mot_1");
    l1.addWord("Mot_2");
    std::map<std::string, int> map = l1.getLexique();
    assert(map["Mot_1"] == 2);
    assert(map["Mot_2"] == 1);
}

void test_removeWordLexique(void)
{

    Lexique l1 = Lexique();
    l1.addWord("Mot_1");
    l1.addWord("Mot_1");
    l1.addWord("Mot_2");

    l1.remove("Mot_1"); // First removal
    l1.remove("Mot_1"); // Try  to remove a non-existing word

    std::map<std::string, int> map = l1.getLexique();
    assert(map["Mot_2"] == 1);
}

void test_nbOfOccurencyLexique(void)
{
    Lexique l1 = Lexique();
    l1.addWord("Mot_1");
    l1.addWord("Mot_1");
    l1.addWord("Mot_2");

    assert(l1.nbOfOccurency("Mot_1") == 2);
    assert(l1.nbOfOccurency("Mot_2") == 1);
    assert(l1.nbOfOccurency("Mot_3") == -1);
}

void test_lengthLexique(void)
{
    Lexique l1 = Lexique();
    Lexique l2 = Lexique();
    l1.addWord("Mot_1");
    l1.addWord("Mot_1");
    l1.addWord("Mot_2");

    assert(l1.length() == 2);
    assert(l2.length() == 0);
}

void test_getContentLexique(void)
{
    Lexique l1 = Lexique();
    Lexique l2 = Lexique();
    l1.addWord("Mot_1");
    assert(l1.getContent() == "Mot_1: 1\n");
    assert(l2.getContent() == "");
}

void test_operatorOutLexique(void)
{
    Lexique l1 = Lexique();
    Lexique l2 = Lexique();
    l1.addWord("Mot_1");
    l1.addWord("Mot_1");
    l1.addWord("Mot_2");

    std::cout << l1;
    std::cout << l2;
}

void test_operatorAddLexique(void)
{
    Lexique l1 = Lexique();
    Lexique l2 = Lexique();
    l1.addWord("Mot_1");

    l2.addWord("Mot_1");
    l2.addWord("Mot_2");

    l1 += l2;
    assert(l1.getContent() == "Mot_1: 2\nMot_2: 1\n");
}

void test_operatorSubLexique(void)
{
    Lexique l1 = Lexique();
    Lexique l2 = Lexique();
    l1.addWord("Mot_1");
    l1.addWord("Mot_1");
    l1.addWord("Mot_2");

    l2.addWord("Mot_2");

    l1 -= l2;
    assert(l1.getContent() == "Mot_1: 2\n");
}
    