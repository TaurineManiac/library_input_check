#  Library for input validation
****
A lightweight C++ library for robust user input validation 
(strings, numbers, passwords, etc.). 
Handles edge cases, trims whitespace, 
and supports cross-platform builds.

## Features:

- **Trim whitespace** — Auto-trim leading/trailing spaces.
- **Type validation** — Integers, floats, strings, passwords.
- **Custom rules** — Cyrillic support, dash validation, password complexity.

## Limitations:

⚠️ **Current limitations:**

1. **Thread Safety**: Not thread-safe due to shared `std::cin` usage
2. **Localization**: Hardcoded Russian error messages (no i18n)
3. **Password Input**: Visible input (no asterisk masking)
4. **Performance**: Multiple string copies during processing
5. **Unicode**: Limited to ASCII/Cyrillic characters
6. **Dependencies**: Requires C++17 standard library

## List of Functions:
In order not to clutter it up, I moved it [here](./ListOfFunctions.md).

## Usage example:

**Input:**
```C++
#include "inputCheck.h"

int main() {
    int num = mylib::checkTryToInputInt();  // Запрашивает ввод, пока не получит число
    std::cout << "Вы ввели: " << num << std::endl;
    return 0;
}
```

**Output:**
```C++
Введите целое число: abc  
Некорректный ввод. Введите целое число.  
Введите целое число: 42  
Вы ввели: 42
```

## Lessons Learned

🔧 **Development insights:**

- **Code Structure**: Mastered header/source separation
- **Validation**: Implemented comprehensive input checks
- **Error Handling**: Robust `try-catch` for numeric conversions
- **Documentation**: Produced bilingual (EN/RU) docs










