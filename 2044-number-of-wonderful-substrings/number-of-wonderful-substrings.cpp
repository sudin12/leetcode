class Solution {
public:
    typedef long long l;

    long long wonderfulSubstrings(string word) {
        unordered_map<l, l> map;

        map[0] = 1;
        int sum = 0;
        l result = 0;

        for (char& ch : word) {
            int shift = ch - 'a';
            sum ^= (1 << shift);
            result += map[sum];

            for (char ch1 = 'a'; ch1 <= 'j'; ch1++) {
                shift = ch1 - 'a';
                l check = (sum ^ (1 << shift));
                result += map[check];
            }
            map[sum]++;
        }
        return result;
    }
};