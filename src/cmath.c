#include "cmath.h"

#include <immintrin.h>

float *vector_alloc(unsigned int n)
{
  return _mm_malloc(n * sizeof(float), 32);
}

void vector_free(float *v)
{
  _mm_free(v);
}

void vector_add(float *u, float const *v, float const *w, unsigned int n)
{
  __m256 *mu = (__m256 *)u;
  __m256 const *mv = (__m256 const *)v;
  __m256 const *mw = (__m256 const *)w;

  unsigned int steps = n / 8;
  for (unsigned int i = 0; i < steps; i++) {
    mu[i] = _mm256_add_ps(mv[i], mw[i]);
  }
}

void vector_sub(float *u, float const *v, float const *w, unsigned int n)
{
  __m256 *mu = (__m256 *)u;
  __m256 const *mv = (__m256 const *)v;
  __m256 const *mw = (__m256 const *)w;

  unsigned int steps = n / 8;
  for (unsigned int i = 0; i < steps; i++) {
    mu[i] = _mm256_sub_ps(mv[i], mw[i]);
  }
}

void vector_mul(float *u, float alpha, float const *v, unsigned int n)
{
  __m256 *mu = (__m256 *)u;
  __m256 const *mv = (__m256 const *)v;

  __m256 malpha = _mm256_set_ps(alpha, alpha, alpha, alpha, alpha, alpha, alpha, alpha);

  unsigned int steps = n / 8;
  for (unsigned int i = 0; i < steps; i++) {
    mu[i] = _mm256_mul_ps(malpha, mv[i]);
  }
}

void vector_div(float *u, float const *v, float alpha, unsigned int n)
{
  __m256 *mu = (__m256 *)u;
  __m256 const *mv = (__m256 const *)v;

  __m256 malpha = _mm256_set_ps(alpha, alpha, alpha, alpha, alpha, alpha, alpha, alpha);

  unsigned int steps = n / 8;
  for (unsigned int i = 0; i < steps; i++) {
    mu[i] = _mm256_div_ps(mv[i], malpha);
  }
}

