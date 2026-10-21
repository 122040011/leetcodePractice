#include <bits/stdc++.h>
using namespace std;


class Solution {

    public:
    pair<int, int> highest = pair<int, int> {0, 0};
    string pString;
    
    string longestPalindrome(string s) {
        //init
        if(s.size() == 1) return s;
        this->pString = s;

        for(int i = 0; i<s.size(); i++){
            explore(1, i);
        }
        for(int i = 0; i<s.size()-1; i++){
            if(s[i]==s[i+1]) explore(2, i);
        }
        cout<<highest.first<<" "<<highest.second<<endl;
        cout<<pString.substr(highest.second, highest.first)<<endl;
        return s.substr(highest.second, highest.first);
    }

    void explore(int size, int start){
        if(size>highest.first){
            cout<<"updating "<<size<<endl;
            highest = pair<int, int> {size, start};
        }
        if(start>0 && start+size<pString.size() && pString[start-1] == pString[start+size]){
            explore(size+2, start-1);
        }
    }

};

int main(){
    Solution solution = Solution();
    solution.longestPalindrome("bbb");
}