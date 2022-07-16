#include <bits/stdc++.h>
using namespace std;

vector<int> intersect(vector<int> nums1, vector<int> nums2)
{

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    vector<int> v;
    int i = 0, j = 0;
    int n = nums1.size(), m = nums2.size();

    while (i < n && j < m)
    {
        if (nums1[i] < nums2[j])
            i++;
        else if (nums2[j] < nums1[i])
            j++;
        else
        {
            v.push_back(nums1[i]), i++;
            j++;
        }
    }

    return v;
}

int main()
{
    int nums11[] = {1, 2, 2, 2, 1};
    vector<int> nums1;
    for (int i = 0; i < 4; i++)
    {
        nums1.push_back(nums11[i]);
    }
    int nums22[] = {2, 2};
    vector<int> nums2;
    for (int i = 0; i < 2; i++)
    {
        nums2.push_back(nums22[i]);
    }
    vector<int> a = intersect(nums1, nums2);

    for (auto it : a)
    {
        cout << it << " ";
    }
}