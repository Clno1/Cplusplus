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
//���ﳵ�� 
class Basket {
public:
	//�ص������������ö�̬����sale����/�ƶ��Լ�һ�ݹ���
	//���ص���ָ�����ͣ�Ȼ�����ָ������sharedָ��� 
	void add_item(const Quote& sale) {	//�������캯��
		item.insert(shared_ptr<Quote>(sale.clone()));
	}
	void add_item(Quote&& sale) {	//�ƶ����캯�� 
		item.insert(shared_ptr<Quote>(std::move(sale).clone()));
	}
	double total_receipt(ostream&) const;
private:
	//һ�����ڱȽ�shared_ptr�ĺ��� 
	static bool compare(const shared_ptr<Quote> &lhs,const shared_ptr<Quote> &rhs) {
		return lhs->isbn() < rhs->isbn();
	}
	//���ؼ���
	multiset<shared_ptr<Quote> , decltype(compare) *>
		items(compare); 
};

double Basket::total_receipt(ostream &os) const {
	double sum=0.0;
	//�����upper_bound�൱���� 
	//�����һ���������shared_ptr������������ǽ�ָ�� 
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
