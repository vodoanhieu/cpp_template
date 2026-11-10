cmake_minimum_required(VERSION 3.16)
project(CppTemplateRepo VERSION 1.0.0 LANGUAGES CXX)

# Ep dung C++17 chuan ISO, tat cac extension rieng cua trinh bien dich
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Khai bao thu vien my_lib
add_library(my_lib src/math_utils.cpp)
target_include_directories(my_lib PUBLIC include)

# Chuong trinh chinh
add_executable(main_app src/main.cpp)
target_link_libraries(main_app PRIVATE my_lib)

# Chuong trinh kiem thu tu dong
enable_testing()
add_executable(unit_tests tests/test_math.cpp)
target_link_libraries(unit_tests PRIVATE my_lib)
add_test(NAME MathTest COMMAND unit_tests)

# Dong bo co canh bao nghiem ngat cho tat ca cac target (MSVC va GCC/Clang)
if(MSVC)
    target_compile_options(my_lib PRIVATE /W4 /WX)
    target_compile_options(main_app PRIVATE /W4 /WX)
    target_compile_options(unit_tests PRIVATE /W4 /WX)
else()
    target_compile_options(my_lib PRIVATE -Wall -Wextra -Wpedantic -Werror)
    target_compile_options(main_app PRIVATE -Wall -Wextra -Wpedantic -Werror)
    target_compile_options(unit_tests PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()

# Tich hop cong cu format va thong bao neu thieu clang-format
find_program(CLANG_FORMAT_BIN clang-format)
if(CLANG_FORMAT_BIN)
    add_custom_target(format
        COMMAND ${CLANG_FORMAT_BIN} -i 
            ${CMAKE_SOURCE_DIR}/include/my_lib/math_utils.hpp
            ${CMAKE_SOURCE_DIR}/src/math_utils.cpp
            ${CMAKE_SOURCE_DIR}/src/main.cpp
            ${CMAKE_SOURCE_DIR}/tests/test_math.cpp
        COMMENT "Auto formatting source files with clang-format"
    )
    add_custom_target(format-check
        COMMAND ${CLANG_FORMAT_BIN} --dry-run --Werror
            ${CMAKE_SOURCE_DIR}/include/my_lib/math_utils.hpp
            ${CMAKE_SOURCE_DIR}/src/math_utils.cpp
            ${CMAKE_SOURCE_DIR}/src/main.cpp
            ${CMAKE_SOURCE_DIR}/tests/test_math.cpp
        COMMENT "Checking code format without modifying files"
    )
else()
    message(WARNING
        "clang-format was not found. "
        "Targets 'format' and 'format-check' will be unavailable."
    )
endif()