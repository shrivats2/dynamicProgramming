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

int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for (int j = 0; j < n; j++) {
        dp[0][j] = matrix[0][j];
    }
    
    for (int i = 1; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (j == 0)
                dp[i][j] = matrix[i][j] + min(dp[i - 1][j], dp[i - 1][j + 1]);
            else if (j == n - 1)
                dp[i][j] = matrix[i][j] + min(dp[i - 1][j - 1], dp[i - 1][j]);
            else 
                dp[i][j] = matrix[i][j] + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i - 1][j + 1]));
            
        }
    }
    
    int ans = INT_MAX;
    for (int j = 0; j < n; j++) 
    {
        ans = min(ans, dp[n - 1][j]);
    }
    return ans;
}

int main() 
{
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int result = minFallingPathSum(matrix);

    cout << result << "\n";

    return 0;
}