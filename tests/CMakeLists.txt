
add_executable(vectortest vector.c)
target_link_libraries(vectortest PUBLIC cmath)
add_test(NAME testvectortest COMMAND vectortest)

