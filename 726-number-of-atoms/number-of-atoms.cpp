class Solution {
public:
    string countOfAtoms(string formula) {
        stack<unordered_map<string, int>> stk;
        stk.push({}); // Initialize with an empty map
        
        int i = 0, n = formula.length();
        
        while (i < n) {
            if (formula[i] == '(') {
                // Push a new empty map for the new level of nesting
                stk.push({});
                i++;
            } else if (formula[i] == ')') {
                // Pop the top map and handle the multiplier
                unordered_map<string, int> top = stk.top();
                stk.pop();
                i++;
                int start = i;
                while (i < n && isdigit(formula[i])) {
                    i++;
                }
                int multiplier = start < i ? stoi(formula.substr(start, i - start)) : 1;
                for (auto& kv : top) {
                    stk.top()[kv.first] += kv.second * multiplier;
                }
            } else {
                // Handle the element and its count
                int start = i++;
                while (i < n && islower(formula[i])) {
                    i++;
                }
                string element = formula.substr(start, i - start);
                start = i;
                while (i < n && isdigit(formula[i])) {
                    i++;
                }
                int count = start < i ? stoi(formula.substr(start, i - start)) : 1;
                stk.top()[element] += count;
            }
        }
        
        // Prepare the result map
        unordered_map<string, int> result = stk.top();
        vector<string> elements;
        for (auto& kv : result) {
            elements.push_back(kv.first);
        }
        sort(elements.begin(), elements.end());
        
        // Build the result string
        string res;
        for (const auto& element : elements) {
            res += element;
            if (result[element] > 1) {
                res += to_string(result[element]);
            }
        }
        
        return res;
    }
};