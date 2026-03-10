// simple_mc_main2.cpp

#include <iostream>

#include "simple_mc.h"
using namespace std;

int main() {
  double expiry;
  double strike;
  double strike2;
  double spot;
  double vol;
  double r;
  unsigned long number_of_paths;

  cout << "\nEnter expiry\n";
  cin >> expiry;

  cout << "\nEnter lower strike\n";
  cin >> strike;

  cout << "\nEnter upper strike for double digital\n";
  cin >> strike2;

  cout << "\nEnter spot\n";
  cin >> spot;

  cout << "\nEnter vol\n";
  cin >> vol;

  cout << "\nEnter r\n";
  cin >> r;

  cout << "\nNumber of paths\n";
  cin >> number_of_paths;

  Payoff call_payoff(strike, strike2, Payoff::Call);
  Payoff put_payoff(strike, strike2, Payoff::Put);
  Payoff dd_payoff(strike, strike2, Payoff::DoubleDigital);
  Payoff dc_payoff(strike, strike2, Payoff::DigitalCall);
  Payoff dp_payoff(strike, strike2, Payoff::DigitalPut);
  Payoff pc1_payoff(strike, strike2, Payoff::PowerCall1);
  Payoff pp1_payoff(strike, strike2, Payoff::PowerPut1);
  Payoff pc2_payoff(strike, strike2, Payoff::PowerCall2);
  Payoff pp2_payoff(strike, strike2, Payoff::PowerPut2);

  double result_call =
      simple_monte_carlo(call_payoff, expiry, spot, vol, r, number_of_paths);

  double result_put =
      simple_monte_carlo(put_payoff, expiry, spot, vol, r, number_of_paths);

  double result_dd =
      simple_monte_carlo(dd_payoff, expiry, spot, vol, r, number_of_paths);
  
  double result_dc =
      simple_monte_carlo(dc_payoff, expiry, spot, vol, r, number_of_paths);
  
  double result_dp =
      simple_monte_carlo(dp_payoff, expiry, spot, vol, r, number_of_paths);

  double result_pc1 =
      simple_monte_carlo(pc1_payoff, expiry, spot, vol, r, number_of_paths);

  double result_pp1 =
      simple_monte_carlo(pp1_payoff, expiry, spot, vol, r, number_of_paths);

  double result_pc2 =
      simple_monte_carlo(pc2_payoff, expiry, spot, vol, r, number_of_paths);

  double result_pp2 =
      simple_monte_carlo(pp2_payoff, expiry, spot, vol, r, number_of_paths);

  cout << "\nthe prices are:\n"
       << result_call << " for the call\n"
       << result_put << " for the put\n"
       << result_dd << " for the double digital\n"
	   << result_dc << " for the digital call\n"
	   << result_dp << " for the digital put\n"
	   << result_pc1 << " for the power call 1\n"
	   << result_pp1 << " for the power put 1\n"
	   << result_pc2 << " for the power call 2\n"
	   << result_pp2 << " for the power put 2\n";


  double tmp;
  cin >> tmp;

  return 0;
}
