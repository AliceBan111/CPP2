#include "option_struct.h"
#include "bs_pricing.h"
#include "mc_pricing.h"
#include <iostream>

int main() {
    OptionData myOption;
    std::cout << "Strike: ";
    std::cin >> myOption.strike;
    
    std::cout << "Spot: ";
    std::cin >> myOption.spot;
    
    std::cout << "Risk-free rate: ";
    std::cin >> myOption.r;
    
    std::cout << "Volatility: ";
    std::cin >> myOption.vol;
    
    std::cout << "Expiry: ";
    std::cin >> myOption.expiry;
    
    std::cout << "Type (1 for Call, 0 for Put): ";
    int type;
    std::cin >> type;
    myOption.isCall = (type == 1);

    printOptionByValue(myOption);
    
    OptionData* ptr = &myOption;
    
    printOptionByPointer(ptr);
    printOptionByReference(myOption);

    double bs1 = blackScholesByValue(myOption);
    double bs2 = blackScholesByPointer(&myOption);
    double bs3 = blackScholesByReference(myOption);
    
    std::cout << "BS price (by value): " << bs1 << "\n";
    std::cout << "BS price (by pointer): " << bs2 << "\n";
    std::cout << "BS price (by reference): " << bs3 << "\n";

    unsigned long paths = 100000;
    
    double mc1 = monteCarloByValue(myOption, paths);
    double mc2 = monteCarloByPointer(&myOption, paths);
    double mc3 = monteCarloByReference(myOption, paths);
    
    std::cout << "MC price (by value): " << mc1 << "\n";
    std::cout << "MC price (by pointer): " << mc2 << "\n";
    std::cout << "MC price (by reference): " << mc3 << "\n";
    
    return 0;
}