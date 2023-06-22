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

int numDistinct(string s, string t)
{
    int n = s.length(), m = t.length();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    function<int(int, int)> helper = [&](int i, int j)
    {
        if (j < 0) return 1;
        if (i < 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j])
        {
            return dp[i][j] = helper(i - 1, j - 1) + helper(i - 1, j);
        }
        return dp[i][j] = helper(i - 1, j);
    };

    return helper(n - 1, m - 1);
}

int main() 
{
    string s, t;

    cin >> s>> t;

    int result = numDistinct(s, t);
    cout <<result << "\n";

    return 0;
}