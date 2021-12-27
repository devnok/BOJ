#include <iostream>
#include <cmath>
using namespace std;

int f(int n)
{
    return (int)sqrt((double)n);
}

int main()
{
    int n, d, ans = 4, zero = 0;
    cin >> n;

    for(int i = 0; i < 240; i++){
        for(int j = 0; j < 240; j++){
            for(int k = 0; k < 240; k++){
                d = n - i*i -k*k - j*j;
                if(d < 0) break;
                if(d == f(d) * f(d)){
                    zero = 0;
                    if(i == 0) zero++;
                    if(j == 0) zero++;
                    if(k == 0) zero++;
                    if(d == 0) zero++;
                    if(ans > 4-zero) ans = 4 - zero;
                }
            }
        }
    }
    cout << ans;
    return 0;
}