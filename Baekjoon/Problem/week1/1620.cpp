// 시간 초과 남
// 모르겠는 것
// 문자열 숫자로 변환하는 법: stoi(문자열), 숫자를 문자열로 변환하는 법: to_string(숫자)
// 문자열이 영문자인지 확인하는 법: 
/*
1. vector내에 해당 원소가 존재하는지 확인 => find(v.begin(), v.end(), 찾는대상)
2. vector내에 해당 원소가 위치하는 인덱스 찾기 => find(v.begin(), v.end(), 칮는대상) - v.begin()
*/
// 문자열인지 숫자인지 모를 때 형선언 어떻게 해서 입력받아야 되는지
// isdigit(문자 1개): 어떤 문자가 숫자인지 확인
// ret 사용도 너무 비효율적인듯..? 문자와 숫자를 같은 컨테이너에 저장 못하나?
#include <bits/stdc++.h>
using namespace std;
int n, m, num;
string name, problem;
vector<string> dogam, ret;
int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> name;
        dogam.push_back(name);
    }

    for(int i = 0; i < m; i++){
        cin >> problem;

        if(isdigit(problem[0])){ // 숫자를 입력받으면 이름을 저장
            num = stoi(problem);  // 문자열을 숫자로 변환 ("11" => 11)
            ret.push_back(dogam[num]);
            // cout << dogam[num] << "\n";
        }
        else { // 문자열이면 (이름을 입력받으면 번호 저장)
            num = find(dogam.begin(), dogam.end(), problem) - dogam.begin(); // 결과: 숫자
            ret.push_back(to_string(num)); // 문자로 변환해서 저장
            // cout << to_string(num) << "\n";
        }
    }

    for(string s : ret) cout << s << "\n";
    return 0;
}