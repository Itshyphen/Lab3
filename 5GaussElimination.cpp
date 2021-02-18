#include<iostream>
/* math.h header file is included for abs() function */
#include<math.h>
using namespace std;

int main()
{
    int i,j,k,D;
    
    cout<<"\nEnter the no. of equations: ";        
    cin>>D;
    
    /* if no of equations are D then size of augmented matrix will be D*D+1. So here we are declaring 2d array 'mat' of size D+D+1 */
    float mat[D][D+1];
    
    /* for D equations there will be D unknowns which will be stored in array 'res' */
    float res[D];
   
    cout<<"\nEnter the elements of the augmented matrix: ";
    for(i=0;i<D;i++)
    {
      for(j=0;j<D+1;j++)
    {
      cin>>mat[i][j]; 
    }    
    }
  
    for(i=0;i<D;i++) 
    {                   
        for(j=i+1;j<D;j++)
        {
            if(abs(mat[i][i]) < abs(mat[j][i]))
            {
                for(k=0;k<D+1;k++)
                {
                    /* swapping mat[i][k] and mat[j][k] */
        mat[i][k]=mat[i][k]+mat[j][k];
                    mat[j][k]=mat[i][k]-mat[j][k];
                    mat[i][k]=mat[i][k]-mat[j][k];
                }
            }
      }
    }
   
     /* performing Gaussian elimination */
    for(i=0;i<D-1;i++)
    {
        for(j=i+1;j<D;j++)
        {
            float f=mat[j][i]/mat[i][i];
            for(k=0;k<D+1;k++)
            {
              mat[j][k]=mat[j][k]-f*mat[i][k];
      }
        }
    }

    /* Backward substitution for discovering values of unknowns */
    for(i=D-1;i>=0;i--)          
    {                     
        res[i]=mat[i][D];
                    
        for(j=i+1;j<D;j++)
        {
          if(i!=j)
          {
              res[i]=res[i]-mat[i][j]*res[j];
    }          
  }
  res[i]=res[i]/mat[i][i];  
    }
    
    cout<<"\nThe values of unknowns for the above equations=>";
    for(i=0;i<D;i++)
    {
      cout<<res[i]<<"\n";
    }
      
    return 0;
}