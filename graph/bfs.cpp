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

vector<int> bfs(int V, vector<int> adj[])
{
    queue<int> q;
    q.push(0);
    vector<int> traversal;
    vector<bool> visited(V, false);
    visited[0] = true;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        traversal.push_back(curr);

        for (auto it : adj[curr])
        {
            if (!visited[it])
            {
                visited[it] = true;
                q.push(it);
            }
        }
    }

    return traversal;
}

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
    }

    vector<int> bfsTraversal = bfs(V, adj);

    for (auto vertex : bfsTraversal)
        cout << vertex << " ";

    return 0;
}
