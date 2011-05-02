cmake_minimum_required(VERSION 2.6)

project(csvlinegraph)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake/Modules")

find_package(Qt4 COMPONENTS QtCore QtGui QtSql Qt3Support REQUIRED)
find_package(Qwt)

include(${QT_USE_FILE})

set(CSV_LINE_GRAPH_HDRS
	csvreader.h
	linegraph.h)

set(CSV_LINE_GRAPH_SRCS
	csvreader.cpp
	linegraph.cpp
	main.cpp)

set(PERFTRACK_GUI_UI)

QT4_WRAP_UI(csvlinegraph_gui_ui ${CSV_LINE_GRAPH_GUI_UI})
QT4_AUTOMOC(${CSV_LINE_GRAPH_GUI_SRCS})

include_directories(${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR} ${Qwt5_INCLUDE_DIR})

add_executable(csvlinegraph ${CSV_LINE_GRAPH_SRCS} ${qwt_test_gui_ui})
target_link_libraries(csvlinegraph ${QT_LIBRARIES} ${Qwt5-Qt4_LIBRARY})

