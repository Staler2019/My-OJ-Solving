#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, in, num;
    string s;
    cin >> t;

    for (int i = 0; i < t;i++){
        set<int> u;

        cin >> num;
        while(true){
            //cerr << "----";
            cin >> in;
            if(1==u.count(in)){
                continue;
            }
            else{
                cout << in << " ";
                u.insert(in);
            }
            //cerr << "-" << (int)u.size() << endl;
            if((int)u.size()==num){
                break;
            }
        }
        if(cin.peek()==32){
            getline(cin, s);
        }
        //cerr << "----" << endl;
    }
}