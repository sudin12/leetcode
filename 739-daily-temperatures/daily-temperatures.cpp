class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size(), 0);
        stack<int> stack;
        
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!stack.empty() && temperatures[i] > temperatures[stack.top()]) {
                int prevIndex = stack.top();
                stack.pop();
                answer[prevIndex] = i - prevIndex;
            }
            stack.push(i);
        }
        
        return answer;
    }
};
