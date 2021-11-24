#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<string.h> 
using namespace std;
class c_point{
	public:
		c_point(int x=0,int y=0){_x=x;_y=y;}
		//+
		c_point operator+(const c_point &_var);
		c_point operator+(const int _var);
		friend c_point operator+(int _var,const c_point &c2);
		//++
		c_point & operator++();
		c_point operator++(int x);
		//=
		c_point & operator=(const c_point &var);
		//><=!
		bool operator>(const c_point &var);
		bool operator<(const c_point &var);
		bool operator<=(const c_point &var);
		bool operator>=(const c_point &var);
		bool operator==(const c_point &var);
		bool operator!=(const c_point &var);
		//>><<
		friend istream & operator>>(istream &is,c_point &var);
		friend ostream & operator<<(ostream &os,c_point &var);
		//()
		const c_point & operator()(void);//输出坐标 
		const double operator()(const c_point &var2);//求两点距离
				
		int get_x(){return _x;}
		int get_y(){return _y;}
	private:
		int _x,_y;
};
c_point c_point::operator+(const c_point &_var){
	return c_point(this->_x+_var._x,this->_y+_var._y);
}
c_point c_point::operator+(const int _var){
	return c_point(this->_x+_var,this->_y+_var);
}
c_point operator+(int _var,const c_point &obj){
	return c_point(obj._x+_var,obj._y+_var);
}
c_point & c_point::operator++(){
	this->_x++;
	this->_y++;
	return *this;
}
c_point c_point::operator++(int x){
	c_point temp=*this;
	this->_x++;
	this->_y++;
	return temp;
}
c_point & c_point::operator=(const c_point &var){
	this->_x=var._x;
	this->_y=var._y;
	return *this;
}
bool c_point::operator<(const c_point &var){//
	return (this->_x<var._x?true:false);
}
bool c_point::operator>(const c_point &var){//
	return (this->_x>var._x?true:false);
}
bool c_point::operator>=(const c_point &var){
	return !(*this<var);
}
bool c_point::operator<=(const c_point &var){
	return !(*this>var);
}
bool c_point::operator==(const c_point &var){
	return !((*this>var)||(*this<var));
}
bool c_point::operator!=(const c_point &var){
	return !(*this==var);
}
istream & operator>>(istream &is,c_point &var){
	is>>var._x>>var._y;
	return is;
}
ostream & operator<<(ostream &os,c_point &var){
	os<<var._x<<"  "<<var._y;
	return os;
}
const c_point & c_point::operator()(){
	cout<<*this<<endl;
	return *this;
}
const double c_point::operator()(const c_point &var2){
	double distance;
	int x,y;
	x=abs(this->_x-var2._x);
	y=abs(this->_y-var2._y);
	distance=sqrt(x*x+y*y);
	return distance;
}



int main(void){
	
	cout<<endl;
	return 0;
}
