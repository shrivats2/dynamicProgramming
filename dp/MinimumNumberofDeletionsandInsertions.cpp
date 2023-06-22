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


int canYouMake(string& str, string& ptr) 
{
    int n = str.size(), m = ptr.size();
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
            if (str[i - 1] == ptr[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } 
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int k = m - dp[n][m];
    int p = n - dp[n][m];

    return k + p;
}

int main()
{
    string str, ptr;

    cin >> str>> ptr;

    int result = canYouMake(str, ptr);
    cout << result << "\n";

    return 0;
}