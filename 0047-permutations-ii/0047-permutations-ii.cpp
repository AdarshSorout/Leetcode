class Solution {
public:
int n;
vector<vector<int>>result;
void solve( vector<int>&temp,unordered_map<int, int>& mp){
    if(temp.size()==n){
        result.push_back(temp);
        return ;
    }
    for(auto&[key,value]:mp){
        if(value==0){
            continue;
        }

        temp.push_back(key);
        mp[key]--;
        solve(temp,mp);
        temp.pop_back();
        mp[key]++;
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       n=nums.size();
       unordered_map<int,int>mp;
       for(int i=0;i<n;i++){
        mp[nums[i]]++;
       } 
       vector<int>temp;
       solve(temp,mp);
       return result;
    }
};