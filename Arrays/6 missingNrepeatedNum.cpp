https://www.interviewbit.com/problems/repeat-and-missing-number-array/

vector<int> Solution::missing_N_repeatedNumbers(const vector<int> &A) {
     //Appr. 1: time O(N)+O(N), space O(n)
    vector<int> v(A.size()+1,0);
    vector<int> result;
    for(int i=0;i<A.size();i++){
        v[A[i]]++;
        if(v[A[i]] == 2)
            result.push_back(A[i]);
    }
    for(int i=1;i<=A.size();i++){
        if(v[i] == 0){
            result.push_back(i);
            break;
        }
    }

    return result;


    // Approach 2: Xor  (To-do)

    
}
