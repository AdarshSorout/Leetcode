class Solution {
public:
bool checkBipartite(vector<vector<int>>& graph,int curr,vector<int>&color,int currColor){
    color[curr]=currColor;

    for(int &v:graph[curr]){
        if(color[v]==color[curr]){
            return false;
        }
        if(color[v]==-1){
            int colorOfV=1-currColor;
            if( checkBipartite(graph,v,color,colorOfV)==false){
                return false;
            }
        }
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>color(V,-1);

        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(checkBipartite(graph,i,color,1)==false)
                return false;
            }
        }
        return true;
    }
};