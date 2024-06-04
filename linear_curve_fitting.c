#include <stdio.h>
#include <math.h>
#include <stdlib.h>



float getNum(){
    float num;
    scanf("%f",&num);
    return num;
}


int main(){
    int n,i;
    float X[50],Y[50],sumx=0,sumx2=0,sumxy=0,sumy=0,a,b;


    printf("Linear curve fitting by the method of least squares\n");
    printf("Enter the no of data points n:\n");
    scanf("%d",&n);
    printf("Enter the respective values of x and y:\n");
    for(i=1;i<=n;i++){
        X[i]=getNum();
        Y[i]=getNum();
    }

    printf("\n The table of data that you enter is as follow\n");

    for(i=1;i<=n;i++){
        printf("%f\t\t%f\n",X[i],Y[i]);
    }

   for(i=1;i<=n;i++){
    sumx=sumx+X[i];
    sumx2=sumx2+X[i]*X[i];
    sumy=sumy+Y[i];
    sumxy=sumxy+X[i]*Y[i];
   }
    b=(n*sumxy-sumx*sumy)/(n*sumx2-sumx*sumx);
    a=(sumy-b*sumx)/n;
    printf("\nThe required values of a and b are \n %0.9f,%0.9fx\n",a,b);
    printf("\nThe best fitted line is y=%0.9f +%0.9fx\n",a,b);
    return 0;

}