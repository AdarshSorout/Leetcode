class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
        return {};

        unordered_map<int,string>mp;
         mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

       vector<string>res;
       res.push_back("");

       for (int i = 0; i < digits.size(); i++) {
            char digit = digits[i];       
            string letters = mp[digit];    
            vector<string> temp;         

            for (int j = 0; j < res.size(); j++) {         
                for (int k = 0; k < letters.size(); k++) { 
                    temp.push_back(res[j] + letters[k]);   
                }
            }

            res = temp;
        }
               
return res;
    }
};