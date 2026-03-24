#include "iostream"
#include "simple_mc6.h"
#include "vanilla3.h"

using namespace std;

int main()
{
    double expiry;
    double strike;
    double boostLevel;
    double spot;
    double vol;
    double r;
    unsigned long number_of_paths;

    cout << "\nEnter expiry\n";
    cin >> expiry;

    cout << "\nEnter strike\n";
    cin >> strike;

    cout << "\nEnter boost level (less than strike)\n";
    cin >> boostLevel;

    cout << "\nEnter spot\n";
    cin >> spot;

    cout << "\nEnter vol\n";
    cin >> vol;

    cout << "\nEnter r\n";
    cin >> r;

    cout << "\nNumber of paths\n";
    cin >> number_of_paths;

    PayOffCall the_payoff(strike);
    VanillaOption option1(the_payoff, expiry);

    ParametersConstant vol_param(vol);
    ParametersConstant r_param(r); // 这两个变量不再是double

    double result = simple_monte_carlo6(option1,
                                        spot,
                                        vol_param,
                                        r_param,
                                        number_of_paths);

    cout << "\nthe call price is " << result << "\n";

    VanillaOption option2(option1);

    result = simple_monte_carlo6(option2,
                                 spot,
                                 vol_param,
                                 r_param,
                                 number_of_paths);

    cout << "\nthe call price is " << result << "\n";

    PayOffPut the_payoff2(strike);
    // std::cout << "step 1\n";
    VanillaOption option3(the_payoff2, expiry);
    // std::cout << "step 2\n";
    option1 = option3;
    // std::cout << "step 3\n";

    result = simple_monte_carlo6(option1,
                                 spot,
                                 vol_param,
                                 r_param,
                                 number_of_paths);

    cout << "\nthe put price is " << result << "\n";


    PayOffCustomCall the_payoff3(strike, boostLevel);
    VanillaOption option4(the_payoff3, expiry);

    result = simple_monte_carlo6(option4,
                                 spot,
                                 vol_param,
                                 r_param,
                                 number_of_paths);

    cout << "\nthe custom call price is " << result << "\n";

    PayOffCustomPut the_payoff4(strike, boostLevel);
    VanillaOption option5(the_payoff4, expiry);

    result = simple_monte_carlo6(option5,
                                 spot,
                                 vol_param,
                                 r_param,
                                 number_of_paths);

    cout << "\nthe custom put price is " << result << "\n";

    return 0;
}
