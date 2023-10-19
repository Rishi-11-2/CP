// https://leetcode.com/problems/rabbits-in-forest/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numRabbits(vector<int> &answers)
    {
        map<int, int> m;
        for (auto &it : answers)
        {
            if (it != 0)
                m[it] += 1;
        }
        int ans = 0;
        for (auto &it : answers)
        {
            if (m[it] != 0 and it != 0)
            {
                int x = m[it] / (it + 1);
                int y = m[it] - ((it + 1) * x);
                ans += (x) * (it + 1);
                m[it] -= (x * (it + 1));
                if (m[it] != 0)
                    ans += max(m[it], it) + 1;
                m[it] = 0;
            }
            if (it == 0)
                ans += 1;
        }
        return ans;
    }
};