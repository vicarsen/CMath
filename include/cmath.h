#pragma once

float *vector_alloc(unsigned int n);
void vector_free(float *v);

void vector_copy(float *u, float const *v, unsigned int n);
void vector_add(float *u, float const *v, float const *w, unsigned int n);
void vector_sub(float *u, float const *v, float const *w, unsigned int n);
void vector_mul(float *u, float alpha, float const *v, unsigned int n);
void vector_div(float *u, float const *v, float alpha, unsigned int n);
float vector_dot(float const *u, float const *v, unsigned int n);

float *matrix_alloc(unsigned int m, unsigned int n);
void matrix_free(float *a);

void matrix_copy(float *b, float const *a, unsigned int m, unsigned int n);
void matrix_add(float *c, float const *a, float const *b, unsigned int m, unsigned int n);
void matrix_sub(float *c, float const *a, float const *b, unsigned int m, unsigned int n);
void matrix_mul(float *b, float alpha, float const *a, unsigned int m, unsigned int n);
void matrix_div(float *b, float const *a, float alpha, unsigned int m, unsigned int n);
void matrix_transpose(float *b, float const *a, unsigned int m, unsigned int n);
void matrix_mat_mul(float *c, float const *a, float const *b, unsigned int m, unsigned int n, unsigned int p);

