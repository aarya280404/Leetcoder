//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    void print_divisors(int n) {
        // Code here.
        vector<int> ans;
        for(int i=1;i<=sqrt(n);i++){
            if(n%i==0 && i!=sqrt(n)){
                ans.push_back(i);
                ans.push_back(n/i);
            }
            if(i==sqrt(n)) ans.push_back(i);
        }
        sort(ans.begin(),ans.end());
        for(auto it:ans) cout<<it<<" ";
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Solution ob;
        ob.print_divisors(n);
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends