class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> freq;

        // Count frequency of characters in string s
        for (char c : s) {
            freq[c]++;
        }

        string result = "";

        // Append characters from order to result based on their frequency in s
        for (char c : order) {
            if (freq.find(c) != freq.end()) {
                result += string(freq[c], c);
                freq.erase(c);
            }
        }

        // Append remaining characters from s to result
        for (auto& pair : freq) {
            result += string(pair.second, pair.first);
        }

        return result;
    }
};
