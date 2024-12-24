class Solution {
public:
int n;
int dp[2002][2002];
unordered_map<int,int>mp;
bool f(vector<int>&a,int curr_idx,int pJump){
    if(curr_idx==n-1)
    return true;
    if(dp[curr_idx][pJump]!=-1){
        return dp[curr_idx][pJump];
    }
    bool result=false;
    for(int nJump=pJump-1;nJump<=pJump+1;nJump++){
        if(nJump>0){
            int next_stone=a[curr_idx]+nJump;
            if(mp.find(next_stone)!=mp.end()){
                result=result||f(a,mp[next_stone],nJump);
            }
        }
    }
return dp[curr_idx][pJump]=result;
   
}
    bool canCross(vector<int>& stones) {
        n=stones.size();
        int m=stones[n-1];
        memset(dp,-1,sizeof(dp));
        if(stones[1]!=1){
            return false;
        }
        for(int i=0;i<n;i++){
            mp[stones[i]]=i;
        }
       return  f(stones,0,0);
    }
};