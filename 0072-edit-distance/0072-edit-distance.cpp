class Solution {
public:
int dp[502][502];
int f(int i,int j,string s1,string s2){
    if(i<0)
    return j+1;
    if (j<0)
    return i+1;
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s1[i]==s2[j]){
        return dp[i][j]=f(i-1,j-1,s1,s2);
    }
    return dp[i][j]= 1+min(f(i-1,j,s1,s2),min(f(i-1,j-1,s1,s2),f(i,j-1,s1,s2)));
}
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
       memset(dp,-1,sizeof(dp));
        return f(n-1,m-1,word1,word2);
    }
};