cmake_minimum_required(VERSION 3.17)
project(sort C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")

add_executable(sort main.c paixu.c bubbleSort.c BubbleSortDemo.c selectSort.c common.h commonFun.c commonHead.h insertion_sort.c Shell_Sort.c quickSort.c)