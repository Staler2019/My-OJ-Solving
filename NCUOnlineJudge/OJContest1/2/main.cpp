#include <iostream>
#include <string>
//#include <linked_list>
#include <vector>
using namespace std;

vector<string> a{"bubble", "tapioka"};

int main()
{

    vector<string> in, out;
    string tmp;
    while (true)
    {
        cin >> tmp;

        in.push_back(tmp);
        if (cin.peek() == '\n')
        {
            break;
        }
    }
    for (int i = 0; i < in.size(); i++)
    {
        //cout << i << endl;
        if (in[i] == a[1] || in[i] == a[0])
        {
        }
        else
        {
            out.push_back(in[i]);
        }
    }
    if(out.size()==0) {
        cout << "nothing";
    }else{
        for (int i = 0; i < out.size();i++) {
            cout << out[i] << " ";
        }
    }

    return 0;
}
