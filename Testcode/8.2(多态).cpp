#include<bits/stdc++.h>
using namespace std;

class Vehicle {
public:
	int MaxSpeed;
	int Weight;
//	void Run() { cout<<"Vehicle Run"<<endl; }
//	void Stop() { cout<<"Vehicle Stop"<<endl; }
	
	//虚函数 
	virtual void Run() { cout<<"Vehicle Run"<<endl; }
	virtual void Stop() { cout<<"Vehicle Stop"<<endl; }
};

class Bicycle : virtual public Vehicle {
public:
	int Height;
	//重写了父类的虚函数 
	void Run() { cout<<"Bicycle Run"<<endl; } 
	void Stop() { cout<<"Bicycle Stop"<<endl; }
};

class Motorcar : virtual public Vehicle {
public:
	int SeatNum;
	//重写了父类的虚函数 
	void Run() { cout<<"Mototcar Run"<<endl; }
	void Stop() { cout<<"Motorcar Stop"<<endl; }
};

class Motorcycle : public Bicycle ,public Motorcar {
public:
	void Run() { cout<<"Motorcycle run"<<endl; }
	void Stop() { cout<<"Motorcycle stop"<<endl; }
};

void show(Vehicle *ptr) {
	ptr->Run();
	ptr->Stop();
}

int main()
{
	Vehicle v;
	Motorcar m;
	Bicycle b;
	Motorcycle mc;
	show(&v);
	show(&m);
	show(&b);
	show(&mc);
	return 0;
}
