#include<bits/stdc++.h>
using namespace std;

class BigInteger {
private:
	vector<char> digits;
	bool sign;
	void trim();
	
public:
	BigInteger();
	BigInteger(int b);
	BigInteger(const string& s);
	BigInteger(const BigInteger& b);
	
	friend int abscompare(const BigInteger& b1,const BigInteger& b2);
	friend bool operator == (const BigInteger& b1,const BigInteger& b2);
	friend bool operator < (const BigInteger& b1,const BigInteger& b2);
	friend bool operator > (const BigInteger& b1,const BigInteger& b2);
	
	BigInteger operator - ();	//负号 
	BigInteger& operator += (const BigInteger& b);
	BigInteger& operator -= (const BigInteger& b);
	BigInteger& operator *= (const BigInteger& b);
	BigInteger& operator /= (const BigInteger& b);
	
	friend void carry(BigInteger& b);
	friend BigInteger operator + (const BigInteger& b1,const BigInteger& b2);
	friend BigInteger operator - (const BigInteger& b1,const BigInteger& b2);
	friend BigInteger operator * (const BigInteger& b1,const BigInteger& b2);
	friend BigInteger operator / (const BigInteger& b1,const BigInteger& b2);
	
	void print();
};

BigInteger::BigInteger() {
	sign=true;
}
BigInteger::BigInteger(int b) {
	if (b<0) { sign=false; b=-b; }
	else sign=true;
	while (b) {
		digits.push_back(char('0'+b%10));
		b/=10;
	}
}
BigInteger::BigInteger(const string& s) {
	int start=0,len=s.length();
	if (s[0]=='-') { start=1; sign=false; }
	else { start=0; sign=true; }
	
	for (int i=len-1;i>=start;i--)
		digits.push_back(s[i]);
}
BigInteger::BigInteger(const BigInteger& b) {
	sign=b.sign;
	digits=b.digits;
}

void BigInteger::print() {
	if (!sign) cout<<"-";
	for (int i=digits.size()-1;i>=0;i--)
		cout<<digits[i];
	//cout<<endl;	
}

BigInteger BigInteger::operator - () {
	BigInteger tmp=*this;
	tmp.sign=1-tmp.sign;
	return tmp;
}

//比较b1和b2的绝对值大小，b1>b2返回1，b1==b2返回0，b1<b2返回-1 
int abscompare(const BigInteger& b1,const BigInteger& b2) {
	if (b1.digits.size()>b2.digits.size()) return 1;
	if (b1.digits.size()<b2.digits.size()) return -1;
	bool bigger=0,smaller=0;
	int len=b1.digits.size();
	for (int i=len-1;i>=0;i--) {
		if (b1.digits[i]>b2.digits[i]) { bigger=true; break; }
		if (b1.digits[i]<b2.digits[i]) { smaller=true; break; }
	}
	if (bigger) return 1;
	else if (smaller) return -1;
	else return 0;
}
bool operator == (const BigInteger& b1,const BigInteger& b2) {
	if (b1.sign!=b2.sign) return false;
	return (abscompare(b1,b2)==0);
}
bool operator < (const BigInteger& b1,const BigInteger& b2) {
	if (b1.sign==true && b2.sign==false) return false;
	if (b1.sign==false && b2.sign==true) return true;
	int cmp=abscompare(b1,b2);
	if (b1.sign==true)
		if (cmp>=0) return false;
		else return true;
	if (b1.sign==false)
		if (cmp<=0) return true;
		else return false;	
}
bool operator > (const BigInteger& b1,const BigInteger& b2) {
	if (b1.sign==true && b2.sign==false) return true;
	if (b1.sign==false && b2.sign==true) return false;
	int cmp=abscompare(b1,b2);
	if (b1.sign==true)
		if (cmp<=0) return false;
		else return true;
	if (b1.sign==false)
		if (cmp>=0) return true;
		else return false;	
}

void carry(BigInteger &b) {
	int len=b.digits.size();
	for (int i=0;i<len-1;i++) {
		b.digits[i+1]+=(b.digits[i]-'0')/10;
		b.digits[i]=(b.digits[i]-'0')%10+'0';
	}
	while (b.digits[b.digits.size()-1]>='0'+10) {
		int t=b.digits.size()-1;
		b.digits.push_back((b.digits[t]-'0')/10+'0');
		b.digits[t]=(b.digits[t]-'0')%10+'0';
	}
}
BigInteger operator + (const BigInteger& b1,const BigInteger& b2) {
	if (b1.sign!=b2.sign) {
		BigInteger newb1(b1),newb2(b2);
		if (b1.sign==true && b2.sign==false) return (newb1-(-newb2));
		else return newb2-(-newb1);
	}
	int maxlen=max(b1.digits.size(),b2.digits.size());
	BigInteger ret;
	for (int i=0;i<maxlen;i++)
		if (b1.digits.size()-1>=i && b2.digits.size()-1>=i) ret.digits.push_back(b1.digits[i]+b2.digits[i]-'0');
		else if (b1.digits.size()-1>=i) ret.digits.push_back(b1.digits[i]);
		else ret.digits.push_back(b2.digits[i]);
	carry(ret);
	ret.sign=b1.sign;
	return ret;
}
BigInteger operator - (const BigInteger& b1,const BigInteger& b2) {		//待完善 
	if (b1.sign!=b2.sign) {
		BigInteger newb1(b1),newb2(b2);
		return (newb1+(-newb2));
	}
	if (b1.sign==false && b2.sign==false) {
		BigInteger newb1(b1),newb2(b2);
		return (-newb2)-(-newb1);
	}
	if (b1<b2) {
		BigInteger newb1(b1),newb2(b2);
		return -(newb2-newb1);
	}
	
	BigInteger ret;
	int maxlen=max(b1.digits.size(),b2.digits.size());
	for (int i=0;i<maxlen;i++)
		if (b1.digits.size()-1>=i && b2.digits.size()-1>=i) ret.digits.push_back(b1.digits[i]-b2.digits[i]);
		else ret.digits.push_back(b1.digits[i]-'0');
	for (int i=0;i<maxlen;i++)
		if (ret.digits[i]<0) {
			ret.digits[i+1]--;
			ret.digits[i]+=10;
		} 
	while (ret.digits.size()>1 && ret.digits[ret.digits.size()-1]==0) ret.digits.pop_back();
	for (int i=0;i<ret.digits.size();i++) ret.digits[i]+='0';
	return ret;
}
BigInteger operator * (const BigInteger& b1,const BigInteger& b2) {
	BigInteger ret;
	ret.sign=(b1.sign==b2.sign);
	int len1=b1.digits.size(),len2=b2.digits.size();
	vector<int> tmp(len1+len2,0);
	for (int i=0;i<len1;i++)
		for (int j=0;j<len2;j++)
			tmp[i+j]+=(b1.digits[i]-'0')*(b2.digits[j]-'0');
	for (int i=0;i<(len1+len2-1);i++) {
		tmp[i+1]+=tmp[i]/10;
		tmp[i]%=10;
	}
	while (tmp[tmp.size()-1]>=10) {
		tmp.push_back(tmp[tmp.size()-1]/10);
		tmp[tmp.size()-2]%=10;
	}
	for (int i=0;i<tmp.size();i++)
		ret.digits.push_back(tmp[i]+'0');
	while (ret.digits.size()>1 && ret.digits[ret.digits.size()-1]=='0') ret.digits.pop_back();
	return ret;	
}

BigInteger& BigInteger::operator +=(const BigInteger& b) {
	*this=*this+b;
	return *this;
}
BigInteger& BigInteger::operator -=(const BigInteger& b) {
	*this=*this-b;
	return *this;
}
BigInteger& BigInteger::operator *=(const BigInteger& b) {
	*this=*this*b;
	return *this;
}

int main()
{
	BigInteger b1(81532);
	BigInteger b2(-156156131);
	BigInteger b3(string("-1561565")); 
	cout<<"b1: "; b1.print(); cout<<endl; 
	cout<<"b2: "; b2.print(); cout<<endl; 
	cout<<"b3: "; b3.print(); cout<<endl; 
	BigInteger b4(b2);
	cout<<"b4: "; b4.print(); cout<<endl; 
	
	BigInteger b5(81533);
	cout<<"-b5 : "; (-b5).print(); cout<<endl;
	cout<<"b2==b1 ? "<<(b2==b1)<<endl;
	cout<<"b2==b4 ? "<<(b2==b4)<<endl;
	cout<<"b1>b5 ? "<<(b1>b5)<<endl;
	cout<<"b1<b5 ? "<<(b1<b5)<<endl;
	cout<<"b5<-b5 ? "<<(-b5>b5)<<endl;
	
	//开始测试加减乘除
	BigInteger b6=b1+b5;
	cout<<"b1+b5 : "; b6.print(); cout<<endl;
	cout<<"b1-b5 : "; (b1-b5).print(); cout<<endl;
	cout<<"b4-b2 : "; (b4-b2).print(); cout<<endl;
	cout<<"b2-b1 : "; (b2-b1).print(); cout<<endl;
	cout<<"b2+b1 : "; (b2+b1).print(); cout<<endl;
	cout<<"b1*b5 : "; (b1*b5).print(); cout<<endl;
	cout<<"b1*b2 : "; (b1*b2).print(); cout<<endl; 

	//测试+=，-=，*=，/=；
	b5*=b1;  
	cout<<"b1*b5 : "; b5.print(); cout<<endl;
	b1*=b2;
	cout<<"b1*b2 : "; b1.print(); cout<<endl; 
	return 0;
}
