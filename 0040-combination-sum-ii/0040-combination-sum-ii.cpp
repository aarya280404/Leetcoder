

class Solution {
public:
    void func(int indx,int target,vector<int> &tmp,vector<int> &a,vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(tmp);
            return;
        }     

        for(int i=indx;i<a.size();i++){
            if(i > indx && a[i] == a[i-1]) continue;
            if(a[i]>target) break;
           
            tmp.push_back(a[i]);
            func(i+1,target-a[i],tmp,a,ans);
            tmp.pop_back();
            
        }    

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>tmp;
        sort(candidates.begin(),candidates.end());
        func(0,target,tmp,candidates,ans);
        return ans;
    }
};