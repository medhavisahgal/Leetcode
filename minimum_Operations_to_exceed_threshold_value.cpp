#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
class Solution
{
public:
    // bool check(vector<long long> &nums, int k, int &cnt)
    //     long long x = nums[0];
    //     long long y = nums[1];
    //     if (x >= k) {
    //         return true;
    //     } else {
    //         nums.erase(nums.begin(), nums.begin() + 2);
    //         long long pb1 = min(x, y) * 2 + max(x, y);
    //         nums.push_back(pb1);
    //         sort(nums.begin(), nums.end());
    //         cnt++;
    //         return false;
    //     }
    // }

    int minOperations(vector<int> &nums, int k)
    {
        //     vector<long long> numsLong(nums.begin(), nums.end());
        //     sort(numsLong.begin(), numsLong.end());
        //     int cnt = 0;
        //     while (numsLong.size() >= 2) {
        //         if (numsLong[0] >= k) {
        //             return cnt;
        //         }
        //         check(numsLong, k, cnt);
        //     }
        //     if (!numsLong.empty() && numsLong[0] >= k) {
        //         return cnt;
        //     }
        //     return -1;
        // Time Complexity: O(n^2logn)
        // Space Complexity: O(n)
        // }
        // Brute force solution is showing TLE
        // Optimized solution
        // we will use priority queue to store the elements in sorted order
        // we will keep on adding the elements in the priority queue and keep on removing the smallest element
        priority_queue<long long, vector<long long>, greater<long long>> min_heap;
        for (auto a : nums)
        {
            min_heap.push(a);
        }
        int cnt = 0;
        while (min_heap.size() >= 2 && min_heap.top() < k)
        {
            long long x = min_heap.top();
            min_heap.pop();
            long long y = min_heap.top();
            min_heap.pop();
            long long pb1 = min(x, y) * 2 + max(x, y);
            min_heap.push(pb1);
            cnt++;
        }
        return (!min_heap.empty() && min_heap.top() >= k) ? cnt : -1;
        // Time Complexity: O(nlogn)
        // Space Complexity: O(n)
    }
};
