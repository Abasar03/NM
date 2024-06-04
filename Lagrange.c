#include<stdio.h>
int main(){
    float x[100],y[100],a,s=1,t=1,k=0;
    int n,i,j,d=1;
    printf("Enter the number of the terms of the table: ");
    scanf("%d",&n);
    printf("\nEnter the respective values of the variables x and y:\n");
    for (i=0;i<n;i++){
        scanf("%f",&x[i]);
        scanf("%f",&y[i]);
    }
    printf("\nThe table you entered is as follows:\n");
    for (i=0;i<n;i++){
        printf("%0.3f\t%0.3f\n",x[i],y[i]);
    }
    while(d==1){
        printf("\nEnter the value of the x to find the respective value of y:\n");
        scanf("%f",&a);
        for (i=0;i<n;i++){
            s=1;
            t=1;
            for (j=0;j<n;j++){
                if (j!=i){
                    s=s*(a-x[j]);
                    t=t*(x[i]-x[j]);
                }
            }
        k=k+((s/t)*y[i]);
    }
    printf("The respective value of the variable y is: %f",k);
    printf("\n\nDo you want to continue?Press 1 to continue and any other key to exit:\n");
    scanf("%d",&d);
}
}


