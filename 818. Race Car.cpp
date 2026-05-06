class Solution {
public:
    int racecar(int target) {
        queue<pair<int,pair<int,int>>> q; // (position, (speed, count of instructions))
        q.push({0,{1,0}}); // Initial position
        
        while(!q.empty()){
            int pos = q.front().first;
            int speed = q.front().second.first;
            int count = q.front().second.second; // Instruction count so far
            q.pop();
            
            // If we reach the target, return the number of instructions
            if(pos == target) {
                return count;
            }
            
            // Pruning the state space
            // we're moving forward, skip this state
            if(pos >= 2*target && pos > 0 && speed > 0) {
                continue;
            }
            
            // we're moving backward, skip this state
            if(pos <= 2*target && pos < 0 && speed < 0) {
                continue;
            }

            // Accelerate: Move position += speed, double speed, increment instruction count
            q.push({pos + speed, {speed * 2, count + 1}});

            // Reverse: Change direction, set speed to 1 or -1 depending on the sign of speed
            if((pos + speed) < target && speed < 0) {
                q.push({pos, {1, count + 1}}); // Reverse to go forward
            } else if((pos + speed) > target && speed > 0) {
                q.push({pos, {-1, count + 1}}); // Reverse to go backward
            }
        }
        return 0;
    }
};
