// Approach 1: Using stack and queue
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        queue<int> studentQueue;
        stack<int> sandwichStack;

        for(int i=0; i<n; i++){
            studentQueue.push(students[i]);
            //push into sandwich stack form back
            sandwichStack.push(sandwiches[n-1-i]);
        }

        int missed = 0;
        while(!studentQueue.empty()){
          // If same entity found on top of queue and satck than pop both, sandwich can be eaten
            if(studentQueue.front() == sandwichStack.top()){
                studentQueue.pop();
                sandwichStack.pop();
                missed = 0; // reset missed sandwiches
            }
            else{
              // if both diff then push that student in back queue
                studentQueue.push(studentQueue.front());
                studentQueue.pop();
                missed++;
                if(missed == studentQueue.size()) break;
            }
        }
        // if remaining student will be in queue
        return studentQueue.size();
    }
};
