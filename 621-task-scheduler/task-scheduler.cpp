class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> taskCount;
        
        // Count the frequency of each task
        for (char task : tasks)
            taskCount[task]++;
        
        // Sort tasks by frequency  
        vector<int> frequencies;
        for (const auto& pair : taskCount)
            frequencies.push_back(pair.second);
            sort(frequencies.begin(), frequencies.end(), greater<int>());
        
        // Find the maximum frequency
        int maxFrequency = frequencies[0];
        
        // Calculate idle time
        int idleTime = (maxFrequency - 1) * n;
        
        // Fill idle time with other tasks
        for (int i = 1; i < frequencies.size(); ++i) {
            idleTime -= min(maxFrequency - 1, frequencies[i]);
        }
        
        // Idle time can't be negative
        idleTime = max(0, idleTime);
        
        // Total time required
        return tasks.size() + idleTime;
    }
};