#include <bits/stdc++.h>
using namespace std;

struct coord{
    int x; 
    int y;
    coord(int x, int y): x(x), y(y) {}
    bool operator==(const coord& other) const {
        return x == other.x && y == other.y;
    }
};

namespace std {
    template <>
    struct hash<coord> {
        size_t operator()(const coord& c) const {
            return hash<int>()(c.x) ^ (hash<int>()(c.y) << 1);
        }
    };
}

class Solution {
public:
    unordered_map<coord, int> memo = unordered_map<coord, int>();
    int xSize; int ySize;

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        ySize = matrix.size();
        xSize = matrix[0].size();
        int highest = 0;
        for(int i = 0; i<ySize; i++){
            for(int j = 0; j<xSize; j++){
                highest = max(sub(j,i, matrix), highest);
            }
        }
        return highest;
    }

    int sub(int x, int y, vector<vector<int>> &matrix){
        if(memo.find(coord(x,y)) != memo.end()){
            return memo[coord(x,y)];
        }
        
        int val = matrix[y][x];
        int highest = 1;

        //up
        if(y+1<=ySize-1 && val<matrix[y+1][x]){
            highest = max(highest, sub(x, y+1, matrix) + 1);
        }

        //down
        if(y-1>=0 && val<matrix[y-1][x]){
            highest = max(highest, sub(x, y-1, matrix) + 1);
        }

        //right
        if(x+1<=xSize-1 && val<matrix[y][x+1]){
            highest = max(highest, sub(x+1, y, matrix) + 1);
        }

        //left
        if(x-1>=0 && val<matrix[y][x-1]){
            highest = max(highest, sub(x-1, y, matrix) + 1);
        }

        
        memo[coord(x,y)] = highest;
        return highest;
    }
};

int main(){
    Solution solution = Solution();
    vector<vector<int>> matrix = vector<vector<int>> {{9,9,4},{6,6,8}};
    cout<<solution.longestIncreasingPath(matrix);
}