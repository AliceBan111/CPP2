#include "simple_mc2.h"
#include <iostream>

int main()
{
    double expiry;
    double strike;
    double upper_strike;
    double spot;
    double vol;
    double r;
    unsigned long number_of_paths;

    std::cout << "\nEnter expiry\n";
    std::cin >> expiry;

    std::cout << "\nEnter strike\n";
    std::cin >> strike;

    std::cout << "\nEnter upper strike\n";
    std::cin >> upper_strike;

    std::cout << "\nEnter spot\n";
    std::cin >> spot;

    std::cout << "\nEnter vol\n";
    std::cin >> vol;

    std::cout << "\nEnter r\n";
    std::cin >> r;

    std::cout << "\nNumber of paths\n";
    std::cin >> number_of_paths;

    PayOffCall payOffCall(strike);
    PayOffPut payOffPut(strike);
    PayOffDigitalCall payoffDigitalCall(strike);
    PayoffDoubleDigital payoffDoubleDigital(strike, upper_strike);
    PayoffPowerCall1 payoffPowerCall1(strike);
    PayoffPowerPut1 payoffPowerPut1(strike);
    PayoffPowerCall2 payoffPowerCall2(strike);
    PayoffPowerPut2 payoffPowerPut2(strike);

    double resultCall = simple_monte_carlo2(payOffCall,
                                            expiry,
                                            spot,
                                            vol,
                                            r,
                                            number_of_paths);

    double resultPut = simple_monte_carlo2(payOffPut,
                                           expiry,
                                           spot,
                                           vol,
                                           r,
                                           number_of_paths);

    double resultDDCall = simple_monte_carlo2(payoffDigitalCall,
                                           expiry,
                                           spot,
                                           vol,
                                           r,
                                           number_of_paths);
    
    double resultDoubleDigital = simple_monte_carlo2(payoffDoubleDigital,
                                           expiry,
                                           spot,
                                           vol,
                                           r,
                                           number_of_paths);

    double resultPowerCall1 = simple_monte_carlo2(payoffPowerCall1,
                                           expiry,
                                           spot,
                                           vol,
                                           r,
                                           number_of_paths); 
                                           
    double resultPowerPut1 = simple_monte_carlo2(payoffPowerPut1,
                                           expiry,
                                           spot,
                                           vol,
                                           r,
                                           number_of_paths);   
                                           
    double resultPowerCall2 = simple_monte_carlo2(payoffPowerCall2,
                                           expiry,
                                           spot,
                                           vol,
                                           r,
                                           number_of_paths);  
                                           
    double resultPowerPut2 = simple_monte_carlo2(payoffPowerPut2,
                                           expiry,
                                           spot,
                                           vol,
                                           r,
                                           number_of_paths);                                       

    std::cout << "the prices are " << resultCall << " for the call and\n "
              << resultPut << " for the put and\n "
              << resultDDCall << " for the digital call\n"
              << resultDoubleDigital << " for the double digital\n"
              << resultPowerCall1 << " for the power call 1\n"
              << resultPowerPut1 << " for the power put 1\n"
              << resultPowerCall2 << " for the power call 2\n"
              << resultPowerPut2 << " for the power put 2\n";

    return 0;
}
