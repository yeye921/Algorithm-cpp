// N/2마리의 폰켓몬을 선택하는 방법 중, 가장 많은 종류의 폰켓몬을 선택하는 방법을 찾아 그때 폰켓몬 종류 번호의 갯수를 반환
// 핵심풀이: 벡터에서 중복 제거한 후 이 개수가 N/2보다 크면 답은 N/2이고, 작으면 중복제거후 벡터 사이즈이다
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int picked = nums.size() / 2;
    
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end()); // erase 사용 주의
    int unique_nums_cnt = nums.size();
    
    if(unique_nums_cnt > picked) answer = picked;
    else answer = unique_nums_cnt;
    // answer = min(unique_nums_cnt, picked); 로 위 코드를 대체할 수 있음

    return answer;
}