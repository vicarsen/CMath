#pragma once

float *vector_alloc(unsigned int n);
void vector_free(float *v);

void vector_add(float *u, float const *v, float const *w, unsigned int n);
void vector_sub(float *u, float const *v, float const *w, unsigned int n);
void vector_mul(float *u, float alpha, float const *v, unsigned int n);
void vector_div(float *u, float const *v, float alpha, unsigned int n);

