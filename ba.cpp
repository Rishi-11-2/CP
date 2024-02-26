struct Hashing{
    string s;
    int n;
    int primes;
    vector<int> hashPrimes = {1000000009, 100000007};
    const int base = 1001;
    vector<vector<int>> hashValues;
    vector<vector<int>> powersOfBase;
    vector<vector<int>> inversePowersOfBase;
    Hashing(string a){
        primes = (int)(hashPrimes.size());
        hashValues.resize(primes);
        powersOfBase.resize(primes);
        inversePowersOfBase.resize(primes);
        s = a;
        n = s.length(); 
        for(int i = 0; i < primes; i++) {
            powersOfBase[i].resize(n + 1);
            inversePowersOfBase[i].resize(n + 1);
            powersOfBase[i][0] = 1;
            for(int j = 1; j <= n; j++){
                powersOfBase[i][j] = (base * powersOfBase[i][j - 1]) % hashPrimes[i];
            }
            inversePowersOfBase[i][n] = inverse(powersOfBase[i][n], hashPrimes[i]);
            for(int j = n - 1; j >= 0; j--){
                inversePowersOfBase[i][j] = ((inversePowersOfBase[i][j + 1]%hashPrimes[i])*(base%hashPrimes[i]))%hashPrimes[i];
            } 
        }
        for(int i = 0; i < primes; i++) {
            hashValues[i].resize(n);
            for(int j = 0; j < n; j++){
                int val=(s[j]-'a'+1LL);
                hashValues[i][j] = (val%hashPrimes[i] * powersOfBase[i][j]%hashPrimes[i]) % hashPrimes[i];
                hashValues[i][j] = (hashValues[i][j] + (j > 0 ? hashValues[i][j - 1] : 0LL)) % hashPrimes[i];
            }
        }
    }
    vector<int> substringHash(int l, int r){
        vector<int> hash(primes);
        for(int i = 0; i < primes; i++){
            int val1 = hashValues[i][r];
            int val2 = l > 0 ? hashValues[i][l - 1] : 0LL;
            hash[i] = ((val1-val2+hashPrimes[i])%hashPrimes[i]*inversePowersOfBase[i][l]%hashPrimes[i])%hashPrimes[i];
        }
        return hash;
    }
};