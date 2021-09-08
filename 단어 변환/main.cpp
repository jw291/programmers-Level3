//테스트케이스 3번 (중복값에 의한 것 때문에 오래걸림)
//map을 쓰면 abc를 aaa로 비교하려할때
//왼쪽에 a가 하나있어도 cnt가 3이됌
//그래서 감소시킴.
#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

int res = 2147000000;
string _target;
int ch[100];

void DFS(int L, int num, string str, vector<string> words){
    map<char,int> wordnum;
    map<char,int> tmpnum;
    map<char,int>::iterator it;
    char a[100];
    wordnum.clear();
    
    if(str == _target) {
        if(res > num){
            res = num;
        }
        return;
    }
        
    if (L == words.size()) return;
    else{
        strcpy(a, str.c_str());

        for(int i = 0; a[i] != '\0'; i++){ //중복처리 때문에 비교되는 값이 줄어들어서
            //반복할때마다 다시 채워야함.
            wordnum[a[i]]++;
        }
        
        for(int i = 0; i < words.size(); i++){
            tmpnum = wordnum;
            
            int cnt = 0;
            char b[100];
            
            strcpy(b, words[i].c_str());
            
            for(int i = 0; a[i] != '\0'; i++){
                if(tmpnum[b[i]] >= 1){
                    tmpnum[b[i]]--; //중복처리를 위함
                    cnt++;
                }
            }
            if(cnt == str.length()-1 && ch[i] == 0){
                ch[i] = 1;
                DFS(L+1,num+1,words[i],words);
                DFS(L+1,num,str,words);
                ch[i] = 0;
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    _target = target;
    DFS(0,0,begin,words);
    if(res == 2147000000) return 0;
    else return res;
}

int main(int argc, const char * argv[]) {
    cout << solution("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"});
}
