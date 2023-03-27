/* in pratica si può dire che usando in printf l'opzione %s (alla quale si 'abbina' un puntatore ad una stringa (array
di char)) vengono stampati tutti i caratteri a partire dalla cella di memoria puntata fino al carattere '/0' */


#include <stdio.h>
#include <stdlib.h>    /* necessaria per sizeof() */
#include <string.h>    /* necessaria per funzioni come strlen, ma NON per la definizione e la manipolazione
                          delle stringhe */

int main() {

    /* i due blocchi seguenti fanno la stessa cosa */

    char sc[] = {'a', 'b', '\0'};    /* esattamente come dichiarare char sc[2] e poi assegnare i valori uno per uno
                                        (si può fare con qualunque tipo di array); si noti che se vogliamo stampare
                                        tutto la stringa tramite %s (quindi evitando cicli in cui si stampa un carattere
                                        alla volta) bisogna aggiungere il carattere di interruzione di stringa) */
    printf("%s\n", sc);

    char* sc_alt = (char*) malloc(2 * sizeof(char));
    *sc_alt = 'a';
    *(sc_alt + 1) = 'b';    /* si noti che in questo caso non devo aggiungere il carattere di interruzione di stringa
                               perché ho allocato la memoria, quindi ho già comunicato la lunghezza della stringa */
    printf("%s\n", sc_alt);
    free(sc_alt);

    char sf[] = "stringa di prova\0roba che non stampo";
    printf("%s\n", sf);
    printf("%c\n", sf[strlen(sf) + 2]);
    printf("%c\n", sf[strlen(sf) + 22]);

    sf[2] = 'R';    /* la stringa è a tutti gli effetti un array */
    printf("%s\n", sf);

    /* sf[2] = "RRRR";      /* ovviamente dà errore */

    const int n = 10;
    sprintf(sf, "sovrascritta anche con il numero %d", n);   /* stampa sulla stringa
                                                                sovrascrivendola */
    printf("%s\n", sf);

    sscanf(sc, "%s\n", sf);   /* legge la stringa passata come primo argomento e la copia
                                 sovrascrivendo la stringa passata per ultima */
    printf("%s\n", sf);

    char sr[] = "bella\0";
    char sff[] = " storia\0";
    strcat(sr, sff);
    printf("%s\n", sr);

    return 0;
}