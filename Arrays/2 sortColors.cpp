        // App. 1: sort fn, O(n*logn)
        // App. 2: O(n) + O(n). Count 0,1,2's and store in variables. Then fill the array based on these variables length.
        
        // App. 3: O(n) 3-pointer apprach
        // Dutch National flag algo variation. 
        // Loop until mid <= high.
        // elements left to low should be 0, while to right of high should be 2.
        // if mid points to 0, swap arr[low] n arr[mid].
        // if mid points to 1, increment mid.
        // if mid points to 2, swap arr[mid] n arr[high], and decrement high.

class Solution {
public:
    void sortColors(vector<int>& nums) {   
        // App. 3: O(n) 3-pointer apprach

        int low = 0, mid = 0, high = nums.size()-1;
        while(mid <= high){
            switch(nums[mid]){
                case 0: 
                    swap(nums[low++],nums[mid++]);
                    break;
                case 1: mid++;
                    break;
                case 2: 
                    swap(nums[mid],nums[high--]);
                    break;
            }
        }
    }
};