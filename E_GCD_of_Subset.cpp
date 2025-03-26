#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    int maxA = 0;
    for (int i = 0; i < N; i++){
        cin >> A[i];
        maxA = max(maxA, A[i]);
    }
    
    // 1. Count frequency of each number in A.
    vector<int> cnt(maxA + 1, 0);
    for (int i = 0; i < N; i++){
        cnt[A[i]]++;
    }
    
    // 2. For each divisor d, count how many numbers in A are divisible by d.
    vector<int> freq(maxA + 1, 0);
    for (int d = 1; d <= maxA; d++){
        for (int j = d; j <= maxA; j += d){
            freq[d] += cnt[j];
        }
    }
    
    // 3. Precompute divisors for each number up to maxA.
    //    For each d, add it as a divisor to all its multiples.
    vector<vector<int>> divs(maxA + 1);
    for (int d = 1; d <= maxA; d++){
        for (int j = d; j <= maxA; j += d){
            divs[j].push_back(d);
        }
    }
    
    // 4. For each A[i], answer is the largest divisor d (of A[i])
    //    for which at least K numbers in A are divisible by d.
    //    Since our divisors are stored in increasing order, we iterate backwards.
    for (int i = 0; i < N; i++){
        int x = A[i];
        int best = 1; // 1 always divides x.
        for (int j = divs[x].size() - 1; j >= 0; j--){
            int d = divs[x][j];
            if (freq[d] >= K) {
                best = d;
                break;
            }
        }
        cout << best << endl;
    }
    
    return 0;
}
