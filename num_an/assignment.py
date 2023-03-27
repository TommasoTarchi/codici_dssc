# in python tutte le variabili sono puntatori, pertanto l'operatore '=' è di assegnazione, ovvero copia nella variabile alla sua sinistra l'indirizzo della variabile a destra; attenzione: ciò non significa che le due variabili sono alias e che punteranno sempre allo stesso oggetto, perchè ogni volta che riassegno una variabile sto cambiando l'indirizzo in essa salvato (in pratica '=' fa una copia dell'indirizzo e non del valore)


a = [1, 2, 3]
b = a

a[0] = 10

print(b)
print()

b = [4, 5, 6]

print(a)
print()
print()

a = b

print(a)
print(b)
print()

c = [1, 2, 3]

b = c

print(a)
print(b)
print(c)


# per fare una semplice copia del valore
a = c.copy()
