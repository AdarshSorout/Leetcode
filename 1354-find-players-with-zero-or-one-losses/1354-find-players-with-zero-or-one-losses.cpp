class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> lost_map;
        vector<int> never_lost;
        vector<int> lost_once;

        for (auto& loser : matches) {
            lost_map[loser[1]]++; 
        }

       for(int i=0;i<matches.size();i++){
        int winner=matches[i][0];
        int loser=matches[i][1];

        if(lost_map.find(winner)==lost_map.end()){
            never_lost.push_back(winner);
            lost_map[winner]=3;
        }
        if(lost_map[loser]==1){
            lost_once.push_back(loser);
        }
       }
sort(begin(lost_once),end(lost_once));
sort(begin(never_lost),end(never_lost));
        return {never_lost, lost_once}; 
    }
};