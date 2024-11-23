class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int maxRows=0;

        for(auto & currRow :matrix){
              vector<int>invert(n);
              for(int col=0;col<n;col++){
                invert[col]=currRow[col]==0 ? 1:0;
              }
              int count=0;
        for(auto& row:matrix){
            if(row==currRow||row==invert){
                count++;
            }
        }
        maxRows=max(count,maxRows);
        }
        return maxRows;
        
    }
};