#include <vector>
#include <unordered_set>
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<int> queryResults(int limit, vector<vector<int>> &queries)
    {
        // BRUTE FORCE
        //     vector<int>color(limit+1,0);
        //     vector<int>ans;
        //     int n=queries.size();
        //     for(const auto& x:queries)
        //     {
        //         //change in color that index
        //         int index=x[0];
        //         color[index]=x[1];
        //         unordered_set<int> s;
        //         for (int c:color)
        //         {
        //             // If not present, then put it in
        //             // hashtable and increment result
        //             if (c!=0)
        //             {
        //                 s.insert(c);
        //             }
        //         }
        //         ans.push_back(s.size());
        //     }
        //     return ans;
        // }
        // Time  Complexity: O(n*limit)
        // Space Complexity: O(limit+n)
        // Showing memory limit exceeded
        // Reason -  vector color of size limit + 1 (up to 10⁹) is using too much memory . This requires ~4 GB of memory (assuming int is 4 bytes), which exceeds typical memory limits.
        // Reason for this space complexity be O(limit+n) and not O(n*limit) is that because the color array stores at most limit elements at any time, and the unordered_set used in each query is reinitialized, not accumulated across queries.
        // Optimized Solution
        unordered_map<int, int> curr_color;
        unordered_map<int, int> color_cnt;
        vector<int> ans;
        for (auto x : queries)
        {
            int index = x[0];
            int new_col = x[1];
            // step 1: update color count
            if (curr_color.count(index))
            {
                // step 2: decrement the count of the current color of the ball at index
                color_cnt[curr_color[index]]--;
                // step 3: if the count of the current color of the ball at index becomes 0, remove it from the map
                if (color_cnt[curr_color[index]] == 0)
                {
                    color_cnt.erase(curr_color[index]);
                }
            }
            // step 4: update the color of the ball at index
            curr_color[index] = new_col;
            // step 5: increment the count of the new color of the ball at index
            color_cnt[new_col]++;
            // step 6: add the number of distinct colors to the answer
            ans.push_back(color_cnt.size());
        }
        return ans;
        // Time  Complexity: O(n)
        // Space Complexity: O(n)
    }
};
