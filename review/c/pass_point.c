/* per poter allocare memoria all'interno di una funzione che non sia il main bisogna
passare l'indirizzo al puntatore, ovvero usare un puntatore al puntatore oppure passare
direttamente l'indirizzo tramite l'operatore & */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mem_all(int**, int);
void pass(int*);
void mem_reall(int**, int);
void join(char*, char*, char*, char**);

int main() {

    int* v;
    int size = 2;
    mem_all(&v, size);
    for (int i = 0; i < size; i++) {
        //printf("%d\n", *(v+i));
    }

    int size2 = 3;
    mem_reall(&v, size2);
    for (int i = 0; i < size; i++) {
        //printf("%d\n", *(v+i));
    }

    free(v);

    int v2[] = {1, 2, 3};
    //printf("%d\n", v2[0]);
    pass(v2);
    //printf("%d\n", v2[0]);

    char s1[] = "ciao";
    char s2[] = " a tutti ";
    char* sp1 = (char*) malloc(2*sizeof(char));
    char** sp2;
    join(s1, s2, sp1, sp2);
    printf("%s\n", s1);
    free(sp1);
    free(*sp2);
    free(sp2);

    return 0;
}

void mem_all(int** w, int size) {
 
    *w = (int*) malloc(size*sizeof(int));
    for (int i = 0; i < size; i++) {
        *((*w)+i) = i;
    }
}

void pass(int* w) {

    w[0] = 4;
}

void mem_reall(int** w, int size) {

    *w = realloc(*w, size*sizeof(int));
    for (int i = 0; i < size; i++) {
        (*w)[i] = i + 10;
    }
}

void join(char* s1, char* s2, char* sp1, char** sp2) {

    sp1[0] = 'a';
    sp1[1] = 'b';

    **sp2 = (char**) malloc(sizeof(char*));
    *sp2 = (char*) malloc(3*sizeof(char));
    (*sp2)[0] = '0';
    (*sp2)[1] = '1';
    (*sp2)[2] = '2';

    strcat(s1, sp1);
    strcat(s1, *sp2);
    strcat(s1, s2);
}
