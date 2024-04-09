class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int value = tickets[k];
        int seconds = 0;

        for(int i = 0; i < tickets.size(); i++){
            int max = (i <= k)? value: value - 1;
            seconds += (tickets[i] > max)? max: tickets[i];
        }

        return seconds;
    
    }
};