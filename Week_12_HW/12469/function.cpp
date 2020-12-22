#include <iostream>
#include <string>
#include <iomanip>
#include "function.h"
using namespace std;
#define MAX_N 1000
#define MAX_Bit 5
#define MAX 100000

istream& operator >>(istream& in, BigInt& b)
{
	string big_int;
	in >> big_int;

	// 處理正負號
	if(big_int[0] == '-')
	{
		b.sign = -1;
		big_int.erase(0,1);
	}
	else b.sign = 1;

	// 翻轉字串
	reverse(big_int.begin(), big_int.end());

	// 每五個數字存成一格
	int id = 0;
	for(int i = 0; i < big_int.length(); i+=MAX_Bit)
	{
		string sub = big_int.substr(i, MAX_Bit);
		reverse(sub.begin(), sub.end());
		b.m[id++] = stoi(sub);
	}

	// 計算長度
	b.l = id;

	return in;
}

ostream& operator<<(ostream& out, BigInt b)
{
	out << b.sign * b.m[b.l-1];
	for(int i = b.l-2; i >= 0; i--)
	{
		out << setfill('0') << setw(MAX_Bit) << b.m[i];
	}
	return out;
}

BigInt
BigInt::operator +(const BigInt &y)
{
	BigInt x(*this);
	long long tmp = 0;
	int new_l = 0;
	// add two numbers together
	for(new_l = 0; new_l < x.l || new_l < y.l || tmp; new_l++)
	{
		if(new_l < x.l) tmp += x.m[new_l]*x.sign;
		if(new_l < y.l) tmp += y.m[new_l]*y.sign;
		x.m[new_l] = tmp % MAX;
		tmp /= MAX;
	}
	x.l = new_l;

	// 判斷答案是正或負
	if(x.m[x.l-1] >= 0)
	{
		x.sign = 1;
		for(int i = 0; i < x.l-1; i++)
		{
			if(x.m[i] < 0)
			{
				x.m[i] += MAX;
				x.m[i+1] -= 1; 
			} else;
		}
	}
	else
	{
		x.sign = -1;
		for(int i = 0; i < x.l; i++)
		{
			if(x.m[i] > 0)
			{
				x.m[i] = x.m[i]-MAX;
				x.m[i+1] += 1; 
			} else;
			x.m[i]*=(-1);
		}
	}

	// 清除多餘的0
	while(x.m[x.l-1]==0 && x.l > 0){
		x.l--;
	}

	// 特殊判斷：答案是否為0
	if(x.l == 0 && x.m[0] == 0) x.l = 1;

	return x;
}

BigInt
BigInt::operator -(const BigInt &y)
{
	BigInt x(*this);
	long long tmp = 0;
	long long carrier = 0;
	int new_l = 0;
	// minus two numbers
	for(new_l = 0; new_l < x.l || new_l < y.l || carrier; new_l++)
	{
		if(new_l < x.l) tmp += x.m[new_l]*x.sign;
		if(new_l < y.l) tmp -= y.m[new_l]*y.sign;
		x.m[new_l] = tmp % MAX;
		tmp /= MAX;
	}
	x.l = new_l;

	// 判斷答案是正或負
	if(x.m[x.l-1] >= 0)
	{
		x.sign = 1;
		// 正 -> 讓每一位都保持正數，處理補位
		for(int i = 0; i < x.l-1; i++)
		{
			if(x.m[i] < 0)
			{
				x.m[i] += MAX;
				x.m[i+1] -= 1; 
			} else;
		}
	}
	else
	{
		x.sign = -1;
		// 負 -> 讓每一位都保持負數，處理補位
		for(int i = 0; i < x.l; i++)
		{
			if(x.m[i] > 0)
			{
				x.m[i] = x.m[i]-MAX;
				x.m[i+1] += 1; 
			} else;
			x.m[i]*=(-1);
		}
	}

	// 清除多餘的0
	while(x.m[x.l-1]==0 && x.l > 0){
		x.l--;
	}

	// 特殊判斷：答案是否為0
	if(x.l == 0 && x.m[0] == 0) x.l = 1;

	return x;
}




