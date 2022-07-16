#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int low = 1;
        int high = n;
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                st.push(high);
                high -= 1;
            }
            else
            {
                st.push(low);
                low++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
}