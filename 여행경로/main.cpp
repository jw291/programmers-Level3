#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

struct Loc{
    int value;
    int row;
    int col;
    
    Loc(int v, int r, int c){
        value = v;
        row = r;
        col = c;
    }
    
    bool operator<(const Loc &ref)const{
        return value > ref.value;
    }
};

string findByValue(map<string, int> mapOfElemen, int value)
{
    auto it= mapOfElemen.begin();
    //Iterate through the map
    while(it != mapOfElemen.end())
    {
        //Check if value of this entry matches with given value
        if(it->second== value)
        {
            return it->first;
        }
        //Go to next entry in map
        it++;
    }
   //key for the value is not found hou probably need to change this depending on your key space
    return "0";
}

vector<string> solution(vector<vector<string>> tickets) {
    map<string,int> m;
    vector<string> answer;
    vector<int> glist[tickets.size() * 2];
    priority_queue<Loc> pQ;
    int num = 1;
    
    //------airport numbering Start
    //result ICN:2 SFO:3 ATL:1
    for(int i = 0; i < tickets.size(); i++){
        for(int j = 0; j < tickets[i].size(); j++)
        {
            m[tickets[i][j]] = 1;
        }
    }
    
    for (auto it = m.begin(); it != m.end(); it++) {
        m[it->first] = num++;
    }
    //HND:1IAD:2ICN:3JFK:4
    //------numbering end
 
    //------adjacent list base numbering
    for(int i = 0; i < tickets.size(); i++){
        glist[m[tickets[i][0]]].push_back(m[tickets[i][1]]);
    }
    
    //------end
    //BFS Start
    pQ.push(Loc(m["ICN"],m["ICN"],-1));
    answer.push_back(findByValue(m, m["ICN"]));
    
    while (!pQ.empty()) {
        int x = pQ.top().value;
        int gx = pQ.top().row;
        int gy = pQ.top().col;

        if(gy != -1){
            if(glist[gx][gy] != 0){
                glist[gx][gy] = 0;
                answer.push_back(findByValue(m, x));
            }
        }

        pQ.pop();

        for (int i = 0; i < glist[x].size(); i++) {
            if(glist[x][i] > 0)
                pQ.push(Loc(glist[x][i],x,i));
        }
    }
    
    return answer;
}

int main(int argc, const char * argv[]) {
    vector<vector<string>> tickets = { {"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"} };
    for(int i = 0; i < solution(tickets).size(); i++)
        cout << solution(tickets)[i] << " ";
    return 0;
}
// {"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}
//{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL","SFO"}
