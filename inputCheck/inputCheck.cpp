#include "inputCheck.h"
#include <string>
#include <iostream>
#include <locale.h>

namespace mylib {
    int checkYourSolution(int lastNum) {
        setlocale(LC_ALL, "Russian");
        std::string input;
        int k;

        while (true) {
            std::cout << "Введите число для выбора: ";
            std::getline(std::cin, input);

            if (input.empty()) {
                std::cout << "Ввод не должен быть пустым. Попробуйте снова." << std::endl;
                continue;
            }

            try {
                k = std::stoi(input);
                if (k < 1 || k > lastNum) {
                    std::cout << "Число должно быть от 1 до " << lastNum << std::endl;
                    continue;
                }
                return k;
            } catch (const std::invalid_argument& ia) {
                std::cout << "Некорректный ввод. Введите целое число." << std::endl;
            } catch (const std::out_of_range& oor) {
                std::cout << "Число выходит за пределы диапазона для типа int." << std::endl;
            }
        }
    }
}