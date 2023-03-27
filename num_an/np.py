# quando passo una serie di numeri come singolo argomento devo metterli nella forma di un iterabile (anche se ad esempio sto passando le dimensioni) a diff di R, numpy dispone i numeri nelle matrici per riga

# gli array rispetto alle liste sono estremamente ottimizzati e quindi più veloci (questo, ad esempio, perché le liste devono allocare memoria per oggetti di qualunque tipo, mentre gli array no)


import numpy as np


print(np.pi)
print()
print()


# come argomento posso passare anche un tuple invece di una lista
v = np.array([1, 2, 3])

print(v)
print(v[2])
print()
print()


v = np.array([[[1, 2, 3], [3, 4, 5], [1, 3, 5]], [[2, 3, 4], [4, 5, 6], [2, 4, 6]]])

print(v)
print(v.shape)  # shape restituisce le dimensioni dell'oggetto
print(v.ndim)
print()
print()

print(v[1][2][2])
print()
print()


v = np.array([1, 2, 3], float)

print(v[1])
v[1] = 20
print(v[1])
print()
print()


print(np.arange(0, 1, 0.2))
print(np.linspace(0, 1, 10))
print(np.zeros((2, 3)))
print(np.ones((2, 3)))
print()
print()


a = np.random.random((2, 3))
b = np.random.normal(loc = 1.4, scale = 2, size = (2, 3))
print(a)
print(b)
# salva l'array nel file di testo passato (se il file non esiste lo crea)
np.savetxt("numpy.txt", a)
# legge il file di testo
c = np.loadtxt("numpy.txt")
# si noti sotto che si ha vettorializzazione come in R
print(c == a)
print()
print()


print(np.arange(10).reshape(2, 5))
print()
print()


# ancora vettorializzazione (e i due print seguenti danno lo stesso output); si noti che, a differenza di R, numpy non esegue operazioni tra array con dimensioni diverse, nemmeno se sono l'una multipla dell'altra; fa eccezione il caso in cui una delle due dimensioni è 1
print(a * b)
a *= b
print(a)

print(a * 2)
c = np.array([1, 2, 3])
d = np.array([[1, 2, 3], [4, 5, 6]])
print(c + d)
print()
print()


# prodotto scalare e prodotto esterno
v = np.array([1, 2, 3])
w = np.ones(3)
print(np.inner(v, w))
print(np.outer(v, w))
print()

# trasposta, prodotto righe per colonne e prodotto colonne per righe
A = np.ones((2, 3))
B = np.array([[1, 2], [1, 2], [3, 4]])
print(B.T)
print(np.dot(A, B))
print(np.dot(B, A))
print()
print()
# attenzione: anche per fare moltiplicazione tra matrice e vettore usare np.dot, non '*'

v = np.random.random((2, 4))
print(v)
print(v.sum())
print(v.max())
print(v.min())
# somma le colonne
print(v.sum(axis=0))
# somma le righe
print(v.sum(axis=1))
print()
print()


v = np.random.random((3, 4))
print(v)
print(v[0, 2])
print(v[2, 1:3])
print(v[:,2])
print()
print()


# per i metodi del seguente blocco posso importare anche soltanto numpy.linalg (ci sono anche metodi più sofisticati, come solve per risolvere sistemi lineari o altri per calcolare autovalori e autovettori); in realtà le stesse operazioni possono essere eseguite (spesso in modo più efficiente) usando la libreria scipy
A = np.random.random(16).reshape(4, 4)
B = np.array([1, 2, 3, 4, 5, 6, 7, 8]).reshape(4, 2)
print(A)
print(B)
print(A.trace())
print(np.eye(3))
print(np.column_stack((A, B, A)))
print()
print()


# anche metodi per trasformate di Fourier in numpy.fft


# molti più metodi disponibili
print(np.random.rand(2, 3))
print(np.random.randint(1, 5, 10))
v = np.random.random(12)
# la seguente funzione prende v e restituisce un array di dimensione size contenente elementi estratti casualmente secondo la distribuzione di probabilità discreta p (di default la distribuzione uniforme); replace = True/False significa che possono/non possono essere estratti gli stessi elementi più di una volta (di default True)
print(np.random.choice(v, size = (5, 2), replace = False))
# ci sono svariate distribuzioni da cui estrarre un campione come nella riga seguente (la sintassi è analoga); se a size non si passa niente di default si ha estrazine di una singolo numero
print(np.random.binomial(3, 0.6, (2, 3)))
