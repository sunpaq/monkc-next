aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRC)

add_library(monkc-stdlib ${SRC})
target_include_directories(monkc-stdlib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(monkc-stdlib monkc-runtime)
