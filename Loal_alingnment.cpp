#include <string>
#include <iostream>
#include<conio.h>
using namespace std;
 int main()

{
	
	string base1;
	string base2;
	int gap=0;
	int match=+2;
	int mismatch=1;
	int d,h,v;
	
	
	 cout<<" enter 1st string"<<endl;
	 cin>>base1;
	 cout<<"enter your second string"<<endl;
	 cin>>base2;
	 cout<<"Second string you entered is;  "<<base1<<endl;
	 cout<<"Second string you entered is;  "<<base2<<endl;
	                   
	            
	            int len1=base1.length()+1; 
	        
	            int len2=base2.length()+1;
	                            /////dynamic array initializing
	                            ////int arr1[len1][len2] gives compiler error so to overcome it we make dynamic array
	  int** arr1= new int*[len1];
	  for (int i=0;i<len1;i++)
	  {
		  arr1[i]=new int[len2];
	  }
	  ////filling of rows and coloumns
	  arr1[0][0]=0;
	  ////row filling
	  for (int j=1;j<len2;j++)
	  {
		  arr1[0][j]=0;
	  }
	  ////  column filling
	  for(int i=1;i<len1;i++)
	  {
		  arr1[i][0]=0;
	  }
	  //// string comparison ////
	  for (int i=1;i<len1;i++)
	  {
		  for (int j=1;j<len2;j++)
		  {
			  if (base1[i-1]==base2[j-1])
			  {
				  d=arr1[i-1][j-1]+match;
			  }
			  //// for mismatch
			  else
			  {
				  d=arr1[i-1][j-1]+mismatch;
				  v=arr1[i-1][j]+gap;
				  h=arr1[i][j-1]+gap;
				  
			  }
			  if (d>v&&d>h&&d>0)
			  {
				  arr1[i][j]=d;
			  }
			  else if (h>d && h>v&&h>0)
			  {
				  arr1[i][j]=h;
			  }
			   else if (v>d && v>h&&v>0)
			  {
				  arr1[i][j]=v;
			  }
			    else if (d==v ||d==h|| v==h||d==0)
			  {
				  arr1[i][j]=d;
			  }
		  }
	  }
	  //printing of the array
	 for(int i=0;i<len1;i++)
	{
		  for (int j=1;j<len2;j++)
		  {
			  cout<<arr1[i][j]<<"\t";
		}
		  cout<<endl;
	}
	 //// code for backtracking
		  int r;
		  int c;
		  int a=len1; //// row
		  int b=len2; //// coloumn
		  
		  char* arr2= new char[len1];
	      char* arr3= new char[len2];
		   for (int r=0;r<len1;r--)
		   {
		
		for (int a=len1;a>=len1;a--)
		         {
		          	for (int j=len2;j>=0;j--)
		                        	if (arr1[a][b]==d)
		                               	{
		       	                       	arr2[r]=base1[a];
		       	                     arr3[c]=base2[b];
		       	                     a--;
		       	                     b--;
		       	                     r++;
		       	                     c++;
		       	                        }
		                        	else if (arr1[a][b]==v)
		                        	  {
		                        	arr2[r]='-';
		                        	  	arr3[c]=base2[b];
		                        	  	b--;
		                        	
		                        	  	r++;
		                        	  	c++;
		                        	  }
		                        	  else if (arr1[a][b]==h)
		                        	{
		                        		arr2[r]=base1[a];
		                        		arr3[c]='-';
		                        		
		                        		a--;
		                        		r++;
		                        		c++;
		                        	}
		        
		
 for (int r=len1;r>=len1;r--)		       
  {
	for (int c=len2;c>=0;c--)
	{
		            
cout<<arr2[r]<<"\t";
	cout<<arr3[c]<<"\t";
		                    
		                                 }
		                             }
		                        	getch ();
		                        	return 0;
		                        	cout<<endl;
		                        }
		                    }
		                }
		                        	
