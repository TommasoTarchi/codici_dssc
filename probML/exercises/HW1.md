---
output:
  pdf_document: default
  html_document: default
---
# Homework 1

*Tommaso Tarchi*
\
\



#### Exercise 1
\
Being the probability mass function constant and equal to $\frac{1}{N}$, we have:

$$
E\left[Y\right] = \sum^N_{j=1}\left[jP\left(Y=j\right)\right] = \sum^N_{j=1}\left({j\frac{1}{N}}\right) = \frac{1}{N}\sum^N_{j=1}{j} = \frac{N+1}{2}
$$

#### Exercise 2
\
y is a function of x, so we can compute the expectation $E\left[y\right]$ using the PDF of x:

$$
E\left[y\right] = \int_{-\infty}^{+\infty}{(8+12x)f(x)dx} = \int_{0}^{2}{(8+12x)(1-\frac{x}{2})dx} = \left[8x+6x^2-2x^2-2x^3\right]_{0}^{2} = 16
$$

#### Exercise 3
\
To compute the marginal PDFs we have to integrate the joint PDF on its domain along each axis.

We see that, for $X=x$, Y is between 0 and $1-x^2$, so we can compute the marginal of X as:
$$
f_X(x) = \int_0^{1-x^2}{\frac{15}{4}x^2dy} = \frac{15}{4}x^2\int_0^{1-x^2}{dy} = \frac{15}{4}x^2\left(1-x^2\right),
$$
for $-1<x<1$.

In the same way, we can see that for $Y=y$ we can compute the marginal of Y as:
$$
f_Y(y) = \int_{-\sqrt{1-y}}^{+\sqrt{1-y}}{\frac{15}{4}x^2dx} = \frac{5}{2}\left(1-y\right)^{\frac{3}{2}},
$$
for $0<y<1$.

#### Exercise 4

1. The marginal PDFs of X and Y are:
$$
f_X(x) = \int_0^\infty{6e^{-\left(2x+3y\right)}dy} = 6e^{-2x}\int_0^\infty{e^{-3y}dy} = 2e^{-2x},
$$
$$
f_Y(y) = \int_0^\infty{6e^{-\left(2x+3y\right)}dx} = ... = 3e^{-3y}.
$$
As we can see, $f(x,y)=f_X(x)f_Y(y)$ (i.e. the total PDF is equal to the product of the two marginal PDFs) which is a sufficient condition for independency, so X and Y are independent.

2. Since X and Y are independent, the value of X is irrelevant w.r.t. the probability of having a given value of Y. Mathematically this can be expressed as $f(y|x)=f_Y(y)$.
Therefore the expectation value $E\left[Y\right | X>2]$ is exactly equal to:
$$
E\left[Y\right] = \int_0^\infty{yf_Y\left(y\right)dy} = \left[ye^{-3y}\right]_0^\infty - \int_0^\infty{e^{-3y}dy} = \frac{1}{3}
$$

3. We want to compute the probability of getting a pair $(X=x, Y=y)$ such that $x>y$. To do that we can integrate the total PDF on the portion of its domain that satisfies this condition (i.e. on the portion of $R_+$x$R_+$ below the line $y=x$):
$$
P(X>Y) = \int_0^\infty{\left[\int_y^\infty{f(x,y)dx}\right]dy} = 6\int_0^\infty{e^{-3y}\left[e^{-2x}\right]_y^{\infty}dy} = 3\int_0^\infty{e^{-5y}dy} = \frac{3}{5}
$$

#### Exercise 5
\
We know that the probability for the laptop to last at least t years is:
$$
P\left(T\ge t\right) = e^{-\frac{t}{5}},
$$
therefore, the probability for the laptop to last less than t years (i.e. of braking within the t-th year) is:
$$
P\left(T<t\right) = 1-e^{-\frac{t}{5}}.
$$

We want to compute $P\left(T<3 | T\ge 2\right)$, which can be written as:
$$
P\left(T<3 | T\ge 2\right) = \frac{P\left(2\le T<3\right)}{P\left(T\ge 2\right)}.
$$

In the previous fraction the denominator is trivially $P\left(T\ge 2\right) = e^{-\frac{2}{5}}$. To compute the numerator we can notice that $P\left(T<t\right)$ is basically the CDF (if we consider t to be a continuous variable) for the event "laptop breaking". Therefore, we can write the probability for the laptop to break during the third year as:
$$
P\left(2\le T<3\right) = \int_2^3\frac{d}{dt}\left(1-e^{-\frac{t}{5}}\right)dt = e^{-\frac{2}{5}}-e^{-\frac{3}{5}}.
$$

Substituting the result in the previous expression, we get:
$$
P\left(T<3 | T\ge 2\right) = 1-e^{-\frac{1}{5}}.
$$

Notice that also considering t as discrete we get the same result, since:
$$
P\left(2\le T<3\right) = P\left(T<3\right) - P\left(T<2\right) = 1-e^{-\frac{3}{5}} - \left(1-e^{-\frac{2}{5}}\right).
$$