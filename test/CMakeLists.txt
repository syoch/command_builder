add_executable(read read.cpp)
target_link_libraries(read builder)
add_test(NAME read COMMAND read)

add_executable(read_data read_data.cpp)
target_link_libraries(read_data builder)
add_test(NAME read_data COMMAND read_data)

add_executable(read_kern read_kern.cpp)
target_link_libraries(read_kern builder)
add_test(NAME read_kern COMMAND read_kern)

add_executable(write write.cpp)
target_link_libraries(write builder)
add_test(NAME write COMMAND write)

add_executable(write16 write16.cpp)
target_link_libraries(write16 builder)
add_test(NAME write16 COMMAND write16)

add_executable(write32 write32.cpp)
target_link_libraries(write32 builder)
add_test(NAME write32 COMMAND write32)

add_executable(write8 write8.cpp)
target_link_libraries(write8 builder)
add_test(NAME write8 COMMAND write8)

add_executable(write_kern write_kern.cpp)
target_link_libraries(write_kern builder)
add_test(NAME write_kern COMMAND write_kern)

add_executable(execute_assembly execute_assembly.cpp)
target_link_libraries(execute_assembly builder)
add_test(NAME execute_assembly COMMAND execute_assembly)
