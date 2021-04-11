#include <iostream>
using namespace std; 

int N, M;
int K;
int A[10000];

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    int result = 0, sum = 0, left = 0, right = 0;

    while (1)
    {
        if (sum >= M)
        {
            sum -= A[left++];
        }
        else if (right == N)
        {
            break;
        }
        else
        {
            sum += A[right++];
        }

        if (sum == M)
        {
            result += 1;
        }
    }

    cout << result;

    return 0;
}