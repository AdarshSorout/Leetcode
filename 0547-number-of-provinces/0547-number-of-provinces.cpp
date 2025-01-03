class Solution {
public:
int n;
void bfs(vector<vector<int>>& isConnected,int u,vector<bool>&visited){
    queue<int>q;
    q.push(u);
    visited[u]=true;
     while(!q.empty()){
            int u=q.front();
            q.pop();

            for(int v=0;v<n;v++){
                if(!visited[v] && isConnected[u][v]==1){
                    q.push(v);
                    visited[v]=true;
                   

                }
            }
        }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        n=isConnected.size();
        vector<bool>visited(n,false);
        unordered_map<int,vector<int>>adj;

       
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                bfs(isConnected,i,visited);
                count++;
            }
        }
        return count;
    }
};