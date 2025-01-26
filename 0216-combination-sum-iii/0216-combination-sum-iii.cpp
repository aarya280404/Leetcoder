class Solution {
public:
    void func(int i,int sum,vector<int> &tmp,int k,int n,vector<vector<int>>&ans){

        
        if(k<0) return;
        if(k==0) {
            if(sum == n){
                ans.push_back(tmp);
            }             
            return;
        }
        if(i == 10) return;
        tmp.push_back(i);
        func(i+1,sum+i,tmp,k-1,n,ans);
        tmp.pop_back();
        func(i+1,sum,tmp,k,n,ans);
    
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int>tmp;
        func(1,0,tmp,k,n,ans);
        return ans;
    }
};
