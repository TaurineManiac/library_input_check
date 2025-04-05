cmake_minimum_required(VERSION 3.20)
project(InputCheck)

set(CMAKE_CXX_STANDARD 17)

# Указываем, что это динамическая библиотека
add_library(InputCheck SHARED inputCheck.cpp)  # Изменили имя на InputCheck

# Указываем путь к заголовочному файлу
target_include_directories(InputCheck PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})