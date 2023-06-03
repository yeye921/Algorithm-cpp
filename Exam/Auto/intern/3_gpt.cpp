// UAM 편대 개수를 1증가시키기 위해 서로 맞바꿀 수 있는 신호정도에 대한 서로다른 쌍의 개수 구하기 (조합)
// 즉, connected component 개수를 1증가시킬 조합 찾기
#include <iostream>
#include <vector>
using namespace std;

// 맞바꿀 수 있는 신호 쌍의 개수를 계산하는 함수
int countSwappablePairs(const vector<int>& signal) {
    vector<int> lastIndex(signal.size(), -1);  // 각 신호의 마지막 인덱스를 저장하는 배열
    int swapCount = 0;  // 맞바꿀 수 있는 신호 쌍의 개수

    for (int i = 0; i < signal.size(); ++i) {
        if (lastIndex[signal[i]] != -1) {
            swapCount += lastIndex[signal[i]];  // 이미 등장한 신호일 경우, 해당 인덱스를 이용하여 맞바꿀 수 있는 쌍의 개수를 증가시킴
        }
        lastIndex[signal[i]] = i;  // 현재 신호의 인덱스를 저장
    }

    return swapCount;
}
int main() {
    int N;
    cin >> N;  // UAM의 수 입력

    vector<int> signal(N);
    for (int i = 0; i < N; ++i) {
        cin >> signal[i];  // 신호 체계 정보 입력
    }

    int result = countSwappablePairs(signal);  // 맞바꿀 수 있는 신호 쌍의 개수 계산
    cout << result << endl;  // 결과 출력

    return 0;
}