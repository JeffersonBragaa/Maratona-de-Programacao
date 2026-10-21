#include <bits/stdc++.h>
using namespace std;

string numeros[] = {
    "",
    "ONE",
    "TWO",
    "THREE",
    "FOUR",
    "FIVE",
    "SIX",
    "SEVEN",
    "EIGHT",
    "NINE",
    "TEN",
    "ELEVEN",
    "TWELVE",
    "THIRTEEN",
    "FOURTEEN",
    "FIFTEEN",
    "SIXTEEN",
    "SEVENTEEN",
    "EIGHTEEN",
    "NINETEEN"
};

string dezenas[] = {
    "",
    "",
    "TWENTY",
    "THIRTY",
    "FORTY",
    "FIFTY",
    "SIXTY",
    "SEVENTY",
    "EIGHTY",
    "NINETY"
};

int f(int x) {

    if (x <= 19) {
        return numeros[x].size();
    }

    if (x < 100) {
        int dezena = x / 10;
        int unidade = x % 10;

        return dezenas[dezena].size() + numeros[unidade].size();
    }

    return 11;
}

int main() {

    int x;
    cin >> x;

    for (int i = 0; i < 1000; i++) {
        x = f(x);
    }

    cout << x << endl;

    return 0;
}