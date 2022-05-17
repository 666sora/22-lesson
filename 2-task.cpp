#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<int, std::string> registry;
    
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
            
            if (answer == "next" || answer == "next") {
                continue;
            }
            registry.insert(std::pair<int, std::string>(i, answer));
            i++;
        }
        if (answer == "next") {
            std::map<int, std::string>::iterator it = registry.begin();
            std::cout << it->second << std::endl;
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