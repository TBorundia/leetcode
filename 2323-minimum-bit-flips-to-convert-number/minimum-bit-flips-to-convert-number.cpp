class Solution {
public:
    int minBitFlips(int start, int goal) {
        int Xor=start^goal;
        int cnt=0;
        while(Xor!=0){
            cnt+=(Xor&1);
            Xor=Xor>>1;
        }
        return cnt;
    }
};