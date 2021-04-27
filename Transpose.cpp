#include <iostream>
#include<string>
#include<cstdlib>
#include<math.h>
using namespace std;



int main()
{
	float Transpose[100][100];
	float Determinant[100][100];
	float Power[100][100];
	char op; // operator"^,T,D"
	string op1;
	string num;
	int n;
	int z = 0; // power
	float temp[100][100];
	float multiply[100][100];

	string string_ip1, string1; // variables for first matrix
	int length1;
	int i, j, c, r, k;
	r = 0, i = 0, c = 0, j = 0, k = 0;
	float string2;
	float matrix1[100][100];

	string detector1_1; // variables for calculating number of rows and columns for 1st matrix
	int n_rows1, n_columns1, counter1_1, counter1_2;
	counter1_1 = 0;
	counter1_2 = 0;
	n_rows1, n_columns1 = 0;

	getline(cin, string_ip1); //input

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


	int counter1_error = 0; // error in matrix detection
	j = 0;
	for (i = 0; i < length1; i++)
	{

		if (string_ip1[i] == ';' || string_ip1[i] == ']')
		{
			counter1_error = 0;
			for (j; j < i; j++)
			{
				if (string_ip1[j] == ' ')
				{
					counter1_error = counter1_error + 1;
				}
			}
			j = i;

			if ((counter1_error + 1) % n_columns1 != 0 && n_columns1 != 1)
			{
				cout << "ERROR";
				return 0; // means matrix is not correct
			}

			if ((counter1_error + 1) != n_columns1 && n_columns1 == 1)
			{
				cout << "ERROR";
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
		if (string_ip1[i + 1] == ']')
		{
			string1 = string1.substr(0, string1.length());
			string2 = atof(string1.c_str());
			matrix1[r][c] = string2;
			break;
		}
	}

	cin >> op;

	switch (op)
	{
	case 'T':
		cout << "[";
		for (i = 0; i < n_columns1; i++)
		{
			for (j = 0; j < n_rows1; j++)
			{
				cout << matrix1[j][i];
				if (j < n_rows1 - 1)
					cout << " ";
			}
			if (i < n_columns1 - 1)
				cout << ";";
		}
		cout << "]";
		break; // runs successfully

	case '^':
		cin >> n; // +ve integar power
		if (n <= 0)
		{
			cout << "ERROR";
			return 0;
		}
		if (n_rows1 != n_columns1)
		{
			cout << "ERROR";
			return 0;
		} // power conditions
		if (n == 1)
		{
			cout << "[";
			for (i = 0; i < n_rows1; i++)
			{
				for (j = 0; j < n_columns1; j++)
				{
					cout << matrix1[i][j];
					if (j < n_columns1 - 1)
						cout << " ";
				}
				if (i < n_rows1 - 1)
					cout << ";";
			}
			cout << "]";
			return 0;
		}


		for (i = 0; i < n_rows1; i++) // delete later
			for (j = 0; j < n_columns1; j++)

			{
				temp[i][j] = matrix1[i][j];
			} //

		while (n > 1)
		{
			for (i = 0; i < n_rows1; i++)

				for (j = 0; j < n_columns1; j++)
				{
					multiply[i][j] = 0;
				}
			for (i = 0; i < n_rows1; i++)

				for (j = 0; j < n_columns1; j++)
					for (k = 0; k < n_columns1; k++)
					{
						multiply[i][j] += temp[i][k] * matrix1[k][j];
					}

			n--;
			for (i = 0; i < n_rows1; i++)
			{
				for (j = 0; j < n_columns1; j++)

				{
					matrix1[i][j] = multiply[i][j];
					Power[i][j] = multiply[i][j];


				}
			}
		}

		cout << "[";
		for (i = 0; i < n_rows1; i++)
		{
			for (j = 0; j < n_columns1; j++)
			{
				cout << Power[i][j];
				if (j < n_columns1 - 1)
					cout << " ";
			}
			if (i < n_rows1 - 1)
				cout << ";";
		}
		cout << "]";
		break;

	case 'D':

		float div; // short for dividor
		float det;

		if (n_rows1 != n_columns1)
		{
			cout << "ERROR";
			return 0;
		}
		if (n_rows1 == 2)
		{
			cout << (matrix1[0][0] * matrix1[1][1]) - (matrix1[0][1] * matrix1[1][0]);
			return 0;

		}
		if (n_rows1 == 1)
		{
			cout << matrix1[0][0];
			return 0;
		}
		else
		{
			for (i = 1; i < n_rows1; i++)
			{
				div = matrix1[i][0] / matrix1[0][0];
				for (j = 0; j <= n_columns1; j++)
				{
					matrix1[i][j] = matrix1[i][j] - (div * matrix1[0][j]);
				}
			}
			for (i = 0; i < n_rows1; i++)
			{
				div = 0;
				for (j = 0; j <= n_columns1; j++)
				{
					if (i > j && matrix1[i][j] != 0)
					{
						div = matrix1[i][j] / matrix1[i - 1][j];
						for (int c = 0; c < n_columns1; c++) {
							matrix1[i][c] = matrix1[i][c] - (div * matrix1[i][c]);
						}
					}
				}
			}
			for (i = 0; i < n_rows1; i++)
			{
				for (j = 0; j < n_columns1; j++)
				{
					if (i == j)
					{
						det *= matrix1[i][j];
					}
				}
			}
			cout << det;
		}

		break;


		/*case'I':
				if(n_rows1!=n_columns1)
				{
					cout<<"ERROR";
					return 0;
				}
				if(n_rows1==2)
				{
				float d;
				d= (matrix1[0][0]*matrix1[1][1])-(matrix1[0][1]*matrix1[1][0]);
				float inverse[n_rows1][n_rows1];

							swap(matrix1[0][0],matrix1[1][1]);

						matrix1[0][1]=-1*matrix1[1][0];
						matrix1[1][0]=-1*matrix1[1][0];

		cout<<"[";
			for(i=0;i<n_columns1;i++)
			{
				for(j=0;j<n_rows1;j++)
				{
					cout<<matrix1[j][i]*d;
					if(j<n_rows1-1)
					cout<<" ";
				}
				if(i<n_columns1-1)
					cout<<";";
			}
			cout<<"]";


				}
		else
		{
			cout<<"["; // temporary
			for(i=0;i<n_columns1;i++)
			{
				for(j=0;j<n_rows1;j++)
				{
					cout<<matrix1[j][i];
					if(j<n_rows1-1)
					cout<<" ";
				}
				if(i<n_columns1-1)
					cout<<";";
			}
			cout<<"]";
		}

		break;

		default: cout<<"ERROR";

		}*/
	}
		return 0;
	}
