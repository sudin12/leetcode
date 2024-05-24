class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();
        int res = 0;

        // count letters
        vector<int> letters_count(26, 0);
        for (char letter : letters) {
            int ind = letter - 'a';
            letters_count[ind] += 1;
        }

        // calculate words
        unordered_map<string, int> words_scores;
        for (string word : words) {
            int s = 0;
            for (char c : word) {
                int ind = c - 'a';
                s += score[ind];
            }
            words_scores[word] = s;
        }

        for (int mask = 0; mask < (1 << n); ++mask) { // There will be exactly 2^n different states
            vector<int> cur_count(26, 0);
            bool can_create = true;
            int cur_score = 0;

            for (int word_ind = 0; word_ind < n; ++word_ind) {
                if (mask & (1 << word_ind)) { // if in mask bit of this word is 1
                    string word = words[word_ind];
                    cur_score += words_scores[word];
                    for (char c : word) {
                        int ind = c - 'a';
                        cur_count[ind] += 1;
                        if (cur_count[ind] > letters_count[ind]) {
                            can_create = false;
                            break;
                        }
                    }
                }
                if (!can_create) {
                    break;
                }
            }
            if (can_create && cur_score > res) {
                res = cur_score;
            }
        }

        return res;
    }
};