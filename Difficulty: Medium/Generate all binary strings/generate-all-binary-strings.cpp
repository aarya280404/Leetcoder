//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    
    void generate(vector<string> &ans,int indx,string str,int num){
        
        if(num == indx){
            ans.push_back(str);
            return;
        }
        
        if (indx == 0 || str[indx - 1] == '0') {
            generate(ans, indx + 1, str + '0', num);
            generate(ans, indx + 1, str + '1', num);
        } else if (str[indx - 1] == '1') {
            generate(ans, indx + 1, str + '0', num);
        }
    }
    vector<string> generateBinaryStrings(int num){
        //Write your code
        vector<string> ans1;
        string res="";
        generate(ans1,0,res,num);
        return ans1;
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        
        vector<string> v = obj.generateBinaryStrings(n);
        for(auto it:v) cout<<it<<" ";
        cout << endl;
    
cout << "~" << "\n";
}

    return 0;
}

// } Driver Code Ends