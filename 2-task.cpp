#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> registry;
    
    std::string answer = " ";
    while (answer != "esc") {
        if (answer == "esc") {
            continue;
        }
        answer = " ";
        while (answer != "next" && answer != "esc") {
            std::cout << "Input command: ";
            std::cin >> answer;
            if (answer == "next" || answer == "esc") {
                continue;
            }
            std::map<std::string, int>::iterator itf = registry.find(answer);
            if (itf == registry.end()) {
                registry.insert(std::pair<std::string, int>(answer, 1));
            }
            else {
                itf->second++;
            }
        }
        if (answer == "next") {
            std::map<std::string, int>::iterator it = registry.begin();
            if (it == registry.end()) {
                std::cout << "No one in there" << std::endl;
                continue;
            }
            std::cout << it->first << std::endl;
            if (it->second > 1) it->second--;
            else registry.erase(it);
        }
    }
}

/*
Напишите программу.
На вход программе приходят строки с фамилиями или строка Next. 
Пришедшие люди становятся в очередь, а по запросу Next необходимо 
вызвать в регистратуру человека с фамилией, идущей первой в 
лексикографическом порядке (по алфавиту), и вывести его фамилию на экран. Фамилии пациентов могут повторяться.
Каждый запрос (на добавление и вывод) должен работать за O(logn).
*/