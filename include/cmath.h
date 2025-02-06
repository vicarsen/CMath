#pragma once

/**
 * Allocates a new vector of a given dimension.
 *
 * @param n The size of the vector to allocate.
 * @return Pointer to the allocated vector.
 */
float *vector_alloc(unsigned int n);

/**
 * Frees a previously allocated vector.
 *
 * @param v The vector to free.
 */
void vector_free(float *v);

/**
 * Copies the elements of a vector to another vector.
 *
 * @param u The vector to copy to.
 * @param v The vector to copy from.
 * @param n The dimension of the vectors.
 */
void vector_copy(float *u, float const *v, unsigned int n);

/**
 * Adds two vectors together.
 *
 * Adds v and w and writes the result in u. There are no restrictions on whether
 * u, v, and w can point to the same vector or not.
 *
 * @param u The vector in which to write the result.
 * @param v The first vector to add.
 * @param w The second vector to add.
 * @param n The dimension of the vectors.
 */
void vector_add(float *u, float const *v, float const *w, unsigned int n);

/**
 * Subtracts one vector from another.
 *
 * Subtracts w from v, and writes the result in u. There are no restrictions on
 * whether u, v, and w can point to the same vector or not.
 *
 * @param u The vector in which to write the result.
 * @param v The LHS of the subtraction.
 * @param w The RHS of the subtraction.
 * @param n The dimension of the vectors.
 */
void vector_sub(float *u, float const *v, float const *w, unsigned int n);

/**
 * Multiples a vector by a scalar.
 *
 * Multiplies v by alpha and writes the result in u. There is no restriction on
 * whether u, and v can point to the same vector or not.
 *
 * @param u The vector in which to write the result.
 * @param alpha The scalar to multiply v by.
 * @param v The vector to multiply by alpha.
 * @param n The dimension of the vectors.
 */
void vector_mul(float *u, float alpha, float const *v, unsigned int n);

/**
 * Calculates the dot product of two vectors.
 *
 * @param u The first vector in the dot product.
 * @param v The second vector in the dot product.
 * @param n The dimension of the vectors.
 * @return The dot prduct of u and v.
 */
float vector_dot(float const *u, float const *v, unsigned int n);

/**
 * Allocates a new matrix.
 *
 * @param m The number of lines of the matrix.
 * @param n The number of columns of the matrix.
 * @return Pointer to the allocated matrix.
 */
float *matrix_alloc(unsigned int m, unsigned int n);

/**
 * Frees a previously allocated matrix.
 *
 * @param a The matrix to free.
 */
void matrix_free(float *a);

/**
 * Copies the elements of a matrix to another matrix.
 *
 * @param b The matrix to copy into.
 * @param a The matrix to copy from.
 * @param m The number of lines of the matrices.
 * @param n The number of columns of the matrices.
 */
void matrix_copy(float *b, float const *a, unsigned int m, unsigned int n);

/**
 * Adds two matrices together.
 *
 * Adds a to b and writes the result in c. There are no restrictions on whether
 * or not a, b, and c can point to the same matrices.
 *
 * @param c The matrix in which to write the result.
 * @param a The first matrix to add.
 * @param b The second matrix to add.
 * @param m The number of lines of the matrices.
 * @param n The number of columns of the matrices.
 */
void matrix_add(float *c, float const *a, float const *b, unsigned int m,
                unsigned int n);

/**
 * Subtracts two matrices.
 *
 * Subtracts b from a and writes the result in c. There are no restrictions on
 * whether or not a, b, and c can point to the same matrices.
 *
 * @param c The matrix in which to write the result.
 * @param a The matrix to subtract from.
 * @param b The matrix to subtract.
 * @param m The number of lines of the matrices.
 * @param n The number of columns of the matrices.
 */
void matrix_sub(float *c, float const *a, float const *b, unsigned int m,
                unsigned int n);

/**
 * Multiples a matrix by a scalar.
 *
 * Multiples a by alpha and writes the result in b. There is no restriction on
 * whether or not a, and b can point to the same matrix.
 *
 * @param b The matrix in which to write the result.
 * @param alpha The scalar to multiply a by.
 * @param a The matrix to multiply by alpha.
 * @param m The number of lines of the matrices.
 * @param n The number of columns of the matrices.
 */
void matrix_mul(float *b, float alpha, float const *a, unsigned int m,
                unsigned int n);

/**
 * Transposes a matrix.
 *
 * Writes in b the transpose of a. a must be a matrix of m lines and n columns,
 * and b must be a matrix of n lines and m columns. a and b must not point to
 * the same matrix (undefined behaviour).
 *
 * @param b The matrix in which to write the result.
 * @param a The matrix to transpose.
 * @param m The number of lines of a/The number of columns of b.
 * @param n The number of columns of a/The number of lines of b.
 */
void matrix_transpose(float *b, float const *a, unsigned int m, unsigned int n);

/**
 * Multiplies two matrices together.
 *
 * Multiplies a and b in this order and writes the result in c. a must have m
 * lines and n columns, b must have n lines and p columns, and c must have m
 * lines and p columns. c must not point to the same matrix as either a, or b.
 *
 * @param c The matrix in which to write the result.
 * @param a The LHS of the multiplication.
 * @param b The RHS of the multiplication.
 * @param m The number of lines of a, and c.
 * @param n The number of columns of a/The number of lines of b.
 * @param p The number of columns of b, and c.
 */
void matrix_mat_mul(float *c, float const *a, float const *b, unsigned int m,
                    unsigned int n, unsigned int p);
