#include<bits/stdc++.h>
using namespace std;

void biggies(vector<string> &words,int sz) {
	//先对words进行长度从小到大排序 
	stable_sort(words.begin(),words.end(),
		[] (const string &a,const string &b) {
			return a.size()<b.size();
		});
	//用find_if函数找出第一个长度>=sz的单词，返回迭代器 
	auto wc=find_if(words.begin(),words.end(),
		[sz] (const string &s) {
			return s.size()>=sz;
		});
	//用末尾迭代器减去wc得到数目 
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
