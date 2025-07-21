class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.length();
        if (s==goal) return true;
        
        for(int i=1;i<s.length();i++){
            string r=s.substr(i,n)+s.substr(0,i);
            if(r==goal) return true;
        }
      return false; 
    }
};