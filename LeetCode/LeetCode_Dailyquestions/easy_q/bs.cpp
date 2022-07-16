#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> prices)
{
    int profit = INT_MAX;
    int ip = 0;
    int l = (int)prices.size();
    for (int i = 0; i < l; i++)
    {
        if (profit > prices[i])
        {
            profit = prices[i];
            ip = i;
        }
    }
    int z = 0;
    for (int i = ip + 1; i < l; i++)
    {
        z = max(prices[i], z);
    }
    if (z != 0)
        z = z - profit;
    else
        z = 0;
    return z;
}
int main()
{
    cout << maxProfit({2, 4, 1});
}