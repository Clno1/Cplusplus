#include<bits/stdc++.h>
using namespace std;

template <typename T> 
class Blob {
public:
	typedef T value_type;
	typedef typename vector<T>::size_type size_type;
	//构造函数
	Blob();
	Blob(initializer_list<T> il);
	//元素数目
	size_type size() const { return data->size(); } 
	bool empty() const { return data->empty(); }
	//添加和删除元素 
	void push_back(const T &t) { data->push_back(t); }
	//移动版本 (右值)
	void push_back(T &&t) { data->push_back(std::move(t)); }
	void pop_back();
	//访问元素 
	T& back();
	T& operator[] (size_type i);
	
private:
	//data其实是一个指向vector<T>的指针 
	shared_ptr<vector<T>> data;
	//data[i]无效，抛出msg异常 
	void check(size_type i,const string &msg) const;
};
//定义成员函数方式： 
//template <typename T>
//ret-type Blob<T>::member-name(parm-list)

template <typename T>
Blob<T>::Blob(initializer_list<T> il) :
	data(make_shared<vector<T>>(il)) {}

template <typename T>
void Blob<T>::check(size_type i,const string &msg) const {
	if (i>=data->size()) throw out_of_range(msg);
}

template <typename T>
T& Blob<T>::operator [] (size_type i) {
	//检查是否越界，不越界返回data[i] 
	check(i,"subscript out of range");
	return (*data)[i];
}
template<typename T> void Blob<T>::pop_back() {
	//检查是否有元素可以pop 
	check(0,"pop_back on empty Blob");
	data->pop_back();
}


//BlobPtr：Blob指针类 
template <typename T> class BlobPtr {
public:
	BlobPtr() : curr(0) { }
	BlobPtr(Blob<T> &a,size_t sz=0):
		wptr(a.data),curr(sz) { }
	T& operator*() const {
		auto p=check(curr,"deraference past end");
		return (*p)[curr];
	}
	BlobPtr& operator++();
	BlobPtr& operator--();

private:
	shared_ptr<vector<T>> check(size_t,const string &) const;
	weak_ptr<vector<T>> wptr;
	size_t curr;
};

//在类模板外使用类模板名
template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int) {	//后置++ 
	BlobPtr ret=*this;	//在类的作用域内，此处当成BlobPtr<T> ret=*this; 
	++ *this;
	return ret;
}

int main()
{
	//Blob<int> ia;
	Blob<int> ia2={0,1,2,3,4};
	
	Blob<int> squares={0,1,2,3,4,5,6,7,8,9};
	for (size_t i=0;i!=squares.size();i++)
		squares[i]=i*i;		//因为重载了[],所以可直接访问 
	for (size_t i=0;i!=squares.size();i++)
		printf("%d ",squares[i]); cout<<endl;
	return 0;
}
