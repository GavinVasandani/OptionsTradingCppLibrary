#include "MCPriceGenerator.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {

    double dt = 2.0;
    double initOptPrice = 100.0;
    int numTimeSteps = 20;
    double rfRate = 1.0;
    double vol = 0.5;

    MCPriceGenerator mcpg (dt, initOptPrice, numTimeSteps, rfRate, vol);
    vector<double> optPrices = mcpg(1);

    for (auto i:optPrices) {
        cout<<" "<<i<<",";
    }

    return 0;
}
