#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	 string line1;
  int count;
  ifstream myfile1 ("D:HIV.txt");
  if (myfile1.is_open())
  {

	while ( getline (myfile1,line1) )
    {
    
       cout <<line1<<endl;
      
  }
  string sequence1;
   if(line1[0] == '>')
      {
      	sequence1=line1;
         cout <<sequence1<<endl;
      }
    myfile1.close();
  }
  string line2;
  ifstream myfile2 ("D:abc.txt");
  if (myfile2.is_open())
  {
    
	while ( getline (myfile2,line2) )
    {
    	
       cout <<line2<<endl;
  }
  string sequence2;
  if(line2[0] == '>')
      {
      	sequence2=line2;
         cout <<sequence2<<endl;
      }
  myfile2.close();
}
  string line3;
  ifstream myfile3 ("D:Human.txt");
  if (myfile3.is_open())
  {
    
	while ( getline (myfile3,line3) )
    {
    	
       cout <<line3<<endl;
      
  }
  string sequence3;
  if(line3[0]=='>')
  {
  	sequence3=line3;
  	cout<<sequence3<<endl;
  }
  myfile3.close();
}
  else cout << "Unable to open the file"<<endl;
  int len1=sizeof(line1)+1;   //// storing the value present in first file to find its length
cout<<"length of the first sequence is"<<":"<<len1<<endl;
int len2=sizeof(line2)+1; 
cout<<"length of the second sequence is"<<":"<<len2<<endl;

int len3=sizeof(line3)+1;

string sequence1;
string sequence2;
string sequence3;
int match=1;/// value to show match
int mismatch=-1;/// value to show mismatch
int gap=-2; /// shows gap score
int H= 1; /// shows the value in upward directio
int V =2; /// value in left direction
int D= 3; /// value to show in diagnol direction
int i; // for iteration
int j; /// iteration

int NALIGN=100;
char Align1[NALIGN]; /// Aligned sequence1
char Align2[NALIGN]; //// Aligned sequence2
char Align3[NALIGN]; /// aligned sequence3

cout<<"length of the third sequence is"<<":"<<len3<<endl;
cout<<"Aligning the first pair"<<endl;
cout<<"enter the first string"<<endl;
cin>>sequence1;
cout<<"enter the second string"<<endl;
cin>>sequence2;

//// globally aligning s1 and s2
int **align1= new int*[len1]; //// dynamic  array decleration 
{
for(int j=0;j<len1;j++)
{
align1[i]= new int[len2];
}
/// Alignment
 align1[0][0]=0;
     for(int i=1;i<len1;i++)
     {
     align1[i][0]=gap+align1[i-1][0];       
     }
    for(int j=1;j<len2;j++)
    {
      align1[0][j]=gap+align1[0][j-1];       
     }
  //matrix filling for s1 and s2
    for(int i=1;i<len1;i++)
    {
    for(int j=1;j<len2;j++)
    {
    if(sequence1[i-1]==sequence2[j-1])
    {
     D=align1[i-1][j-1]+match;
    }
    else
   {
    D=align1[i-1][j-1]+mismatch;
    V=align1[i-1][j]+gap;
    H=align1[i][j-1]+gap;
    }
    if(D>V&&D>H)
    {
    align1[i][j]=D;
    }
	else if(H>D&&H>V)
    {
    align1[i][j]=H;
    }
    else if(V>D&&V>H)
    {
    align1[i][j]=V;
    }
    else if(D==V||D==H||V==H)
    {
    align1[i][j]=D;
    }
    }
    }
//// backtracking
                                                                                     
for(int i=len1;i>0;i--)
{
for(int j=len2;j>0;j--)
{
if(align1[i-1][j-1]>align1[i-1][j]&&align1[i-1][j-1]>align1[i][j-1])
{
align1[i][j]=align1[i-1][j-1];
}if(align1[i-1][j]>align1[i-1][j-1]&&align1[i-1][j]>align1[i][j-1])
{
align1[i][j]=align1[i-1][j];
}
else
{
align1[i][j]=align1[i][j-1];
}
}
}
                    /// printing the matrix
                 for (int i=0;i<len1;i++)
                {
                for(int j=0;j<len2;j++)
                { 
                cout<<align1[i][j]<<"\t";
                }
                }
                /// now storing the result into another array and comparing it with sequence 3
                string temp; /// value to store the result of the 1st dynamic array
                int len4=sizeof(temp)+1;
                temp=align1[i][j];
                cout<<"result of the first pair alignment is "<<temp<<endl;
                 /// to get the value in length of the result of the array
                /// comparing result of s1 ,s2 and s3
                int **align2= new int*[len3];
                {
                	for(int n=0;n<len3;n++)
                	{
                		align2[i]= new int[len4];
                	}
                }
                /// doing alignment to get the final matrix
                cout<<"enter the third string"<<endl;
                cin>>sequence3;
                int m,n;
                align2[0][0]=0;
     for(int m=1;m<len3;m++)
     {
     align2[m][0]=gap+align2[m-1][0];       
     }
    for(int n=1;n<len4;n++)
    {
      align2[0][n]=gap+align2[0][n-1];       
     }
  //matrix filling for s1 and s2
    for(int m=1;m<len3;m++)
    {
    for(int n=1;n<len4;n++)
    {
            if(sequence3[m-1]==temp[m-1])
            {
                                    D=align2[m-1][n-1]+match;
                                    }
                                    else
                                    {
                                        D=align2[m-1][n-1]+mismatch;
                                        V=align2[m-1][n]+gap;
                                        H=align2[m][n-1]+gap;
                                        }
                                        if(D>V&&D>H)
                                        {
                                        align2[m][n]=D;
                                        }
                                        else if(H>D&&H>V)
                                        {
                                        align2[m][n]=H;
                                        }
                                         else if(V>D&&V>H)
                                        {
                                        align2[m][n]=V;
                                        }
                                        else if(D==V||D==H||V==H)
                                        {
                                        align2[m][n]=D;
                                        }
                                        }
                                        
//// backtracking
                                                                                     
for(int m=len3;m>0;m--)
{
for(int n=len4;n>0;n--)
{
	if(align2[m-1][n-1]>align2[m-1][n]&&align2[m-1][n-1]>align2[m][n-1])
    {
    align2[m][n]=align2[m-1][n-1];
    }
    if(align2[m-1][n]>align2[m-1][n-1]&&align2[m-1][n]>align2[m][n-1])
    {
    align2[m][n]=align2[m-1][n];
    }
    else
    {
    align2[m][n]=align2[m][n-1];
    }
    }
    }
                /// printing the matrix
                for (int m=0;m<len3;m++)
                {
                	for(int n=0;n<len4;n++)
                	{ 
                	 cout<<align2[m][n]<<"\t";
                	}
                }
      
                
                
            

  


             

	getch ();
	return 0;
	
}
}
}
