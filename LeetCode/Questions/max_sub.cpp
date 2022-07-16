#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        long long l = nums.size();
        int s = 0;
        int maxS = 0;
        int t = 0;
        int minT = INT_MIN;
        if (l != 1)
        {
            for (auto it : nums)
            {
                s += it;
                if (it < 0)
                {
                    t++;
                    minT = max(it, minT);
                }
                if (s < 0)
                {
                    s = 0;
                }
                maxS = max(s, maxS);
            }
        }
        else
        {
            maxS = *nums.begin();
        }
        if (t == l)
        {
            maxS = minT;
        }
        return maxS;
    }
};