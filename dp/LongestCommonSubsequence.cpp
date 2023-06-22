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

int longestCommonSubsequence(string text1, string text2) 
{
    int n = text1.size(), m = text2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    for (int i = 0; i <= n; i++) 
    {
        dp[i][0] = 0;
    }

    for (int i = 0; i <= m; i++) 
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= m; j++) 
        {
            if (text1[i - 1] == text2[j - 1]) //match
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } 
            else //not-match
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}

int main() 
{
    string text1, text2;
    cin >> text1>> text2;

    int lcsLength = longestCommonSubsequence(text1, text2);
    cout <<lcsLength << "\n";

    return 0;
}