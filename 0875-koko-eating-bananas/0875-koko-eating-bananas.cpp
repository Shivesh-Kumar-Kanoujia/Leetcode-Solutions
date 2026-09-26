class Solution {
public:
    int findMax(vector<int>& v) {
        int maxi = INT_MIN;

        for (int i = 0; i < v.size(); i++) {
            maxi = max(maxi, v[i]);
        }

        return maxi;
    }

    long long CalculateHours(vector<int>& v, int hours) {
        long long totalHrs = 0;

        for (int i = 0; i < v.size(); i++) {
            totalHrs += ceil((double)v[i] / hours);
        }

        return totalHrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findMax(piles);

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long totalH = CalculateHours(piles, mid);

            if (totalH <= h) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};