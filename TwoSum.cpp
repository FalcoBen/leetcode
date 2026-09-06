#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using  namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target);
};

vector<int> Solution::twoSum(vector<int>& nums, int target)
{
    vector<int> result;
    vector<int> last;
    vector<int>::iterator it = nums.begin();
    vector<int>::iterator next;

    std::vector<std::pair<int, int>> test;
    for(size_t i = 0; i < nums.size(); i++)
    {
        std::pair<int, int> couple;
        couple.first = i;
        couple.second = nums[i];
        test.push_back(couple);
    }
    while(it != nums.end())
    {
        next = it + 1;
        while(next != nums.end())
        {
            if(*it + *next == target)
            {
                result.push_back(*it);
                result.push_back(*next);
                break;
            }
            next++;
        }
        it++;
    }
    if(result.size() == 2)
    {
        int j = 0;
        for(size_t i = 0; i < test.size(); i++)
        {
            if(j == 2)
                break;
            if(test[i].second == result[j])
            {
                last.push_back(test[i].first);
                j++;
            }
        }
    }

    return last;
}




/*

Input: nums = [3,2,4], target = 6
Output: [1,2]
*/

int main()
{
    std::vector<int> nb;
    nb.push_back(3);
    nb.push_back(2);
    nb.push_back(4);
    Solution obj;
    vector<int> res =  obj.twoSum(nb, 6);
    std::cout << "[";
    for(size_t i = 0; i < res.size(); i++)
    {
        std::cout << res[i]; 
    }
    std::cout << "]" << std::endl;
}