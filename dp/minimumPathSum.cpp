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

int minPathSum(vector<vector<int>>& grid)
{
    int m=grid.size(),n=grid[0].size();
    vector<vector<int>> dp(m,vector<int>(n));
    // for(int i = 1 ; i <= m ;++i)
    //  {   
    //      for(int j = 1 ; j <= n ;++j)
    //       { if (i == 1) 
    //            dp[i][j] = dp[i][j-1] + grid[i-1][j-1];
    //         else if (j == 1) 
    //            dp[i][j] = dp[i-1][j] + grid[i-1][j-1];
    //         else 
    //           dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i-1][j-1];
    //      }
    //  }
    function<int(int , int)>helper=[&](int i,int j)
    {
        if(i==0&&j==0) return dp[i][j]=grid[i][j];
        if(i<0||j<0) return 201;
        if(dp[i][j]) return dp[i][j];

        int up=helper(i-1,j);
        int down=helper(i,j-1);

        return dp[i][j]=grid[i][j]+min(up,down);
    };
    return helper(m-1,n-1);
}

int main() {
    ll m, n;
    cin >> m>> n;
    vector<vector<int>> grid(m, vector<int>(n));

    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cin >> grid[i][j];
        }
    }
    int result = minPathSum(grid);
    cout <<result << "\n";

    return 0;
}