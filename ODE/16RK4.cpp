#include<iostream>
#include<cmath>
#include<iomanip>

//given function
inline float f(float x,float y) {return x*2-y;}

using namespace std;
int main()
{
 float x, y, xn, k1,k2,k3,k4,k, sum=0, h, grad;
 int i, n;

 cout<<setprecision(4)<<fixed;

 cout<<"Enter initial condition, x0: ";
 cin>>x;
 cout<<"Enter initial condition, y0: ";
 cin>>y;
 cout<<"Enter no. of steps, n: ";
 cin>>n;
  cout<<"Enter calculation point, xn: ";
 cin>>xn;

//finding stepsize
 h = (xn - x)/n;

 cout<<"\nx0\ty0\tf(x,y)\tf(x+h,y+k)\tyn\n";
 cout<<"-------------------------------------------"<<endl;

 for(i=0; i < n; i++)
 {
  grad = f(x, y);
  k1 = h * f(x, y);
  k2 = h * f(x+h/2, y+k1/2);
  k3 = h * f(x+h/2, y+k2/2);
  k4 = h * f(x+h, y+k3);
  k  = (k1+2*k2+2*k3+k4)/6.0;
  cout<< x<<"\t"<<"\t\t"<< y+k<< endl;
  y = y+k;
  x = x+h;
 }

 cout<< endl<<"Required value of y at x= "<<xn<<"is: "<< y<<endl;

 return 0;
}