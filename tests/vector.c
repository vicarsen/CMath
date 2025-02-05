#include <assert.h>
#include <cmath.h>

int main(void) {
  unsigned int n = 32;
  float *u = vector_alloc(n);
  float *v = vector_alloc(n);
  float *w = vector_alloc(n);

  for (unsigned int i = 0; i < n; i++) {
    v[i] = i;
    w[i] = n - i;
  }

  vector_add(u, v, w, n);

  for (unsigned int i = 0; i < n; i++) {
    assert(u[i] == n && "Vector add failed!");
  }

  vector_sub(w, u, w, n);

  for (unsigned int i = 0; i < n; i++) {
    assert(w[i] == v[i] && "Vector sub failed!");
  }

  vector_mul(v, 3, v, n);

  for (unsigned int i = 0; i < n; i++) {
    assert(v[i] == 3 * i && "Vector mul failed!");
  }

  vector_div(v, v, 3, n);

  for (unsigned int i = 0; i < n; i++) {
    assert(v[i] == i && "Vector div failed!");
  }

  float product = vector_dot(v, v, n);
  assert(product == (n - 1) * n * (2 * n - 1) / 6.0 &&
         "Vector dot product failed!");

  vector_free(u);
  vector_free(v);
  vector_free(w);

  return 0;
}
