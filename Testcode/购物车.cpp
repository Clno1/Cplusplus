#include<bits/stdc++.h>
using namespace std;

class Quote {
public:
	virtual Quote* clone() const & {
		return new Quote(*this);	
	}
	virtual Quote* clone() && {
		return new Quote(std::move(*this));
	}
};
class Bulk_quote : public Quote {
	Bulk_quote* clone() const & {
		return new Bulk_quote(*this);
	}
	Bulk_quote* clone() && {
		return new Bulk_quote(std::move(*this));
	}
};
//购物车类 
class Basket {
public:
	//重点理解这里：先利用多态调用sale拷贝/移动自己一份过来
	//返回的是指针类型，然后这个指针再与shared指针绑定 
	void add_item(const Quote& sale) {	//拷贝构造函数
		item.insert(shared_ptr<Quote>(sale.clone()));
	}
	void add_item(Quote&& sale) {	//移动构造函数 
		item.insert(shared_ptr<Quote>(std::move(sale).clone()));
	}
	double total_receipt(ostream&) const;
private:
	//一个用于比较shared_ptr的函数 
	static bool compare(const shared_ptr<Quote> &lhs,const shared_ptr<Quote> &rhs) {
		return lhs->isbn() < rhs->isbn();
	}
	//多重集合
	multiset<shared_ptr<Quote> , decltype(compare) *>
		items(compare); 
};

double Basket::total_receipt(ostream &os) const {
	double sum=0.0;
	//这里的upper_bound相当巧妙 
	//这里的一层解引用是shared_ptr，二层解引用是解指针 
	for (auto iter=items.cbegin();iter!=items.cend();
		iter=items.upper_bound(*iter)) {
			sum+=print_total(os,**iter,items.count(*iter));
		}
	os<<"Total Sale: "<<sum<<endl;
	return sum;
}

int main()
{
	Basket bsk;
	bsk.add_item(make_shared<Quote>("123",45));
	bsk.add_item(make_shared<bulk_quote>("345",45,3,0.15));	
	return 0;
} 
