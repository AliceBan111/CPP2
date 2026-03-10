#include "option_struct.h"
#include <iostream>

void printOptionByValue(OptionData opt) {
    std::cout << "\n Option Information (by value)" << "\n";
    std::cout << "Strike: " << opt.strike << "\n";
    std::cout << "Spot: " << opt.spot << "\n";
    std::cout << "Risk-free rate: " << opt.r << "\n";
    std::cout << "Volatility: " << opt.vol << "\n";
    std::cout << "Expiry: " << opt.expiry << "\n";
    std::cout << "Type: " << (opt.isCall ? "Call" : "Put") << "\n";
}

void printOptionByPointer(const OptionData* opt) {
    std::cout << "\nOption Information (by pointer)" << "\n";
    std::cout << "Strike: " << opt->strike << "\n";
    std::cout << "Spot: " << opt->spot << "\n";
    std::cout << "Risk-free rate: " << opt->r << "\n";
    std::cout << "Volatility: " << opt->vol << "\n";
    std::cout << "Expiry: " << opt->expiry << "\n";
    std::cout << "Type: " << (opt->isCall ? "Call" : "Put") << "\n";
}

void printOptionByReference(const OptionData& opt) {
    std::cout << "\n Option Information (by reference)" << "\n";
    std::cout << "Strike: " << opt.strike << "\n";
    std::cout << "Spot: " << opt.spot << "\n";
    std::cout << "Risk-free rate: " << opt.r << "\n";
    std::cout << "Volatility: " << opt.vol << "\n";
    std::cout << "Expiry: " << opt.expiry << "\n";
    std::cout << "Type: " << (opt.isCall ? "Call" : "Put") << "\n";
}