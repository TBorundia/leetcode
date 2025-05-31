class Solution {
public:
    bool f(vector<int>& a, int t, int k,int index, vector<int> &v){
        if(index >= a.size()){
            for(auto e:v){
                if(e != t) return false;
            }
            return true;
        }

        for(int j=0;j<k;j++){
            if(v[j]+a[index] > t) continue;
            v[j] += a[index];
            if(f(a,t,k,index+1,v)) return true;
            v[j] -= a[index];
            
            if(v[j] == 0) break;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& a, int k) {
        int n = a.size();
        int sum = accumulate(a.begin(), a.end(), 0LL);
        if(sum%k) return false;
        sort(a.rbegin(), a.rend());
        int t = sum/k;
        if(a[0] > t) return false;
        vector<int> v(k,0);
        return f(a,t,k,0,v);
    }
};