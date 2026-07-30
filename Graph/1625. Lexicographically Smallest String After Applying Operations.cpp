class Solution {
public:
    void rotate(string &s, int b){
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin() + b);
        reverse(s.begin() + b, s.end());
    }
    string findLexSmallestString(string s, int a, int b) {
        // using BFS traversal logic , first initialize empty unordered_set and push string to controll visited
        //then in while loop(!q.empty()) keep on adding 'a' on odd pos if sum > 9 then do modulo 10 and then keep on rotating before that keep updateing smallest String
        string smallString = s;
        unordered_set<string> visited;
        queue<string> q;
        q.push(s);
        visited.insert(s);

        while(!q.empty()){
            string curr = q.front();
            q.pop();

            if(curr < smallString){
                smallString = curr;
            }

            // Now addition at odd pos
            string tmp = curr;
            for(int i=1; i<tmp.size(); i+=2){
                tmp[i] = (tmp[i]-'0' + a)%10 + '0';
            }

            if(!visited.count(tmp)){
                visited.insert(tmp);
                q.push(tmp);
            }

            // now rotate tmp right by b
            rotate(curr, b);
            if(!visited.count(curr)){
                visited.insert(curr);
                q.push(curr);
            }
        }

        return smallString;
    }
};
