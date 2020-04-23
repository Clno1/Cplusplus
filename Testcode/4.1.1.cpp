#include<bits/stdc++.h>
using namespace std;

//C++枚举类 
enum CPU_Rank {
	P1=1,P2,P3,P4,P5,P6,P7
};

class CPU
{
private:
	CPU_Rank rank;
	int frequency;
	float voltage;
public:
	//CPU的构造函数 
	CPU (CPU_Rank r,int f,float v) {
		rank=r;
		frequency=f;
		voltage=v;
		cout<<"构造CPU"<<endl;
	}
	//CPU析构函数 
	~CPU () {
		cout<<"析构CPU"<<endl;
	}
	
	CPU_Rank GetRank() const { return rank; }
	int GetFrequency() const { return frequency; }
	float GetVoltage() const { return voltage; }
	
	void Run() {
		cout<<"CPU运行"<<endl;
	}
	void Stop() {
		cout<<"CPU停止运行"<<endl;
	}
};

int main()
{
	//创造一个对象acpu，并调用相应的构造函数 
	CPU acpu(P6,300,2.8);
	acpu.Run();
	acpu.Stop();
	return 0;
} 
