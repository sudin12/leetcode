class Solution {
public:
    int countSeniors(vector<string>& details) {
        int seniorCount = 0;
        
        for (string& passengerInfo : details) {
            int age = stoi(passengerInfo.substr(11, 2));

            if (age > 60) {
                seniorCount++;
            }
        }

        return seniorCount;
    }
};