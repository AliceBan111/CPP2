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

double BSCallValue(double S,
	double X,
	double r,
	double sigma,
	double time);

#endif
