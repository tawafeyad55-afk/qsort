//  Quick Sort. Module implantant la partition autour d'un pivot et le tri
//    rapide.

//  AUCUNE MODIFICATION DE CE SOURCE N'EST AUTORISÉE.

#define __CH_VERSION_QUICKSORT_H__ 202609L

#ifndef QUICKSORT__H
#define QUICKSORT__H

#include <stddef.h>

//  partition_pivot : partitionne un tableau autour d'un pivot selon une
//    fonction de comparaison. Même sémantique des paramètres que pour la
//    fonction qsort déclarée dans l'en-tête <stdlib.h>. Le pivot est un
//    composant du tableau mais son choix n'est pas précisé dans cette
//    spécification. Renvoie un pointeur nul si le valeur de nmemb est nulle,
//    l'adresse finale du pivot sinon.
extern void *partition_pivot(void *base, size_t nmemb, size_t size,
    int (*compar)(const void *, const void *));

//  quicksort : même spécification que la fonction qsort déclarée dans l'en-tête
//    <stdlib.h> de la bibliothèque standard.
extern void quicksort(void *base, size_t nmemb, size_t size,
    int (*compar)(const void *, const void *));

#endif
