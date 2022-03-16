add_executable(testexe test.cpp)
target_link_libraries(testexe builder)

add_test(NAME run_test COMMAND testexe)