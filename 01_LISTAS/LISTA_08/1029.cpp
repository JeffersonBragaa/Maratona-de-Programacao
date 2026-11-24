#include <bits/stdc++.h>

using namespace std;

int fiboPD(int n, vector<long long int> &fb, vector<long long int> &fbSoma)
{
    fb[0] = 0;
    fb[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        fb[i] = fb[i - 1] + fb[i - 2];
        fbSoma[i] = fbSoma[i - 1] + fbSoma[i - 2] + 2;
    }

    return fb[n];
}

int main()
{
    int n, x;
    cin >> n;

    vector<long long int> fb(40);
    vector<long long int> fbSoma(40);

    while (n--)
    {
        cin >> x;
        int resultado = fiboPD(x, fb, fbSoma);
        printf("fib(%d) = %lld calls = %d\n", x, fbSoma[x], resultado);
    }

    return 0;
}
