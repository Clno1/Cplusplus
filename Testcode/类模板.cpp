#include<bits/stdc++.h>
using namespace std;

template <typename T> 
class Blob {
public:
	typedef T value_type;
	typedef typename vector<T>::size_type size_type;
	//���캯��
	Blob();
	Blob(initializer_list<T> il);
	//Ԫ����Ŀ
	size_type size() const { return data->size(); } 
	bool empty() const { return data->empty(); }
	//��Ӻ�ɾ��Ԫ�� 
	void push_back(const T &t) { data->push_back(t); }
	//�ƶ��汾 (��ֵ)
	void push_back(T &&t) { data->push_back(std::move(t)); }
	void pop_back();
	//����Ԫ�� 
	T& back();
	T& operator[] (size_type i);
	
private:
	//data��ʵ��һ��ָ��vector<T>��ָ�� 
	shared_ptr<vector<T>> data;
	//data[i]��Ч���׳�msg�쳣 
	void check(size_type i,const string &msg) const;
};
//�����Ա������ʽ�� 
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
	//����Ƿ�Խ�磬��Խ�緵��data[i] 
	check(i,"subscript out of range");
	return (*data)[i];
}
template<typename T> void Blob<T>::pop_back() {
	//����Ƿ���Ԫ�ؿ���pop 
	check(0,"pop_back on empty Blob");
	data->pop_back();
}


//BlobPtr��Blobָ���� 
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

//����ģ����ʹ����ģ����
template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int) {	//����++ 
	BlobPtr ret=*this;	//������������ڣ��˴�����BlobPtr<T> ret=*this; 
	++ *this;
	return ret;
}

int main()
{
	//Blob<int> ia;
	Blob<int> ia2={0,1,2,3,4};
	
	Blob<int> squares={0,1,2,3,4,5,6,7,8,9};
	for (size_t i=0;i!=squares.size();i++)
		squares[i]=i*i;		//��Ϊ������[],���Կ�ֱ�ӷ��� 
	for (size_t i=0;i!=squares.size();i++)
		printf("%d ",squares[i]); cout<<endl;
	return 0;
}
