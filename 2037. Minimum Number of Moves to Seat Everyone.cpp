class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        // Sort both the seats and students arrays
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int minMoves = 0;
        // Calculate the total number of moves required
        for (int i = 0; i < seats.size(); ++i) {
            minMoves += abs(seats[i] - students[i]);
        }

        return minMoves;
    }
};
