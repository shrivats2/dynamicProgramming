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

int cherryPickup(vector<vector<int>>& grid) {
    int n=grid.size(),m=grid[0].size();

    vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));

    function<int(int,int,int)>helper=[&](int i,int j,int j1)
    {
        if(i>=n||j>=m||j1>=m||j<0||j1<0) return -100;

        if(i==n-1)
        {
            if(j==j1) return grid[i][j];
            else
            {
                return grid[i][j]+grid[i][j1];
            }
        }
        if(dp[i][j][j1]!=-1) return dp[i][j][j1];

        int ans=INT_MIN;

        for(int dj=-1;dj<=1;dj++)
        {
            for(int dj1=-1;dj1<=1;dj1++)
            {
                int pick=0;
                if(j==j1) pick=grid[i][j];
                else
                {
                    pick=grid[i][j]+grid[i][j1];
                }
                pick+=helper(i+1,j+dj,j1+dj1);
                ans=max(ans,pick);
            }
        } 

        return dp[i][j][j1]= ans;
    };

    return helper(0,0,m-1);
}

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m));
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>grid[i][j];

    int result = cherryPickup(grid);
    cout <<result << "\n";

    return 0;
}