
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long long low = *max_element(nums.begin(), nums.end());
        long long high = 0;

        for (int x : nums) {
            high += x;
        }

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            int subarrays = 1;
            long long sum = 0;

            for (int x : nums) {
                if (sum + x <= mid) {
                    sum += x;
                } else {
                    subarrays++;
                    sum = x;
                }
            }

            if (subarrays <= k) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return (int)low;
    }
};
