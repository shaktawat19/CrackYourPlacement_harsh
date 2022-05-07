class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Brute force(With extra space) : copy elems of two arrays in 3rd array. Sort this array. Copy elems from 3rd array to nums1.
        
        
        // Better: compare both arrays, if elem in arr1 >  0th elem in arr2, then swap, and sort arr2 again. Repeat. 
        // Then copy arr2 to arr1 finally.
        // // Note : This is giving runtime error for some test cases.
        // for(int i=0;i<m;i++){
        //     if(nums1[i] > nums2[0]){
        //         swap(nums1[i],nums2[0]);
        //         sort(nums2.begin(),nums2.end());
        //     }
        // }
        // int k=0;
        // for(int i=m;i<m+n;i++){
        //     nums1[i] = nums2[k++]; 
        // }
        
        
    // Optimal(w/o space) :
        // start filling nums1 from backwards.
        int i=m-1,j=n-1,pos=nums1.size()-1;
        while(i>=0 && j>=0){
            if(nums1[i] >= nums2[j]){
                nums1[pos--] = nums1[i--];
            }
            else{
                nums1[pos--] = nums2[j--];
            }
        }
        // fill remaining elems.
        while(i>=0){
            nums1[pos--] = nums1[i--];
        }
        while(j>=0){
            nums1[pos--] = nums2[j--];
        }
        
        
 // Gap Algorithm for different question variation:
        // Take gap as ceil of sum of both arr size by 2.
        // outer loop until gap > 0
        // inner loop untill jumping is in total size range.
        //
   void merge(int ar1[], int ar2[], int n, int m) {
  int gap = ceil((float)(n + m) / 2);
  while (gap > 0) {
    int i = 0;
    int j = gap;
    while (j < (n + m)) {
      if (j < n && ar1[i] > ar1[j]) {
        swap(ar1[i], ar1[j]);
      } else if (j >= n && i < n && ar1[i] > ar2[j - n]) {
        swap(ar1[i], ar2[j - n]);
      } else if (j >= n && i >= n && ar2[i - n] > ar2[j - n]) {
        swap(ar2[i - n], ar2[j - n]);
      }
      j++;
      i++;
    }
    if (gap == 1) {
      gap = 0;
    } else {
      gap = ceil((float) gap / 2);
    }
  }
}
   
        
    }
};