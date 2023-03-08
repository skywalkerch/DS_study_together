cmake_minimum_required(VERSION 3.24)
project(DS)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(LIBRARY_OUTPUT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/build")


include(FetchContent)
FetchContent_Declare(
   googletest
   GIT_REPOSITORY https://github.com/google/googletest
   GIT_TAG  release-1.12.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()
set(MAIN src/start.cpp)
set(HEADERS
        include/LinearList_H/LinkList.h
        include/LinearList_H/SquentialList.h
        include/Stack_H/LinkStack.h
        include/Stack_H/SqStack.h
        include/macro.h
        include/Queue_H/SqQueue.h
        include/Queue_H/LinkQueue.h
        include/SString_H/SString.h
        include/Tree_H/SqBinaryTree.h
        include/Tree_H/LinkBinaryTree.h)
add_executable(DS ${MAIN} ${HEADERS})
set(TEST_H "test/test.cpp")
set(GTEST_LIB gtest gtest_main)
add_executable(DS_TEST ${TEST_H})
target_link_libraries(DS_TEST gtest gtest_main)
add_test(NAME DS_TEST COMMAND DS_TEST)
