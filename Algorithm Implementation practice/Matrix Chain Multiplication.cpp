/************************************************************************************************
*  Matrix multiplication optimizer
*  by Richard Lundeen - webstersProdigy.net
*
*  This program optimizes the order in which a chain of matrices are multiplied together in
*  O(n^3).  It prints out tables for documentation purposes - although these are not necessary
*  to understand the final grouping
*
**************************************************************************************************/

#include <iostream>

using namespace std;

void printdobArray(int** array, int row, int col);
void printOptimalParens(int** kArray, int i, int j);

int main()
{
   int numMat;
   cout<<"**********************************************************************"<<endl
       <<"Welcome to the matrix optimization program.  This program calculates"<<endl
       <<"the optimal way to multiply a series of matrices together"<<endl
       <<"*********************************************************************"<<endl;
   cout<<"Please enter the Number of Matricies: ";
   cin>>numMat;

   int *p;
   int psize = numMat + 1;
   p = new int[psize];

   cout<<"------------------------------------------------------------------------"<<endl
       <<"Now please enter dimensions.  \nFor example, if you were multiplying three matricies "<<endl
       <<"with the respective dimensions 3x1  1x1000 and 1000x13, you would enter '3', '1', '1000', '13'."<<endl
       <<"------------------------------------------------------------------------"<<endl<<endl;
   for(int i = 0; i < psize; i++)
   {
      cout<<"dimension "<<i<<" : ";
      cin>>p[i];
   }

   //an array which holds the cost table
   int **cost;
   cost = new int*[psize];  // sets up an array of row pointers
   for(int i =0; i < psize; i++)
   {
       cost[i] = new int[psize]; // allocates each row of the grades array
   }

   //an array which holds the splits
   int ** kArray;
   kArray = new int*[psize];
   for(int i=0; i<(psize); i++)
   {
      kArray[i]=new int[psize];
   }

   for(int length = 1; length < numMat; length++)
   {
      for(int i = 1; i<numMat-length + 1; i++)
      {

         int j = i+ length;
	 int tempCost;
	 int k = i;
	 int minCost = cost[i][k] + cost[k+1][j] + p[i-1]*p[k]*p[j];
	 int kay = i;
	 for(; k<j; k++)
	 {
	   tempCost = cost[i][k] + cost[k+1][j] + p[i-1]*p[k]*p[j];
	   if(tempCost<minCost)
	   {
	      minCost = tempCost;
	      kay = k;
	   }
	 }

	cost[i][j] = minCost;
	kArray[i][j] = kay;
      }
   }

   cout<<"\nTotal Cost Table\n************************************"<<endl;
   printdobArray(cost, psize, psize);

   cout<<"Corresponding K-Table\n***********************************"<<endl;
   printdobArray(kArray,psize,psize);

   cout<<endl<<endl;
   cout<<"This corresponds to the following multiplication chain"<<endl;
   printOptimalParens(kArray, 1, numMat);
   cout<<endl;
   return 0;
}

void printdobArray(int** array, int row, int col)
{
   for(int i = 1; i<row; i++)
   {
      for(int j=1; j<col; j++)
         cout<<array[i][j]<<"\t|\t";
      cout<<endl;
   }
}

void printOptimalParens(int** kArray, int i, int j)
{
   if(i==j)
    {
       cout<<"A"<<i<<" ";
    }
    else
    {
       cout<<"(";
       printOptimalParens(kArray,i, kArray[i][j]);
       printOptimalParens(kArray, kArray[i][j] + 1, j);
       cout<<")";
    }
}