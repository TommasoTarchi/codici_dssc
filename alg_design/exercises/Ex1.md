---
output:
  pdf_document: default
  html_document: default
---
## Exercises first lecture

*Tommaso Tarchi*

\

#### Ex.1

$$
g_1=f_1, g_2=f_5, g_3=f_3, g_4=f_8, g_5=f_4, g_6=f_2, g_7=f_7, g_8=f_6
$$

\

#### Ex.2

1. Sometimes it is true.
For example it is true for $f(n)=n$ (but basically for any function that tends to infinite for $n$ tending to infinite).
Instead, it is not true for example for $f(n)=\frac{1}{n}$.

2. Always true. Knowing that the two functions are asymptotically nonnegative, we know for sure that their sum will never be smaller than their $\max$ or larger than twice their $\max$.

3. Always true for similar reasons as above: asymptotically $c_1=1, c_2=2$ can be used as constants to bound $f+O\left(f\right)$ with $f$.

4. Sometimes true.
For example for $f(n)=n^2, g(n)=n$ it is not true, while for $f(n)=n^2+n, g(n)=n^2$ it is true.

5. Sometimes true.
For example it is not true for $f(n)=n^2, g(n)=n$, but it is true for $f(n)=n|\sin{n}|, g(n)=n|\cos{n}|$.
