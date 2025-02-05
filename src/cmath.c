#include "cmath.h"

#include <immintrin.h>
#include <string.h>

float *vector_alloc(unsigned int n)
{
  return _mm_malloc(n * sizeof(float), 32);
}

void vector_free(float *v)
{
  _mm_free(v);
}

void vector_copy(float *u, float const *v, unsigned int n)
{
  memcpy(u, v, n * sizeof(float));
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

  __m256 malpha = _mm256_set1_ps(alpha);

  unsigned int steps = n / 8;
  for (unsigned int i = 0; i < steps; i++) {
    mu[i] = _mm256_mul_ps(malpha, mv[i]);
  }
}

void vector_div(float *u, float const *v, float alpha, unsigned int n)
{
  __m256 *mu = (__m256 *)u;
  __m256 const *mv = (__m256 const *)v;

  __m256 malpha = _mm256_set1_ps(alpha);

  unsigned int steps = n / 8;
  for (unsigned int i = 0; i < steps; i++) {
    mu[i] = _mm256_div_ps(mv[i], malpha);
  }
}

float vector_dot(float const *u, float const *v, unsigned int n)
{
  __m256 const *mu = (__m256 const *)u;
  __m256 const *mv = (__m256 const *)v;

  __m256 mr = _mm256_mul_ps(mu[0], mv[0]);

  unsigned int steps = n / 8;
  for (unsigned int i = 1; i < steps; i++) {
    __m256 mp = _mm256_mul_ps(mu[i], mv[i]);
    mr = _mm256_add_ps(mr, mp);
  }

  float *r = (float *)&mr;
  return r[0] + r[1] + r[2] + r[3] +
         r[4] + r[5] + r[6] + r[7];
}

float *matrix_alloc(unsigned int m, unsigned int n)
{
  return _mm_malloc(m * n * sizeof(float), 32);
}

void matrix_free(float *a)
{
  _mm_free(a);
}

void matrix_copy(float *b, float const *a, unsigned int m, unsigned int n)
{
  memcpy(b, a, m * n * sizeof(float));
}

void matrix_add(float *c, float const *a, float const *b, unsigned int m, unsigned int n)
{
  vector_add(c, a, b, m * n);
}

void matrix_sub(float *c, float const *a, float const *b, unsigned int m, unsigned int n)
{
  vector_sub(c, a, b, m * n);
}

void matrix_mul(float *b, float alpha, float const *a, unsigned int m, unsigned int n)
{
  vector_mul(b, alpha, a, m * n);
}

void matrix_div(float *b, float const *a, float alpha, unsigned int m, unsigned int n)
{
  vector_div(b, a, alpha, m * n);
}

void matrix_transpose(float *b, float const *a, unsigned int m, unsigned int n)
{
  for (unsigned int i = 0; i < m; i++) {
    for (unsigned int j = 0; j < n; j++) {
      b[j * m + i] = a[i * n + j];
    }
  }
}

void matrix_mat_mul(float *c, float const *a, float const *b, unsigned int m, unsigned int n, unsigned int p)
{
  float *bt = matrix_alloc(p, n);
  float *ans = matrix_alloc(m, p);
  
  matrix_transpose(bt, b, n, p);
  for (unsigned int i = 0; i < m; i++) {
    for (unsigned int j = 0; j < p; j++) {
      ans[i * p + j] = vector_dot(a + i * n, bt + j * n, n);
    }
  }

  matrix_copy(c, ans, m, p);

  matrix_free(ans);
  matrix_free(bt);
}

