#include<bits/stdc++.h>
using namespace std;

class String {
private:
	char *ptr;	//字符串首指针 
	size_t len;	//字符串长度 
	
public:
	String(const char *str=NULL);	//构造函数 
	String(const String &str);	//复制构造函数 
	~String();	//析构函数 
	
	friend String operator + (const String& str1,const String& str2);	//重载加号 
	
	String& operator = (const String& str);	//重载赋值运算符 
	String& operator += (const String& str);	//重载+= 
	bool operator == (const String &str);	//重载相等判断符 
	char& operator [] (int n);	//重载下标取值 
	
	size_t size() const;	//返回长度 
	const char* c_str() const;	//获得String的C风格字符串 
	
	//输入输出运算 
	friend istream& operator >> (istream &is,String &str);
	friend ostream& operator << (ostream &os,String &str);	
};

//字符串拷贝函数：把strSrc串拷贝到strDest串 
char* strcpy(char *strDest,const char *strSrc) {
	if (strDest==NULL || strSrc==NULL) return NULL;
	if (strDest==strSrc) return strDest;
	char *head=strDest;	//先把首指针保存一份用来输出 
	while ((*strDest++ = *strSrc++) != '\0');
	return head; 
}

String::String(const char *str) {
	if (str==NULL) {	//构造为空串 
		this->len=0;
		this->ptr=new char[1];
		*ptr='\0';
	} else {
		this->len=strlen(str);
		this->ptr=new char[this->len+1];	//为什么+1，考虑'\0' 
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
	//这一步很关键，先把以前的空间删掉再赋值，否则空间泄露 
	delete []this->ptr;
	
	this->len=str.len;
	this->ptr=new char[this->len+1];
	strcpy(this->ptr,str.ptr);
	return *this;
} 
String& String::operator += (const String& str) {
	//+=和上面的=同理，注意把以前的空间先释放
	char *tmp=this->ptr;
	*this=*this+str;
	delete []tmp;
	return *this;
}
//内联函数加快运行速度
inline bool String::operator == (const String& str) {
	if (this->len!=str.len) return 0;
	for (int i=0;i<this->len;i++)
		if (*(this->ptr+i) != *(str.ptr+i)) return 0;
	return 1;	 
}
char& String::operator [] (int n) {
	//if (n>this->len-1) throw;  //越界异常
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
	//这里的串会当成C语言字符串，调用构造函数 
	String s2("AqA"); cout<<s2<<endl;	
	//这里的s2就是String类了，调用复制构造函数 
	String s3(s2); cout<<s3<<endl;
	
	String s4(s2+s1+s3); cout<<s4<<endl;
	//这里的"11"会自动转成String ？ 
	String s5=s4+"11"; cout<<s5<<endl;
	
	cout<<s5[3]<<endl;
	cout<<"s2==s3 ? "<<(s2==s3)<<endl;
	cout<<"s1==s3 ? "<<(s1==s3)<<endl;
	return 0;
} 
