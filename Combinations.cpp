class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        int i=0;
        vector<int>m(k,0);
        while(i>=0){
            m[i]++;
            if(m[i]>n){
                i--;
            }
            else if(i==k-1){
                ans.push_back(m);
            }
            else{
                i++;
                m[i]=m[i-1];
            }
        }
        return ans;
    }
};
//used backtracking
