
#include"cppinterface.h"
#include "normdist.h"
#include <cmath>
#pragma warning (disable : 4996)


short // echoes a short
EchoShort(short x // number to be echoed
           )
{
    return x;
}

double BSCallValue(double S, 
				   double X, 
				   double r, 
				   double sigma, 
				   double time) {
double time_sqrt=sqrt(time);
double d1=(log(S/X)+r*time)/(sigma*time_sqrt)+0.5*sigma*time_sqrt;
double d2=d1-(sigma*time_sqrt);
double c=S* N(d1) - X*exp(-r*time)*N(d2);
return c;
}

