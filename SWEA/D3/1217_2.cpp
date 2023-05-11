#include<iostream>
 
using namespace std;
 
int myself(int n, int m);
 
int main(int argc, char** argv)
{
    int test_case,cnt,n,m;
 
    for(test_case = 1; test_case <= 10; ++test_case)
    {
        scanf("%d",&cnt);
        scanf("%d",&n);
        scanf("%d",&m);  
        printf("#%d, %d\n",cnt,myself(n,m));
    }
    return 0;
}
 
int myself(int n, int m){
    if(m <= 1)
        return n;
    return n * myself(n, m-1);
}