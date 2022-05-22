#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> registry;
    
    std::string answer = " ";
    int i = 0;
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
            registry.insert(std::pair<std::string, int>(answer, i));
            i++;
        }
        if (answer == "next") {
            std::map<std::string, int>::iterator it = registry.begin();
            if (it == registry.end()) {
                std::cout << "No one in there" << std::endl;
                continue;
            }
            std::cout << it->first << std::endl;
            registry.erase(it);
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