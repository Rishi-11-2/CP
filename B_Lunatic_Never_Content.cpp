#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
void solve();
bool is_palindrome(const vector<int> &a, int x)
{
    unordered_map<int, int> counts;
    for (int num : a)
    {
        int rem = num % x;
        counts[rem]++;
    }
    int odd_count = 0;
    for (auto it : counts)
    {
        if (it.second % 2 == 1)
        {
            odd_count++;
        }
    }
    if (a.size() % 2 == 0)
    {
        return odd_count == 0;
    }
    else
    {
        return odd_count == 1;
    }
}

int largest_palindrome_x(const vector<int> &a)
{
    int max_x = *max_element(a.begin(), a.end()) + 1;
    while (max_x > 1)
    {
        if (is_palindrome(a, max_x))
        {
            return max_x;
        }
        max_x--;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int low = 0;
    int high = n - 1;
    int x = abs(arr[low] - arr[high]);
    low++;
    high--;
    while (low <= high)
    {
        if (low == high && n % 2 == 1)
            break;
        x = __gcd(x, abs(arr[low] - arr[high]));
        low++;
        high--;
    }
    if (x == INT_MAX)
        x = 0;
    cout << x << endl;
}