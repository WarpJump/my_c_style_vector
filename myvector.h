#define concatenate(a, b) a##_##b
#define dynamic_array(type) concatenate(DynamicArr, type)

#define define_dynamic_array(mytype) \
    struct dynamic_array(mytype)       \
    {                                \
        mytype *arr = nullptr;       \
        long long size = 0;          \
        long long used = 0;          \
    }

#define define_destroy(type)                \
    void destroy(dynamic_array(type) *vector) \
    {                                       \
        if (vector->arr != nullptr)         \
        {                                   \
            free(vector->arr);              \
        }                                   \
        vector->size = 0;                   \
    }

#define define_resize(type)                                                          \
    int resize(dynamic_array(type) *vector, size_t size)                               \
    {                                                                                \
        if ((vector == nullptr) || (size == 0))                                      \
        {                                                                            \
            return 1;                                                                \
        }                                                                            \
        if (vector->arr == nullptr)                                                  \
        {                                                                            \
            vector->arr = reinterpret_cast<type *>(calloc(size, sizeof(type)));      \
        }                                                                            \
        else                                                                         \
        {                                                                            \
            vector->arr =                                                            \
                reinterpret_cast<type *>(realloc(vector->arr, size * sizeof(type))); \
        }                                                                            \
        vector->size = size;                                                         \
                                                                                     \
        return 0;                                                                    \
    }

#define define_push(type)                         \
    int push(dynamic_array(type) *vector, type obj) \
    {                                             \
        if (used < size)                          \
        {                                         \
            (vector->arr)[used] = obj;            \
            ++used;                               \
        }                                         \
    }

#define define_pop(type)                         \
    int pop(dynamic_array(type) *vector, type obj) \
    {                                            \
        if (used >)                              \
        {                                        \
            (vector->arr)[used] = obj;           \
            ++used;                              \
        }                                        \
    }

#define define_vector(type)     \
    define_dynamic_array(type); \
    define_destroy(type);       \
    define_resize(type);
