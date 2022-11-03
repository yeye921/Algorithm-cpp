// 최대공약수 구하는 방법 (유클리드 호제법 이용)
// a와 b의 최대공약수는 b와 a%b의 최대공약수와 같다 (a % b = r, r % b = r1, r1이 0이면 최대공약수는 b) 

// 알고리즘
// 1. 입력으로 두 수가 들어온다
// 2. n이 0이라면 m을 출력하고 알고리즘을 종료한다
// 3. 그렇지 않으면, m을 n으로 나눈 나머지를 새롭게 m에 대입하고 m과 n을 바꾸고 2번으로 돌아온다
// 결론: gcd(나머지, 나눈 수)
int gcd(int a, int b){ // if a > b
    if(b == 0) return a; // 나눈 나머지가 0이면 몫이 최대공약수
    return gcd(b, a % b); // 작은 쪽에 나머지공식이 들어가야함
}
int gcd1(int a, int b){ // if a < b
    if(a == 0) return b;
    return gcd(a % b, a);
}
int gcd2(int a, int b){
    int c;
    while(b){ // b = 0이면 탈출
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}