class Solution {
public:
    int n;
    vector<vector<string>> partition(string s) {
        n=s.size();
        vector<vector<string>> res;
        vector<string> curr;
        backTrack(s,0,1,curr,res);
        return res;
    }

    void backTrack(string& s, int beg, int len, vector<string> curr, vector<vector<string>>& res) {
        if(beg==n) {
            res.push_back(curr);
            return;
        }
        if((beg+len)>n)return;


        backTrack(s,beg,len+1,curr,res);

        if(isPallindrome(s.substr(beg, len))) {
            curr.push_back(s.substr(beg, len));
            backTrack(s, beg+len, 1, curr, res);
        }
    }

    bool isPallindrome(string s){
        int beg=0;int end = s.size()-1;
        while(beg<end){
            if(s[beg]!=s[end])return false;
            beg++;end--;
        }
        return true;
    }
};