class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>unique;
        unordered_set<int>st;
        for(auto&no:arr){
            unique[no]++;
        }
        for(auto&duplicate:unique){
           int freq=duplicate.second;
           if(st.find(freq)!=st.end()){
            
            return false;

           }
           st.insert(freq);
        }
        return true;
    }
};