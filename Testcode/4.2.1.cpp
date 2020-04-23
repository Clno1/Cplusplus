#include<bits/stdc++.h>
using namespace std;

//C++ö���� 
//�������Ϊ��һ��CPU_Rank�����ͣ������������P1��P7��ͬ��ֵ 
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
	//�������캯�� 
	CPU (CPU &c) {
		rank=c.rank;
		frequency=c.frequency;
		voltage=c.voltage;
		cout<<"����������һ��CPU"<<endl;
	}
	//CPU�������� 
	~CPU () {
		cout<<"����CPU"<<endl;
	}
	
	//Getter Setter������Ϊprivate�ṩ���ӿ� 
	CPU_Rank GetRank() const { return rank; }
	int GetFrequency() const { return frequency; }
	float GetVoltage() const { return voltage; }
	
	void SetRank(CPU_Rank r) { rank=r; }
	void SetFrequency(int f) { frequency=f; }
	void SetVoltage(float v) { voltage=v; }
	
	//����һЩpublic���� 
	void Run() {
		cout<<"CPU����"<<endl;
	}
	void Stop() {
		cout<<"CPUֹͣ����"<<endl;
	}
};

//RAM�� 
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
		cout<<"������һ��RAM"<<endl;
	}	
	~RAM() { cout<<"������RAM"<<endl; }
	
	//Setter Getter����
	 
};

//CD_ROM�� 
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
		cout<<"������CDROM"<<endl;
	}
	~CD_ROM() {
		cout<<"����CD_ROM"<<endl;
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
