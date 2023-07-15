class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>col(n,-1);
        function<bool(int)>bfs=[&](int node){
          queue<int>q;
          col[node]=0;
          q.push(node);

          while(!q.empty()){
              int m=q.front();
              q.pop();
              for(auto i:graph[m])
              {
                  if(col[i]==-1)
                  {
                      col[i]=1-col[m];
                      q.push(i);
                  }
                  else if(col[i]==col[m])
                  {
                      return false;
                  }
              }
          }
          return true;
        };

        for(int i=0;i<n;i++)
        {
            if(col[i]==-1)
            {
                if(!bfs(i))
                {
                    return false;
                }
            }
        }
        return true;
    }
};