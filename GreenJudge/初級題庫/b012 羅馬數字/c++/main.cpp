#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input="";
    int str_length=0,i=0,pre=0,now=0,output=0;
    cin >> input;
    str_length = input.length();
    for(;i<str_length;i++)
    {
        switch(input[i])
        {
            case 'I':
                now=1;
                break;
            case 'V':
                now=5;
                break;
            case 'X':
                now=10;
                break;
            case 'L':
                now=50;
                break;
            case 'C':
                now=100;
                break;
            case 'D':
                now=500;
                break;
            case 'M':
                now=1000;
        }
        if(now>pre)                 /*大數字減去小數字*/
            output-=pre;            /*因為規則:大數字左側最多只會有一個小數字*/
        else                        /*ex:MM'CD'LX"IX"=24691000+1000+[500-100]+50+10+[10-1]*/
            output+=pre;
        pre=now;
    }
    output+=now;
    cout << output;
    return 0;
}
