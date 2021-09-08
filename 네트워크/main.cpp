//완전 스스로해결 한번에 테스트케이스 통과
//전 날엔 집중 못해서 오래걸렸는데 다음날 30분만에 품
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int ch[100] = {0};
    int network = n;
    queue<int> Q;
    
    for(int i = 0; i < n; i++){
        if(ch[i] == 0 && computers[i][i] == 1){
            Q.push(i);
            ch[i] = 1;
        }
        
        while(!Q.empty()){
            int x = Q.front();
            Q.pop();
            
            for (int j = 0; j < n; j++){
                if(ch[j] == 0 && computers[x][j] == 1){
                    Q.push(j);
                    ch[j] = 1;
                    network--;
                }
            }
        }
    }
    
    return network;
    
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> arr = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    cout << solution(3, arr);
    return 0;
}
