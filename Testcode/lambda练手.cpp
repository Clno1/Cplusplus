#include<bits/stdc++.h>
using namespace std;

void biggies(vector<string> &words,int sz) {
	//�ȶ�words���г��ȴ�С�������� 
	stable_sort(words.begin(),words.end(),
		[] (const string &a,const string &b) {
			return a.size()<b.size();
		});
	//��find_if�����ҳ���һ������>=sz�ĵ��ʣ����ص����� 
	auto wc=find_if(words.begin(),words.end(),
		[sz] (const string &s) {
			return s.size()>=sz;
		});
	//��ĩβ��������ȥwc�õ���Ŀ 
	auto count=words.end()-wc;
	cout<<cout<<" "<<sz<<endl;
	for_each(wc,words.end(),
		[] (const string &s) {
			cout<<s<<" ";
		});
}

int main()
{
	vector<string> words{"asdas","sdad","gdfgdgdf","sd","dasfsf","dsadasdasdasd"};
	biggies(words,5);
	return 0;
}
