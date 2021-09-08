#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int *dis = new int[n+1];
    fill_n(dis,n+1,2147000000);
    int *ch = new int[n+1];
    fill_n(ch,n+1,0);
    queue<int> Q;
    vector<int> graph[n+1];
    
    //인접 리스트로 변환
    for(int i = 0; i < edge.size(); i++)
    {
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    
    Q.push(1); //start node
    dis[1] = 0;
    ch[1] = 1; // node visit
    
    while(!Q.empty())
    {
        int x = Q.front();
        Q.pop();

        for(int i = 0; i < graph[x].size(); i++)
        {
            int distance = dis[x] + 1;
            
            if(ch[graph[x][i]] == 0 && distance < dis[graph[x][i]]) //이전 노드로부터 거리와 원래 할당된 거리값을 비교 만약 더 작다면
            {
                dis[graph[x][i]] = distance; //작은 값을 할당한다.
                ch[graph[x][i]] = 1; //체크
                Q.push(graph[x][i]);
            }
        }

    }
    
    int maxValue = -2147000000;
    int answer = 1;
    
    for(int i = 1; i < n+1; i++)
    {
        if(dis[i] == maxValue) answer++;
        else if(dis[i] > maxValue)
        {
            maxValue = dis[i];
            answer = 1;
        }
    }

    delete [] dis;
    delete [] ch;
    return answer;
}

int main(int argc, const char * argv[]) {
    solution(6, { {3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2} });
    return 0;
}
