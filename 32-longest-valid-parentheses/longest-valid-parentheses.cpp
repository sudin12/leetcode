class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1); // Initialize with a base index

        int max_length = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i); // Update the base index
                } else {
                    max_length = max(max_length, i - stk.top());
                }
            }
        }

        return max_length;
    }
};