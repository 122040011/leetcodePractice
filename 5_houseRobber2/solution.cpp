#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    unordered_map<int, int> memo;
    

    int rob(vector<int>& nums) {
        if(nums.size()<=1)return nums[0];
        
        int v1 = robSub(0, nums);
        memo = unordered_map<int, int>();
        int v2 = robSub2(-1, nums);
        return max(v1, v2);
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
    int robSub2(int pos, vector<int>& nums){
        int highest = 0;
        
        //base case
        if((float)nums.size()-1-pos<2) {memo[pos] = highest;return highest;}

        //rob first house
        int firstHouse = (memo.find(pos+2) == memo.end()) ? robSub2(pos+2, nums) + nums[pos+1] : memo[pos+2] + nums[pos+1];
        cout<<"first" << firstHouse<<endl;
        highest = max(firstHouse, highest);
        

        if((float)nums.size()-1-pos<3) {memo[pos] = highest; return highest;}
        //rob second house
        int secondHouse = (memo.find(pos+3) == memo.end()) ? robSub2(pos+3, nums) + nums[pos+2] : memo[pos+3] + nums[pos+2];
        cout<<"second" << secondHouse<<endl;
        highest = max(secondHouse, highest);
        {memo[pos] = highest; return highest;}
    }
};

int main(){
    Solution solution = Solution();
    vector<int> pVector = vector<int> {1,10,100};
    cout << solution.rob(pVector);
}