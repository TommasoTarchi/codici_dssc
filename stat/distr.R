# example of joint distribution: Y (normal) depends on X (binomial) through the fact that the
# mean of Y is five times the value of X


par(mfrow = c(1, 2))

x <- rbinom(10000, size = 1, prob = 0.7)
y <- rnorm(10000, mean = x*5, s = 1)
hist(y, breaks = 50, xlim = c(-4, 10))

# the distribution we obtained is a linear combination of two normal distributions
xx <- seq(-4, 10, 1000)
ff <- 0.3 * dnorm(xx, 0) + 0.7 * dnorm(xx, 5)
hist(y, breaks = 50, xlim = c(-4, 10))

# si può anche usare la funzione hist.scott() per creare un istogramma con larghezza dei bin
# automatica; fa parte del package MASS