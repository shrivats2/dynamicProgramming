class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int node, vector<int>& safe) 
    {
        if (safe[node] != 0)
            return safe[node] == 1;
        safe[node] = 2;//not safe
        for (int next : graph[node]) 
        {
            if (!dfs(graph, next, safe))
                return false;
        }
        safe[node] = 1; 
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> safe(n, 0);
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if (dfs(graph, i, safe))
                ans.push_back(i);
        }

        return ans;
    }
};
