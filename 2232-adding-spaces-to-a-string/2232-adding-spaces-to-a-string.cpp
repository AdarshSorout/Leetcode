class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        stringstream ss;
        int posIdx=0;
        int n=s.size();
        int m =spaces.size();
        for(int i=0;i<n;i++){
             
            if(posIdx<m && i==spaces[posIdx]){
              ss <<' ';
              posIdx++;
               
            }
             ss <<s[i];
        }
        return ss.str();
    }
};