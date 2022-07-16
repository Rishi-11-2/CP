#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        auto it1 = height.begin();
        auto it2 = height.end();
        long long int l = height.size();
        int maxA = (l - 1) * min(*it1, *it2);
        auto it = height.begin();
        auto ir = height.rbegin();
        int i = 1;
        it++;
        ir++;
        cout << *it1 << *it2 << endl;
        for (int j = 1; j < l; j++)
        {
            int A1 = (l - j - 1) * min(*it, *it2);
            int A2 = (l - j - 2) * min(*it, *ir);
            int A3 = (l - j - 1) * min(*ir, *it1);
            maxA = max(A1, A2);
            maxA = max(A3, maxA);
            it++;
            ir++;
        }
        return maxA;
    }
};