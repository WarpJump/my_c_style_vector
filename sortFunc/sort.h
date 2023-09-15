#include "colors.h"

#define define_sort(type)                                                      \
  void swap(type* first, type* second) {                                       \
    type temp = *second;                                                       \
    *second = *first;                                                          \
    *first = temp;                                                             \
  }                                                                            \
  size_t base_sort(type* begin, type* end, int (*comparator)(type*, type*)) {  \
    --end;                                                                     \
    switch (end - begin) {                                                     \
      case 2:                                                                  \
        printf("%d %d %d \n", begin[0], begin[1], begin[2]);                   \
        if ((*comparator)(begin, end) > 0) {                                   \
          swap(begin, end);                                                    \
        }                                                                      \
        if ((*comparator)(begin + 1, end) > 0) {                               \
          swap(begin + 1, end);                                                \
        }                                                                      \
        if ((*comparator)(begin, end - 1) > 0) {                               \
          swap(begin, end - 1);                                                \
        }                                                                      \
        break;                                                                 \
      case 1:                                                                  \
        printf("%d %d\n", *begin, *end);                                       \
        if ((*comparator)(begin, end) > 0) {                                   \
          swap(begin, end);                                                    \
        }                                                                      \
        break;                                                                 \
      default:                                                                 \
        return 1;                                                              \
    }                                                                          \
    return 0;                                                                  \
  }                                                                            \
                                                                               \
  type* Partition(type* begin, type* end, int (*comparator)(type*, type*)) {   \
    --end;                                                                     \
    type* pivot_ptr = (begin + (end - begin) / 2);                             \
    type elem = *pivot_ptr;                                                    \
    for (type* runner = beginning; runner < ending; ++runner) {                \
      if (runner == pivot_ptr) {                                               \
        printf("%s%d%s ", "\033[0;31m", *runner, "\033[0m");                   \
        continue;                                                              \
      }                                                                        \
      if (begin <= runner && runner <= end) {                                  \
        printf("%s%d%s ", "\033[93m", *runner, "\033[0m");                     \
      } else {                                                                 \
        printf("%d ", *runner);                                                \
      }                                                                        \
    }                                                                          \
    putchar('\n');                                                             \
                                                                               \
    --begin;                                                                   \
    ++end;                                                                     \
    while (true) {                                                             \
      do {                                                                     \
        ++begin;                                                               \
      } while ((*comparator)(begin, &elem) < 0);                               \
      do {                                                                     \
        --end;                                                                 \
      } while ((*comparator)(end, &elem) > 0);                                 \
                                                                               \
      if (begin >= end) {                                                      \
        return end;                                                            \
      }                                                                        \
      swap(begin, end);                                                        \
    }                                                                          \
    for (type* runner = beginning; runner < ending; ++runner) {                \
      printf("%d ", *runner);                                                  \
    }                                                                          \
    putchar('\n');                                                             \
    return end;                                                                \
  }                                                                            \
                                                                               \
  size_t quick_sort(type* begin, type* end, int (*comparator)(type*, type*)) { \
    if (begin < end - 1) {                                                     \
      type* pivot = Partition(begin, end, comparator);                         \
      quick_sort(pivot + 1, end, comparator);                                  \
      quick_sort(begin, pivot + 1, comparator);                                    \
    }                                                                          \
    return 0;                                                                  \
  }
