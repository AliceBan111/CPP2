//
//
//                                                                    Test.h
//

#ifndef TEST_H
#define TEST_H

#include <xlw/MyContainers.h>
#include <xlw/CellMatrix.h>
#include <xlw/DoubleOrNothing.h>
#include <xlw/ArgList.h>  
    
using namespace xlw;

//<xlw:libraryname=MyTestLibrary


short // echoes a short
EchoShort(short x // number to be echoed
       );

double EuropeanCallMC(
    double spot,
    double strike,
    double r,
    double vol,
    double expiry,
    int number_of_paths,
    int number_of_experiments
);

#endif
