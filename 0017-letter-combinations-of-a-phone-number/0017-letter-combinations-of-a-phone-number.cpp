class Solution {
public:
    void func(int indx, string &tmp,vector<string> &ans,string &str,map<char,string>m){
        if(indx == str.size()){
            ans.push_back(tmp);
            return;
        }

        string val=m[str[indx]];

        for(int i=0;i<val.size();i++){
            tmp.push_back(val[i]);
            func(indx+1,tmp,ans,str,m);
            tmp.pop_back();
        }
        
       
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0) return ans;
        map<char,string>m;
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";
          
       
        string res="";
        func(0,res,ans,digits,m);
        return ans;
    }
};