
class Solution {
public:
// App. 1: Time: O(n*n)
    int maxSubArray(vector<int>& nums) {
        int finalSum = INT_MIN;
        for(int i=0;i<nums.size()-1;i++){
            int tempSum=nums[i];
            for(int j=i+1;j<nums.size();j++){
               tempSum = tempSum + nums[j];
                if(tempSum > finalSum)
                    finalSum = tempSum;
            }
        }
        return finalSum;
    }

// Optimised: O(n) Time
// Kadane's Algo: We will get maximum until sum of elements is +ve, and as soon as it goes -ve, we assign 0 to sum.

    int maxSubArray(vector<int>& nums) {    
        int sum = 0, maxi = INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            maxi = max(sum,maxi);
            if(sum < 0)
                sum = 0;
        }
        return maxi;
    }
};