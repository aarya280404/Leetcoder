class Solution {
public:
    void func(int indx,int target,vector<int> &tmp,vector<int> &a,vector<vector<int>> &ans){
        if(indx == a.size()){
            if(target == 0){
                ans.push_back(tmp);
            }
            return;
        }


        if(a[indx] <= target){
            tmp.push_back(a[indx]);
            func(indx,target-a[indx],tmp,a,ans);
            tmp.pop_back();

        }
        
        func(indx+1,target,tmp,a,ans);        

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>tmp;
        func(0,target,tmp,candidates,ans);
        return ans;
    }
};