## List of functions:
| Function                | Description                             | Example                                   |
|-------------------------|-----------------------------------------|------------------------------------------------------------------|
| `checkTryToInputInt()`  | Validates integer input                 | `int num = checkTryToInputInt()`          |
| `checkTryToInputDouble()` | Validates floating-point input          | `double val = checkTryToInputDouble()`    |
| `checkTryToInputString`  | 	Validates string input                 |`	std::string name = mylib::checkTryToInputString();std::string address = mylib::checkTryToInputString(true); // Allows Cyrillic`|
|`checkTryToInputChar()`| Validates single character input        |`char initial = static_cast<char>(mylib::checkTryToInputChar());int asciiCode = mylib::checkTryToInputChar();`|
| `checkTryToInputPassword()` | Validates password input (6-20 symbols) | `std::string pwd = checkTryToInputPassword()` |
|`checkTryToInputStringName()`| Validates name strings                                        |`std::string fullName = mylib::checkTryToInputStringName("Doe-Smith");std::string lastName = mylib::checkTryToInputStringName(userInput);`|
|`checkYourSolution()`|	Validates menu selections|`int menuChoice = mylib::checkYourSolution(5); // 1-5 onlyint option = mylib::checkYourSolution(10); // 1-10 range`|
|`checkTryToInputMaxSizeOfSmth()`|Validates size limits|`int maxSize = mylib::checkTryToInputMaxSizeOfSmth();int bufferSize = mylib::checkTryToInputMaxSizeOfSmth();`|
|`trimInput()`|	Trims whitespace from strings|`std::string clean = mylib::trimInput(" hello "); // "hello"std::string trimmed = mylib::trimInput(rawInput);`|
|`isDashHere()`|Checks dash placement|`bool valid = mylib::isDashHere("well-formed"); // truebool bad = mylib::isDashHere("-bad"); // false`|
[Return back](./readme.md)
