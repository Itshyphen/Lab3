
#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	 float data[2][100],  x=0, y=0, p;
	 int i,j,n;
	 cout<<"Enter number of data: ";
	 cin>>n;
	 cout<<"Enter data:"<< endl<<"x , y"<<endl;
	 for(i=0;i<n;i++)
	 {
		 scanf("%f, %f", &data[0][i], &data[1][i]);
	 }
	 cout<<"Enter interpolation point: ";
	 cin>>x;

	 /* Implementing Lagrange Interpolation */
	 for(i=0;i<n;i++)
	 {
		  p=1;
		  for(j=0;j<n;j++)
		  {
			   if(i!=j)
			   {
			    	p = p* (x - data[0][j])/(data[0][i] - data[0][j]);
			   }
		  }
		  y = y + p * data[1][i];
	 }
	 cout<< endl<<"Interpolated value at "<< x<< " is "<< y<<endl;

	 return 0;
}

