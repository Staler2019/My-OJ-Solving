//http://140.115.50.98/problem/1020
#include <iostream>
using namespace std;
using ll = long long;
#define M (ll)(1e9 + 7)
const int m_size = 2;

struct Matrix {
    ll m[m_size][m_size]{};
    Matrix(ll a = 0, ll b = 0, ll c = 0, ll d = 0) {
        m[0][0] = a, m[0][1] = b, m[1][0] = c, m[1][1] = d;
    }
    void operator*=(const Matrix &mat) {
        Matrix ans;
        for (int i = 0; i < m_size; i++) {
            for (int j = 0; j < m_size; j++) {
                for (int k = 0; k < m_size; k++) {
                    ans.m[i][j] =
                        (ans.m[i][j] +
                         ((this->m[i][k] % M) * (mat.m[k][j] % M)) % M) %
                        M;
                }
            }
        }
        *this = ans;
    }
    Matrix pow(const ll n) {
        if (n == 1) return (*this);
        Matrix ans = this->pow(n / 2);
        // ans = ans * ans;
        ans *= ans;
        //cerr << ans.m[1][0] << endl;
        if (n & 1)  // return ans * (*this);
            ans *= (*this);
        return ans;
    }
};

int main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    Matrix Fibo(1, 1, 1, 0);
    Fibo = Fibo.pow(n + 1);
    cout << Fibo.m[1][0] << endl;
}