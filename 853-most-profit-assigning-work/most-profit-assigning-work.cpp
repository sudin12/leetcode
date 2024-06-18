class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        sort(worker.begin(),worker.end());
        vector<pair<int,int>>v;
        for(int i=0;i<difficulty.size();i++){
            v.push_back({difficulty[i],profit[i]});
        }
        sort(v.begin(),v.end());
        int maxi=0; 
        int bonus=0;
        int i=0;
        for(auto it : worker){
            while(i<v.size() && v[i].first<=it){
                bonus=max(bonus,v[i].second);
                i++;
            }
            maxi+=bonus;
        }
        return maxi;
    }
};