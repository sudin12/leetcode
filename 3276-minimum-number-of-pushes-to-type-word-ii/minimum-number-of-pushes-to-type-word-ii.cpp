class Solution {
public:
    int minimumPushes(string word) {
        vector<int> count(26, 0);
        for (char x : word) {
            int idx = x - 'a';
            count[idx] += 1;
        }

        sort(count.begin(), count.end(), greater<int>());
        
        int ans = 0;
        ans += accumulate(count.begin(), count.begin() + 8, 0) * 1;
        ans += accumulate(count.begin() + 8, count.begin() + 16, 0) * 2;
        ans += accumulate(count.begin() + 16, count.begin() + 24, 0) * 3;
        ans += accumulate(count.begin() + 24, count.end(), 0) * 4;

        return ans;
    }
};