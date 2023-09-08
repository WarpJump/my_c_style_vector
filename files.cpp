#include <stdio.h>
#include <stdlib.h>

#define dynamic_array(type) cucumber_##type

#define define_dynamic_array(mytype) \
  struct cucumber_##mytype {         \
    using type = mytype;             \
    type* arr = nullptr;             \
    long long size = 0;              \
  }

#define define_destroy(type)              \
  void destroy(cucumber_##type* vector) { \
    if (vector->arr != nullptr) {         \
      free(vector->arr);                  \
    }                                     \
    vector->size = 0;                     \
  }

#define define_resize(type)                                                   \
  int resize(cucumber_##type* vector, size_t size) {                          \
    if ((vector == nullptr) || (size == 0)) {                                 \
      return 1;                                                               \
    }                                                                         \
    if (vector->arr == nullptr) {                                             \
      vector->arr = reinterpret_cast<type*>(calloc(size, sizeof(type)));      \
    } else {                                                                  \
      vector->arr =                                                           \
          reinterpret_cast<type*>(realloc(vector->arr, size * sizeof(type))); \
    }                                                                         \
    vector->size = size;                                                      \
                                                                              \
    return 0;                                                                 \
  }

#define define_vector(type)   \
  define_dynamic_array(type); \
  define_destroy(type);       \
  define_resize(type);

define_vector(int);

int main() {
  dynamic_array(int) a;
  printf("%d", a.size);
  resize(&a, 10);
  printf("%d", a.size);

  destroy(&a);
}