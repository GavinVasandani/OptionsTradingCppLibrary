#include "MCPriceGenerator.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {

    int dt = 2.0;
    int initOptPrice = 100.0;
    int numTimeSteps = 20;
    int rfRate = 1.0;
    int vol = 0.5;

    MCPriceGenerator mcpg (dt, initOptPrice, numTimeSteps, rfRate, vol);
    vector<int> optPrices = mcpg(1);

    for (auto i:optPrices) {
        cout<<" "<<i<<",";
    }

    return 0;
}
