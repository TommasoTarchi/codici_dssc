import numpy as np
import matplotlib.pyplot as plot
import seaborn as sns


sns.set()

data = np.random.randn(1000)

f, (h1, h2) = plot.subplots(nrows = 1, ncols = 2)
h1.hist(data, bins = 30, color = 'b')
h2.hist(data, bins = 30, color = 'b', cumulative = True)
plot.show()
