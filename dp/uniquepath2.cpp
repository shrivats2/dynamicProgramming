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

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n));

    // function<int(int , int)>helper=[&](int i,int j)
    // {
    //  if(i<0||j<0) return 0;
    //  if(obstacleGrid[i][j]==1) return dp[i][j]=0;
    //  if((i==0&&j==0)&&obstacleGrid[i][j]!=1) return 1;
    //  if(dp[i][j]!=0) return dp[i][j];

    //  int up=helper(i-1,j);
    //  int down=helper(i,j-1);

    //  return dp[i][j]=up+down;
    // };

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[i][j] == 1) {
                dp[i][j] = 0;
                continue;
            }
            if (i == 0 && j == 0) {
                dp[i][j] = 1;
                continue;
            }

            int up = 0;
            int left = 0;

            if (i > 0)
                up = dp[i - 1][j];
            if (j > 0)
                left = dp[i][j - 1];

            dp[i][j] = up + left;
        }
    }

    return dp[m - 1][n - 1];
}

int main() 
{
    ll m, n;
    cin >> m>> n;

    vector<vector<int>> obstacleGrid(m, vector<int>(n));
    
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++)
        {
            cin >> obstacleGrid[i][j];
        }
    }
    int result = uniquePathsWithObstacles(obstacleGrid);
    cout << result << "\n";

    return 0;
}