#ifndef MC_PRICE_GENERATOR_H
#define MC_PRICE_GENERATOR_H

#include <vector>

using namespace std;

//Header file containing only class name and declaring class member var and funcs.

class MCPriceGenerator {

    private:

    //double used for decimal points in terms 0.0
    double dt; //duration of each time interval
    double initOptionPrice; //initial option price from when evaluating
    int numTimeSteps; //number of time steps aka t so number of price points to be calculated
    double rfRate; //some rate
    double volatility; //standard deviation of current option price for norm (average)

    public:

    //Constructor with default values
    MCPriceGenerator(double dt_ = 5.0, double initOptionPrice_ = 100.0, int numTimeSteps_ = 10, double rfRate_ = 1.0, double volatility_ = 0.5) {
        dt = dt_;
        initOptionPrice = initOptionPrice_;
        numofTimeSteps = numofTimeSteps_;
        rfRate = rfRate_;
        volatility = volatility_;
    }

    //operator overloading of (), output is vector of option price throughout time steps, and price is type double so vector element type is double
    //input seed is needed to generate values from engine
    vector<double> operator() (int seed); 

};

#endif