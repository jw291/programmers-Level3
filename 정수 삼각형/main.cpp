#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = -2147000000;
    //vector<vector<int>> dy = triangle;
    vector<vector<int>> dy(triangle.size(), vector<int>(triangle.size(),0));
    
    dy[0][0] = triangle[0][0];
    for(int i = 1; i < triangle.size(); i++){
        int index_first = 0;
        unsigned long beforeStep_index_last = triangle[i-1].size()-1;
        unsigned long index_last = triangle[i].size()-1;
        
        dy[i][index_first] = dy[i-1][index_first] + triangle[i][index_first];
        dy[i][index_last] = dy[i-1][beforeStep_index_last] + triangle[i][index_last];
    }
    
    for(int i = 2; i < triangle.size(); i++){
        for(int j = 1; j < triangle[i].size()-1; j++){
            int num = max(dy[i-1][j-1], dy[i-1][j]);
            dy[i][j] = num + triangle[i][j];
        }
    }
    
    for(int j = 0; j < triangle[triangle.size()-1].size(); j++){
        answer = max(answer , dy[dy.size()-1][j]);
    }
    
    cout << answer;
    
    
//    for(int i = 0; i < triangle.size(); i++){//dynamic table result checking
//        for(int j = 0; j < triangle[i].size(); j++){
//            cout << dy[i][j];
//        }
//        cout << endl;
//    }
    return answer;
}

int main(int argc, const char * argv[]) {
    solution({{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}});
    return 0;
}
