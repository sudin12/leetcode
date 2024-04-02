class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;
        
        char s_to_t[256] = {0};
        char t_to_s[256] = {0};
        
        for (int i = 0; i < s.size(); ++i) {
            char s_char = s[i];
            char t_char = t[i];
            
            if (s_to_t[s_char] != 0) {
                if (s_to_t[s_char] != t_char)
                    return false;
            } else if (t_to_s[t_char] != 0) {
                if (t_to_s[t_char] != s_char)
                    return false;
            } else {
                s_to_t[s_char] = t_char;
                t_to_s[t_char] = s_char;
            }
        }
        
        return true;
    }
};