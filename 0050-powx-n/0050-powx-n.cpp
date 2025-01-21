class Solution {
public:
    double myPow(double x, int n) {
        long long nn=n;
        double xx=x;
        double ans=1;
        if(nn<0) nn=(-1)*nn;

        while(nn != 0){
            if(nn%2 == 0){
                nn=nn/2;
                xx=xx*xx;
            }
            //odd power
            else{
                nn--;
                ans=ans*xx;
            }
        }

        if(n<0) ans=(1.0)/ans;
        return ans;
    }
};