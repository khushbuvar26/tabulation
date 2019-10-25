#include<iostream>
#include<cmath>
using namespace std;
int* convert_binary(int n,int d)
{
	int rem =0,j=0,i=0,k;
	int *rbinary = new int[d];
	int *binary = new int[d];
	while(n!=0)
	{
		rem = n%2;
		n = n/2;
		rbinary[j] = rem;
		j++;
	}
	k = j;
	while(j-1<d-1)     //if we have 3 variable functions for suppose then to store 0s in initial places like 010 for 2 instead of 10
	{
		binary[i] = 0;
		i++;
		j++;	
	}
	k=k-1;
	while(k>=0)
	{
		binary[i] = rbinary[k];
		i++;
		k--;
	}	
	return binary;
}
int numone(int *a, int n)
{
	int i,no=0;
	for(i=0;i<n;i++)
	{
		if(a[i]==1)
		{
			no++;
		}
	}
	return no;
}
void second_column(int **b, char **b1,int nm,int d)
{
	int i,j,k,eqd=0,grnone;
	grnone = numone(b[nm-1],d);	
	for(i=0;i<nm;i++)
	{	
		j=i;
		k=numone(b[i],d);
		if((i!=nm-1)&&(k<grnone))
		{
			while(!((numone(b[j],d))==k+1))
				j++;
		}	
		while((j<nm)&&(i!=j))
		{
			eqd=0;
			if((numone(b[i],d)+1==(numone(b[j],d))))
			{
				for(int l=0;l<d;l++)
				{
					if(b[i][l]==b[j][l])
						eqd++;
				}
				if(eqd==d-1)
				{
					for(int l=0;l<d;l++)
					{
						if(b[i][l]==b[j][l])
						{
							b1[i][l]=static_cast<char>(b[i][l]+48);
						}	
						else
						{
							b1[i][l] = '-';
						}	
						cout<<b1[i][l];		
					}	
					cout<<endl;	
				}
			//	cout<<endl;
				
			}
			j++;
		}
		
	}
}
int main()
{
	int m,n,i,m1,tmin,binary=0,none,j,k,u,v=0;
	cout<<"Enter number of variables"<<endl;
	cin>>m;
	cout<<"Enter number of functions";
	cin>>n;
	tmin = pow(2,m);
//	int *a[tmin],*temp;
	int **a = new int*[tmin];
	char **a1 = new char*[tmin];
	int *temp;
	for(i=0;i<n;i++)
	{
		cout<<"Enter number of minterms for function"<<i+1<<endl;
		cin>>m1;
		cout<<"Enter minterms"<<endl;
		for(j=0;j<m1;j++)
		{
			cin>>binary;
			a[j]=new int[m];
			a1[j]=new char[m];
			a[j] = convert_binary(binary, m);
			for(k=0;k<m;k++)
				cout<<a[j][k];
			cout<<endl;	
				
		}
		for(int x=0;x<m1-1;x++)
		{
			for(int y=0;y<m1-1;y++)
			{
					
				if((numone(a[y],m))>(numone(a[y+1],m)))
				{
					temp = a[y];
					a[y]=a[y+1];
					a[y+1]=temp;
							
				}
			}
		}
		for(int d=0;d<m1;d++)
		{
			for(int e=0;e<m;e++)
				cout<<a[d][e];
			cout<<endl;
		}
		second_column(a,a1,m1,m);
		for(int d=0;d<m1;d++)
		{
			for(int e=0;e<m;e++)
				cout<<a1[d][e];
			cout<<endl;
		}
		
	}
	return 0;
	
}
