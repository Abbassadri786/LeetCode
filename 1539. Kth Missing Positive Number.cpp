class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int missingCount = 0;
        int lastChecked = 0;

        for (int num : arr) {
            // Count the missing numbers between lastChecked + 1 and num - 1
            while (lastChecked + 1 < num) {
                missingCount++;
                lastChecked++;
                if (missingCount == k) {
                    return lastChecked;
                }
            }
            lastChecked = num;
        }

        
        return lastChecked + (k - missingCount);
    }
};

// Using Binary Search
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0, high = n-1;

        while(low <= high){
            int mid = (low + high)/2;
            int missing = arr[mid] - (mid + 1);
            if(missing < k){
                low = mid + 1;
            }
            else{
                high = mid -1;
            }
        }

        return low + k;
    }
};
