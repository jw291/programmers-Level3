#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map<string,int> genresHash;

struct Loc{
    int number;
    string genres;
    int plays;
    
    Loc(int number, string genres, int plays){
        this -> number = number;
        this -> genres = genres;
        this -> plays = plays;
    }
    
    bool operator < (const Loc &ref)const{
        if(genres == ref.genres){ //같은 장르 내에서의 정렬
            if(plays == ref.plays)
                return number < ref.number;
            else
                return plays > ref.plays;
        }
        
        return genresHash[genres] > genresHash[ref.genres]; //전체에서 큰 장르부터 정렬
    }
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    string prev_genres;
    int cnt = 0;
    
    vector<int> answer;
    
    vector<Loc> data;
    
    for(int i = 0; i < genres.size(); i++){
        genresHash[genres[i]] += plays[i];
        data.push_back(Loc(i,genres[i], plays[i]));
    }
    
    sort(data.begin(), data.end());
    
    prev_genres = data[0].genres;
    
    for(int i = 0; i < data.size(); i++)
    {
        if(data[i].genres == prev_genres){
            if(cnt < 2){
                answer.push_back(data[i].number);
                cnt++;
            }
        }else{
            answer.push_back(data[i].number);
            prev_genres = data[i].genres;
            cnt = 1;
        }
    }
    
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << " ";
    }
    
//    for(int i = 0; i < data.size(); i++)
//    {
//        cout << data[i].number << " " << data[i].genres << " " <<data[i].plays << endl;
//    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<string> genres = {"classic", "pop", "classic", "classic", "pop"};
    vector<int> plays = {500, 600, 150, 800, 2500};
    solution(genres, plays);
    return 0;
}
/*
 String[] genres = {"A", "A", "B", "A", "B", "B", "A", "A", "A", "A"};
 int[] plays = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
 [0, 1, 2, 4]
 
 ["classic", "pop", "classic", "classic","jazz","pop", "Rock", "jazz"]
 [500, 600, 150, 800, 1100, 2500, 100, 1000]
 [5, 1, 4, 7, 3, 0, 6]
 */
