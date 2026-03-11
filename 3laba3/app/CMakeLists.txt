cmake_minimum_required(VERSION 3.15)
set(PROJECT_NAME 3laba3)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDART 20)

add_executable("${PROJECT_NAME}" main.cpp product.cpp product.hpp)
# Создаем библиотеку
add_library(my_lib STATIC src/my_lib.cpp)

# Указываем пути к заголовочным файлам
target_include_directories(my_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)


# Линкуем библиотеку к исполняемому файлу
target_link_libraries("${PROJECT_NAME}" my_lib)

# Добавляем путь к заголовкам для исполняемого файла
target_include_directories("${PROJECT_NAME}" PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})