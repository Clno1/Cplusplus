#include<bits/stdc++.h>
using namespace std;

const int DEAULT_CAPACITY=5;

template<typename T>
class Vector {
public:
	//各种构造函数和析构函数 
	Vector(int cap=DEAULT_CAPACITY,int sz=0,const T v=T() );
	Vector(const T *arr,int n);
	Vector(const T *arr,int l,int r);
	Vector(const Vector<T> &v);
	Vector(const Vector<T> &v,int l,int r);
	~Vector() { delete[] data; }
	Vector<T>& operator = (const Vector<T> &v);
	
	//获取信息 
	int GetCapacity() const { return capacity; }
	int GetSize() const { return size; }
	bool empty() const { return (size==0); }
	int find(const T &v) const;
	
	//改变元素 
	int insert(int p,const T &v);
	int remove(int p);
	void push_back(const T &v) { insert(size-1); }
	void pop_back() { remove(size-1); };
	void clear();
	
	//重载运算符
	T& operator [] (const int p); 
	friend ostream& operator << (ostream &o,const Vector<T> &v);
	
private:
	int uniquify_impl1();
	int uniquify_impl2();
	static void swap(T &a,T &b) { T tmp=a; a=b; b=tmp; }
	
protected:
	int capacity;	//容量 
	int size;		//Vector大小 
	T *data;		//实际数据 
};

template<typename T>
T& Vector<T>::operator [] (const int p) {
	//if (p>size) throw;
	return data[p];
}

template<typename T>
ostream& operator << (ostream &o,const Vector<T> &v) {
	for (int i=0;i<v.GetSize();i++)
		o<<v[i]<<" ";
	return o;
}

template<typename T>		//默认构造函数，可以全部无值 
Vector<T>::Vector(int cap=DEAULT_CAPACITY,int sz=0,const T v=T()):
	capacity(cap),size(sz) {
		data=new T[capacity];
		for (int i=0;i<size;i++) data[i]=v;
	}



void Test1() {
	Vector<int> v1;
	cout<<v1<<endl;
}
void Test2() {
	
}

int main()
{
	Test1();
	Test2();
	return 0;
} 

