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


int lcs(string &str1, string &str2) 
{
    int n = str1.length(), m = str2.length();
    int dp[n + 1][m + 1];
    int ans = 0;

    for (int i = 0; i <= n; i++) 
    {
        for (int j = 0; j <= m; j++) 
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (str1[i - 1] == str2[j - 1]) 
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            } 
            else
                dp[i][j] = 0;
        }
    }

    return ans;
}

int main()
 {
    string str1, str2;
    cin >> str1>> str2;

    int lcsLength = lcs(str1, str2);
    cout <<lcsLength << "\n";

    return 0;
}