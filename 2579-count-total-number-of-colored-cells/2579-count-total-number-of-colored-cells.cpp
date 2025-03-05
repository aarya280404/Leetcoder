class Solution {
public:
    long long coloredCells(int n) {
        long long left=n*1LL-2,cnt=0;
        while(left>=1){
            cnt+=left;
            left--;
        }

        return cnt*4+((n*1LL-1)*4+1);
    }
};