#include<iostream>
#include<cmath>
#include<iomanip>

//given function
inline float f(float x,float y) {return x+2-y;}

using namespace std;
int main()
{
 float x, y, xn, k, sum=0, h, grad;
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

 cout<<"\nx0\ty0\tGradient\tyn\n";
 cout<<"-------------------------------------------"<<endl;

 for(i=0; i < n; i++)
 {
  grad = f(x, y);
  k = h * grad;
  cout<< x<<"\t"<< y0<<"\t"<< grad<<"\t\t"<< y+k<< endl;
  y = y+k;
  x = x+h;
 }

 cout<< endl<<"Required value of y at x= "<<xn<<"is: "<< y<<endl;

 return 0;
}