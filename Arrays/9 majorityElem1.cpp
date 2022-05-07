class Solution {
public:
    int majorityElement(vector<int>& nums) {
// Brute force: O(n*n), check for evry elem, n count.
// Better: time: O(nlogn), space: O(n)
        map<int,int> m;
        int size = floor(nums.size()/2);
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
            if(m[nums[i]] > size)
                return nums[i];
        }
        return -1;
        
// Optimal: Moore’s Voting Algorithm  O(N), space: O(1)

// 1. Initialize 2 variables: 
            // Count –  for tracking the count of element.
            // Element – for which element we are counting.
// 2. Traverse through nums array..
            // If Count is 0 then initialize the current traversing integer of array as Element .
            // If the traversing integer of array and Element are same increase Count by 1.
            // If they are different decrease Count by 1.
// 3. The integer present in Element is the result we are expecting. 
       
        int count = 0;
        int candidate = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            if(num==candidate) count += 1; 
            else count -= 1; 
        }

        return candidate;
        
    }
};