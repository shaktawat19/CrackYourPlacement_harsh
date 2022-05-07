class Solution
{
public:
     vector<int> majorityElement(vector<int> &nums)
     {
          // Brute force: O(n*n), check for evry elem, n count.

          // Better: time (nlogn), space O(n)
          map<int, int> uMap;
          vector<int> majorityMap;
          int s = floor(nums.size() / 3);
          for (int i = 0; i < nums.size(); ++i)
          {
               uMap[nums[i]]++;
               if (uMap[nums[i]] > s)
               {
                    if (!count(majorityMap.begin(), majorityMap.end(), nums[i]))
                    {
                         // checking if elem is present already, then won't push in final vector.
                         majorityMap.push_back(nums[i]);
                    }
               }
          }
          return majorityMap;


          // Optimal: Moore’s Voting Algorithm
          // Here by analysis we get to know that we cant have more than 2 majority elem in array.

          int sz = nums.size();
          int num1 = -1, num2 = -1, count1 = 0, count2 = 0, i;
          for (i = 0; i < sz; i++)
          {
               if (nums[i] == num1)
                    count1++;
               else if (nums[i] == num2)
                    count2++;
               else if (count1 == 0)
               {
                    num1 = nums[i];
                    count1 = 1;
               }
               else if (count2 == 0)
               {
                    num2 = nums[i];
                    count2 = 1;
               }
               else
               {
                    count1--;
                    count2--;
               }
          }
          vector<int> ans;
          count1 = count2 = 0;
          for (i = 0; i < sz; i++)
          {
               if (nums[i] == num1)
                    count1++;
               else if (nums[i] == num2)
                    count2++;
          }
          if (count1 > sz / 3)
               ans.push_back(num1);
          if (count2 > sz / 3)
               ans.push_back(num2);
          return ans;
     }
};