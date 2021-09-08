#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//왠지.. 괜히 10억이 아니더라
//자료형 차이 심함. long long안쓰면 안풀림

//10분이 걸리는 심사대는 28분 이내로 2명을 처리할 수 있음 28/10
//7분이 걸리는 심사대는 28분 이내로 4명을 처리할 수 있음 28/7
//1. 둘다 시간이기때문에 계산에 논리가 틀리지 않음
//2. 동시에 처리가 가능하기 때문에 둘이 더해도 됨.
//3. 어차피 이분검색이기 때문에 이렇게 간단하게 해도 결과가 나오는거임.

//이 둘을 더함
long long Count(long long mid, vector<int> times)
{
    long long cnt = 0;

    for(int i = 0; i < times.size(); i++)
    {
        cnt += mid / times[i];
    }
    return cnt;
}

long long solution(int n, vector<int> times) {
    long long answer = 0, mid;
    long long lt = *min_element(times.begin(), times.end());
    long long rt = *max_element(times.begin(), times.end()) * n;

    while (lt <= rt) {
        mid = (lt+rt) / 2;
        if(Count(mid, times) >= n){ //mid시간 안에 n명 이상 받으면 답인데 줄여나가기.

            answer = mid;
            rt = mid-1;
        }else lt = mid+1;
    }
    cout << answer;
    return answer;
}

int main(int argc, const char * argv[]) {
    solution(6, {7,10});
    return 0;
}

