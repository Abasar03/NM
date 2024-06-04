#include<stdio.h>
#include<math.h>

float f(float x, float y);

int main(){
    float x0, y0, m1, m2, m3, m4, m, y, x, h, xp;
    printf("Enter x0, y0, xp, h:\n");
    scanf("%f%f%f%f", &x0, &y0, &xp, &h);
    x = x0;
    y = y0;
    printf("\n\nX\t\tY\n");
    while(x < xp){
        m1 = f(x, y);
        m2 = f((x + h / 2.0), (y + m1 / 2.0));
        m3 = f((x + h / 2.0), (y + m2  / 2.0));
        m4 = f((x + h), (y + m3 ));
        m = ((m1 + 2 * m2 + 2 * m3 + m4) / 6);
        y = y + m * h;
        x = x + h; // Increment x after printing
        printf("%f\t%f\n", x, y);
    }
}

float f(float x, float y){
    float m;
    m = (pow(y,2)-pow(x,2))/(pow(y,2)+pow(x,2));
    return m;
}