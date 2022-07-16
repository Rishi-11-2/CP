#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> nums, int target)
{
    vector<int> a;
    int l = nums.size();
    multiset<int, greater<int>> mg;
    multiset<int, greater<int>>::iterator itr;
    multiset<int, greater<int>>::reverse_iterator ritr;
    int k = 0;
    int j = 0;
    if (target != 0)
    {
        for (int i = 0; i < l; i++)
        {
            mg.insert(nums[i]);
        }
        itr = mg.begin();
        ritr = mg.rbegin();
        int s = *itr + *ritr;
        while (s != target)
        {
            if (s > target)
            {
                itr++;
                s = *itr + *ritr;
            }
            if (s < target)
            {
                ritr++;
                s = *itr + *ritr;
            }
        }
        int index = 0;
        auto it = find(nums.begin(), nums.end(), *itr);
        if (it != nums.end())
        {
            index = it - nums.begin();
            a.push_back(index);
        }
        if (*itr != *ritr)
        {
            auto it1 = find(nums.begin(), nums.end(), *ritr);
            if (it1 != nums.end())
            {
                int index1 = it1 - nums.begin();
                a.push_back(index1);
            }
        }
        else
        {
            auto it1 = find(nums.begin() + index + 1, nums.end(), *ritr);
            if (it1 != nums.end())
            {
                int index1 = it1 - nums.begin();
                a.push_back(index1);
            }
        }
    }
    else
    {
        int minS = INT_MAX;
        for (auto it : nums)
        {
            minS = min(it, minS);
        }
        if (minS < 0)
        {
            auto i = find(nums.begin(), nums.end(), abs(minS));
            auto j = find(nums.begin(), nums.end(), minS);
            int index1 = i - nums.begin();
            int index2 = j - nums.begin();
            a.push_back(index1);
            a.push_back(index2);
        }
        else
        {
            auto it = find(nums.begin(), nums.end(), 0);
            int index = it - nums.begin();
            auto it1 = find(nums.begin() + index + 1, nums.end(), 0);
            int index2 = it1 - nums.begin();
            a.push_back(index);
            a.push_back(index2);
        }
    }

    return a;
}
int main()
{
    vector<int> a = twoSum({2, 7, 11, 15}, 9);
    for (auto it : a)
    {
        cout << it << "  ";
    }
    cout << endl;
}

// a more efficient approach
// vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int, int> findNums;
//         for(int i =0; i < nums.size(); ++i){
//             int num = nums[i];
//             int targetNum = target - num;
//             if(findNums.find(targetNum) != findNums.end()){
//                 return {i, findNums[targetNum]};
//             }
//             findNums[num] = i;
//         }
//         return {0, 0};
//     }

// a great approach
// vector<int> twoSum(vector<int>& nums, int target) {
//     unordered_map<int, int> map;
//     vector<int> ans;
//     for(int i = 0; i < nums.size(); i++){
//         if(map.find(target- nums[i]) != map.end()){
//             ans.push_back(i);
//             ans.push_back(map[target-nums[i]]);
//             break;
//         }
//         else
//         {
//             map[nums[i]] = i;
//         }
//     }
//     return ans;
// }