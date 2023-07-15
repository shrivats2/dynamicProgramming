class Solution {
public:
    
    void dfs(int src,vector<vector<int>>&isConnected,vector<bool>&vis)
    {   vis[src]=true;
        int n=isConnected.size();
        
        for(int j=0;j<n;j++)
        {
            if(!vis[j]&&isConnected[src][j])
            {
                dfs(j,isConnected,vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n=isConnected.size(),ans=0;
        
        vector<bool>vis(n,false);
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
               ans++;
                dfs(i,isConnected,vis);
            }
        }
        return ans;
    }
};