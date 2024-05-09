class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long sum= 0 , diff=0 ; 
        sort(happiness.begin() , happiness.end(),greater<int>());
        int n = happiness.size();
       for(int i=0 ; i<k ; i++)
       {
           if(happiness[i] > diff)
           {
               sum += happiness[i] - diff;
           }
           diff++;
       }
        return sum;
    }
};