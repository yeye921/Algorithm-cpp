// 목표: 제한된 횟수만큼 옮기는 작업을 한 후 최고점과 최저점의 차이를 반환
// Tip!) arr에서 가장 큰 수를 찾고 => 이렇게 가장 큰 수를 찾아야 할때는 max_element말고 배열을 정렬시키고 가장 나중값을 직접접근하는게 좋음!!
// 실수: 테케문에서 배열 초기화 안함!!
#include <iostream>
using namespace std;
vector<int> arr;
int dump;
int num;
int main(){
    for(int test_case = 1; test_case <= 10; test_case++){
        vector<int> arr;
        int ret = 0;
        cin >> dump;
        for(int i = 0; i < 100; i++){
            cin >> num;
            arr.push_back(num);
        }
        sort(arr.begin(), arr.end()); 
        while(dump--){
            // 가장 높은 곳에서 낮은 곳으로 상자를 옮김 (배열의 가로 길이는 항상 100)
            arr[99]--;
            arr[0]++;
            sort(arr.begin(), arr.end()); // sort의 순서에 따라 값이 달라짐 !! (상자를 옮기고 > 정렬을 한 후에 > 높이차를 계산해야함)
            ret = arr[99] - arr[0];

            // 평탄화가 완료되었으면 탈출하는 조건 추가
            if(ret <= 1) break;
        }
        cout << "#" << test_case << " " << ret << "\n";
    }
}