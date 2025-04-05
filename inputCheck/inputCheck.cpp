#include "inputCheck.h"
#include <string>
#include <iostream>
#include <locale.h>
#include <cctype> // Для std::isdigit

namespace mylib {
    int checkYourSolution(int lastNum) {
        std::string input;
        int k;

        while (true) {
            std::cout << "Введите число для выбора: ";
            std::getline(std::cin, input);

            // Проверка на пустой ввод
            if (input.empty()) {
                std::cout << "Ввод не должен быть пустым. Попробуйте снова." << std::endl;
                continue;
            }

            // Удаляем пробелы в начале и конце, используя int вместо size_t
            int start = 0;
            int end = input.length() - 1;

            // Находим первый непробельный символ
            while (start < input.length() && (input[start] == ' ' || input[start] == '\t')) {
                start++;
            }

            // Находим последний непробельный символ
            while (end >= 0 && (input[end] == ' ' || input[end] == '\t')) {
                end--;
            }

            // Проверяем, не состоит ли строка только из пробелов
            if (start > end) {
                std::cout << "Ввод не должен состоять только из пробелов. Попробуйте снова." << std::endl;
                continue;
            }

            // Обрезаем строку
            input = input.substr(start, end - start + 1);

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

    double checkTryToInputDouble() {
        std::string input;
        double k;

        while (true) {
            std::cout << "Введите число с плавающей точкой: ";
            std::getline(std::cin, input);

            // Проверка на пустой ввод
            if (input.empty()) {
                std::cout << "Ввод не должен быть пустым. Попробуйте снова." << std::endl;
                continue;
            }

            // Удаляем пробелы в начале и конце, используя int вместо size_t
            int start = 0;
            int end = input.length() - 1;

            // Находим первый непробельный символ
            while (start < input.length() && (input[start] == ' ' || input[start] == '\t')) {
                start++;
            }

            // Находим последний непробельный символ
            while (end >= 0 && (input[end] == ' ' || input[end] == '\t')) {
                end--;
            }

            // Проверяем, не состоит ли строка только из пробелов
            if (start > end) {
                std::cout << "Ввод не должен состоять только из пробелов. Попробуйте снова." << std::endl;
                continue;
            }

            // Обрезаем строку
            input = input.substr(start, end - start + 1);

            // Проверяем количество точек
            int dotCounter = 0;
            for (int i = 0; i < input.length(); i++) {
                if (input[i] == '.') {
                    dotCounter++;
                }
            }
            if (dotCounter > 1) {
                std::cout << "Точка должна быть только одна!" << std::endl;
                continue;
            }

            // Проверяем формат числа
            bool valid = true;
            bool hasDot = (dotCounter == 1);
            int dotPos = -1;
            for (int i = 0; i < input.length(); i++) {
                if (input[i] == '.') {
                    dotPos = i;
                    break;
                }
            }
            int pos = 0;

            // Проверяем, начинается ли строка с минуса
            if (input[0] == '-') {
                pos++;
            }

            // Проверяем, что перед точкой есть хотя бы одна цифра
            if (pos == input.length() || !std::isdigit(input[pos])) {
                valid = false;
            } else if (hasDot) {
                // Проверяем, что после точки есть хотя бы одна цифра
                if (dotPos == 0 || dotPos == input.length() - 1 || !std::isdigit(input[dotPos - 1]) || !std::isdigit(input[dotPos + 1])) {
                    valid = false;
                }
            }

            // Проверяем, что все символы корректны
            for (int i = pos; i < input.length(); i++) {
                if (i != dotPos && !std::isdigit(input[i])) {
                    valid = false;
                    break;
                }
            }

            if (!valid) {
                std::cout << "Некорректный формат числа. Введите число в формате x.y (где x и y — цифры)." << std::endl;
                continue;
            }

            try {
                k = std::stod(input);
                return k;
            } catch (const std::invalid_argument& ia) {
                std::cout << "Некорректный ввод. Введите число с плавающей точкой." << std::endl;
            } catch (const std::out_of_range& oor) {
                std::cout << "Число выходит за пределы диапазона для типа double." << std::endl;
            }
        }
    }

    int checkTryToInputMaxSizeOfSmth() {
        std::string input;
        int k;

        while (true) {
            std::cout << "Введите число для выбора: ";
            std::getline(std::cin, input);

            // Проверка на пустой ввод
            if (input.empty()) {
                std::cout << "Ввод не должен быть пустым. Попробуйте снова." << std::endl;
                continue;
            }

            // Удаляем пробелы в начале и конце, используя int вместо size_t
            int start = 0;
            int end = input.length() - 1;

            // Находим первый непробельный символ
            while (start < input.length() && (input[start] == ' ' || input[start] == '\t')) {
                start++;
            }

            // Находим последний непробельный символ
            while (end >= 0 && (input[end] == ' ' || input[end] == '\t')) {
                end--;
            }

            // Проверяем, не состоит ли строка только из пробелов
            if (start > end) {
                std::cout << "Ввод не должен состоять только из пробелов. Попробуйте снова." << std::endl;
                continue;
            }

            // Обрезаем строку
            input = input.substr(start, end - start + 1);

            try {
                k = std::stoi(input);
                if (k <= 0) {
                    std::cout << "Размер должен быть больше 0. Попробуйте снова." << std::endl;
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