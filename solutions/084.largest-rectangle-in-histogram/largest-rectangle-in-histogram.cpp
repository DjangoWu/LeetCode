class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.push_back(0);
        
        int i = 0, sum = 0;
        while (i < heights.size()) {
            if (st.empty() || heights[i] > heights[st.top()]) {
                st.push(i);
                ++i;
            } else {
                int t = st.top();
                st.pop();
                sum = max(sum, heights[t] * (st.empty() ? i : i - st.top() - 1));
            }
        }
        return sum;
    }
};