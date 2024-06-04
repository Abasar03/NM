#include<stdio.h>
#include<math.h>
#define f(x) (pow(5,x)-(6*x))
 
void main()
{
	 float x0, x1, x2, f0, f1, f2, e;
	 int step = 1; 
 
	 up:
	 printf("\nEnter two initial guesses x0 abd x1:\n");
	 scanf("%f%f", &x0, &x1);
	 printf("Enter maximum error:\n");
	 scanf("%f", &e);
	 f0 = f(x0);
	 f1 = f(x1);
    printf("\nf0:%f\nf1:%f\n",f0,f1);	
	 if( f0 * f1 > 0.0)
	 {
		  printf("Incorrect Initial Guesses.\n");
		  goto up;
	 }
     printf("\n____________________________________________________________________________\n");
	 printf("\nIteration\tx0\t\tx1\t\tx2\t\tf(x2)\n");
     printf("\n____________________________________________________________________________\n");
 
	 do
	 {
		  x2 = (x0 + x1)/2;
		  f2 = f(x2);
 
		  printf("%d\t\t%f\t%f\t%f\t%f\n",step, x0, x1, x2, f2);
 
		  if( f0 * f2 < 0.0)
		  {
			   x1 = x2;
			   f1 = f2;
		  }
		  else
		  {
			   x0 = x2;
			   f0 = f2;
		  }
		  step = step + 1;
	 }while(fabs(f2)>e);
     printf("\n____________________________________________________________________________\n");
	 printf("\nRoot is: %f", x2);
 
}