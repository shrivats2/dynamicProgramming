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

bool subsetSumToK(int n, int k, vector<int>& arr) 
{
    function<int(int, int)> helper;
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    helper = [&](int i, int k) -> int {
        if (k == 0)
            return 1;
        if (i == 0)
            return arr[i] == k ? 1 : 0;
        if (dp[i][k] != -1)
            return dp[i][k];

        int pick = 0;
        if (arr[i] <= k)
            pick = helper(i - 1, k - arr[i]);
        int notpick = helper(i - 1, k);

        return dp[i][k] = pick || notpick;
    };

    return helper(n - 1, k);
}

int main() 
{
    int n = 4;
    int k = 5;
    vector<int> arr = {1, 2, 3, 4};

    bool exists = subsetSumToK(n, k, arr);

     cout << exists << "\n";

    return 0;
}