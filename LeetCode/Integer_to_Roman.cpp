#include <bits/stdc++.h>
using namespace std;
int findElement(int A[], int x)
{
    for (int i = 0; i < (sizeof(A) / sizeof(A[0])); i++)
    {
        if (x == A[i])
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    string a = "IVXLCDM";
    int b[] = {1, 5, 10, 50, 100, 500, 1000};
    string s = "IVIXXLXCCDCM";
    int z[] = {4, 9, 40, 90, 400, 900};
    int n;
    cin >> n;
    int c = 0;
    int k = n;
    vector<int> d;
    while (k > 0)
    {
        c++;
        auto it = d.insert(d.begin(), k % 10);
        k /= 10;
    }
    c -= 1;
    string z;
    for (auto it : d)
    {
        if (findElement(b, it) != -1)
        {
            z += a[findElement(b, it)];
        }
    }
}