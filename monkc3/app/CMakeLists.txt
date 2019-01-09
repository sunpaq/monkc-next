aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRC)

add_executable(demo ${SRC})
target_link_libraries(demo monkc-runtime)
