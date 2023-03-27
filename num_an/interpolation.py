import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns



# funzione da interpolare
def my_function(x):
    return 1/(1 + 50 * (x-0.5)**2)

# funzione che calcola la base polinomiale sui punti di interpolazione
def basis(x, i, n):
    assert i <= n   # controlla che tale condizione sia soddisfatta
    return x ** i



n = 5   # order of the polynomial
X = np.linspace(0, 1, n+1)   # interpolation points
x = np.linspace(-0,1, 250)   # points on which we compute the function

# costruisco la matrice V tale che Vp = u, dove p sono i coeffincienti della funzione da
# interpolare u rispetto alla base polinomiale, ovvero la matrice delle basi nei punti di
# interpolazione (ogni riga di V rappresenta la base calcolata in un determinato punto di
# interpolazione)
V = np.zeros((n+1, n+1))
for i in range(n+1):
    V[:, i] = basis(X, i, n)

# modo alternativo (più pythonic) di eseguire il blocco sopra
# V = np.array([[basis(X[i], j, n) for j in range(n+1)] for i in range(n+1)])

# funzione da interpolare calcolata sui punti di interpolazione
u = my_function(X)

# ricavo i coefficienti di u sulla base polinomiale nei punti di interpolazione
p = np.linalg.solve(V, u)

# calcolo la base polinomiale sui punti in cui voglio calcolare la funzione; la funzione
# approssimata sarà infine Bp, dove B è la matrice della base polinomiale calcolata su tutti
# i punti in cui voglio valutare la funzione e p è il vettore dei coefficienti calcolati sui
# punti di interpolazione (in pratica conoscendo il valore della funzione nei punti di
# interpolazione mi ricostruisco la funzione in tutti i punti usando l'approssimazione
# polinomiale)
B = np.array([[basis(x[i], j, n) for j in range(n+1)] for i in range(len(x))])
approx = B.dot(p)

sns.set()
plt.plot(x, my_function(x))
plt.plot(x, approx)
plt.show()

# come errore di approssimazione si prende la massima distanza tra la funzione vera e
# l'approssimazione
error = max(abs(approx - my_function(x)))
print(error)

# per alcuni valori di n si ottengono errori enormi, in particolare il condition number
# dipende da n; ciò è dovuto al fatto che all'aumentare di n i vettori di V relativi
# ad alcuni punti di interpolazione diventano quasi uguali (si ricordi che devono tutti i
# punti della matrice devono essere ben distinti affinché il problema sia ben posto); si può
# risolvere il problema ad esempio usando al posto della base banale usata la base dei
# polinomi di Lagrange