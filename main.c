#include <stdio.h>
#include "src/info.h"
#include "src/complex.h"
#include "src/float.h"


int main() {
    int w_m, w_t;
    vector *v1 = NULL, *v2 = NULL, *res;
    float x1, x2, y1, y2, z1, z2;
    complex x_1, y_1, z_1, x_2, y_2, z_2;
    info* info1 = NULL;

    while(1) {
        puts("Choose action:");
        puts("1) Add vectors");
        puts("2) Find the sum of vectors");
        puts("3) Find the scalar multiplication");
        puts("4) Find the vector multiplication");
        puts("5) Exit");

        scanf("%d", &w_m);
        while(getchar() != '\n');

        switch(w_m) {
            case 1:
                puts("Select data type: ");
                puts("1) Float");
                puts("2) Complex");
                scanf("%d", &w_t);
                while (getchar() != '\n');

                switch (w_t) {
                    case 1:
                        puts("Enter coordinates of first vector: ");
                        scanf("%f", &x1);
                        scanf("%f", &y1);
                        scanf("%f", &z1);
                        puts("Enter coordinates of second vector: ");
                        scanf("%f", &x2);
                        scanf("%f", &y2);
                        scanf("%f", &z2);
                        v1 = Create((void *)&x1, (void *) &y1, (void *) &z1);
                        v2 = Create((void *) &x2, (void *) &y2, (void *) &z2);
                        info1 = Create_i(&Get_float, &Sum_float, &Mult_float, &Minus_float);
                        puts("Done!");
                        break;

                    case 2:
                        puts("Enter coordinates of first vector(re im): ");
                        scanf("%d %d", &x_1.real, &x_1.im);
                        scanf("%d %d", &y_1.real, &y_1.im);
                        scanf("%d %d", &z_1.real, &z_1.im);
                        puts("Enter coordinates of second vector(re im): ");
                        scanf("%d %d", &x_2.real, &x_2.im);
                        scanf("%d %d", &y_2.real, &y_2.im);
                        scanf("%d %d", &z_2.real, &z_2.im);
                        v1 = Create((void*)&x_1, (void*)&y_1, (void*)&z_1);
                        v2 = Create((void*)&x_2, (void*)&y_2, (void*)&z_2);
                        info1 = Create_i(&Get_complex, &Sum_complex, &Mult_complex, &Minus_complex);
                        puts("Done!");
                        break;
                }
                break;

            case 2:
                res = Create(info1->sum(v1->x, v2->x), info1->sum(v1->y, v2->y), info1->sum(v1->z, v2->z));
                puts("Result of summary: ");
                printf("\nx = ");
                info1->get(res->x);
                printf("\ny = ");
                info1->get(res->y);
                printf("\nz = ");
                info1->get(res->z);
                puts("\n");
                break;

            case 3:
                printf("Result of scalar multiplication: ");
                info1->get(info1->sum(info1->mult(v1->x, v2->x), info1->sum(info1->mult(v1->y, v2->y), info1->mult(v1->z, v2->z))));
                puts("\n");
                break;

            case 4:
                printf("Result of vector multiplication: \nx = ");
                info1->get(info1->sum(info1->mult(v1->y, v2->z), info1->minus(info1->mult(v2->y, v1->z))));
                printf("\ny = ");
                info1->get(info1->sum(info1->mult(v1->x, v2->z), info1->minus(info1->mult(v2->x, v1->z))));
                printf("\nz = ");
                info1->get(info1->sum(info1->mult(v1->x, v2->y), info1->minus(info1->mult(v2->x, v1->y))));
                puts("\n");
                break;

            case 5:
                Delete_vector(v1);
                Delete_vector(v2);
                Delete_i(info1);
                puts("Bye :3");
                return 0;
        }
    }
}
