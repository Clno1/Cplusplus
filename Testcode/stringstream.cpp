#include<bits/stdc++.h>
using namespace std;

//练习stringstream 
//输入好处：当不知道一行有多少东西的时候可以先输入到string流里面，然后再对流进行处理
//输出好处：也是不知道一行应该输出多少东西，我们可以先存到string流，处理好了再输出 
struct PersonInfo {
	string name;
	vector<string> phones;
};

int main()
{
	string lines,word;
	vector<PersonInfo> people;
	
	while (getline(cin,lines)) {		//每次读取一行 
		PersonInfo info;	//代表一个人 
		istringstream record(lines);		//把这行转为stringsteam流
		record>>info.name;		//这时候就可以把record当作普通的输入流处理 
		while (record>>word)	//直到record流没东西才停止 
			info.phones.push_back(word);
			
		people.push_back(info);
	}
	
//	for (int i=0;i<people.size();i++) {
//		cout<<people[i].name<<" ";
//		for (int j=0;j<people[i].phones.size();j++) 
//			cout<<people[i].phones[j]<<" ";
//		cout<<endl;
//	}

	for (const auto &entry : people) {
		ostringstream goodnum,badnum;
		for (const auto &nums : entry.phones)
			if (nums.size()!=8) badnum<<nums<<" ";
			else goodnum<<nums<<" ";
		if (badnum.str().empty()) 
			cout<<entry.name<<"'s phones is "<<goodnum.str()<<endl;
		else 
			cout<<entry.name<<"'s bad input is "<<badnum.str()<<endl;	
	}
	return 0;
} 
