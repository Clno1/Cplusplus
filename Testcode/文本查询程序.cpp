#include<bits/stdc++.h>
using namespace std;

class QueryResult {
friend ostream & print(ostream& ,const QueryResult& );

public:
	using line_no=vector<string>::size_type;
	QueryResult(string s,shared_ptr<set<line_no>> p,shared_ptr<vector<string>> f)
		: sought(s),lines(p),file(f)  { }
	
private:
	string sought;	//查询单词 
	shared_ptr<set<line_no>> lines;		//出现行号 
	shared_ptr<vector<string>> file;	//输入文件（就是TextQuery那份） 
};

class TextQuery {
public:
	using line_no=vector<string>::size_type;
	TextQuery(ifstream& is);	//构造函数 
	//重点函数！：query查询函数返回查询结构为QueryResult 
	QueryResult query(const string&) const;		
	
private:
	shared_ptr<vector<string>> file;	//file是一个shared_ptr指针 
	//wm是：单词 --> set<int> 的映射(这个set用shared指针保存)，亦即单词到答案的映射 
	map<string,shared_ptr<set<line_no>>> wm;	
};

//TextQuery的构造函数，接受一个文件读入流 
TextQuery::TextQuery(ifstream& is) : file(new vector<string>) {
	string text;
	while (getline(is,text)) {
		file->push_back(text);	//把一行保存到vector<>file中 
		int n=file->size()-1;	//获取行号 
		istringstream line(text);	//利用stringstream分类单词，老办法了
		string word;
		while (line>>word) {
			auto &lines=wm[word];	//lines是一个shared_ptr
			 
			if (lines==nullptr) lines.reset(new set<line_no>);
			lines->insert(n);
		} 
	}
}
//查询函数： 
QueryResult TextQuery::query(const string &sought) const {
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc=wm.find(sought);	//在map这个单词 
	
	if (loc==wm.end()) 	//找不到，返回空set 
		return QueryResult(sought,nodata,file);
	else 	//找到了，返回答案set<line_no> 
		return QueryResult(sought,loc->second,file);
}
//打印函数
ostream& print(ostream& os,const QueryResult &qr) {
	os<<qr.sought<<" occurs "<<qr.lines->size()<<endl;
	for (auto num : *qr.lines)	
		os<<"\t(line "<<num+1<<") "<<*(qr.file->begin()+num)<<endl;
	return os; 
} 


//主处理函数 
void runQuery(ifstream &infile) {
	TextQuery tq(infile);	//对输入文件进行处理 
	while (true) {	 //不断处理询问 
		cout<<"enter word to look for,or q to quit :";
		string s;
		if (!(cin>>s) || s=="q") break;		//没输入了或者输入q
		print(cout,tq.query(s))<<endl;		//打印查询结果 
	}
}

int main()
{
	ifstream file("Text.txt");
	runQuery(file);
	return 0;
} 
