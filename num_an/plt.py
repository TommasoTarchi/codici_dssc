import numpy as np
import matplotlib.pyplot as plt
# il seguente pacchetto è per la visualizzazione dati (aggiunge griglie, colori, ecc...); opera automaticamente sui grafici, basta importare il pacchetto e chiamare set()
import seaborn as sns


sns.set()

# scatter plot
x = np.linspace(0, 10, 50)
y = np.array(x ** 2)
z = np.array(x ** 3)
# il terzo parametro passato è relativo alla forma e al colore del plot: ad esempio 'g-' indica 'green and by lines', 'bo' indica 'blue and by circles', ecc...
plt.plot(x, y, 'g-', label = '$x^2$')
plt.plot(x, z, 'bo', label = '$x^3$')
plt.xlabel('basi')
plt.ylabel('risultati')
plt.title('potenze')
# aggiunge la legenda
plt.legend()
# salva la figura nel documento pdf (chiamarla sempre prima di plt.show())
plt.savefig('plot.pdf')
plt.show()