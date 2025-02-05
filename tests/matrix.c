#include <assert.h>
#include <cmath.h>

void test_add() {
  unsigned int m = 8, n = 8;
  float *a = matrix_alloc(m, n);
  float *b = matrix_alloc(m, n);
  float *c = matrix_alloc(m, n);

  for (unsigned int i = 0; i < m * n; i++) {
    a[i] = i;
    b[i] = m * n - i;
  }

  matrix_add(c, a, b, m, n);

  for (unsigned int i = 0; i < m * n; i++) {
    assert(c[i] == m * n && "Matrix add failed!");
  }

  matrix_add(a, a, b, m, n);

  for (unsigned int i = 0; i < m * n; i++) {
    assert(a[i] == m * n && "Matrix add failed!");
  }

  matrix_sub(a, a, b, m, n);

  for (unsigned int i = 0; i < m * n; i++) {
    assert(a[i] == i && "Matrix sub failed!");
  }

  matrix_sub(c, a, b, n, m);

  for (unsigned int i = 0; i < m * n; i++) {
    assert(c[i] == 2.0f * i - m * n && "Matrix sub failed!");
  }

  matrix_free(a);
  matrix_free(b);
  matrix_free(c);
}

void test_mul() {
  unsigned int m = 8, n = 8;
  float *a = matrix_alloc(m, n);

  for (unsigned int i = 0; i < m * n; i++) {
    a[i] = i;
  }

  matrix_mul(a, 3, a, m, n);

  for (unsigned int i = 0; i < m * n; i++) {
    assert(a[i] == 3 * i && "Matrix mul failed!");
  }

  matrix_div(a, a, 3, m, n);

  for (unsigned int i = 0; i < m * n; i++) {
    assert(a[i] == i && "Matrix div failed!");
  }

  matrix_free(a);
}

void test_transpose() {
  unsigned int m = 8, n = 16;
  float *a = matrix_alloc(m, n);
  float *b = matrix_alloc(n, m);

  for (unsigned int i = 0; i < m * n; i++) {
    a[i] = i;
  }

  matrix_transpose(b, a, m, n);

  for (unsigned int i = 0; i < n; i++) {
    for (unsigned int j = 0; j < m; j++) {
      assert(b[i * m + j] == a[j * n + i] && "Matrix transpose failed!");
    }
  }

  matrix_free(a);
  matrix_free(b);
}

void test_mat_mul() {
  unsigned int m = 16, n = 8, p = 16;
  float *a = matrix_alloc(m, n);
  float *b = matrix_alloc(n, p);
  float *c = matrix_alloc(m, p);

  for (unsigned int i = 0; i < m; i++) {
    for (unsigned int j = 0; j < n; j++) {
      if (i == j) {
        a[i * n + j] = i;
      } else {
        a[i * n + j] = 0.0f;
      }
    }
  }

  for (unsigned int i = 0; i < n; i++) {
    for (unsigned int j = 0; j < p; j++) {
      b[i * p + j] = i + j;
    }
  }

  matrix_mat_mul(c, a, b, m, n, p);

  for (unsigned int i = 0; i < m; i++) {
    for (unsigned int j = 0; j < p; j++) {
      if (i < n) {
        assert(c[i * p + j] == i * (i + j) && "Matrix mat mul failed!");
      } else {
        assert(c[i * p + j] == 0 && "Matrix mat mul failed!");
      }
    }
  }

  matrix_free(a);
  matrix_free(b);
  matrix_free(c);
}

int main() {
  test_add();
  test_mul();
  test_transpose();
  test_mat_mul();
  return 0;
}
