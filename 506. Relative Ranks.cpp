class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int, int>> scorePairs;
        for (int i = 0; i < score.size(); ++i) {
            scorePairs.emplace_back(score[i], i);
        }
        sort(scorePairs.rbegin(), scorePairs.rend());

        vector<string> result(score.size());
        for (int i = 0; i < scorePairs.size(); ++i) {
            if (i == 0) result[scorePairs[i].second] = "Gold Medal";
            else if (i == 1) result[scorePairs[i].second] = "Silver Medal";
            else if (i == 2) result[scorePairs[i].second] = "Bronze Medal";
            else result[scorePairs[i].second] = to_string(i + 1);
        }
        return result;
    }
};
