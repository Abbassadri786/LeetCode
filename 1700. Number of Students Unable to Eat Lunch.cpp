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

// Approach 2: Counting 1 & 0
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        int cntOne = 0;
        int cntZero = 0;
        
        for(int i=0; i<n; i++){
            if(students[i] == 1) cntOne++;
            else{
                cntZero++;
            }
        }

        for(int sandwich : sandwiches){
            if(sandwich == 1 && cntOne == 0) return cntZero;
            if(sandwich == 0 && cntZero == 0) return cntOne;
            
            if(sandwich == 1){
                cntOne--;
            }else{
                cntZero--;
            }
        }
        return 0;
    }
};
