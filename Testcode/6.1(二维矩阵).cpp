#include<bits/stdc++.h>
using namespace std;

int main()
{
	//一维数组名是：一个指针 
	//二维数组名是：指针的指针 
	int **a;
	//a是指针的指针，a指向一维指针数组 
	a=new int*[3];
	
	for (int i=0;i<3;i++) 	a[i]=new int[3]; 
	
	
	for (int i=0;i<3;i++)
		for (int j=0;j<3;j++)
			cin>>a[i][j];
			
	for (int i=0;i<3;i++)
		for (int j=0;j<i;j++)
			swap(a[i][j],a[j][i]);
			
	for (int i=0;i<3;i++)
		for (int j=0;j<3;j++) 
			cout<<a[i][j]<<" ";
	return 0;
}
