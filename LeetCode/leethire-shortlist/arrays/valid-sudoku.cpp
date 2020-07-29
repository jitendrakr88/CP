/* Author: Jitendra Kumar (jitendra.iitp@gmail.com) */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF LLONG_MAX/4
#define MOD 1e9+7
#define DEBUG(x) cerr << #x << " is " << (x) << endl;


class Solution {
private:
    bool isValid1to9(vector<char> nine) {
        set<char> s;
        for (char x: nine) {
            if (x=='.')
                continue;
            if (s.find(x)!=s.end())
                return false;
            s.insert(x);
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check rows
        for(int r=0;r<9;r++) {
            if(!isValid1to9(board[r]))
                return false;
        }
        // check columns
        for(int c=0;c<9;c++) {
            vector<char> col;
            for(int r=0;r<9; r++)
                col.push_back(board[r][c]);
            if (!isValid1to9(col))
                return false;
        }
        // check 3*3 box
        int x=0, y=0;
        for(int i=0; i<3; i++) {
            x = i*3;
            for(int j=0; j<3; j++) {
                y = j*3;
                vector<char> box;
                for(int r=x; r<x+3; r++)
                    for(int c=y; c<y+3; c++)
                        box.push_back(board[r][c]);
                if(!isValid1to9(box))
                    return false;
            }
        }
        return true;
    }
};
