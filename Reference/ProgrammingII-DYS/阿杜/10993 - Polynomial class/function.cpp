#include <iostream>
#include "function.h"
using namespace std;
Polynomial::Polynomial(){}
Polynomial::Polynomial(const int gp,const int cof[51]){
	for(int i=gp;i>=0;i--)
		this->coefficients[i]=cof[i];
	this->greatestPower=gp;
}
Polynomial Polynomial::add(const Polynomial next) const{
	Polynomial tmp = *this;
	int gp2 = next.greatestPower;
	int gp1 = tmp.greatestPower;
	int cnt = gp2>gp1?gp2:gp1;
	tmp.greatestPower = cnt;
	for(int i=cnt;i>=0;i--)
		if(i==gp2){
			tmp.coefficients[i]+=next.coefficients[i];
			gp2--;
		}
	return tmp;
}
Polynomial Polynomial::subtract(const Polynomial next) const{
	Polynomial tmp = *this;
	int gp2 = next.greatestPower;
	int gp1 = tmp.greatestPower;
	int cnt = gp2>gp1?gp2:gp1;
	tmp.greatestPower = cnt;
	for(int i=cnt;i>=0;i--){
		if(i==gp2) tmp.coefficients[i]-=next.coefficients[i],gp2--;
	}
	return tmp;
}
Polynomial Polynomial::multiplication(const Polynomial next) const{
	Polynomial tmp = *this;
	int gp2 = next.greatestPower;
	int gp1 = tmp.greatestPower;
	int cnt = gp1+gp2;
	int cotmp[110] = {0};
	tmp.greatestPower = cnt;
	for(int i=0;i<=gp1;i++)
		for(int j=0;j<=gp2;j++)
			cotmp[i+j]+=tmp.coefficients[i]*next.coefficients[j];
	for(int i=0;i<=cnt;i++)
		tmp.coefficients[i] = cotmp[i];
	return tmp;
}
void Polynomial::output()const{
	for(int i =this->greatestPower;i>0;i--)
		cout<<this->coefficients[i]<<" ";
	cout<<this->coefficients[0];
}

