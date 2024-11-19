cmake_minimum_required(VERSION 3.10)
project(third)

# Укажите стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Укажите папку сборки yaml-cpp
add_subdirectory(yaml-cpp)

# Добавьте основной файл main.cpp
add_executable(third main.cpp)

# Свяжите проект с библиотекой yaml-cpp
target_link_libraries(third PRIVATE yaml-cpp)

# Добавьте googletest
add_subdirectory(googletest)

add_executable(tests test_main.cpp)

# Свяжите тесты с библиотеками gtest и yaml-cpp
target_link_libraries(tests PRIVATE gtest gtest_main yaml-cpp)