// 24비트 버퍼 > 한 바이트씩 3바이트의 문자 집어넣음 > 6비트씩 잘라 그 값을 읽고 각각의 값을 아스키코드 표를 이용해서 인코딩하기

// 예시 (이해하기 쉽게 24비트씩(=3byte의 문자) 공백 넣었음)
// TGlm ZSBp dHNl bGYg aXMg YSBx dW90 YXRp b24u (54비트)
// 19 6 11 12
#include <iostream>
#include <string>
 
using namespace std;
 
string table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
 
int main()
{
    int tc;
    cin >> tc;
 
    for (int i = 0; i < tc; i++)
    {
        string in;
        cin >> in;
 
        int len_code = in.size();
        char res[3];
        cout << '#' << i + 1 << ' ';
        for (int j = 0; j < len_code;)
        {
            res[0] = (table.find(in[j++]) << 2) | ((table.find(in[j]) >> 4));
            res[1] = (table.find(in[j++]) << 4) | ((table.find(in[j]) >> 2));
            res[2] = (table.find(in[j++]) << 6) | ((table.find(in[j++])));
 
            for (int jj = 0; jj < 3; jj++)
                cout << res[jj];
        }
        cout << endl;
    }
}