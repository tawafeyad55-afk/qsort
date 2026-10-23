#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_rec.h"

#define TEST_PTR(fun, text, arg)                                               \
  {                                                                            \
    printf("--- " #fun "\n");                                                  \
    printf("%s\n", text);                                                      \
    const char *p = fun(text, arg);                                            \
    if (p == nullptr) {                                                        \
      printf("*");                                                             \
    } else {                                                                   \
      printf("%*c", (int) (p - text + 1), '^');                                \
    }                                                                          \
    printf("%s\n", #arg);                                                      \
  }

#define TEST_SIZE(fun, text, arg)                                              \
  {                                                                            \
    printf("--- " #fun "\n");                                                  \
    printf("%s\n", text);                                                      \
    for (size_t n = fun(text, arg); n > 0; --n) {                              \
      printf(".");                                                             \
    }                                                                          \
    printf("%s\n", #arg);                                                      \
  }

#define TEXT "https://www.open-std.org/jtc1/sc22/wg14/www/docs/n3096.pdf"

int main() {
  printf("--- Trials on strings utilities\n"
      "--- Utilities prefixed by 'str_' are homemade\n\n");
  TEST_PTR(strchr, TEXT, 'd');
  TEST_PTR(str_chr, TEXT, 'd');
  TEST_PTR(strchr, TEXT, 'a');
  TEST_PTR(str_chr, TEXT, 'a');
  TEST_PTR(strchr, TEXT, '\0');
  TEST_PTR(str_chr, TEXT, '\0');
  TEST_PTR(strpbrk, TEXT, "-.:/");
  TEST_PTR(str_pbrk, TEXT, "-.:/");
  TEST_PTR(strpbrk, TEXT, "0123456789");
  TEST_PTR(str_pbrk, TEXT, "0123456789");
  TEST_PTR(strpbrk, TEXT, "abiklmquvxyz");
  TEST_PTR(str_pbrk, TEXT, "abiklmquvxyz");
  TEST_PTR(strpbrk, TEXT, "f");
  TEST_PTR(str_pbrk, TEXT, "f");
  TEST_PTR(strpbrk, TEXT, "");
  TEST_PTR(str_pbrk, TEXT, "");
  TEST_PTR(strrchr, TEXT, 'd');
  TEST_PTR(str_rchr, TEXT, 'd');
  TEST_PTR(strrchr, TEXT, 'a');
  TEST_PTR(str_rchr, TEXT, 'a');
  TEST_PTR(strrchr, TEXT, '\0');
  TEST_PTR(str_rchr, TEXT, '\0');
  TEST_SIZE(strspn, TEXT, "abcdefghijklmnopqrstuvwxyz");
  TEST_SIZE(str_spn, TEXT, "abcdefghijklmnopqrstuvwxyz");
  TEST_SIZE(strspn, TEXT, "-.:/");
  TEST_SIZE(str_spn, TEXT, "-.:/");
  TEST_SIZE(strspn, TEXT, "-.:/0123469cdefghjnoprstw");
  TEST_SIZE(str_spn, TEXT, "-.:/0123469cdefghjnoprstw");
  TEST_SIZE(strspn, TEXT, "");
  TEST_SIZE(str_spn, TEXT, "");
  return EXIT_SUCCESS;
}
