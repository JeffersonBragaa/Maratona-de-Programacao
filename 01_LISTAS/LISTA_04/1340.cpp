#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, op, num;

    while (cin >> n) {

        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;

        bool fila = true;
        bool pilha = true;
        bool fila_pri = true;

        while (n--) {

            cin >> op >> num;

            if (op == 1) {
                s.push(num);
                q.push(num);
                pq.push(num);
            }
            else {

                if (pilha && s.top() != num) {
                    pilha = false;
                }

                if (fila && q.front() != num) {
                    fila = false;
                }

                if (fila_pri && pq.top() != num) {
                    fila_pri = false;
                }

                s.pop();
                q.pop();
                pq.pop();
            }
        }

        if (pilha && !fila && !fila_pri) {
            cout << "stack\n";
        }
        else if (!pilha && fila && !fila_pri) {
            cout << "queue\n";
        }
        else if (!pilha && !fila && fila_pri) {
            cout << "priority queue\n";
        }
        else if (pilha || fila || fila_pri) {
            cout << "not sure\n";
        }
        else {
            cout << "impossible\n";
        }
    }

    return 0;
}