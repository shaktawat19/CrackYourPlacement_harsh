class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Brute force: time O(n*n)
        // vector<int> result;
        // for(int i=0;i<nums.size()-1;i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         if(nums[i]+nums[j] == target && i != j){
        //             result.push_back(i);
        //             result.push_back(j);
        //             return result;
        //         }
        //     }
        // }
        // return result;
        
        // Optimal: Hashmap O(n)
        map<int, int> mp;
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            if(mp.find(target - nums[i]) != mp.end()){
                result.push_back(i);
                result.push_back(mp[target-nums[i]]);
            }
            mp[nums[i]] = i;
        }
        return result;
    }
};