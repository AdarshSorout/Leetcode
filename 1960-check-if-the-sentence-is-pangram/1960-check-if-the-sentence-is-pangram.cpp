class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int>letters(26,0);
        int count=0;
        for(int i=0;i<sentence.size();i++){
            if(letters[sentence[i]-'a']==0){ 
                      letters[sentence[i]-'a']++;
                count++;}
      
             


        }
       
        if(count==26)
        return true;

   return false;     
    }
};