# inverse sampling: it is possible to obtain a sample distributed according to a given
# distribution extracting random numbers according to uniform distribution between 0 and 1 and
# computing their quantiles with respect to the given distribution
# for example with normal distribution:

sunif <- runif(10000, 0, 1)
y <- qnorm(sunif)
y <- y[order(y, decreasing = F)]

hist(y, breaks = 50, probability = T)

z <- seq(-3, 3, 0.005)
curve(dnorm(x), add = T, col = 'red')