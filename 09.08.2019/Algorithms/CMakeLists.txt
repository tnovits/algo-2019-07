cmake_minimum_required(VERSION 3.12)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#project(Algorithms)
#add_executable(${PROJECT_NAME} "main.c")

project(Algorithms)
add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE
    main.cpp
    Euclidean/euclidean.cpp
    Euclidean/euclidean.h
    Exponentiation/exponentiation.cpp
    Exponentiation/exponentiation.h
    PrimeCount/PrimeCount.cpp
    PrimeCount/PrimeCount.h
    Fibonacci/Fibonacci.cpp
    Fibonacci/Fibonacci.h
    )



