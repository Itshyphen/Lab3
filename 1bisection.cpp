// //bisection method
// #include<iostream>
// #include<cmath>
// #include<iomanip>
// using namespace std;
  
// inline double f(double x)   
// {
//     return pow(x,3)-x-11.0;    //write the equation whose roots are to be determined
// }
// int main()
// {    
//     cout<<setprecision(4)<<fixed;        

//     double a,b,c,error,fa,fb,fc;    
//     do{
//     cout<<"Enter the initial guesses:\na=";    //Enter the value of a
//     cin>>a;
//     cout<<"\nb=";            //Enter the value of b
//     cin>>b;
//     }while(f(a)*f(b)>0);


//     cout<<"\nEnter the degree of accuracy desired"<<endl;    //Enter the accuracy
//     cin>>error;              

//     cout<<setw(20)<<"a"<<setw(20)<<"b"<<setw(20)<<"c"<<setw(20)<<"f(c)"<<endl;

//     while (fabs(a-b)>=error)        //If the difference of a and b is greater than error, continue the iteration
//     {
//         c=(a+b)/2.0; 

//         fa=f(a);        fb=f(b);        fc=f(c);

//         cout<<setw(20)<<a<<setw(20)<<b<<setw(20)<<c<<setw(20)<<fc<<endl;

//         if (fc==0)        
//         {
//             cout<<"The root of the equation is "<<c;    
//             break;
//         }
 
//         if (fa*fc>0)    //if f(a)xf(c)>0, that means no root exist between a and c 
//         {
//             a=c;   
//         }
//         else if (fa*fc<0)
//         {    
//             b=c;    
//         }    
         
     
//     }
//  //The loop ends when the difference between a and b becomes less than the desired accuracy ie now the value stored in 'c' can be called the approximate root of the equation         
//     cout<<"\nThe root of the equation is "<<c;    //print the root    
//     return 0;    
// }

#include<iostream>
#include<iomanip>
#include<math.h>

/*
 Defining equation to be solved.
 Change this equation to solve another problem.
*/

#define f(x) log(x) - x

using namespace std;

int main()
{
	 /* Declaring required variables */
	 float x0, x1, x, f0, f1, f, e;
	 int step = 1;

	 /* Setting precision and writing floating point values in fixed-point notation. */
     cout<< setprecision(6)<< fixed;

	 /* Inputs */
	 up:
	 cout<<"Enter first guess: ";
     cin>>x0;
     cout<<"Enter second one: ";
     cin>>x1;
     cout<<"Enter tolerable error: ";
     cin>>e;

	 /* Calculating Functional Value */
	 f0 = f(x0);
	 f1 = f(x1);

	 /* Checking whether given guesses brackets the root or not. */
	 if( f0 * f1 > 0.0)
	 {
		  cout<<""<< endl;
		  goto up;
	 }
   /* Implementing Bisection Method */
     
	 cout<<"Bisection Method"<< endl;
	 
	 do 
	 {
		  /* Bisecting Interval */
		  x = (x0 + x1)/2;
		  f = f(x);

		  cout<<"step-"<< step<<":\t x = "<< setw(10)<< x<<" and f(x) = "<< setw(10)<< f(x)<< endl;

		  if( f0 * f < 0)
		  {
			   x1 = x;
		  }
		  else
		  {
			   x0 = x;
		  }
		  step = step + 1;
	 }while(fabs(f)>e);

	 cout<< endl<< "Required root is: "<<  x<< endl;

	 return 0;
}