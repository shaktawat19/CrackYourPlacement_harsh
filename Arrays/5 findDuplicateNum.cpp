https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // O(nlogn) + O(n)
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] == nums[i+1])
                return nums[i];
        }
        return 0;
        
        // Approach 2: Hashing O(n)
        vector<int> freq(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
            if( freq[nums[i]] == 2)
                return nums[i];
        }
        return 0;
        
        
        // App. 3: Linked-list cycle method. O(n)
        
        // initialy both points to first elem.
        int slow = nums[0];
        int fast = nums[0];
        do{ // slow moves 1-step n fast 2-steps,until collide.
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        
        fast = nums[0]; // Now, put fast at first place
        
        while(slow != fast){ //  Both move by 1-step, until final collision.
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};