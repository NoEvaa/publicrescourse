#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdlib>
using namespace std;
class Electric{
	public:
		Electric(int voltage=100,int current=20,char*name="elctric");
		Electric(Electric &refobj);
		~Electric();
		
		int get_operating_voltage(void)const;
		bool set_operating_voltage(int v_val);
		
		int get_operating_current(void )const;
		bool set_operating_current(int c_val);
		void show_name(void);
	private:
		int operating_voltage;
		int operating_current;
		char *p_name;
}; 
Electric::Electric(int voltage,int current,char*name){
	int leng;
	if(name==NULL)
	{
		name="electric";	
	}
	leng=strlen(name);
	operating_voltage = voltage;
	operating_current = current;	
	p_name=(char*)malloc(leng);
	strcpy(p_name,name); 
}
Electric::Electric(Electric &refobj){
	int leng;
	operating_voltage = refobj.operating_voltage;
	operating_current = refobj.operating_current;
	
	leng = strlen(refobj.p_name);
	p_name=(char*)malloc(leng);
	strcpy(p_name,refobj.p_name);
	cout<<"fuzhi!"<<endl;
}
Electric::~Electric(){
	delete[] p_name;
}
int Electric::get_operating_voltage(void)const{
	return operating_voltage;
};
bool Electric::set_operating_voltage(int v_val){
	if(v_val<0){
		return false;
	}
	operating_voltage=v_val;
	return true;
};
int Electric::get_operating_current(void)const{
	return operating_current;
};
bool Electric::set_operating_current(int c_val){
	if(c_val<0){
		return false;
	}
	operating_current=c_val;
	return true;
}
void Electric::show_name(void){
	cout<<"mz:"<<this->p_name<<endl;
};

int main(void){
	Electric elc_0(10,50,"ee");
	cout<<elc_0.get_operating_voltage()<<endl;
	cout<<elc_0.get_operating_current()<<endl;
	elc_0.show_name();
	Electric elc_1 = elc_0;
	elc_1.show_name();
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
