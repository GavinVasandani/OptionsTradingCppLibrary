#include "MCPriceGenerator.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {

    int dt = 2;
    int initOptPrice = 100;
    int numTimeSteps = 2;
    int rfRate = 1;
    int vol = 1;

    //Call to constructor in nm
    MCPriceGenerator mcpg (dt, initOptPrice, numTimeSteps, rfRate, vol);

    //Call to operator() func in nm
    vector<int> optPrices = mcpg(1);

    for (auto i:optPrices) {
        cout<<" "<<i<<",";
    }

    return 0;
}
