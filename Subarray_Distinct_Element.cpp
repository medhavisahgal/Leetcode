#include <vector>
#include <set>
using namespace std;
class Solution
{
public:
    int sumCounts(vector<int>& nums)
    {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            vector<int> v;
            for(int j = i; j < nums.size(); j++)
            {
                v.push_back(nums[j]); 
                set<int> disele(v.begin(), v.end());  
                sum += disele.size() * disele.size();
            }
        }
        return sum;
    }
};
