## Likelihood ------------------------------------------------------------------
set.seed(483)

n <- 30
p <- 0.5

y <- rbinom(n, 1, p)
sumy <- sum(y)

bin <- function(n, sumy, pt) pt^sumy*(1-pt)^(n-sumy)

# il massimo valore della likelihood L è in p
p.seq <- seq(0, 1, 0.1)
L <- bin(n, sumy, p.seq)
cbind(p.seq, L)
max(L)
p.seq[which.max(L)]

plot(p.seq, L, type = "p")
curve(bin(n, sumy, x), 0, 1, add=T)

points(p.seq[which.max(bin(n, sumy, p.seq))], max(bin(n, sumy, p.seq)), 
       col = "red")

# set.seed(24)

plot(p.seq, dbinom(sumy,n, p.seq), type = "n", ylim=c(0,.4))
abline(v = .7)

for(i in 1:1000){
  n <- 20
  y <- rbinom(n,1,.7)
  sumy <- sum(y)
  
  p.seq <- seq(0,1,0.01)
  
  curve(dbinom(sumy,n, x), 0,1, add=T)
  
  max(dbinom(sumy,n, p.seq))
  p.seq[which.max(dbinom(sumy,n, p.seq))]
  
  points(jitter(p.seq[which.max(dbinom(sumy,n, p.seq))]), jitter(max(dbinom(sumy,n, p.seq)),2), 
         col = "grey", pch = 19, cex = .1)
  
}

## log lik
set.seed(14)
plot(p.seq, dbinom(sumy,n, p.seq,log = T), type = "n", ylim= c( -5,0))
abline(v = .7)

for(i in 1:1000){
  n <- 20
  y <- rbinom(n,1,.7)
  sumy <- sum(y)
  
  p.seq <- seq(0,1,0.01)
  
  curve(dbinom(sumy,n, x, log = T)-max(dbinom(sumy,n, p.seq, log = T)), 0,1, add=T)
  
  max(dbinom(sumy,n, p.seq, log = T))
  p.seq[which.max(dbinom(sumy,n, p.seq, log = T))]
  
  points(jitter(p.seq[which.max(dbinom(sumy,n, p.seq, log = T))]), 0, 
         col = "grey", pch = 19, cex = .1)
}


# Poisson model 

# Y_i ~ iid Poisson(lambda), lambda>0

lik_pois <- function(lam, n, sumy) log(lam) * sumy - n * lam 
xx <- seq(6.5, 12, l = 30)
ll <- sapply(xx, lik_pois, sumy = 90, n = 10)
#lik_pois(xx,10,90)
par(pty = "s")
plot(xx, ll - max(ll), type = "l", xlab = expression(lambda),
     ylab = expression(l(lambda)-max(l(lambda))), cex.lab = 2)

for(i in 1:100){
  sumy <- sum(rpois(10,9))
  ll <- lik_pois(xx,10,sumy)
  lines(xx,ll-max(ll),type = "l", xlab = expression(lambda),
        ylab = expression(l(lambda)-max(l(lambda))), cex.lab = 2)
}
abline(v=9)
