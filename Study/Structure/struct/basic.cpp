// x,y,z 등 여러가지 인자들이 나오고 커스텀한 솔팅이 필요하다면 구조체를 사용하는 것이 좋음
// 정렬이 필요하지 않은 경우에는 2처럼 단순하게 구조체 설정하면 됨

// 1) 커스텀한 정렬이 필요한 경우
struct Point {
    int y, x;  // 이 구조체의 변수
    Point(int y, int x) : y(y), x(x){} // y,x를 받아 생성한다는 의미 (이 구조체를 기반으로 객체를 생성할 때 y,x를 받아 생성한다는 의미)
    Point(){y = -1; x = -1; } // 만약 y, x가 정해지지 않은 경우 기본값으로 -1, -1을 집어넣는다는 의미
    bool operator < (const Point & a) const {  // 해당 구조체를 기반으로 만들어진 객체들끼리 비교하는 기준을 잡는 것
        if(x == a.x) return y < a.y;           // 1순위는 x, 2순위는 y를 기반으로 크고 작음을 판단
        return x < a.x;
    }
}
// +) bool operator는 연산자 오버로딩(연산자를 하위클래스에서 재정의)하는 것 ex. <, >, ..

// 2) 정렬이 필요하지 않을 경우
struct percent {
    int x, y;
    double w, d, l;
} a[6];