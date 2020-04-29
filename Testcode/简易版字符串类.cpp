#include<bits/stdc++.h>
using namespace std;

class String {
private:
	char *ptr;	//�ַ�����ָ�� 
	size_t len;	//�ַ������� 
	
public:
	String(const char *str=NULL);	//���캯�� 
	String(const String &str);	//���ƹ��캯�� 
	~String();	//�������� 
	
	friend String operator + (const String& str1,const String& str2);	//���ؼӺ� 
	
	String& operator = (const String& str);	//���ظ�ֵ����� 
	String& operator += (const String& str);	//����+= 
	bool operator == (const String &str);	//��������жϷ� 
	char& operator [] (int n);	//�����±�ȡֵ 
	
	size_t size() const;	//���س��� 
	const char* c_str() const;	//���String��C����ַ��� 
	
	//����������� 
	friend istream& operator >> (istream &is,String &str);
	friend ostream& operator << (ostream &os,String &str);	
};

//�ַ���������������strSrc��������strDest�� 
char* strcpy(char *strDest,const char *strSrc) {
	if (strDest==NULL || strSrc==NULL) return NULL;
	if (strDest==strSrc) return strDest;
	char *head=strDest;	//�Ȱ���ָ�뱣��һ��������� 
	while ((*strDest++ = *strSrc++) != '\0');
	return head; 
}

String::String(const char *str) {
	if (str==NULL) {	//����Ϊ�մ� 
		this->len=0;
		this->ptr=new char[1];
		*ptr='\0';
	} else {
		this->len=strlen(str);
		this->ptr=new char[this->len+1];	//Ϊʲô+1������'\0' 
		strcpy(this->ptr,str);
	}
}
String::String(const String &str) {
	this->len=str.len;
	this->ptr=new char[this->len+1];
	strcpy(this->ptr,str.ptr);
}
String::~String() {
	delete []this->ptr;
	this->len=0;
}

size_t String::size() const {
	return this->len;
}
const char* String::c_str() const {
	return this->ptr;
}

String operator + (const String& str1,const String& str2) {
	String newString;
	newString.len=str1.len+str2.len;
	newString.ptr=new char[newString.len+1];
	strcpy(newString.ptr,str1.ptr);
	strcat(newString.ptr,str2.ptr);
	return newString;
}
String& String::operator = (const String& str) {
	if (this==(&str)) return *this;
	//��һ���ܹؼ����Ȱ���ǰ�Ŀռ�ɾ���ٸ�ֵ������ռ�й¶ 
	delete []this->ptr;
	
	this->len=str.len;
	this->ptr=new char[this->len+1];
	strcpy(this->ptr,str.ptr);
	return *this;
} 
String& String::operator += (const String& str) {
	//+=�������=ͬ��ע�����ǰ�Ŀռ����ͷ�
	char *tmp=this->ptr;
	*this=*this+str;
	delete []tmp;
	return *this;
}
//���������ӿ������ٶ�
inline bool String::operator == (const String& str) {
	if (this->len!=str.len) return 0;
	for (int i=0;i<this->len;i++)
		if (*(this->ptr+i) != *(str.ptr+i)) return 0;
	return 1;	 
}
char& String::operator [] (int n) {
	//if (n>this->len-1) throw;  //Խ���쳣
	return *(this->ptr+n); 
}

istream& operator >> (istream &is,String &str) {
	char s[100]; scanf("%s",s);
	str.len=strlen(s);
	strcpy(str.ptr,s);
}
ostream& operator << (ostream &os,String &str) {
	for (int i=0;i<str.len;i++)
		os<<*(str.ptr+i);
	return os;
}

int main()
{
	String s1; cin>>s1; cout<<s1<<endl;
	//����Ĵ��ᵱ��C�����ַ��������ù��캯�� 
	String s2("AqA"); cout<<s2<<endl;	
	//�����s2����String���ˣ����ø��ƹ��캯�� 
	String s3(s2); cout<<s3<<endl;
	
	String s4(s2+s1+s3); cout<<s4<<endl;
	//�����"11"���Զ�ת��String �� 
	String s5=s4+"11"; cout<<s5<<endl;
	
	cout<<s5[3]<<endl;
	cout<<"s2==s3 ? "<<(s2==s3)<<endl;
	cout<<"s1==s3 ? "<<(s1==s3)<<endl;
	return 0;
} 
