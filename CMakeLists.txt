cmake_minimum_required(VERSION 3.20)
project(doublelinkedlist)

set(CMAKE_CXX_STANDARD 14)

add_executable(doublelinkedlist main.cpp Monitor.cpp Monitor.h Node.h LinkedList.cpp LinkedList.h Control.cpp Control.h)
