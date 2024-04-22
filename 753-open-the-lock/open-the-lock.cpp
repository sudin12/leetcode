class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadends_set(deadends.begin(), deadends.end());
        if (deadends_set.find("0000") != deadends_set.end())
            return -1;

        queue<pair<string, int>> q;
        q.push({"0000", 0});

        while (!q.empty()) {
            auto [current, turns] = q.front();
            q.pop();

            if (current == target)
                return turns;

            for (int i = 0; i < 4; ++i) {
                for (int inc : {-1, 1}) {
                    string next_state = current;
                    next_state[i] =
                        ((next_state[i] - '0' + inc + 10) % 10) + '0';

                    if (deadends_set.find(next_state) == deadends_set.end()) {
                        deadends_set.insert(next_state);
                        q.push({next_state, turns + 1});
                    }
                }
            }
        }

        return -1;
    }
};