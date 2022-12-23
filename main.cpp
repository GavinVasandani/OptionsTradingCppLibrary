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

    MCPriceGenerator mcpg (dt, initOptPrice, numTimeSteps, rfRate, vol);
    vector<int> optPrices = mcpg(1);

    for (auto i:optPrices) {
        cout<<" "<<i<<",";
    }

    return 0;
}
