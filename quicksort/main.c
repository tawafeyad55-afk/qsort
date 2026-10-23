#include <stdio.h>
#include <stdlib.h>

#define STR(s)  #s
#define XSTR(s) STR(s)

#if defined QSORT

#define SORT        qsort
#define SORT_LABEL  "GCC " XSTR(SORT)

#else

#define SORT        quicksort
#define SORT_LABEL  "a homemade " XSTR(SORT)

#include "quicksort.h"

#endif

#define LENGTH  25

//  int_compar : renvoie une valeur strictement négative, nulle ou strictement
//    positive selon que l'objet pointé par p1 est strictement inférieur, égal
//    ou strictement supérieur à celui pointé par p2.
int int_compar(const int *p1, const int *p2);

//  stop : affiche sur la sortie standard une invite de commande. Lit ensuite
//    des caractères sur l'entrée standard jusqu'à détecter la fin de l'entrée
//    ou obtenir 'q', 'Q' ou '\n'. Renvoie zéro si '\n' est obtenu. Provoque
//    sinon la terminaison normale du programme en signifiant à l’environnement
//    d’exécution un succès.
int stop();

int main() {
  srand(0);
  printf(
      "--- Trials on " SORT_LABEL "\n"
      "--- Type ctrl+d or enter 'q' or 'Q' to exit\n\n");
  do {
    int a[LENGTH];
    for (size_t k = 0; k < LENGTH; ++k) {
      a[k] = rand() % 100;
    }
    for (size_t k = 0; k < LENGTH; ++k) {
      printf("%3d", a[k]);
    }
    printf("\n");
    SORT(a, LENGTH, sizeof *a,
        (int (*)(const void *, const void *)) int_compar);
    for (size_t k = 0; k < LENGTH; ++k) {
      printf("%3d", a[k]);
    }
    printf("\n");
  } while (!stop());
}

int int_compar(const int *p1, const int *p2) {
  return (*p1 > *p2) - (*p1 < *p2);
}

#define PROMPT "> "

int stop() {
  printf(PROMPT);
  while (1) {
    int c = getchar();
    if (c == EOF || c == 'q' || c == 'Q') {
      printf("\n");
      exit(EXIT_SUCCESS);
    }
    if (c == '\n') {
      return 0;
    }
  }
}
