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

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4));

    function<int(int, int)> helper = [&](int i, int d) {
        if (i == 0)
        {
            int maxpt = 0;
            for (int j = 0; j < 3; j++)
            {
                if (d != j)
                    maxpt = max(maxpt, points[i][j]);
            }

            return maxpt;
        }

        if (dp[i][d] != 0)
            return dp[i][d];

        int maxpt = 0;

        for (int j = 0; j < 3; j++)
        {
            if (d != j)
            {
                int pt = points[i][j] + helper(i - 1, j);
                maxpt = max(maxpt, pt);
            }
        }

        return dp[i][d] = maxpt;
    };

    return helper(points.size() - 1, 3);
}

int main()
{
    int n;
    cin>>n;

     vector<vector<int>> points(n,vector<int>(3));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
           cin>>points[i][j]; 
        }
    }

    int result = ninjaTraining(points.size(), points);

    cout << result << "\n";

    return 0;
}