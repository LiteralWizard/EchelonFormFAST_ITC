#include <iostream>
using namespace std;

void print2DArray(float Array[][3], int Rows, int Columns)
{
	for(int itr=0; itr<Rows; itr++)
	{
		for(int itr2=0; itr2<Columns; itr2++)
		{
			cout<<Array[itr][itr2];
			if(Array[itr][itr2]<10 && Array[itr][itr2]>-10)
			{
				cout<<"   ";
			}
			else
			{
				cout<<"  ";
			}
		}
		cout<<endl;
	}
	cout<<endl;
}

int main() {
	float Matrix[3][3];
	int Row=3;
	int Col=3;
	for(int itr=0; itr<Row; itr++)
	{
		for(int itr2=0; itr2<Col; itr2++)
		{
			cout<<"Enter element at Row "<<itr<<" and Column "<<itr2<<": ";
			cin>>Matrix[itr][itr2];
		}
	}

	cout<<"Your Matrix was:"<<endl;
	print2DArray(Matrix,Row,Col);
	for(int Leading1=0; Leading1<Row; Leading1++)
	{
		int OneInd=0;
		while(Matrix[Leading1][OneInd]==0)
		{
			OneInd+=1;
		}
		if(Matrix[Leading1][OneInd]!=0)
		{
			float Divisor=Matrix[Leading1][OneInd];
			for(int itr=OneInd; itr<Col; itr++)
			{
				Matrix[Leading1][itr]=Matrix[Leading1][itr]/Divisor;
			}
		}

		if(Leading1!=Row-1)
		{
			for(int itr=Leading1+1; itr<Row; itr++)
			{
				float Multiple=Matrix[itr][OneInd]/Matrix[Leading1][OneInd];
				for(int itr2=OneInd; itr2<Col; itr2++)
				{
					Matrix[itr][itr2]=Matrix[itr][itr2]-(Multiple*Matrix[Leading1][itr2]);
				}
			}
		}
	}
	cout<<endl<<"Echelon form: "<<endl;
	print2DArray(Matrix,Row,Col);
	return 0;
}