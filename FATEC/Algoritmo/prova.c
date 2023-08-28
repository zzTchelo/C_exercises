#include <stdio.h>
#include <math.h>

#define MAXN 100

typedef struct {
    double x, y;
} Point;

Point p[MAXN];

double dist(Point a, Point b) {
    double dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    int n;
    while (scanf("%d", &n) == 1 && n > 0) {
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &p[i].x, &p[i].y);
        }

        Point center;
        double radius = 1e9;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                Point c = { (p[i].x + p[j].x) / 2, (p[i].y + p[j].y) / 2 };
                double r = dist(c, p[i]);

                int ok = 1;
                for (int k = 0; k < n; k++) {
                    if (dist(c, p[k]) > r + 1e-9) {
                        ok = 0;
                        break;
                    }
                }

                if (ok && r < radius) {
                    center = c;
                    radius = r;
                }
            }
        }

        printf("%.2lf %.2lf %.2lf\n", center.x, center.y, radius);
    }

    return 0;
}
