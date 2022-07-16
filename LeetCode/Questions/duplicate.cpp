#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        long long int arr[2 * (int)(pow(10, 9))] = {0};
        int z = 0;
        for (auto it : nums)
        {
            if (it < 0)
            {
                arr[it + (int)(pow(10, 9))] += 1;
                if (arr[it + (int)(pow(10, 9))] > 1)
                {
                    return true;
                }
            }
            arr[it] += 1;
            if (arr[it] > 1)
            {
                return true;
            }
        }
        return false;
    }
};
