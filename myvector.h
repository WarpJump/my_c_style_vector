#define concatenate(a, b) a##_##b
#define dynamic_array(type) concatenate(DynamicArr, type)

inline void destroy(int *) {}

inline void destroy(long long *) {}
inline void destroy(unsigned long long *) {}
inline void destroy(double *) {}

#define define_dynamic_array(mytype) \
  struct dynamic_array(mytype) {     \
    mytype *arr = nullptr;           \
    size_t size = 0;                 \
    size_t used = 0;                 \
  }

#define define_arr_destructor(type)            \
  void destroy(dynamic_array(type) * vector) { \
    while (vector->used) {                     \
      pop(vector);                             \
    }                                          \
    if (vector->arr != nullptr) {              \
      free(vector->arr);                       \
    }                                          \
    vector->size = 0;                          \
  }

#define define_resize(type)                                                    \
  int resize(dynamic_array(type) * vector, size_t size) {                      \
    if ((vector == nullptr) || (size == 0)) {                                  \
      return 1;                                                                \
    }                                                                          \
    else {                                                                   \
      vector->arr =                                                            \
          reinterpret_cast<type *>(realloc(vector->arr, size * sizeof(type))); \
    }                                                                          \
    vector->size = size;                                                       \
                                                                               \
    return 0;                                                                  \
  }

#define define_push(type)                            \
  int push(dynamic_array(type) * vector, type obj) { \
    if (vector->used < size) {                       \
      (vector->arr)[vector->used] = obj;             \
      ++vector->used;                                \
    }                                                \
  }

#define define_pop(type)                         \
  int pop(dynamic_array(type) * vector) {        \
    if (vector->used > 0) {                      \
      destroy(vector->arr + (vector->used - 1)); \
      --vector->used;                            \
      return 0;                                  \
    }                                            \
    return 1;                                    \
  }

#define define_get(type)                                       \
  type *get_elem(dynamic_array(type) * vector, size_t index) { \
    return (vector->arr + index);                              \
  }

#define define_print(type)                       \
  void print_vec(dynamic_array(type) * vector) { \
    for (int i = 0; i < vector->size; ++i) {     \
      printf("%d ", *(vector->arr + i));         \
    }                                            \
    putchar('\n');                               \
  }

#define define_vector(type)    \
  define_dynamic_array(type);  \
  define_pop(type);            \
  define_arr_destructor(type); \
  define_resize(type);         \
  define_get(type);            \
  define_print(type);
