class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // use the greedy approch:
        // like first you can sort each array pairs by start time
        // for any day if I have option to select among events. I wil choose the one that ends earlier
        // suppose  we have [{1,1}, {1,4}] then will choose 1,1 first and 2nd one can be done till 4 so we can pick at day 2
        // skip the events whose endDay < currDay
        
        // Sort events by start day
        sort(events.begin(), events.end());

        int n = events.size();
        int i = 0;
        int count = 0;

        // Min-heap stores end days of available events
        priority_queue<int, vector<int>, greater<int>> pq;

        int day = events[0][0];

        while(i < n || !pq.empty()) {

            // If no event is available, jump to the next event's start day
            if(pq.empty()) {
                day = max(day, events[i][0]);
            }

            // Add all events that have started by the current day
            while(i < n && events[i][0] <= day) {
                pq.push(events[i][1]);
                i++;
            }

            // Remove events that have already expired
            while(!pq.empty() && pq.top() < day) {
                pq.pop();
            }

            // Attend the event that ends earliest
            if(!pq.empty()) {
                pq.pop();
                count++;
                day++;
            }
        }

        return count;
    }
};
