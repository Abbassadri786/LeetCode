class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        // Step 1: Count frequency of each task
        vector<int> freq(26,0);
        for(char t : tasks){
            freq[t - 'A']++;
        }

        // Step 2: Max heap to always pick task with highest remaining frequency
        priority_queue<int> pq;
        for(int f : freq){
            if(f > 0) pq.push(f);
        }

        int time = 0; // total time required to execute all tasks

        // Step 3: Process tasks in cycles of length (n + 1)
        // because after executing a task we must wait 'n' intervals
        while(!pq.empty()){
            
            vector<int> temp;  // stores remaining frequencies of tasks used in this cycle
            int cycle = n + 1; // number of slots available in this cycle

            // Fill the cycle with most frequent tasks
            while(cycle > 0 && !pq.empty()){
                int f = pq.top(); 
                pq.pop();

                // After executing the task, decrease its remaining count
                if(f - 1 > 0){
                    temp.push_back(f - 1); // store remaining occurrences
                }

                time++;   // one unit of time spent executing task
                cycle--;  // one slot used
            }

            // Push remaining tasks back into heap for next cycles
            for(int x : temp){
                pq.push(x);
            }

            // If no tasks remain, break (no need to add idle time)
            if(pq.empty()) break;

            // If cycle not fully used, remaining slots are idle times
            time += cycle;
        }

        return time;
    }
};
