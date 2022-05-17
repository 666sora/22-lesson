#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
    std::map<std::string, std::string> phonebook;
    std::map<std::string, std::vector<std::string>> phonebook_backward;
    std::string answer = "";
    while (answer != "esc") {
        std::cout << "Input command: ";
        std::getline(std::cin, answer);
        if (answer == "esc") {
            continue;
        }
        else if (answer.find(' ') != std::string::npos) {
            std::string number = answer.substr(0, answer.find(' '));
            std::string name = answer.substr(answer.find(' ') + 1, answer.length());
            phonebook[number] = name;
            phonebook_backward[name].push_back(number);
        }
        else if (answer.find(' ') == std::string::npos) {
            if (answer.find('-') == std::string::npos) {
                std::map<std::string, std::vector<std::string>>::iterator itf = phonebook_backward.find(answer);
                for (auto i: itf->second) {
                    std::cout << answer << "'s phone number is " << i << std::endl;
                }
            }
            else if (answer.find('-') != std::string::npos) {
                std::map<std::string, std::string>::iterator itf = phonebook.find(answer);
                std::cout << answer << " is " << itf->second << "'s phone number" << std::endl;
            }
        }
    }
}

/*
Напишите программу «Телефонный справочник».
На вход программе поступают запросы трёх типов:
69-70-30 Ivanov — добавить телефон и фамилию абонента в справочник
69-70-30 — узнать фамилию абонента по номеру телефона
Ivanov — узнать телефон абонента по фамилии 
Необходимо выводить в консоль ответ на запросы 2 и 3. Обратите внимание, что абоненты 
по разным номерам могут иметь одинаковые фамилии. В таком случае на запрос 3 необходимо выдать все номера через пробелы. 
Операции запросов должны работать за O(logn) или O(logn × количество номеров с этой фамилией).
*/