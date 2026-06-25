#include "stack.h"
#include <iostream>
#include <string>

int main() {
    int n;
    if (!(std::cin >> n)) return 0;

    Stack s;
    init(&s);

    for (int i = 0; i < n; i++) {
        std::string simbol;
        std::cin >> simbol;

        if (isdigit(simbol[0]) || (simbol.size() > 1 && simbol[0] == '-')) {
            push(&s, std::stoi(simbol));
        } else {
         
            int v2 = peek(&s); pop(&s);
            int v1 = peek(&s); pop(&s);

            if (simbol == "+") push(&s, v1 + v2);
            else if (simbol == "-") push(&s, v1 - v2);
            else if (simbol == "*") push(&s, v1 * v2);
            else if (simbol == "/") push(&s, v1 / v2);
        }
    }
    std::cout << peek(&s) << std::endl;
    return 0;
}