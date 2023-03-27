#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int interval(int, int);
double root_bisection(double, double, double);   /* only for numbers >= 1 (easy to implement
                                                    for < 1) */
int change(int, int*, char*);   /* gives the minimal change for an amount n of money in a
                                   currency with coins' values recorded in cr (for the sake
                                   of simplicity we record values in cr from minor to major)*/

int main() {

    const int n = 10, m = 15;
    printf("sum of numbers in interval [%d, %d) = %d\n", n, m, interval(n, m));

    const double p = 20.2345;
    printf("square root of %f = %f\n", p, root_bisection(1, p, p));

    const int k = 15;   /* amount of money */
    int cr[] = {4, 5, 8};   /* currency's kinds of coins */
    char cg[] = "\0";   /* string recording the change */
    int esito = change(k, cr, cg);
    if (!esito) {
        printf("minimal change for %d:  %s\n", k, cg);
    } else {
        printf("there isn't a minimal change for %d\n", k);
    }

    return 0;
}

int interval(int n, int m) {

    if (n == m) {
        return 0;
    }

    return n + interval(n+1, m);
}

double root_bisection(double inf, double sup, double p) {

    double q = (sup - inf) / 2. + inf;
    if ((q * q > p - 0.00001) && (q * q < p + 0.00001)) {
        return q;
    } else if (q * q >= p + 0.00001) {
        return root_bisection(inf, q, p);
    } else {
        return root_bisection(q, sup, p);
    }
}

int change(int k, int* cr, char* cg) {

    char supp[] = "   \0";
    int i, j, t;
    int resto;
    unsigned int size_cr = sizeof(cr)/sizeof(cr[0]) + 1;
    int esito_p = 0;
    printf("ultimo: %d   (%d)\n", cr[size_cr-1], size_cr);

    resto = k % cr[size_cr-1];   /* controllo se il numero è multiplo del taglio di currency
                                  più grande */
    printf("resto: %d\n", resto);
    if (resto == 0) {
        for (j = 0; j < k/cr[size_cr-1]; j++) {
            sprintf(supp, "%d ", cr[size_cr-1]);
            strcat(cg, supp);
        }
        return 0;
    }

    /* non funziona perché scritto come se cr_p fosse passato per valore, mentre (essendo
    un vettore) viene passato per indirizzo; si può risolvere il problema definendo cr_p
    da subito della stessa dimensione di cr e mettendo di volta in volta =0 i tagli che
    non si usano */

    for (i = size_cr-2; i >= 0; i--) {

        int cr_p[size_cr-i-2];
        for (j = size_cr-2; j >= i; j--) {
            cr_p[size_cr-2-j] = cr[j];
            printf("%d\n", cr_p[size_cr-2-j]);
        }

        printf("dim: %ld\n", sizeof(cr_p)/sizeof(cr_p[0]) + 1);

        for (j = 0; j <= k/cr[size_cr-1]; j++) {
            printf("fatto\n");
            esito_p = change(resto + j*cr[size_cr-1], cr_p , cg);
            if (esito_p == 0) {
                for (t = 0; t < k/cr[i]; t++) {
                    sprintf(supp, "%d ", cr[i]);
                    strcat(cg, supp);
                }
                return 0;
            }
        }
    }

    return 1;
}