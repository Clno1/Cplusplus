#include<bits/stdc++.h>
using namespace std;

int main()
{
	//һά�������ǣ�һ��ָ�� 
	//��ά�������ǣ�ָ���ָ�� 
	int **a;
	//a��ָ���ָ�룬aָ��һάָ������ 
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
