project(talib_test)
cmake_minimum_required(VERSION 2.8)
add_definitions(-std=c++11)

include_directories(/home/zhuzhenping/ta-lib/include)

link_directories(/usr/lib)
 
SET(STRATEGY_SOURCE_FILE talib_test.cpp)
 
add_executable(${PROJECT_NAME} ${STRATEGY_SOURCE_FILE})

# link static library, notice the link sequence
target_link_libraries(${PROJECT_NAME}
                        libta_lib.so)
