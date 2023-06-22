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

int longestPalindromeSubseq(string s) 
{
    int n = s.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    string s1 = s;
    reverse(s1.begin(), s1.end());

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= n; j++) 
        {
            if (s[i - 1] == s1[j - 1]) 
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } 
            else 
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][n];
}

int main() 
{
    string s;
    cin >> s;

    int longestSubseq = longestPalindromeSubseq(s);
    cout << longestSubseq << "\n";

    return 0;
}