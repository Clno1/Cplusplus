#include<bits/stdc++.h>
using namespace std;

//��ϰstringstream 
//����ô�������֪��һ���ж��ٶ�����ʱ����������뵽string�����棬Ȼ���ٶ������д���
//����ô���Ҳ�ǲ�֪��һ��Ӧ��������ٶ��������ǿ����ȴ浽string���������������� 
struct PersonInfo {
	string name;
	vector<string> phones;
};

int main()
{
	string lines,word;
	vector<PersonInfo> people;
	
	while (getline(cin,lines)) {		//ÿ�ζ�ȡһ�� 
		PersonInfo info;	//����һ���� 
		istringstream record(lines);		//������תΪstringsteam��
		record>>info.name;		//��ʱ��Ϳ��԰�record������ͨ������������ 
		while (record>>word)	//ֱ��record��û������ֹͣ 
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
