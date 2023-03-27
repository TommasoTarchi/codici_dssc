#include "poly.h"

double poly(double a[], double x, int degree)
{
	long int i;
	double result = a[0];
	double xpwr = x; /* equals x^i at start of loop */
	for (i = 1; i <= degree; i++) {
		result += a[i] * xpwr;
		xpwr = x * xpwr;
	}
	return result;
}

double polyh(double a[], double x, int degree)
{
	long int i;
	double result = a[degree];
		for (i = degree-1; i >= 0; i--)
			result = a[i] + x*result;
		return result;
}

double mypoly1(double a[], double x, int degree)
{
  long int i;
  double x2   = x*x;
  double res = a[0];
  double xpwr = x;
  
  for ( i = 1; i < degree; i += 2 )
    {
      // unrolling
      res += a[i] * xpwr;
      res += a[i+1] * xpwr * x;
      xpwr *= x2;	
    }
  return res;
}

double mypoly2(double a[], double x, int degree)
{
  long int i;
  double x2   = x*x;
  double res  = a[0];
  double xpwr = x;

  /* notice that multiplying two terms at te same time does
  not change anything (it doesn't tell the compiler that it
  can vectorize, so it is pointless) */
  for ( i = 1; i < degree; i += 2 )
    {
      res += (a[i] + a[i+1]*x)* xpwr;
      xpwr *= x2;	
    }
  for ( ; i <= degree; i ++ )
    {
      res += a[i] * xpwr;
      xpwr *= x;
    }
  return res;
}

double mypoly3(double a[], double x, int degree)
{
  long int i;
  double x2   = x*x;
  double res1  = a[0];
  double res2  = a[2];
  double xpwr = x;
  double xpwr3 = x2*x;
  
  for ( i = 1; i < degree-4; i += 4 )
    {
      res1 += (a[i] + a[i+1]*x)* xpwr;
      res2 += (a[i+2] + a[i+3]*x)* xpwr3;
      xpwr *= x2;
      xpwr3 *= x2;
    }
  for ( ; i <= degree; i ++ )
    {
      res1 += a[i] * xpwr;
      xpwr *= x;	
    }
  
  return res1+res2;
}


double mypoly4(double a[], double x, int degree)
{
  long int i;
  double x2 = x*x;
  double res_even  = a[0];
  double res_odd   = 0;
  double xpwr_even = x2;
  double xpwr_odd  = x;
 
  for ( i = 1; i <= degree; i += 2 )
    {
      res_odd   += a[i] * xpwr_odd;
      xpwr_odd  *= x2;
      res_even  += a[i+1] * xpwr_even;
      xpwr_even *= x2;
    }
  //for ( ; i <= degree; i ++ )
  //  {
  //    res_odd += a[i] * xpwr_even;
  //    xpwr_even *= x;	
  //  }
  return res_even + res_odd;
}

double mypoly_tommy(double a[], double x, int degree)
{
  long int i;
  double x2   = x*x;
  double res1  = a[0];
  double res2  = a[2];
  double xpwr = x;
  double xpwr3 = x2*x;
  
  for ( i = 1; i < degree-4; i += 4 )
    {
      /* this is like mypoly3 but operations are more
       * splitted: no significant improvement */
      double temp1 = a[i] + a[i+1]*x;
      double temp2 = a[i+2] + a[i+3]*x;
      res1 += temp1 * xpwr;
      res2 += temp2 * xpwr3;
      xpwr *= x2;
      xpwr3 *= x2;
    }
  for ( ; i <= degree; i ++ )
    {
      res1 += a[i] * xpwr;
      xpwr *= x;	
    }
  
  return res1+res2;
}



double sp1(double a[], double x, int degree) {

    int N=400;
    double sum=0;
    
    for (int i=0; i<N; i++) {
        sum += a[i]*a[N+i];
    }

    return sum;
}   

double sp2(double a[], double x, int degree) {

    int N=400;
    double sum=0;
    double sum1=0, sum2=0;
    int N_2=N/2;
    
    for (int i=0; i<N_2; i++) {
        sum1 += a[i]*a[N+i];
        sum2 += a[N_2+i]*a[N+N_2+i];
    }

    return sum1+sum2;
}

double sp3(double a[], double x, int degree) {

    int N=400;
    double sum=0;
    double sum1=0, sum2=0;
    int N_2=N/2;
    
    for (int i=0; i<N_2; i+=2) {
        sum1 += a[i]*a[N+i];
        sum1 += a[i+1]*a[N+i+1];
        sum2 += a[N_2+i]*a[N+N_2+i];
        sum2 += a[N_2+i+1]*a[N+N_2+i+1];
    }

    return sum1+sum2;
}

double sp4(double a[], double x, int degree) {

    int N=400;
    double sum=0;
    double sum1=0, sum2=0;
    int N_2=N/2;
    
    for (int i=0; i<N_2; i+=4) {
        double temp1=a[i]*a[N+i];
        double temp2=a[i+1]*a[N+i+1];
        sum1 += temp1;
        sum1 += temp2;
    }

    return sum1+sum2;
}


void register_functions(void)
{
	set_check_function(&poly); /* used as reference implementation */

	add_function(&poly, "Polynomial: Naive implementation");
	add_function(&polyh, "Polynomial: Horner's method");
	add_function(&mypoly1, "Polynomial: my poly1, unroll x 2");
	add_function(&mypoly2, "Polynomial: my poly2, 2 separate loops");
	add_function(&mypoly3, "Polynomial: my poly3, unroll x 2 and separate accumulation");
    add_function(&mypoly4, "Polynomial: my poly4, separate accumulation");
    add_function(&mypoly_tommy, "Polynomial: my poly tommy");

    add_function(&sp1, "Scalar product: Naive implementation");
    add_function(&sp2, "Scalar product: 2 separate loops");
    add_function(&sp3, "Scalar product: 2 separate loops, unroll x 2");
    add_function(&sp4, "Scalar product: 2 separate loops, unroll x 2, separate accumulation");
	return;
}
