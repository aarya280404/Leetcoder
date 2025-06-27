class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st; // stores indices
        int water = 0;
        int n = height.size();

        for (int i = 0; i < n; ++i) {
            // While current bar is higher than the bar at top stack
            while (!st.empty() && height[i] > height[st.top()]) {
                int top = st.top();
                st.pop();

                if (st.empty()) break;

                int distance = i - st.top() - 1;
                int bounded_height = min(height[i], height[st.top()]) - height[top];
                water += distance * bounded_height;
            }
            st.push(i);
        }
        return water;
    }
};
