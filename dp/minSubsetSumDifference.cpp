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

int minSubsetSumDifference(vector<int>& arr, int n) {
    int sum = accumulate(arr.begin(), arr.end(), 0);
    vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

    for (int i = 0; i < n; i++) 
    {
        dp[i][0] = true;
    }

    if (arr[0] <= sum) 
    {
        dp[0][arr[0]] = true;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= sum; j++) {
            bool notake = dp[i - 1][j];
            bool take = false;
            if (arr[i] <= j) {
                take = dp[i - 1][j - arr[i]];
            }
            dp[i][j] = take || notake;
        }
    }

    int ans = INT_MAX;

    for (int i = 0; i <= sum / 2; i++) {
        if (dp[n - 1][i] == true) {
            int t1 = i, t2 = sum - t1;
            ans = min(ans, abs(t1 - t2));
        }
    }

    return ans;
}

int main() 
{
    ll n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
   

    int minDiff = minSubsetSumDifference(arr, n);

    cout << minDiff << "\n";

    return 0;
}