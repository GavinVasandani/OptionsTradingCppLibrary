#include <vector>
#include <cmath>
#include <random>

using namespace std;

//Cannot have main in this file so initialize member func in class MCPriceGenerator namespace:

MCPriceGenerator::MCPriceGenerator(int dt_, int initOptionPrice_, int numTimeSteps_, int rfRate_, int volatility_) :
    dt(dt_), 
    initOptionPrice(initOptionPrice_),
    numTimeSteps(numTimeSteps_),
    rfRate(rfRate_),
    volatility(volatility_)
    {}

vector<int> MCPriceGenerator::operator() (int seed) {

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