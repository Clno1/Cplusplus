#include<bits/stdc++.h>
using namespace std;

//C++ö���� 
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
	//CPU�Ĺ��캯�� 
	CPU (CPU_Rank r,int f,float v) {
		rank=r;
		frequency=f;
		voltage=v;
		cout<<"����CPU"<<endl;
	}
	//CPU�������� 
	~CPU () {
		cout<<"����CPU"<<endl;
	}
	
	CPU_Rank GetRank() const { return rank; }
	int GetFrequency() const { return frequency; }
	float GetVoltage() const { return voltage; }
	
	void Run() {
		cout<<"CPU����"<<endl;
	}
	void Stop() {
		cout<<"CPUֹͣ����"<<endl;
	}
};

int main()
{
	//����һ������acpu����������Ӧ�Ĺ��캯�� 
	CPU acpu(P6,300,2.8);
	acpu.Run();
	acpu.Stop();
	return 0;
} 
