#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    

    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        
        unordered_map<int, int> map;
        for(int i = 0; i<nums.size(); i++){
            int remain = target-nums[i];
            if(map.find(remain) != map.end()){
                return vector<int> {map[remain], i};
            }
            else map.insert(pair<int, int> {nums[i], i});
        }
        return vector<int> {0};
    }

};

int main(){
    Solution solution = Solution();
    vector<int> *nums = new vector<int> {2,7,11, 15};
    vector<int> ans = solution.twoSum(*nums, 9);
    cout<<ans[0]<<ans[1];
}
