#include "inputCheck.h"
#include <string>
#include <iostream>
#include <cctype>
#include <random>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <locale>

namespace mylib {
    std::string trimInput(const std::string& input) {
        int start = 0;
        int end = input.length() - 1;

        while (start < input.length() && (input[start] == ' ' || input[start] == '\t')) {
            start++;
        }

        while (end >= 0 && (input[end] == ' ' || input[end] == '\t')) {
            end--;
        }

        if (start > end) {
            return "";
        }

        return input.substr(start, end - start + 1);
    }

    std::string checkTryToInputString(bool allowCyrillic) {
        std::string input;
        while (true) {
            std::cout << "Введите строку: ";
            std::getline(std::cin, input);

            if (input.empty()) {
                std::cout << "Ввод не должен быть пустым. Попробуйте снова." << std::endl;
                continue;
            }

            input = trimInput(input);
            if (input.empty()) {
                std::cout << "Ввод не должен состоять только из пробелов. Попробуйте снова." << std::endl;
                continue;
            }

            if (!allowCyrillic) {
                bool hasCyrillic = true;
                for (char& c : input) {
                    if (std::isalpha(c)) {
                        c = std::tolower(c);
                        hasCyrillic = false;
                    }
                }
                if (hasCyrillic) {
                    std::cout << "Строка должна содержать символы латиницы. Попробуйте снова." << std::endl;
                    continue;
                }
            }

            return input;
        }
    }

    int checkYourSolution(int lastNum) {
        std::string input;
        int result;

        while (true) {
            std::cout << "Введите число для выбора: ";
            std::getline(std::cin, input);

            if (input.empty()) {
                std::cout << "Ввод не должен быть пустым. Попробуйте снова." << std::endl;
                continue;
            }

            input = trimInput(input);
            if (input.empty()) {
                std::cout << "Ввод не должен состоять только из пробелов. Попробуйте снова." << std::endl;
                continue;
            }

            try {
                result = std::stoi(input);
                if (result < 1 || result > lastNum) {
                    std::cout << "Число должно быть от 1 до " << lastNum << std::endl;
                    continue;
                }
                return result;
            } catch (const std::invalid_argument& ia) {
                std::cout << "Некорректный ввод. Введите целое число." << std::endl;
            } catch (const std::out_of_range& oor) {
                std::cout << "Число выходит за пределы диапазона для типа int." << std::endl;
            }
        }
    }

    double checkTryToInputDouble() {
        std::string input;
        double result;

        while (true) {
            std::cout << "Введите число с плавающей точкой: ";
            std::getline(std::cin, input);

            if (input.empty()) {
                std::cout << "Ввод не должен быть пустым. Попробуйте снова." << std::endl;
                continue;
            }

            input = trimInput(input);
            if (input.empty()) {
                std::cout << "Ввод не должен состоять только из пробелов. Попробуйте снова." << std::endl;
                continue;
            }

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

            if (input[0] == '-') {
                pos++;
            }

            if (pos == input.length() || !std::isdigit(input[pos])) {
                valid = false;
            } else if (hasDot) {
                if (dotPos == 0 || dotPos == input.length() - 1 || !std::isdigit(input[dotPos - 1]) || !std::isdigit(input[dotPos + 1])) {
                    valid = false;
                }
            }

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
                std::locale::global(std::locale("C"));
                result = std::stod(input);
                return result;
            } catch (const std::invalid_argument& ia) {
                std::cout << "Некорректный ввод. Введите число с плавающей точкой." << std::endl;
            } catch (const std::out_of_range& oor) {
                std::cout << "Число выходит за пределы диапазона для типа double." << std::endl;
            }
        }
    }

    int checkTryToInputMaxSizeOfSmth() {
        std::string input;
        int result;

        while (true) {
            std::cout << "Введите число для максимального размера: ";
            std::getline(std::cin, input);

            if (input.empty()) {
                std::cout << "Ввод не должен быть пустым. Попробуйте снова." << std::endl;
                continue;
            }

            input = trimInput(input);
            if (input.empty()) {
                std::cout << "Ввод не должен состоять только из пробелов. Попробуйте снова." << std::endl;
                continue;
            }

            try {
                result = std::stoi(input);
                if (result <= 0) {
                    std::cout << "Размер должен быть больше 0. Попробуйте снова." << std::endl;
                    continue;
                }
                return result;
            } catch (const std::invalid_argument& ia) {
                std::cout << "Некорректный ввод. Введите целое число." << std::endl;
            } catch (const std::out_of_range& oor) {
                std::cout << "Число выходит за пределы диапазона для типа int." << std::endl;
            }
        }
    }

    int checkTryToInputInt() {
        std::string input;
        int result;

        while (true) {
            std::cout << "Введите целое число: ";
            std::getline(std::cin, input);

            if (input.empty()) {
                std::cout << "Ввод не должен быть пустым. Попробуйте снова." << std::endl;
                continue;
            }

            input = trimInput(input);
            if (input.empty()) {
                std::cout << "Ввод не должен состоять только из пробелов. Попробуйте снова." << std::endl;
                continue;
            }
            bool isAllDigits = true;
            for (int i = 0; i < input.size(); i++) {
                if (i == 0 && input[i] == '-') {
                    continue;
                }
                if (!isdigit(input[i])) {
                    isAllDigits = false;
                    break;
                }
            }
            if (!isAllDigits) {
                std::cout << "Некорректный ввод. Введите целое число." << std::endl;
                continue;
            }
            try {
                result = std::stoi(input);
                return result;
            } catch (const std::invalid_argument& ia) {
                std::cout << "Некорректный ввод. Введите целое число." << std::endl;
            } catch (const std::out_of_range& oor) {
                std::cout << "Число выходит за пределы диапазона для типа int." << std::endl;
            }
        }
    }

    int checkTryToInputChar() {
        std::string input;
        while (true) {
            std::cout << "Введите символ: ";
            std::getline(std::cin, input);

            if (input.empty()) {
                std::cout << "Ввод не должен быть пустым. Попробуйте снова." << std::endl;
                continue;
            }

            input = trimInput(input);
            if (input.empty()) {
                std::cout << "Ввод не должен состоять только из пробелов. Попробуйте снова." << std::endl;
                continue;
            }

            if (input.length() != 1) {
                std::cout << "Введите ровно один символ." << std::endl;
                continue;
            }

            return static_cast<int>(input[0]);
        }
    }

    bool isDashHere(const std::string& s) {
        if (s.empty()) return false;
        if (s[0] == '-' || s[s.length() - 1] == '-') return false;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '-') {
                if (i == 0 || i == s.length() - 1 || (i + 1 < s.length() && s[i + 1] == '-')) {
                    return false;
                }
            }
        }
        return true;
    }

    std::string checkTryToInputStringName(const std::string& s) {
        std::string input = trimInput(s);
        while (true) {
            std::cout << "Введите строку: ";
            std::getline(std::cin, input);

            if (input.empty()) {
                std::cout << "Ввод не должен быть пустым. Попробуйте снова." << std::endl;
                continue;
            }

            input = trimInput(input);
            if (input.empty()) {
                std::cout << "Ввод не должен состоять только из пробелов. Попробуйте снова." << std::endl;
                continue;
            }

            if (input.length() > 20) {
                std::cout << "Строка не должна превышать 20 символов. Попробуйте снова." << std::endl;
                continue;
            }

            bool valid = true;
            for (int i = 0; i < input.length(); ++i) {
                if (!std::isalpha(input[i]) && input[i] != '-') {
                    valid = false;
                    break;
                }
                if (input[i] == '-' && (i == 0 || i == input.length() - 1 || !std::isalpha(input[i - 1]) || !std::isalpha(input[i + 1]))) {
                    valid = false;
                    break;
                }
            }

            if (!valid || !isDashHere(input)) {
                std::cout << "Строка должна содержать только буквы и символ '-', расположенный между двумя буквами, не в начале, не в конце и без последовательных тире. Попробуйте снова." << std::endl;
                continue;
            }

            return input;
        }
    }

    std::string checkTryToInputPassword(const std::string& s) {
        std::string input = trimInput(s);
        while (true) {
            std::cout << "Введите пароль: ";
            std::getline(std::cin, input);

            if (input.empty()) {
                std::cout << "Ввод не должен быть пустым. Попробуйте снова." << std::endl;
                continue;
            }

            input = trimInput(input);
            if (input.empty()) {
                std::cout << "Ввод не должен состоять только из пробелов. Попробуйте снова." << std::endl;
                continue;
            }

            if (input.length() > 20 || input.length() < 6) {
                std::cout << "Пароль должен содержать от 6 до 20 символов. Попробуйте снова." << std::endl;
                continue;
            }

            bool valid = true;
            bool hasLetter = false;
            bool hasDigit = false;
            for (int i = 0; i < input.length(); ++i) {
                if (!std::isalnum(input[i]) && input[i] != '-') {
                    valid = false;
                    break;
                }
                if (input[i] == '-' && (i == 0 || i == input.length() - 1 || !std::isalnum(input[i - 1]) || !std::isalnum(input[i + 1]))) {
                    valid = false;
                    break;
                }
                if (std::isalpha(input[i])) {
                    hasLetter = true;
                }
                if (std::isdigit(input[i])) {
                    hasDigit = true;
                }
            }

            if (!valid || !isDashHere(input)) {
                std::cout << "Пароль должен содержать только буквы, цифры и символ '-', расположенный между двумя символами, не в начале, не в конце и без последовательных тире. Попробуйте снова." << std::endl;
                continue;
            }

            if (!hasLetter || !hasDigit) {
                std::cout << "Пароль должен содержать хотя бы одну букву и одну цифру. Попробуйте снова." << std::endl;
                continue;
            }

            return input;
        }
    }
}