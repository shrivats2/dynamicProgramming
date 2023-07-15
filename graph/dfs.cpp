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


int main()
{
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> ans;
    vector<bool> visited(V, false);

    function<void(int)> dfs = [&](int i) 
    {
        visited[i] = true;
        ans.push_back(i);

        for (int it : adj[i])
        {
            if (!visited[it])
                dfs(it);
        }
    };

    dfs(0);

    for (auto vertex : ans)
        cout << vertex << " ";

    return 0;
}
