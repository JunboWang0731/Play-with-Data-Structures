#include <iostream>
#include "LinkedListSet.h"
#include "FileOperation.h"

int main() {
    std::cout << "a-tale-of-two-cities.txt" << std::endl;
    vector<string> words;
    if (FileOps::readFile(".././a-tale-of-two-cities.txt", words)) {
        std::cout << "Total words: " << words.size() << std::endl;
        LinkedListSet<string> *linkedListSet = new LinkedListSet<string>();
        for(string word : words) {
            linkedListSet->add(word);
        }
        std::cout << "Total different words: " << linkedListSet->getSize() << std::endl;
    }
    std::cout << "a-tale-of-two-cities.txt" << std::endl;
    vector<string> words1;
    if (FileOps::readFile(".././pride-and-prejudice.txt", words1)) {
        std::cout << "Total words: " << words1.size() << std::endl;
        LinkedListSet<string> *linkedListSet1 = new LinkedListSet<string>();
        for(string word : words1) {
            linkedListSet1->add(word);
        }
        std::cout << "Total different words: " << linkedListSet1->getSize() << std::endl;
    }
    return 0;
}