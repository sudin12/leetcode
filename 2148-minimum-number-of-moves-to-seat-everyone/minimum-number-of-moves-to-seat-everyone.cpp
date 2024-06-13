class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        // Sort both arrays
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int totalMoves = 0;

        // Calculate the total number of moves required
        for (size_t i = 0; i < seats.size(); ++i) {
            totalMoves += abs(seats[i] - students[i]);
        }

        return totalMoves;
    }
};