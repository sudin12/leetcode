class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.empty()) return result;
        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string current = "";
        generateCombinations(result, digits, mapping, current, 0);
        return result;
    }
    
    void generateCombinations(vector<string>& result, string& digits, vector<string>& mapping, string& current, int index) {
        if(index == digits.length()) {
            result.push_back(current);
            return;
        }
        string letters = mapping[digits[index] - '0'];
        for(char c : letters) {
            current.push_back(c);
            generateCombinations(result, digits, mapping, current, index + 1);
            current.pop_back();
        }
    }
};