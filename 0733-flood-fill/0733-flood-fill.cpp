class Solution {
public:
vector<vector<int>>directions{{0,1},{1,0},{0,-1},{-1,0}};

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int temp=image[sr][sc];
       
       if(image[sr][sc]==color){
        return image;
       }
        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc]=color;
       
       while(!q.empty()){
        auto curr=q.front();
        q.pop();

        int i=curr.first;
        int j=curr.second;

        for(auto &dir:directions){
            int new_i=i+dir[0];
            int new_j=j+dir[1];

            if(new_i>=0 && new_j>=0 && new_i<n && new_j<m && 
            image[new_i][new_j] == temp){
                image[new_i][new_j]=color;
                q.push({new_i,new_j});
            }
        }

       }
       return image;
    }
};