class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        string padded = preprocess(s);
        int n = padded.size();
        
        vector<int> palindromeLengths(n, 0);
        int center = 0, right = 0;
        
        for (int i = 1; i < n - 1; ++i) {
            int mirror = 2 * center - i;
            if (i < right) {
                palindromeLengths[i] = min(right - i, palindromeLengths[mirror]);
            }
            
            while (padded[i + (1 + palindromeLengths[i])] == padded[i - (1 + palindromeLengths[i])]) {
                palindromeLengths[i]++;
            }
            
            if (i + palindromeLengths[i] > right) {
                center = i;
                right = i + palindromeLengths[i];
            }
        }
        
        int maxLen = 0, centerIndex = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (palindromeLengths[i] > maxLen) {
                maxLen = palindromeLengths[i];
                centerIndex = i;
            }
        }
        
        return s.substr((centerIndex - maxLen) / 2, maxLen);
    }  
private:
    string preprocess(const string& s) {
        string result = "^";
        for (char c : s) {
            result += "#" + string(1, c);
        }
        result += "#$";
        return result;
    }
};
