#include <iostream>
using namespace std;
int N; 
bool prime[1000001];
 
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 2; i <= 1000001; i++)
    {
        if (!prime[i])
            for (int j = i + i; j <= 1000001; j = j + i) prime[j] = true;
    }  
 
    while(true)
    {
        cin >> N;

        if (N == 0) break;

        bool fail = true;
        for (int i = 3; i < 1000001; i = i + 2)
        {
            if (!prime[i] && !prime[N - i])
            {
                cout << N << " = " << i << " + " << N - i << "\n";
                fail = false;
                break;
            }
        }
        if (fail) cout << "Goldbach's conjecture is wrong." << "\n";
    }
 
    return 0;
}

