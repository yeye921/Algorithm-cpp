// 두 회사 중 더 적게 수도 요금을 부과하는 회사를 고르려고 함
// 각 회사의 수도 요금을 계산해서 더 적은 금액을 출력하면 됨
#include <iostream>
using namespace std;
int T, test_case;
int p, q, r, s, w;
int fee_a, fee_b;
int main(){
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){
        cin >> p >> q >> r >> s >> w;
        fee_a = p * w;
        fee_b = q; // 기본 요금
        if(w > r){ // 추가 요금
            fee_b += (w - r) * s;
        }

        // 두 회사 중 더 적은 요금 선택
        cout << "#" << test_case << " " << min(fee_a, fee_b) << "\n";
    }
}