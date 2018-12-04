aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRC)

add_library(monkc-runtime ${SRC})
target_include_directories(monkc-runtime PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})