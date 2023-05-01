class Solution {
public:
    bool isPalindrome(string s) {
        int i=0,j=s.size()-1;
        if(j<1){
            return true;
        }
        while(i<=j){
            if(!isalnum(s[j])){
                j--;
                continue;
            }
            if(!isalnum(s[i])){
                i++;
                continue;
            }
            if(tolower(s[i++])!=tolower(s[j--])){
                return false;
            }
        }
        return true;
    }
};
