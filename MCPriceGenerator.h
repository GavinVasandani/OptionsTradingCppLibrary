#ifndef MC_PRICE_GENERATOR_H
#define MC_PRICE_GENERATOR_H

#include <vector>
#include <cmath>
#include <random>

using namespace std;

//Header file containing only class name and declaring class member var and funcs.

class MCPriceGenerator {

    private:

    //double used for decimal points in terms 0.0
    int dt; //duration of each time interval
    int initOptionPrice; //initial option price from when evaluating
    int numTimeSteps; //number of time steps aka t so number of price points to be calculated
    int rfRate; //some rate
    int volatility; //standard deviation of current option price for norm (average)

    public:

    //Constructor with default values
    //Cannot initialize constructor with default arguments outside class even with using class namespace for some reason
    MCPriceGenerator(int dt_ = 5, int initOptionPrice_ = 100, int numTimeSteps_ = 2, int rfRate_ = 1, int volatility_ = 1) :
    dt(dt_), 
    initOptionPrice(initOptionPrice_),
    numTimeSteps(numTimeSteps_),
    rfRate(rfRate_),
    volatility(volatility_)
    {}

    //operator overloading of (), output is vector of option price throughout time steps, and price is type double so vector element type is double
    //input seed is needed to generate values from engine
    vector<int> operator() (int seed); 

};



vector<int> MCPriceGenerator::operator()(int seed) {

    vector<int> optionPrices;
    mt19937_64 engineGenerateVal (seed); //an engine to generate values, numbers generated are dependent on seed

    normal_distribution <int> nd; //object of class normal_distribution, <> means default class type is used to make class non-templated so object can be made.
    //default is double. also default constructor values used. nd object applies filter on numbers generated to follow normal_dist.
    //normal_distribution has operator overloading () where for a set of double inputs into (), it generates the normal distribution so nd(engineGenerateVal) gives normal_dist of vals generated from engine

    //lambda func has a name currPrice which is used to call function and input params();
    //output type of currPrice func is auto which is inferred from func return type which is double
    //so in algorithms that use predicate, in algo implementation, name is assigned to lambda func its just that
    //lambda func is written as input parameter and its type is return type which is same type as lambda func name
    auto currPrice = [this] (int prevPrice, int randomVal) {
        int expArg = (rfRate-((volatility^2)/2.0))*dt + (volatility*randomVal*sqrt(dt));
        auto price = prevPrice*exp(expArg);
        return price;
    };

    optionPrices.push_back(initOptionPrice);

    for (int i=1; i<=numTimeSteps; i++) {
        
        //currentOptPrice is determined by taking previous option price, and
        //using any number from normal dist at randomVal
        int currentOptPrice = currPrice(optionPrices.back(), nd(engineGenerateVal));
        optionPrices.push_back(currentOptPrice);

    }
    
    return optionPrices;

}

#endif