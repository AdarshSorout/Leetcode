class Solution {
public:

    int numPairsDivisibleBy60(vector<int>& time) {
       int count=0;
       int complement;
       int n=time.size();
       vector<int>results(60,0);
       for(int i=0;i<n;i++){
int remainder=time[i]%60;
if(remainder==0){
    complement=0;
}
else{
    complement=60-remainder;
}
 count += results[complement];
 results[remainder]++;
       }
            return count;
    }
};