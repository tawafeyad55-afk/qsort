#include "quicksort.h"

#if __CH_VERSION_QUICKSORT_H__ != 202609L
#error "Bad 'quicksort' version."
#endif

void mem_swap(void *s1, void *s2, size_t n) {
  unsigned char *p1 = (unsigned char *) s1;
  unsigned char *p2 = (unsigned char *) s2;
  for (size_t k = 0 ; k < n ; k++) {
    unsigned char tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
    p1++;
    p2++;
  }
}

void *partition_pivot(void *base, size_t nmemb, size_t size,
    int (*compar)(const void *, const void *)) {
  if (nmemb == 0) {
    return nullptr;
  }
  if (size == 0) {
    return nullptr;
  }
  size_t p = 0;
  size_t q = 0;
  char *t = (char *) base;
  char *pivot_par = (char *) base + (nmemb - 1) * size;
  while (q < nmemb - 1) {
    if (compar(t + q * size, pivot_par) < 0) {
      mem_swap(t + p * size, t + q * size, size);
      p++;
    }
    q++;
  }
  mem_swap(t + p * size, pivot_par, size);
  return t + p * size;
}

//void quicksort_partiel(void *base, size_t j, size_t k, size_t size, int
//(*compar)(const void *, const void *)) {
//char *t = (char *) base;
//while (j < k) {
//void *pivot = partition_pivot(t + j * size, k - j + 1, size, compar);
//size_t p = (size_t) ((char *) pivot - t) / size;
//if (p - j < k - p) {
//quicksort_partiel(base, j, p - 1, size, compar);
//j = p + 1;
//} else {
//quicksort_partiel(base, p + 1, k, size, compar);
//k = p - 1;
//}
//}
//}

//void quicksort(void *base, size_t nmemb, size_t size,
//int (*compar)(const void *, const void *)){
//if (nmemb < 2 || size == 0)
//return;

//quicksort_partiel(base, 0, nmemb - 1, size, compar);
//}

void quicksort(void *base, size_t nmemb, size_t size,
    int (*compar)(const void *, const void *)) {
  char *debut = base;
  char *fin = debut + (nmemb * size);
  while ((size_t) (fin - debut) > size) {
    char *p = partition_pivot(debut, (size_t) (fin - debut) / size, size,
          compar);
    if ((p - debut) < (fin - (p + size))) {
      quicksort(debut, (size_t) (p - debut) / size, size, compar);
      debut = p + size;
    } else {
      quicksort(p + size, (size_t) (fin - (p + size)) / size, size, compar);
      fin = p;
    }
  }
}

