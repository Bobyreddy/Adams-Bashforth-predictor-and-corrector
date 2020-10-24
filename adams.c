#include<stdio.h>

float Y(float X, float Y);

void main(){
    float x[100], y[100], h, X, F, P, C;
    int i, j, k, n, m;

    printf("\nhow many values:");
    scanf("%d", &n);

    printf("enter x and y values:\n");
    i = 0; 
    while(i<n){
        scanf("%f %f", &x[i], &y[i]);
        i++; 
    }

    printf("\n\tX \t\tY \t\tY'=x^2(1+y)\n");
    for(j=0; j<n; j++){
        F = Y(x[j], y[j]);
        printf("\n X%d = %.2f \t Y%d = %.4f \t y(%d)' = %.4f \n", j, x[j], j, y[j], j, F);
    }

    h = x[1] - x[0];

    // predictior formula
    printf("enter X4 value: ");
    scanf("%f", &x[4]);
    P = y[3] + (h/24) * ( 55 * Y(x[3], y[3])- 59 * Y(x[2], y[2]) + 37 * Y(x[1], y[1]) - 9 * Y(x[0], y[0]));
    printf("Y(4)p = %.4f \n", P);
    P = Y(x[4], P);
    printf("Y(4)'= %.4f \n", P);
    y[4] = P;
    C = P; 

    //corrector formula
    printf("enter the number of iteration to be performed:");
    scanf("%d", &m);
    for(k=1; k<=m; k++){
        C = y[3] + (h/24) * ( 9 * Y(x[4], y[4]) + 19 * Y(x[3], y[3]) - 5 * Y(x[2], y[2]) + Y(x[1], y[1]) );
        if(k == 1){
            printf("corrector formula\n");
        }
        else
        {
            printf("iteration (%d):\n", k);
        }
        printf("Y(4)c = %.4f\n", C);
        C = Y(x[4], C);
        printf("Y(4)' = %.4f\n", C);
        y[4] = C;
        
    }
}

float Y(float X, float Y){
    float z;
    z = (X*X)*(1+Y);
    return z; 
}
