#include<iostream>
#include<cmath>
#include<iomanip>

//given function
inline float f(float x, float y, float z) {return y+2;}

inline float g(float x, float y, float z) {return x*z-y;}

using namespace std;
int main()
{
 float x, y, z, xn, k1,k2,k3,k4,k,l1,l2,l3,l4,l, sum=0, h, grad;
 int i, n;

 cout<<setprecision(4)<<fixed;

 cout<<"Enter initial condition, x0: ";
 cin>>x;
 cout<<"Enter initial condition, y0: ";
 cin>>y;
 cout<<"Enter initial condition, z0: ";
 cin>>z;

 cout<<"Enter no. of steps, n: ";
 cin>>n;
 cout<<"Enter calculation point, xn: ";
 cin>>xn;

//finding stepsize
 h = (xn - x)/n;

 cout<<"\nx\tyn\n";
 cout<<"-------------------------------------------"<<endl;

 for(i=0; i < n; i++)
 {
  grad = f(x, y, z);
  k1 = h * f(x, y, z);
  l1 = h * g(x, y, z);
  k2 = h * f(x+h/2, y+k1/2, z+l1/2);
  l2 = h * g(x+h/2, y+k1/2, z+l1/2);
  k3 = h * f(x+h/2, y+k2/2, z+l2/2);
  l3 = h * g(x+h/2, y+k2/2, z+l2/2);
  k4 = h * f(x+h, y+k3, z+l3);
  l4 = h * g(x+h, y+k3, z+l3);
  k  = (k1+2*k2+2*k3+k4)/6.0;
  l  = (l1+2*l2+2*l3+l4)/6.0;
  cout<< x<<"\t"<< y+k<< endl;
  y = y+k;
  z = z+l;
  x = x+h;
 }

 cout<< endl<<"Required value of y at x= "<<xn<<"is: "<< y<<endl;

 return 0;
}