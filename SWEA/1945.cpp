#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int num;
        cin>>num;
        int a=0, b=0, c=0, d=0, e=0;
        
        while(1)
        {
            if(num==1)
                break;
            
            if(num%2==0){
                num=num/2;
            	a++;
            }
            else if(num%3==0){
                num=num/3;
                b++;
            }
            else if(num%5==0){
                num=num/5;
                c++;
            }
            else if(num%7==0){
                num=num/7;
                d++;
            }
            else if(num%11==0){
                num=num/11;
                e++;
            }
        }
        cout<<"#"<<test_case<<" "<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<"\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}