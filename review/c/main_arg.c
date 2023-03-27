/* il primo argomento passato alla funzione è sempre il nome dell'eseguibile;
abbiamo bisogno di puntatori a puntatori perché gli argomenti passati sono
stringhe, pertanto possiamo dereferenziare una sola volta se vogliamo accedere
alle stringhe e due volte se vogliamo accedere ai singoli caratteri */

#include <stdio.h>

int main(int argc, char** argv) {

  if (argc > 1) {

    printf("numero di argomenti: %d\n", argc-1);
    printf("primo argomento: %s\n", *(argv+1));
    printf("terza lettera del secondo argomento: %c\n", *(*(argv+2)+2));

  } else {

    printf("nessun argomento\n");

  }

  return 0;
}
