// lower_bound(): 어떠한 값의 이상이 되는 위치 (0번째부터 탐색)
// upper_bound(): 어떠한 값이 나오기 전의 위치 (뒤에서부터 탐색)
// 정렬된 배열에서 어떤 값이 나오는 지점이나 어떤 값이 나오기전의 위치를 반환할 때 사용
// 이분탐색을 쉽게 함수로 구현하기 위해 사용
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v;
    int a[5] = {1,2,2,2,3};
    for(int i = 0; i < 5; i++) v.push_back(a[i]); // v = {1,2,2,2,3}
    int x = 2;

    // 2가 나오기 전의 위치(4) - 2이상이 되는 위치(1) = 4-1 = 3
    // x의 개수를 이런 방식으로 셀 수 있다 (중요!!)
    int c = (int)(upper_bound(v.begin(), v.end(), x) - lower_bound(v.begin(), v.end(), x)); 
    
    int f = (int)(lower_bound(v.begin(), v.end(), x) - v.begin()); // 2이상이 되는 위치의 인덱스
    int t = (int)(upper_bound(v.begin(), v.end(), x) - v.begin()); // 2가 나오기 전 위치의 인덱스

    int f2 = *lower_bound(v.begin(), v.end(), x); 
    int t2 = *upper_bound(v.begin(), v.end(), x);
    cout << x << "의 개수: " << c << ", 시작되는 위치: " << f << ", 끝나는 위치: " << t << "\n";
    cout << "lower bound가 시작되는 점의 값: " << f2 << ", upper bound가 시작되는 점의 값: " << t2 << "\n"; 
    
    // x가 나오기 전의 위치 - x의 이상이 되는 위치 = 4-1 = 3
    c = (int)(upper_bound(a, a + 5, x) - lower_bound(a, a + 5, x));
    f = (int)(lower_bound(a, a + 5, x) - a); // x값의 이상이 되는 위치
    t = (int)(upper_bound(a, a + 5, x) - a); // x가 나오기 전의 위치 

    f2 = *lower_bound(a, a + 5, x);
    t2 = *upper_bound(a, a + 5, x);
    cout << x <<"의 개수: " << c << ", 시작되는 위치: " << f << " 끝나는 위치: " << t << "\n";
    cout << "lower bound가 시작되는 위치의 값: " << f2 << ", upper bound가 시작되는 위치의 값: " << t2 << "\n";
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    vector<int> a;
    for(int i = 1; i <= 3; i++) a.push_back(i);
    for(int i = 5; i <= 10; i++) a.push_back(i);
    // a = {1,2,3,5,6,7,8,9,10}

    // 4이상이 되는 위치
    cout << lower_bound(a.begin(), a.end(), 4) - a.begin() << "\n"; // 3
    return 0;
}

// 만약 원소를 찾을 때 값이 없다면 그 근방 지점을 반환한다
#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
    for(int i = 2; i <= 5; i++) v.push_back(i);
    v.push_back(7);
    // v = {2,3,4,5,7}

    cout << upper_bound(v.begin(), v.end(), 6) - v.begin() << "\n"; // 6이 나오기 전의 위치 인덱스 = 4
    cout << lower_bound(v.begin(), v.end(), 6) - v.begin() << "\n"; // 6이상의 값의 위치 인덱스 = 4
    
    // 값이 없다면 그 근방지점을 반환하는 예제
    cout << upper_bound(v.begin(), v.end(), 9) - v.begin() << "\n"; // 9가 나오기 전의 위치 인덱스 = 5
    cout << lower_bound(v.begin(), v.end(), 9) - v.begin() << "\n"; // 9이상의 값의 위치 인덱스 = 5

    cout << upper_bound(v.begin(), v.end(), 0) - v.begin() << "\n"; // 0이 나오기 전의 위치 인덱스 = 0
    cout << lower_bound(v.begin(), v.end(), 0) - v.begin() << "\n"; // 0이상의 값의 위치 인덱스 = 0
}

