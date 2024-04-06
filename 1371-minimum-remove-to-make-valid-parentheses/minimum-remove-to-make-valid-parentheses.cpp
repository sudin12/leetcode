class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        int balance = 0;

        // First pass: remove invalid closing parentheses
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                ++balance;
            } else if (s[i] == ')') {
                if (balance == 0) {
                    s[i] = '*'; // Mark invalid closing parenthesis
                } else {
                    --balance;
                }
            }
        }

        // Second pass: remove unmatched opening parentheses
        balance = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == ')') {
                ++balance;
            } else if (s[i] == '(') {
                if (balance == 0) {
                    s[i] = '*'; // Mark invalid opening parenthesis
                } else {
                    --balance;
                }
            }
        }

        // Remove marked parentheses
        string result;
        for (char c : s) {
            if (c != '*') {
                result.push_back(c);
            }
        }

        return result;
    }
};