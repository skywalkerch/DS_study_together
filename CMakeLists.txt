cmake_minimum_required(VERSION 3.24)
project(DS)
set(CMAKE_CXX_STANDARD 11)
set(MAIN src/start.cpp)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(LIBRARY_OUTPUT_PATH build)

set(HEADERS
        include/LinearList_H/LinkList.h
        include/LinearList_H/SquentialList.h
        include/Stack_H/LinkStack.h
        include/Stack_H/SqStack.h
        include/macro.h
        include/Queue_H/SqQueue.h
        include/Queue_H/LinkQueue.h
        include/SString_H/SString.h include/Tree_H/SqBinaryTree.h include/Tree_H/LinkBinaryTree.h)
include_directories(
        include
        include/LinearList_H
        include/Queue_H
        include/Stack_H
        include/SString_H
)
add_executable(DS ${MAIN} ${HEADERS})
