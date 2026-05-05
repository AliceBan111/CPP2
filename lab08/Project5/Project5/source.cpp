
#include"cppinterface.h"
#include <random>
#pragma warning (disable : 4996)


short // echoes a short
EchoShort(short x // number to be echoed
           )
{
    return x;
}

double DrawNatural(int a, int b)
{
    static std::random_device rd;
    static std::mt19937 generator(rd());

    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    std::uniform_int_distribution<int> distribution(a, b);

    return distribution(generator);
}

