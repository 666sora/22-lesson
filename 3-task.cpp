#include <iostream>
#include <map>
#include <string>

bool is_anagram(std::string& answer_1, std::string& answer_2) {
    std::map<char, int> word;
    for (int i = 0; i < answer_1.length(); i++) {
        word.insert(std::pair<char, int>(answer_1[i], i));
    }

    for (int i = 0; i < answer_1.length(); i++) {
        std::map<char, int>::iterator it = word.find(answer_2[i]);
        if (it == word.end()) {
            return false;
        }
        word.erase(it);
    }
    return true;
}

int main() {

    std::string answer_1, answer_2;
    do {
        std::cout << "Input first word: ";
        std::cin >> answer_1;
        std::cout << "Input second word: ";
        std::cin >> answer_2;
        if (answer_1.length() != answer_2.length()) {
            std::cout << "Wrong input" << std::endl;
        }
    } while (answer_1.length() != answer_2.length());

    if (is_anagram(answer_1, answer_2)) {
        std::cout << "It's anagram";
    }
    else {
        std::cout << "It's not anagram";
    }
}

/*
Напишите функцию, которая принимает две строки и возвращает true, если первая строка является
анаграммой второй (то есть можно получить первую строку из второй путём перестановки букв местами),
и false иначе. Для достижения хорошей асимптотики решения рекомендуется использовать std::map.
Пример анаграммы: лекарство — стекловар
*/