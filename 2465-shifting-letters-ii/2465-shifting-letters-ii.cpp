class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int>pf(n+1,0);
        for(auto &it : shifts){
            if(it[2]==0){
            pf[it[0]]--,pf[1+it[1]]++;
            }
            else {pf[it[0]]++,pf[1+it[1]]--;}
        }
        for(int i=1;i<=n;++i){
            pf[i]+=pf[i-1];
        }
        int x = 0 ; char c = 'a' ;
        for(int i =0 ;i<n;i++){
            x = pf[i]%26;
            c = char('a'+(26+s[i]-'a'+x)%26);
            s[i]=c;
        }
        return s;
    }
};