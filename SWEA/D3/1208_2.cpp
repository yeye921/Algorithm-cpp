#include<iostream>
#include <algorithm>
using namespace std;
 
int b[102];
 
int main(int argc, char** argv)
{
    int test_case;
    //tc 10으로 바꾸기
    for(test_case = 1; test_case <= 10; ++test_case)
    {
        fill(b,b+102,0);
        int n; cin>>n;
        for(int i=0; i<100; i++) cin>>b[i];
         
        int mnIdx=0,mxIdx=0;
        while(n--){
            for(int i=0; i<100; i++){
                if(b[mnIdx]>b[i]) mnIdx=i;
                if(b[mxIdx]<b[i]) mxIdx=i;
            }
             
            b[mnIdx]++;
            b[mxIdx]--;
        }
         
        cout<<"#"<<test_case<<" "<<*max_element(b,b+100)-*min_element(b,b+100)<<'\n';
 
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}