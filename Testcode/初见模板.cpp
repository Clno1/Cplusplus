#include<bits/stdc++.h>
using namespace std;

//����������ģ�壬���Ͳ�����ʾ����һ�����Ͷ���ֵ 
template <typename T>
int compare(const T& a,const T& b) {
	if (a<b) return -1;
	if (a>b) return 1;
	return 0;
} 

//�����Ƿ����Ͳ�������ʾһ��ֵ����һ������
//�ṩһ���������ʽ���������ڱ���ʱʵ����ģ�� 
template<unsigned N,unsigned M>		
int compare2(const char (&p1)[N],const char (&p2)[M]) {
	return strcmp(p1,p2);
} 
 

int main()
{
	cout<<compare(1,2)<<endl;
	cout<<compare("1651","1561")<<endl;
	cout<<compare(9,3)<<endl;
	cout<<compare(1.2232,0.2125)<<endl;
	
	//���"321"��"32"���Ȳ�ͬ�ǲ��ܵ���compare�ģ����Ȳ�ͬ������Ϊ��ͬ���� 
	//cout<<compare("321","32")<<endl;
	cout<<compare2("32","321")<<endl;
	return 0;
}
