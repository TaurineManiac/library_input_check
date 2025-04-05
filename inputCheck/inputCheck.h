#ifndef INPUTCHECK_INPUTCHECK_H
#define INPUTCHECK_INPUTCHECK_H

#ifdef _WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif

namespace mylib {
    DLL_EXPORT int checkYourSolution(int lastNum);
    DLL_EXPORT double checkTryToInputDouble();
    DLL_EXPORT int checkTryToInputMaxSizeOfSmth();
}

#endif // INPUTCHECK_INPUTCHECK_H