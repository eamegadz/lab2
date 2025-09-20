#include <stdio.h>
#include <math.h>


void print_with_commas(float num) {
    int integer_part = (int)num;               
    int decimals = (int)roundf((num - integer_part) * 100); 

   
    if (num < 0) {
        printf("-");
        integer_part = -integer_part;
        decimals = -decimals;
    }

   
    char buffer[50];
    sprintf(buffer, "%d", integer_part);

    int len = 0;
    while (buffer[len] != '\0') len++;

    
    int first_group = len % 3;
    if (first_group == 0) first_group = 3;

    for (int i = 0; i < len; i++) {
        putchar(buffer[i]);
        if ((i + 1 - first_group) % 3 == 0 && i != len - 1) {
            putchar(',');
        }
    }

   
    printf(".%02d", decimals);
}


float distance(float x1, float y1, float x2, float y2) {
    float dx = x1 - x2;
    float dy = y1 - y2;
    return sqrtf(dx*dx + dy*dy);
}

int main(void) {
    float x[3], y[3];

    for (int i = 0; i < 3; i++) {
        printf("Point %d: ", i+1);
        if (scanf(" (%f, %f)", &x[i], &y[i]) != 2) {
            return 1;
        }
    }

    float d12 = distance(x[0], y[0], x[1], y[1]);
    float d13 = distance(x[0], y[0], x[2], y[2]);
    float d23 = distance(x[1], y[1], x[2], y[2]);

    float min = d12;
    if (d13 < min) min = d13;
    if (d23 < min) min = d23;

    if (fabsf(d12 - d13) < 1e-5 && fabsf(d13 - d23) < 1e-5) {
        printf("All points are equal distance: ");
        print_with_commas(d12);
        printf("\n");
        return 0;
    }

    if (fabsf(d12 - min) < 1e-5) {
        printf("P1<->P2: ");
        print_with_commas(d12);
        printf("\n");
    }
    if (fabsf(d13 - min) < 1e-5) {
        printf("P1<->P3: ");
        print_with_commas(d13);
        printf("\n");
    }
    if (fabsf(d23 - min) < 1e-5) {
        printf("P2<->P3: ");
        print_with_commas(d23);
        printf("\n");
    }

    return 0;
}
