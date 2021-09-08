//테스트케이스 10:7
//다시 풀기
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 32001;
char op[4] = {'+','-','*','/'};

int solution(int N, int number) {
    int idx, tmp = 1, answer;

    vector<int> dy(MAX, 10);
    vector<int> ch(MAX, 0);
    vector<int> sub;
    queue<int> Q;

    idx = N;

    while(idx < MAX){
        dy[idx] = tmp;
        ch[idx] = 1;
        Q.push(idx);
        sub.push_back(idx);
        idx = (idx * 10) + N;
        tmp++;
    }

    while(!Q.empty()){
        int x = Q.front();
        Q.pop();

        for(int i = 0; i < 4; i++){
            for(int j = 0; j < sub.size(); j++){
                int xx = 0;
                switch (op[i]) {
                    case '+':
                        xx = x+sub[j];
                        break;
                    case '-':
                        xx = x-sub[j];
                        break;
                    case '*':
                        xx = x*sub[j];
                        break;
                    case '/':
                        xx = x/sub[j];
                        break;
                }

                if(xx < MAX && xx > 0 && ch[xx] == 0){
                    Q.push(xx);
                    dy[xx] = min(dy[xx],dy[x]+dy[sub[j]]);
                    ch[xx] = 1;
                }

                if(xx == number){
                    if(dy[xx] > 8){
                        return -1;
                    }
                    else
                    {
                        return dy[xx];
                    }
                }
            }
        }
    }
    return 0;
}

int main(int argc, const char * argv[]){
    cout << solution(4, 17) << endl;
}

