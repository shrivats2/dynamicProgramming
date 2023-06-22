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

int findWays(vector<int>& arr, int tar) {
    int n = arr.size();

    vector<vector<int>> dp(n + 1, vector<int>(tar + 1, -1));

    function<int(int, int)> helper = [&](int i, int k) {
        if (i < 0) {
            return k == 0 ? 1 : 0;
        }
        if (dp[i][k] != -1) {
            return dp[i][k];
        }

        int notake = helper(i - 1, k);
        int take = 0;
        if (arr[i] <= k) {
            take = helper(i - 1, k - arr[i]);
        }

        return dp[i][k] = take + notake;
    };

    return helper(n - 1, tar);
}

int main() 
{
    ll n,tar;
    cin >> n>> tar;

    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ways = findWays(arr, tar);

    cout << ways << endl;

    return 0;
}