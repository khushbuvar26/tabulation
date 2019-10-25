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
/*void second_column(int **b, char **b1,int nm,int d)
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
}*/
void pla_table(char **fun, int k, int dg)
{
	for(int a=0;a<k;a++)
	{
		fin_pro[w]= new char[dg];
		for(int b=0;b<dg;b++)
		{
			fin_pro[w][b] = fun[a][b];
			cout<<fin_pro[w][b];
		}
		if(a!=k-1)
		cout<<"+";
		w++;
	}
	cout<<endl;
}
void complementtt(int *minarr, int d, int orm)
{
	int i,j;
	int tmin = pow(2,d);
	char **ca = new char*[tmin-orm];
	char *temp;
	int p=0;
	int *compmin = new int[tmin];
	cout<<endl;
	for(i=0;i<tmin;i++)
	{
		int ch;
		for(j=0;j<orm;j++)
		{
			ch = 0;
			if(i==minarr[j])
			{
				ch++;
				break;
			}
			else
			{
				continue;
			}
		}
		if(ch ==0)
		{
			compmin[p] = i;
			p++;
		}
	}
	for(int u=0;u<p;u++)
		cout<<compmin[u]<<"\t";
	cout<<endl;	
	for(int j=0;j<p;j++)
		{
			ca[j]=new char[d+1];
			ca[j] = convert_binary(compmin[j], d);
			for(int k=0;k<d;k++)
				cout<<ca[j][k];
			cout<<endl;	
				
		}
		for(int x=0;x<p-1;x++)
		{
			for(int y=0;y<p-1;y++)
			{
					
				if((numone(ca[y],d))>(numone(ca[y+1],d)))
				{
					temp = ca[y];
					ca[y]=ca[y+1];
					ca[y+1]=temp;
							
				}
			}
		}
		for(int g=0;g<p;g++)
		{
			for(int e=0;e<d;e++)
				cout<<ca[g][e];
			cout<<endl;
		}
		impli = new char*[tmin];
		tabulation(ca,p,d,0,p,compmin);
	
}
char** minterms(int n, int di,int min, int *minarr)
{
	cout<<n<<endl;
	char **func = new char*[n];
	char **func_ano = new char*[n]; 
	int alpha = 97;
	for(int x=0;x<n-1;x++)
	{
		for(int y=0;y<di;y++)
		{
			if(impli[x][y]==impli[x+1][y])
			{
				if(y==di-1)
				{
					for(int t=x;t<n;t++)
					{
							impli[t]=impli[t+1];	
					}
					n--;
				}
			}
			else
			{
				break;
			}
		}
	}
	
	for(int x=0;x<n;x++)
	{
		for(int y=0;y<di;y++)
		{
			cout<<impli[x][y];
		}
		cout<<endl;
	}
	for(int x=0;x<n;x++)
	{
		func[x] = new char[2*di];
		int z=0;
		for(int y=0;y<di;y++)
		{
			
			if(impli[x][y]=='0')
				{
					func[x][z] = y+alpha;
					cout<<func[x][z];
					z++;
					func[x][z]= '\'';
					cout<<func[x][z];
					z++;
					
				}
				else if(impli[x][y]=='1')
				{
					func[x][z] = y+alpha;
					cout<<func[x][z];
					z++;
					func[x][z]= ' ';
					cout<<func[x][z];
					z++;
				}
				else
				{
					continue;
				}
		}
		cout<<endl;
	}
	int **primetable = new int*[n+1];
	for(int x=0;x<n+1;x++)
	{
		primetable[x] = new int[min+1];
		for(int y=1;y<min+1;y++)
		{
			if(x==0)
			{
				primetable[x][y] = minarr[y-1];
			}
		}
			if(x!=0)
			{
				int dig,num=0,nda,po;
				nda = numdashes(impli[x-1],di);
				po = pow(2,nda);
				char **dasss= new char*[po];	
				char temp[200];
				if(nda>0)
				{
				
					for(int g =0;g<di;g++)
					{
						temp[g] = impli[x-1][g];
					}
				}		
				cout<<endl;
					for(int u=0;u<po;u++)
					{
						num=0;
						int s=0;
						dasss[u]= new char[nda];
						dasss[u] = convert_binary(u,nda);
						for(int t=0;t<di;t++)
						{	
							if(impli[x-1][t]=='-')
							{	
								impli[x-1][t] = dasss[u][s];
								s++;
							}
						}
						int h=0;
						for(int ind=di-1; ind>=0;ind--)
						{	
								dig = static_cast<int>(impli[x-1][h]-'0');
							//	cout<<impli[x-1][h];
							//	cout<<dig<<endl;
								num = num+dig*pow(2,ind);
								h++;	
						}
					//	cout<<num<<endl;		
						for(int t=1;t<min+1;t++)
						{
							if(primetable[0][t]==num)
							{
								primetable[x][t]=1;
							}
						}
						if(nda>0)
						{
							for(int g =0;g<di;g++)
							{
								impli[x-1][g] = temp[g];
							}
						}		
					}	
					if(num==0)
					{
						for(int ind = di-1;ind>=0;ind--)
						{
								int h=0;
								dig = static_cast<int>(impli[x-1][h]-48);
								num = num+dig*pow(2,ind);
								h++;
						}
						for(int t=1;t<min+1;t++)
						{
							if(primetable[0][t]==num)
							{
								primetable[x][t]=1;
							}
						}
						
					}
			}
		
	}
	primetable[0][0]=0;
	for(int e=1;e<n+1;e++)
	{
		for(int f = 0;f<min+1;f++)
		{
			if(primetable[e][f]!=1)
			{
				primetable[e][f] =0;
			}
		}
		cout<<endl;
	}
	for(int e=0;e<n+1;e++)
	{
		for(int f = 0;f<min+1;f++)
		{
			cout<<primetable[e][f]<<"\t";
		}
		cout<<endl;
	}
	int l =0;
	int rno;
	int c;
	int *covered = new int[min];
	int p;
	for(int e=1;e<min+1;e++)
	{
		c = 0;		
		for(int f=1;f<n+1;f++)
		{
			
			if(primetable[f][e]==1)
			{
				c++;	
				rno = f;
			}
			
		}
		if(c==1)
		{
				func_ano[l] =new char[2*di];		
				for(int m=0;m<2*di;m++)
				{
					func_ano[l][m] = func[rno-1][m];
					cout<<func_ano[l][m];
				}
				l++;
				cout<<endl;
	
				for(int b=0;b<min+1;b++)
				{
						if(primetable[rno][b]==1)
						{
							covered[p] = primetable[0][b];
							p++;
						}	
				}			
		}
		else
		{
			continue;
		}		
		
	}
	for(int e=0;e<l-1;e++)
	{
		for(int f=0;f<2*di;f++)
		{
			if(func_ano[e][f]==func_ano[e+1][f])
			{
				if(f==2*di-1)
				{
					for(int t=e;t<l;t++)
					{
						func_ano[t] = func_ano[t+1];
					}
					l--;
				}
			}
			else
			{
				break;
			}
		}
	}
	int v=0;
	int *notcovered = new int[100];
	for(int a=0;a<min;a++)
	{
		for(int b=0;b<p;b++)
		{
			if(minarr[a]==covered[b])
			{
				break;
			}
			if(b==min-1)
			{
				notcovered[v] = minarr[a];
				v++;
			}
		}
	}
	cout<<endl;
	pla_table(func_ano,l,2*di);
	
}

void tabulation(char **b,int nm,int d,int q,int w,int *minarr)
{
	int f = pow(2,d);
	char **b1= new char*[f];
	int i,j,k,eqd=0,grnone,z=0;
	grnone = numone(b[nm-1],d);	
	for(i=0;i<nm;i++)
	{	
		j=i;
		k=numone(b[i],d);
		if((i!=nm-1)&&(k<grnone))
		{
			while(!((numone(b[j],d))==k+1))
			{
				j++;
				if(j==nm)
				{
					k=k+2;
					int o =i;
					while(!(numone(b[o],d)==k)&&k<=grnone&&o!=nm-1)
					{
						o++;
						if(o==nm)
						{
							o=i;
							k++;
							continue;
						}
						if(o==nm-1)
						{
							i=o;
							j=i;
							break;
						}	
					}
					if(i==nm-1)
					{
						break;
					}	
					else
					{
						i=o;
						j=i;
					}
					if(i==nm-2&&(numone(b[nm-2],d)==numone(b[nm-1],d)))
						break;
					
				}	
				
			}
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
					b1[z]=new char[d+1];
					b[i][d] = '*';
					b[j][d] = '*';
					for(int l=0;l<d;l++)
					{
						if(b[i][l]==b[j][l])
						{
							b1[z][l]=b[i][l];
						}	
						else
						{
							b1[z][l] = '-';
						}	
						cout<<b1[z][l];		
					}	
					cout<<endl;	
					z++;
				}	
			}
			j++;
		}
		
	}
	
	if(z>0)
	{
		cout<<"---------------------------------"<<endl;
		for(int x=0;x<nm;x++)
		{
			if(b[x][d]!='*')
				{
				//	impli[q] = new char[d+1];
					impli[q]= b[x];
					q++;
				}
			for(int y=0;y<=d;y++)
			{
				cout<<b[x][y];
			}
			cout<<endl;
		}
		tabulation(b1,z,d,q,w,minarr);
	}
	else
	{
		for(int x=0;x<nm;x++)
		{
			if(b[x][d]!='*')
			{
			//	impli[q] = new char[d+1];
				impli[q]= b[x];
				q++;
			}
			for(int y=0;y<=d;y++)
			{
				cout<<b[x][y];
			}
			cout<<endl;
		}
		for(int x=0;x<q;x++)
		{
			for(int y=0;y<=d;y++)
			{
				cout<<impli[x][y];
			}
			cout<<endl;
		}
		minterms(q,d,w,minarr);
		
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
