#include<bits/stdc++.h>
using namespace std;

//C++枚举类 
//可以理解为有一个CPU_Rank的类型，这个类型下有P1到P7不同的值 
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
	//拷贝构造函数 
	CPU (CPU &c) {
		rank=c.rank;
		frequency=c.frequency;
		voltage=c.voltage;
		cout<<"拷贝构造了一个CPU"<<endl;
	}
	//CPU析构函数 
	~CPU () {
		cout<<"析构CPU"<<endl;
	}
	
	//Getter Setter方法：为private提供外界接口 
	CPU_Rank GetRank() const { return rank; }
	int GetFrequency() const { return frequency; }
	float GetVoltage() const { return voltage; }
	
	void SetRank(CPU_Rank r) { rank=r; }
	void SetFrequency(int f) { frequency=f; }
	void SetVoltage(float v) { voltage=v; }
	
	//其他一些public方法 
	void Run() {
		cout<<"CPU运行"<<endl;
	}
	void Stop() {
		cout<<"CPU停止运行"<<endl;
	}
};

//RAM类 
enum RAM_Type { DDR2=2,DDR3,DDR4 };
class RAM
{
private:
	enum RAM_Type type;
	unsigned int frequency;
	unsigned int size;

public:
	RAM(RAM_Type t,unsigned int f,unsigned int s) {
		type=t;
		frequency=f;
		size=s;
		cout<<"构造了一个RAM"<<endl;
	}	
	~RAM() { cout<<"析构了RAM"<<endl; }
	
	//Setter Getter方法
	 
};

//CD_ROM类 
enum CDROM_Interface { SATA,USB };
enum CDROM_Install_type { external,built_in };
class CD_ROM
{
private:
	enum CDROM_Interface interface_type;
	unsigned int cache_size;	//MB
	CDROM_Install_type install_type;
	
public:
	CD_ROM(CDROM_Interface i,unsigned int s,CDROM_Install_type it) {
		interface_type=i;
		cache_size=s;
		install_type=it;
		cout<<"构造了CDROM"<<endl;
	}
	~CD_ROM() {
		cout<<"析构CD_ROM"<<endl;
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
