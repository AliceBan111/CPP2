
#include"cppinterface.h"
#pragma warning (disable : 4996)


short // echoes a short
EchoShort(short x // number to be echoed
           )
{
    return x;
}

double BondPrice(int n,
	double couponyield,
	int m,
	double ytm,
	double f) {

	double price = 0;

	//discounting all the coupons
	for (int i = 1; i <= (n * m); ++i) {
		price += (couponyield * f / m) / pow((1 + ytm / m), double(i));
	}

	//discounting face value
	price += f / pow(1 + ytm / m, double(n * m));

	return price;

}
