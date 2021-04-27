#include <iostream>
#include<string>
#include<cstdlib>
#include<math.h>
using namespace std;

float ADD(float a, float b) // addition function

{
   return a+b;

}

float SUBTRACT(float a, float b) // subtraction function
{
    return a-b;
}

int main() // start of program
{
	float x1,x2; // variables for functions
	float sum[100][100];
	float subtr[100][100];
	float multiply[100][100];
    //

	char op; // operator"+,-.*"
	string op1; //

	string string_ip1,string1; // variables for first matrix
	int length1;
	int i, j, c, r,k;
	r = 0, i = 0, c = 0, j = 0,k=0;
	float string2;
	float matrix1[100][100];

	string detector1_1; // variables for calculating number of rows and columns for 1st matrix
	int n_rows1, n_columns1, counter1_1, counter1_2;
	counter1_1 = 0;
	counter1_2 = 0;
	n_rows1, n_columns1 = 0;


    string string_ip2, string3; // variables for matrix 2
	int length2;
	float string4;
	float matrix2[100][100]; //

	string detector2_1; // variables for calculating number of rows and columns of 2nd matrix
	int n_rows2, n_columns2, counter2_1, counter2_2;
	counter2_1 = 0;
	counter2_2 = 0;
	n_rows2, n_columns2 = 0; //


	getline( cin, string_ip1); //input 1

    length1 = string_ip1.length(); // working on matrix 1
	for (i = 0; i < length1; i++) // rows counter
	{
		detector1_1 = string_ip1[i];
		if (detector1_1 == ";")
			counter1_1 = counter1_1 + 1;
	} // end of rows counter
	n_rows1 = counter1_1 + 1; // number of rows

	for (i = 0; i < length1; i++) // columns counter
	{
		detector1_1 = string_ip1[i];
		if (detector1_1 == " ")
			counter1_2 = counter1_2 + 1;
		if (detector1_1 == ";")
			break;
	}
	n_columns1 = counter1_2 + 1; // end of columns counter


    int flag1; // checking for error in matrix1
	int counter1_error=0;
	j=0;
	for(i=0;i<length1;i++)
    {

        if(string_ip1[i]==';'||string_ip1[i]==']')
        {
            counter1_error=0;
            for(j;j<i;j++)
            {
                if(string_ip1[j]==' ')
                {
                    counter1_error=counter1_error+1;
                } }
                j=i;

                   if( (counter1_error+1) %n_columns1!=0 &&n_columns1!=1)
                {
                    cout<<"ERROR";
                    flag1=0; // tells me that the matrix is ready for any operation(+,-,*)
                    return 0; // means matrix is not correct
                }

                if( (counter1_error+1)!=n_columns1&&n_columns1==1)
                {
                    cout<<"ERROR";
                    return 0; // means matrix is not correct
                }

                }
            }


	for (i = 1; i < length1 - 1; i++) // storing elements into array 1
	{
		string1 += string_ip1[i];
		if (string_ip1[i] == ' ')
		{
			string1 = string1.substr(0, string1.length() - 1);
			string2 = atof(string1.c_str());
			matrix1[r][c] = string2;
			string1 = "";
			c++;
		}
		if (string_ip1[i] == ';')
		{
			string1 = string1.substr(0, string1.length() - 1);
			string2 = atof(string1.c_str());
			matrix1[r][c] = string2;
			r++;
			c = 0;
			string1 = "";
		}
		if (string_ip1[i+1] == ']')
		{
			string1 = string1.substr(0, string1.length());
			string2 = atof(string1.c_str());
			matrix1[r][c] = string2;
			break;
		}
	}


    getline(cin,op1); // input of character and matrix2
    getline(cin, string_ip2);
    op=op1[0];//

    r = 0, i = 0, c = 0, j = 0; // working on 2nd matrix
	length2 = string_ip2.length();

	for (i = 0; i < length2; i++) // rows counter
	{
		detector2_1 = string_ip2[i];
		if (detector2_1 == ";")
			counter2_1 = counter2_1 + 1;
	} // end of rows counter

	n_rows2 = counter2_1 + 1; // number of rows

	for (i = 0; i < length2; i++) // columns counter
	{
		detector2_1 = string_ip2[i];
		if (detector2_1 == " ")
			counter2_2=counter2_2+1;
		if (detector2_1 == ";")
			break;
	}
	n_columns2 = counter2_2 + 1; // end of columns counter


    int flag2; // checking for error in matrix 2
	int counter2_error=0;
	j=0;
	for(i=0;i<length2;i++)
    {

        if(string_ip2[i]==';'||string_ip2[i]==']')
        {
            counter2_error=0;
            for(j;j<i;j++)
            {
                if(string_ip2[j]==' ')
                {
                    counter2_error=counter2_error+1;
                } }
                j=i;

                   if( (counter2_error+1) %n_columns2!=0&&n_columns2!=1)
                {
                    cout<<"ERROR";
                    return 0; // means matrix is not correct
                }
                if( (counter2_error+1)!=n_columns2&&n_columns2==1)
                {
                    cout<<"ERROR";
                    return 0; // means matrix is not correct
                }
                }
            }

	for (i = 1; i < length2 - 1; i++) // Storing elements into array 2
	{
		string3 += string_ip2[i];
		if (string_ip2[i] == ' ')
		{
			string3 = string3.substr(0, string3.length() - 1);
			string4 = atof(string3.c_str());
			matrix2[r][c] = string4;
			string3 = "";
			c++;
		}
		if (string_ip2[i] == ';')
		{
			string3 = string3.substr(0, string3.length() - 1);
			string4 = atof(string3.c_str());
			matrix2[r][c] = string4;
			r++;
			c = 0;
			string3 = "";
		}
		if (string_ip2[i+1] == ']')
		{
			string3 = string3.substr(0, string3.length());
			string4 = atof(string3.c_str());
			matrix2[r][c] = string4;
			break;
		}
	} //


    switch(op)
    {
        case'+': // addition case
        if(n_rows1==n_rows2&&n_columns1==n_columns2)
       {
           for(i=0;i<n_rows1;i++)
       {
           for(j=0;j<n_columns1;j++)
       {
        x1=matrix1[i][j];
        x2=matrix2[i][j];
        sum[i][j]=ADD(x1,x2); }
       }
       cout<<"[";
       for(i=0;i<n_rows1;i++)
       {
           for(j=0;j<n_columns1;j++)
           {
            cout<<sum[i][j];
            if(j<n_columns1-1)
            {
                cout<<" ";
            }
           }
           if(i<n_rows1-1)
           cout<<";";
       }
       cout<<"]";
       }
       else {cout<<"ERROR";
       return 0;} // ADDITION ERROR
       break;

       case '-': // subtraction case

   if(n_rows1==n_rows2&&n_columns1==n_columns2)
       {
           for(i=0;i<n_rows1;i++)
       {
           for(j=0;j<n_columns1;j++)
       {
        x1=matrix1[i][j];
        x2=matrix2[i][j];
        subtr[i][j]=SUBTRACT(x1,x2); }
       }
       cout<<"[";
       for(i=0;i<n_rows1;i++)
       {
           for(j=0;j<n_columns1;j++)
           {
            cout<<subtr[i][j];
           if(j<n_columns1-1)
            {
                cout<<" ";
            }
           }
           if(i<n_rows1-1)
           cout<<";";
       }
       cout<<"]";
       }
       else {cout<<"ERROR";
       return 0;} // ADDITION ERROR
       break;

       case '*': // multiplication case
           if(n_columns1!=n_rows2)
            {
            cout<<"ERROR";
            return 0;
            }
           if(n_rows2==n_columns1)
           {
               for(i=0;i<n_rows1;i++)

                   for(j=0;j<n_columns2;j++)
                   {
                       multiply[i][j]=0;
                       }
                       for(i=0;i<n_rows1;i++)

                           for(j=0;j<n_columns2;j++)
                            for(k=0;k<n_columns1;k++)
                           {
                                multiply[i][j] += matrix1[i][k] * matrix2[k][j];
                           }

               cout<<"[";
           for(i=0;i<n_rows1;i++)
           {
               for(j=0;j<n_columns2;j++)
               {
                   cout<<multiply[i][j];
                   if(j<n_columns2-1)
                   {
                       cout<<" ";
                   }
               }
               if(i<n_rows1-1)

               cout<<";";
           }
           cout<<"]";}
           break;

    default:
        {cout<<"ERROR";
        return 0;
        }// error for inserting wrong operator

     } // end of operations
return 0;
}
