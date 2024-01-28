class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndexMap;
        int maxLength = 0, start = -1;
        
        for (int i = 0; i < s.length(); ++i) {
            if (charIndexMap.find(s[i]) != charIndexMap.end() && charIndexMap[s[i]] > start) {
                start = charIndexMap[s[i]];
            }
            charIndexMap[s[i]] = i;
            maxLength = max(maxLength, i - start);
        }
        
        return maxLength;
    }
};
