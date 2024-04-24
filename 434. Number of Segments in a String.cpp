class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        bool inSegment = false;

        for (char c : s) {
            if (c != ' ') {
                if (!inSegment) {
                    inSegment = true;  // We are entering a new segment
                    ++count;
                }
            } else {
                inSegment = false;  // We are leaving a segment
            }
        }

        return count;
        
    }
};
