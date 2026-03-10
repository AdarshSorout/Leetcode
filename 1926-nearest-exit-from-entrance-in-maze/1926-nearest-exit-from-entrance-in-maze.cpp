class Solution {
public:
 vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size();
        int m=maze[0].size();
      queue<pair<int,int>>q;
      q.push({entrance[0],entrance[1]});
      maze[entrance[0]][entrance[1]]='+';
      
      int steps=0;

      while(!q.empty()){
        int N=q.size();

        while(N--){
            pair<int,int>temp=q.front();
            q.pop();

            int i=temp.first;
            int j=temp.second;

            if(temp!=make_pair(entrance[0],entrance[1]) && 
            (i==0 || i==n-1 || j==0 || j==m-1)){
                return steps;
            } 
  
  for(auto &dir: directions){
    int i=temp.first + dir[0];
    int j=temp.second +dir[1];

    if (i>=0 && i<n && j>=0 && j<m && maze[i][j]!='+'){
        q.push({i,j});

        maze[i][j]='+';

    }
  }

        }
        steps++;
      }
      return -1;
    }
};