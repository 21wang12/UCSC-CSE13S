#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <math.h>
#include "mathlib.h"
#define OPTIONS "asctl"
// int main(void) {
int main(int argc, char **argv) {
    int opt = 0;
    bool run_arcsin=false, run_arccos=false, run_arctan=false, run_log=false;
    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'a':
            run_arcsin = true;
            run_arccos = true;
            run_arctan = true;
            run_log = true;
            break;

        case 's': run_arcsin = true; break;

        case 'c': run_arccos = true; break;

        case 't': run_arctan = true; break;

        case 'l': run_log = true; break;
        default: fprintf(stderr, "Usage: %s -[asctl]\n", argv[0]);
        }
    }

    if (run_arcsin) {
        puts("  x            arcSin           Library          Difference");
        puts("  -            ------           -------          ----------");
        for (double i = -1; i < 1; i += 0.1) {
            printf(" %7.4lf %16.8lf %16.8lf %16.8lf\n", i, arcSin(i), asin(i), arcSin(i) - asin(i));
        }
    }
    if (run_arccos) {
        puts("  x            arcCos           Library          Difference");
        puts("  -            ------           -------          ----------");
        for (double i = -1; i < 1; i += 0.1) {
            printf(" %7.4lf %16.8lf %16.8lf %16.8lf\n", i, arcCos(i), acos(i), arcCos(i) - acos(i));
        }
    }

    if (run_arctan) {
        puts("  x            arcTan           Library          Difference");
        puts("  -            ------           -------          ----------");
        for (double i = 1; i < 10; i += 0.1) {
            printf(" %7.4lf %16.8lf %16.8lf %16.8lf\n", i, arcTan(i), atan(i), arcTan(i) - atan(i));
        }
    }

    if (run_log) {
        puts("  x            Log              Library        Difference");
        puts("  -            ---              -------        ----------");
        for (double i = 1; i < 10; i += 0.1) {
            printf(" %7.4lf %16.8lf %16.8lf %16.8lf\n", i, Log(i), log(i), Log(i) - log(i));
        }
    }
    // double a = arcSin(1);
    // printf("%f", a);
    return 0;
}
