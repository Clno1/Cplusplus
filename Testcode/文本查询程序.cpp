#include<bits/stdc++.h>
using namespace std;

class QueryResult {
friend ostream & print(ostream& ,const QueryResult& );

public:
	using line_no=vector<string>::size_type;
	QueryResult(string s,shared_ptr<set<line_no>> p,shared_ptr<vector<string>> f)
		: sought(s),lines(p),file(f)  { }
	
private:
	string sought;	//��ѯ���� 
	shared_ptr<set<line_no>> lines;		//�����к� 
	shared_ptr<vector<string>> file;	//�����ļ�������TextQuery�Ƿݣ� 
};

class TextQuery {
public:
	using line_no=vector<string>::size_type;
	TextQuery(ifstream& is);	//���캯�� 
	//�ص㺯������query��ѯ�������ز�ѯ�ṹΪQueryResult 
	QueryResult query(const string&) const;		
	
private:
	shared_ptr<vector<string>> file;	//file��һ��shared_ptrָ�� 
	//wm�ǣ����� --> set<int> ��ӳ��(���set��sharedָ�뱣��)���༴���ʵ��𰸵�ӳ�� 
	map<string,shared_ptr<set<line_no>>> wm;	
};

//TextQuery�Ĺ��캯��������һ���ļ������� 
TextQuery::TextQuery(ifstream& is) : file(new vector<string>) {
	string text;
	while (getline(is,text)) {
		file->push_back(text);	//��һ�б��浽vector<>file�� 
		int n=file->size()-1;	//��ȡ�к� 
		istringstream line(text);	//����stringstream���൥�ʣ��ϰ취��
		string word;
		while (line>>word) {
			auto &lines=wm[word];	//lines��һ��shared_ptr
			 
			if (lines==nullptr) lines.reset(new set<line_no>);
			lines->insert(n);
		} 
	}
}
//��ѯ������ 
QueryResult TextQuery::query(const string &sought) const {
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc=wm.find(sought);	//��map������� 
	
	if (loc==wm.end()) 	//�Ҳ��������ؿ�set 
		return QueryResult(sought,nodata,file);
	else 	//�ҵ��ˣ����ش�set<line_no> 
		return QueryResult(sought,loc->second,file);
}
//��ӡ����
ostream& print(ostream& os,const QueryResult &qr) {
	os<<qr.sought<<" occurs "<<qr.lines->size()<<endl;
	for (auto num : *qr.lines)	
		os<<"\t(line "<<num+1<<") "<<*(qr.file->begin()+num)<<endl;
	return os; 
} 


//�������� 
void runQuery(ifstream &infile) {
	TextQuery tq(infile);	//�������ļ����д��� 
	while (true) {	 //���ϴ���ѯ�� 
		cout<<"enter word to look for,or q to quit :";
		string s;
		if (!(cin>>s) || s=="q") break;		//û�����˻�������q
		print(cout,tq.query(s))<<endl;		//��ӡ��ѯ��� 
	}
}

int main()
{
	ifstream file("Text.txt");
	runQuery(file);
	return 0;
} 
