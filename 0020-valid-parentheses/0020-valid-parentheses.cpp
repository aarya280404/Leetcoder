class Solution {
public:
    bool isValid(string s) {
               stack<char> st;

        for (char c : s) {
            // Push opening brackets onto the stack
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                // Check if the stack is empty or the top doesn't match the current closing bracket
                if (st.empty()) return false;

                char top = st.top();
                st.pop();
                
                if ((c == ')' && top != '(') || 
                    (c == ']' && top != '[') || 
                    (c == '}' && top != '{')) {
                    return false;
                }
            }
        }

        // If the stack is empty, all brackets matched properly
        return st.empty();
    
    }
};