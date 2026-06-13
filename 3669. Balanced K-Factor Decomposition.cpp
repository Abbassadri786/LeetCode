class Solution {
    int mini = INT_MAX;
    vector<int> best;

private:

    // Update answer if current decomposition has smaller difference
    void check(const vector<int>& curr) {

        int diff = curr.back() - curr.front();

        if(diff < mini) {
            mini = diff;
            best = curr;
        }
    }

    void solve(int n, int k, int start, vector<int>& curr, vector<int>& fact){

        // Chosen exactly k factors
        if(k == 0) {
            // Product must equal original number
            if(n == 1) {
                check(curr);
            }
            return;
        }

        // Try all factors from current index onward
        for(int j = start; j < fact.size(); j++) {
            if(n % fact[j] == 0) {
                curr.push_back(fact[j]);
                // Keep factors in non-decreasing order
                solve(n / fact[j], k - 1, j, curr, fact);
                curr.pop_back();
            }
        }
    }

public:
    vector<int> minDifference(int n, int k) {

        vector<int> curr;
        vector<int> fact;

        // Generate all factors of n
        for(int i = 1; i * i <= n; i++) {
            if(n % i == 0) {
                fact.push_back(i);
                if(i * i != n) {
                    fact.push_back(n / i);
                }
            }
        }

        sort(fact.begin(), fact.end());

        solve(n, k, 0, curr, fact);

        return best;
    }
};
