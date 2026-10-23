#include "string_rec.h"

#if __CH_VERSION_STRING_REC_H__ != 202609L
#error "Bad 'string_rec' version."
#endif

char *str_chr(const char *s, int c){

  if(*s == c){
    return (char*)s;
  }
  if(*s == '\0'){
    return (char *)'\0';//je peux faire NULL ici a la palce de (char *)'\0'
  }
  return str_chr((const char*)++s, c);
}

char *str_pbrk(const char *s1, const char *s2){
  if(*s1 == '\0'){
    return nullptr;
  }
  if(str_chr(s2,*s1) != nullptr){
    return (char*)s1;
  }
  return str_pbrk(s1 +1,s2);
}


//const char *str_rchr_aux(const char *s, int c) {
    //if (*s == '\0') {
        //return (c == '\0') ? s : nullptr;
    //}

    //const char *trouve_plus_loin = str_rchr_aux(s + 1, c);

    //if (trouve_plus_loin != nullptr) {
        //return trouve_plus_loin;
    //}

    //if (*s == c) {
        //return s;
    //}

    //return nullptr;
//}

//char *str_rchr(const char *s, int c) {
    //return (char *)str_rchr_aux(s, c);
//}

char *str_rchr(const char *s, int c) {
    if (*s == '\0')
        return (c == '\0') ? (char *)s : nullptr;

    char *suite = str_rchr(s + 1, c);
    return suite ? suite : (*s == (char)c ? (char *)s : nullptr);
}


// Fonction auxiliaire pour vérifier si un caractère est présent dans la liste
int est_dans(char c, const char *s1) {
    if (*s1 == '\0')
        return 0;

    if (*s1 == c)
        return 1;

    return est_dans(c, s1 + 1);
}

size_t str_spn(const char *s1, const char *s2) {
    if (*s1 == '\0' || !est_dans(*s1, s2)) {
        return 0;
    }

    return 1 + str_spn(s1 + 1, s2);
}


