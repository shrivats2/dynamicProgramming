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

int uniquePaths(int m, int n) 
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 0; i < n; i++)
    {
        dp[0][i] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

int main() {
    ll m, n;
    cin >> m>> n;

    int result = uniquePaths(m, n);

    cout << result << "\n";

    return 0;
}




