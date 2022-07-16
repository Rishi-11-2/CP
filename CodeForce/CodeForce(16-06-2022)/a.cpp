#include <bits/stdc++.h>
using namespace std;
#define el endl
#define vi vector<int>
#define pb push_back
#define ht unordered_map
#define uset unordered_set
#define ll long long int
#define lld long double
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll a, b;
    cin >> a >> b;
    int h = (a / b);
    if (a % b != 0)
    {
        h++;
    }
    cout << h << el;
}