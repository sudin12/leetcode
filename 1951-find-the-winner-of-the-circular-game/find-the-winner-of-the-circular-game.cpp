class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = i+1;
        }
        int start = 0;
        while (a.size() > 1) {
            start = (start + (k - 1)) % a.size();
            a.erase(a.begin() + start);
            if (start == a.size()) start = 0;
        }
        return a[0];
    }
};