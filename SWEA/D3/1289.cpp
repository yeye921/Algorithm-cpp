// 그냥 origin과 reset의 각자리를 비교해가면서 다르면 그 값으로 해당 비트를 결정하고 같으면 건너뜀 <= 여러 예시를 통해 이 규칙을 발견함

// +) 문자/문자열을 특정 횟수만큼 붙이는 법: string()함수 이용
// 문자와 반복 횟수로 초기화: string()은 특정 문자를 반복해서 사용하여 초기화된 문자열 객체를 생성함
// ex. string (5, 'A') => 'AAAAA'
#include <iostream>
using namespace std;
int T;
int main(){
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){
        int ret = 0; // 초기화 상태에서 원래 상태로 돌아가는데 걸리는 최소 횟수
        string origin = "";
        string reset = "";
        cin >> origin;

        int size = origin.size();
        reset = string(size, '0'); // 메모리 초기화 설정

        // 원래상태와 초기상태의 각 문자를 비교
        for(int i = 0; i < size; i++){
            if(origin[i] == reset[i]) continue;

            ret++; // 변경횟수 증가
            // i만큼 기존 값으로 채우고 size-i만큼 origin[i]값으로 채우기
            reset = reset.substr(0, i) + string(size-i, origin[i]); // string 함수를 이용해 해당값으로 메모리 끝까지 덮어씌움
        }
        cout << "#" << test_case << " " << ret << "\n";
    }
}