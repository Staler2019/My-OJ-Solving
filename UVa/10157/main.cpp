#include <iostream>

using namespace std;

int main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    int n, d;
    cin >> n >> d;
    n /= 2;
    /*
    Sample Input:
    (1) 6 2 -->> (C3_2)*(C1_1)
    (2) 300 150 -->> (C150_150)
    (3) 10 2 -->> (C10_2)*(
     (C10_2)*(C10_2)*(C10_2)*(C10_2)*(1/5!)
     + [2,3]*[1,2] + [2,2]*[1,4] + [2,1]*[1,6] + [1,8]
     // MEANS: FIRST_NUM: C._?
     //        SECOND_NUM: HOW MANY OF "C"
     )
    */
}