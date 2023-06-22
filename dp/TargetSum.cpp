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

int findTargetSumWays(vector<int>& arr, int target) {
    int sum = 0, n = arr.size();
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    if (sum - target < 0 || (sum - target) % 2) {
        return 0;
    }

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));

    function<int(int, int)> helper = [&](int idx, int k) {
        if (idx == 0) {
            if (k == 0 && arr[0] == 0)
                return 2;
            if (k == 0 || k == arr[0])
                return 1;
            return 0;
        }
        if (dp[idx][k] != -1) {
            return dp[idx][k];
        }

        int notake = helper(idx - 1, k);
        int take = 0;
        if (arr[idx] <= k) {
            take = helper(idx - 1, k - arr[idx]);
        }

        return dp[idx][k] = (take + notake);
    };

    long int ans = helper(n - 1, (sum - target) / 2);

    return ans;
}

int main() {
    ll n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;
    cin >> target;

    int ways = findTargetSumWays(arr, target);
    cout << ways<<"\n";

    return 0;
}
