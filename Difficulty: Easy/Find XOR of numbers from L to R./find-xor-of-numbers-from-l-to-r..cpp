//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
  
    int helper(int x){
        if(x%4==0) return x;
        if(x%4==1) return 1;
        if(x%4==2) return x+1;
        if(x%4==3) return 0;
    }
    int findXOR(int l, int r) {
        // complete the function here
        return helper(l-1)^helper(r);
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        // Input

        int l, r;
        cin >> l >> r;

        Solution obj;
        cout << obj.findXOR(l, r) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends