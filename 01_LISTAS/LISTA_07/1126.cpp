
#include <bits/stdc++.h>
using namespace std;

struct Ponto {
    double x, y, z;
};

Ponto subtrair(Ponto a, Ponto b) {
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}

double escalar(Ponto a, Ponto b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Ponto vetorial(Ponto a, Ponto b) {
    return {
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    };
}

double pontoSegmento(Ponto p, Ponto a, Ponto b) {
    Ponto ab = subtrair(b, a);
    Ponto ap = subtrair(p, a);

    double t = escalar(ap, ab) / escalar(ab, ab);

    t = max(0.0, min(1.0, t));

    Ponto proximo = {
        a.x + t * ab.x,
        a.y + t * ab.y,
        a.z + t * ab.z
    };

    Ponto d = subtrair(p, proximo);

    return escalar(d, d);
}

double pontoTriangulo(Ponto p, Ponto a, Ponto b, Ponto c) {
    Ponto ab = subtrair(b, a);
    Ponto ac = subtrair(c, a);
    Ponto ap = subtrair(p, a);

    double d00 = escalar(ab, ab);
    double d01 = escalar(ab, ac);
    double d11 = escalar(ac, ac);
    double d20 = escalar(ap, ab);
    double d21 = escalar(ap, ac);

    double den = d00 * d11 - d01 * d01;

    double u = (d11 * d20 - d01 * d21) / den;
    double v = (d00 * d21 - d01 * d20) / den;

    if (u >= -1e-10 && v >= -1e-10 && u + v <= 1.0 + 1e-10) {
        Ponto normal = vetorial(ab, ac);

        double h = escalar(ap, normal);

        return h * h / escalar(normal, normal);
    }

    return min({
        pontoSegmento(p, a, b),
        pontoSegmento(p, a, c),
        pontoSegmento(p, b, c)
    });
}

double segmentoSegmento(Ponto a, Ponto b, Ponto c, Ponto d) {
    Ponto u = subtrair(b, a);
    Ponto v = subtrair(d, c);
    Ponto w = subtrair(a, c);

    double A = escalar(u, u);
    double B = escalar(u, v);
    double C = escalar(v, v);
    double D = escalar(u, w);
    double E = escalar(v, w);

    double den = A * C - B * B;

    double menor = min({
        pontoSegmento(a, c, d),
        pontoSegmento(b, c, d),
        pontoSegmento(c, a, b),
        pontoSegmento(d, a, b)
    });

    if (den > 1e-10) {
        double s = (B * E - C * D) / den;
        double t = (A * E - B * D) / den;

        if (s >= 0 && s <= 1 && t >= 0 && t <= 1) {
            Ponto dif = {
                w.x + s * u.x - t * v.x,
                w.y + s * u.y - t * v.y,
                w.z + s * u.z - t * v.z
            };

            menor = min(menor, escalar(dif, dif));
        }
    }

    return menor;
}

int main() {
    int T;
    cin >> T;

    int faces[4][3] = {
        {0, 1, 2},
        {0, 1, 3},
        {0, 2, 3},
        {1, 2, 3}
    };

    int arestas[6][2] = {
        {0, 1},
        {0, 2},
        {0, 3},
        {1, 2},
        {1, 3},
        {2, 3}
    };

    while (T--) {
        Ponto a[4], b[4];

        for (int i = 0; i < 4; i++) {
            cin >> a[i].x >> a[i].y >> a[i].z;
        }

        for (int i = 0; i < 4; i++) {
            cin >> b[i].x >> b[i].y >> b[i].z;
        }

        double menor = 1e100;

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int x = faces[j][0];
                int y = faces[j][1];
                int z = faces[j][2];

                menor = min(menor,
                    pontoTriangulo(a[i], b[x], b[y], b[z]));

                menor = min(menor,
                    pontoTriangulo(b[i], a[x], a[y], a[z]));
            }
        }

        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                menor = min(menor, segmentoSegmento(
                    a[arestas[i][0]], a[arestas[i][1]],
                    b[arestas[j][0]], b[arestas[j][1]]
                ));
            }
        }

        cout << fixed << setprecision(2)
             << sqrt(menor) << endl;
    }

    return 0;
}
