class Solution {
public:
int n;
void dfs(unordered_map<int,vector<int>>&adj,int node, vector<bool>&visited){
    visited[node]=true;
    for(int neighbor:adj[node]){
if(!visited[neighbor]){
    dfs(adj,neighbor,visited);
}
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        n=isConnected.size();
      vector<bool>visited(n,false);

      unordered_map<int,vector<int>>adj;

      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(isConnected[i][j]==1){
               adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
      }
    int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
               dfs(adj,i,visited);
              count++; 
            }
        }

      
return count;
    }
};