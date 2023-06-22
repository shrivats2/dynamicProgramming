#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define yes cout << "YES"<< "\n";
#define no cout << "NO" << "\n";
#define fr(i, a, b) for(int i = a; i<b; i++)
#define vi vector<ll>
#define pb push_back
#define aa(l,n) ll l[n]; fr(i,0,n) cin>>l[i];
#define av(l, n) vector<ll> l(n); fr(i,0,n) cin>>l[i];

const int mod = 1e9 + 7; 

int minDistance(string word1, string word2) {
    int n = word1.size(), m = word2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    function<int(int, int)> helper = [&](int i, int j) {
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (word1[i] == word2[j])
            return dp[i][j] = 0 + helper(i - 1, j - 1);
        else
            return dp[i][j] = 1 + min(helper(i - 1, j - 1),
                                      min(helper(i - 1, j), helper(i, j - 1)));
    };

    return helper(n - 1, m - 1);
}

int main() 
{
    string word1, word2;

    cin >> word1 >> word2;

    int result = minDistance(word1, word2);
    cout << result << endl;

    return 0;
}