class Solution {
public:
string rotate(string s, int k){
    if(k==0){
        return s;
    }
       char a=s[0];
        int n=s.size();
       
for(int i=1;i<n;i++){
    s[i-1]=s[i];
}
s[n-1]=a;
return rotate(s,k-1);

}
    bool rotateString(string s, string goal) {
        char a=s[0];
        int n=s.size();
        if(n!=goal.size()){
            return false;
        }
     int k;
     for(int i=0;i<n;i++){
        if(s[0]==goal[i]){
            k=n-i+1;
        }
     }
   
     for(int i=0;i<n;i++){
      if(s==goal){
        return true;
       
     }
      s=rotate(s,1);
     }
    
     return false;
    }
};