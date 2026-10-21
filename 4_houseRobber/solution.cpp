#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    unordered_map<int, int> memo;

    int rob(vector<int>& nums) {
        
        
        robSub(-1, nums);
        cout<<"memo2:"<<memo[2]<<endl;
        return robSub(-1, nums);
    }

    int robSub(int pos, vector<int>& nums){
        int highest = 0;
        
        //base case
        if((float)nums.size()-pos<2) {memo[pos] = highest;return highest;}

        //rob first house
        int firstHouse = (memo.find(pos+2) == memo.end()) ? robSub(pos+2, nums) + nums[pos+1] : memo[pos+2] + nums[pos+1];
        cout<<"first" << firstHouse<<endl;
        highest = max(firstHouse, highest);
        

        if((float)nums.size()-pos<3) {memo[pos] = highest; return highest;}
        //rob second house
        int secondHouse = (memo.find(pos+3) == memo.end()) ? robSub(pos+3, nums) + nums[pos+2] : memo[pos+3] + nums[pos+2];
        cout<<"second" << secondHouse<<endl;
        highest = max(secondHouse, highest);
        {memo[pos] = highest; return highest;}
    }
};
// 4 - 2 = 2
int main(){
    Solution solution = Solution();
    vector<int> pVector = vector<int> {1,10,100,1000};
    cout << solution.rob(pVector);
}