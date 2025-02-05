
add_executable(vectortest vector.c)
target_link_libraries(vectortest PUBLIC cmath)
add_test(NAME testvectortest COMMAND vectortest)

add_executable(matrixtest matrix.c)
target_link_libraries(matrixtest PUBLIC cmath)
add_test(NAME testmatrixtest COMMAND matrixtest)

