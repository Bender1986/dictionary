cmake_minimum_required(VERSION 3.16.3)

project("ServerApp" VERSION 1.0.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")


set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)


add_executable(DictionaryApp main.cpp               
                ${MY_INCLUDE_DIR}/dictionary.h dictionary.cpp       
               
               )

target_include_directories(DictionaryApp PUBLIC ${MY_INCLUDE_DIR})