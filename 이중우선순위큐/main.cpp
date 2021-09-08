//최소 최대 두개 뽑아오려고 max minheap 두개썼는데
//minheap에서 삭제된걸 maxheap도 알려야해서
//map으로 지워진건 체크했음

//근데 deque를 쓰거나
//set을 쓰면 최대 최소 두 값에 모두 접근이 가능함
//deque는 매번 sort를 해야한다는 문제가 있음(그래도 통과)
//set으로 한번 풀어보는게 좋을듯
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int Extraction(string str){
    char tmp = str.at(0);
    int res = 0;
    int num = 0;
    if(tmp == 'I'){
        if(str[2] == '-'){
            for(int i = 3; i < strlen(str.c_str()); i++){
                num = num * 10 + str[i] - 48;
            }
            res = -num;
        }else{
            for(int i = 2; i < strlen(str.c_str()); i++){
                num = num * 10 + str[i] - 48;
            }
            res = num;
        }
    }
    return res;
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    int tmp = 1;
    int count = 0;
    int max_res = -2147000000;
    int min_res = 2147000000;
    map<int,int> ch;
    vector<int> vec_res;
    priority_queue<int, vector<int>, less<int>> MAX_Q;
    priority_queue<int, vector<int>, greater<int>> MIN_Q;
    
    for (auto it = operations.begin(); it != operations.end(); it++) {
        if(*it  == "D 1"){
            if(count != 0){
                while(ch[MAX_Q.top()] <= 0){
                    ch[MAX_Q.top()]--;
                    MAX_Q.pop();
                }
                ch[MAX_Q.top()]--;
                MAX_Q.pop();
                count--;
            }
        }else if(*it == "D -1"){
            if(count != 0){
                while(ch[MIN_Q.top()] <= 0){
                    ch[MIN_Q.top()]--;
                    MIN_Q.pop();
                }
                ch[MIN_Q.top()]--;
                MIN_Q.pop();
                count--;
            }
        }else{
            int tmp = Extraction(*it);
            MAX_Q.push(tmp);
            MIN_Q.push(tmp);
            ch[tmp]++;
            count++;
        }
    }
    
    while (!MAX_Q.empty()) {
        int num = MAX_Q.top();
        MAX_Q.pop();
        
        if(ch[num] >= 1){
            vec_res.push_back(num);
        }
        
    }
    for(int i = 0; i < vec_res.size(); i++){
        max_res = max(max_res,vec_res[i]);
        min_res = min(min_res,vec_res[i]);
    }
    
    if(max_res == -2147000000 && min_res == 2147000000){
        return {0,0};
    }else{
        answer.push_back(max_res);
        answer.push_back(min_res);
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<string> operations = {"I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"};
    cout << solution(operations)[0] << solution(operations)[1];
    return 0;
}
