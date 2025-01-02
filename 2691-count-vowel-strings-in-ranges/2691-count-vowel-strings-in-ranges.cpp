class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        int m=queries.size();
       string s="aeiou";
        vector<int>result(m);
        vector<int>prefSum(n);
        unordered_set<char>set;
        for(int i=0;i<5;i++){
            set.insert(s[i]);
        }
        int sum=0;
        for(int i=0;i<n;i++){
            if(set.find(words[i][0])!=set.end() && set.find(words[i].back()) !=set.end()){
                sum++;
            }
            prefSum[i]=sum;
        }

        for(int i=0;i<m;i++){
            int l=queries[i][0];
            int r=queries[i][1];

            result[i]=prefSum[r]-(l > 0 ? prefSum[l - 1] : 0);
        }
        return result;
    }
};