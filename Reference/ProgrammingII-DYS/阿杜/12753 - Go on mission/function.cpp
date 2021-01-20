#include<iostream>
#include<string.h>
#include<iomanip>
#include"function.h"
using namespace std;
BigInt::BigInt():sign(true){
    for(int i=0;i<N;i++){
        bigInt[i] = 0;
    }
}

BigInt::BigInt(char *input):sign(true){
    for(int i=0;i<N;i++){
        this->bigInt[i]=0;
    }
    long long len = strlen(input);
    int cursor = 0;
    int i;
    for(i=len-1;i>7;i-=8){
        int temp = 0;
        for(int j = i-7;j<=i;j++){
            temp*=10;
            temp+=input[j]-'0';
        }
        this->bigInt[cursor++] = temp;
    }
    int temp = 0;
    for(int j=0;j<=i;j++){
        temp*=10;
        temp+=input[j]-'0';
    }
    this->bigInt[cursor] = temp;
}

BigInt::BigInt(const BigInt& copied){
    *this = copied;
}

BigInt& BigInt::operator=(const BigInt& copied){
    if(this==&copied)   return *this;
    this->sign = copied.sign;
    for(int i=0;i<N;i++){
        this->bigInt[i] = copied.bigInt[i];
    }
    return *this;
}

bool BigInt::operator < (BigInt eval){
    if(this->sign == true&&eval.sign == false)
        return false;
    else if(this->sign==false&&eval.sign==true)
        return true;
    else if (this->sign==true&&eval.sign==true){
        for(int i = N-1;i>=0;i--){
            if(this->bigInt[i]>eval.bigInt[i])
                return false;
            else if(this->bigInt[i]<eval.bigInt[i])
                return true;
        }
    }
    else if(this->sign==false&&this->sign==false){
        for(int i = N-1;i>=0;i--){
            if(this->bigInt[i]>eval.bigInt[i])
                return true;
            else if(this->bigInt[i]<eval.bigInt[i])
                return false;
        }
    }
    return false;
}

bool BigInt::operator > (BigInt eval){
    if(this->sign == true&&eval.sign == false)
        return true;
    else if(this->sign==false&&eval.sign==true)
        return false;
    else if (this->sign==true&&eval.sign==true){
        for(int i = N-1;i>=0;i--){
            if(this->bigInt[i]>eval.bigInt[i])
                return true;
            else if(this->bigInt[i]<eval.bigInt[i])
                return false;
        }
    }
    else if (this->sign==false&&eval.sign==false){
        for(int i = N-1;i>=0;i--){
            if(this->bigInt[i]>eval.bigInt[i])
                return false;
            else if(this->bigInt[i]<eval.bigInt[i])
                return true;
        }
    }
    return false;
}

bool BigInt::operator==(BigInt eval){
    if(this->sign!=eval.sign)
        return false;
    for(int i=N-1;i>=0;i--){
        if(this->bigInt[i]!=eval.bigInt[i])
            return false;
    }
    return true;
}

bool BigInt::operator>=(BigInt eval){
    if(this->sign == true&&eval.sign == false)
        return true;
    else if(this->sign==false&&eval.sign==true)
        return false;
    else if (this->sign==true&&eval.sign==true){
        for(int i = N-1;i>=0;i--){
            if(this->bigInt[i]>eval.bigInt[i])
                return true;
            else if(this->bigInt[i]<eval.bigInt[i])
                return false;
        }
    }
    else if (this->sign==false&&eval.sign==false){
        for(int i = N-1;i>=0;i--){
            if(this->bigInt[i]>eval.bigInt[i])
                return false;
            else if(this->bigInt[i]<eval.bigInt[i])
                return true;
        }
    }
    return true;
}

bool BigInt::operator <= (BigInt eval){
    if(this->sign == true&&eval.sign == false)
        return false;
    else if(this->sign==false&&eval.sign==true)
        return true;
    else if (this->sign==true&&eval.sign==true){
        for(int i = N-1;i>=0;i--){
            if(this->bigInt[i]>eval.bigInt[i])
                return false;
            else if(this->bigInt[i]<eval.bigInt[i])
                return true;
        }
    }
    else if(this->sign==false&&this->sign==false){
        for(int i = N-1;i>=0;i--){
            if(this->bigInt[i]>eval.bigInt[i])
                return true;
            else if(this->bigInt[i]<eval.bigInt[i])
                return false;
        }
    }
    return true;
}

BigInt BigInt::operator+(BigInt eval){
    return *this;
}
BigInt BigInt::operator-(BigInt eval){
    BigInt ans;
    if(this->sign==true){
        if(*this==eval){
            ans.sign=true;
            for(int i=N-1;i>=0;i--){
                ans.bigInt[i]=0;
            }
        }
        else if(*this>eval){
            ans.sign = true;
            for(int i=0;i<N;i++){
                if(this->bigInt[i]>eval.bigInt[i])
                    ans.bigInt[i] = this->bigInt[i]-eval.bigInt[i];
                else if(this->bigInt[i]<eval.bigInt[i]){
                    this->bigInt[i+1]-=1;
                    ans.bigInt[i] = this->bigInt[i] + (BASE - eval.bigInt[i]);
                }
                else
                    ans.bigInt[i]=0;
            }
        }
        else if(*this<eval){
            ans.sign = false;
            for(int i=0;i<N;i++){
                if(eval.bigInt[i]>this->bigInt[i])
                    ans.bigInt[i] = eval.bigInt[i]-this->bigInt[i];
                else if(eval.bigInt[i]<this->bigInt[i]){
                    eval.bigInt[i+1]-=1;
                    ans.bigInt[i] = eval.bigInt[i] + (BASE - this->bigInt[i]);
                }
                else
                    ans.bigInt[i]=0;
            }
        }
    }
    else if(this->sign==false){
        ans.sign = false;
        for(int i=0;i<N;i++){
            ans.bigInt[i] = this->bigInt[i] + eval.bigInt[i];
            if(ans.bigInt[i]>=BASE){
                ans.bigInt[i]  = ans.bigInt[i]-BASE;
                this->bigInt[i+1]+=1;
            }
        }
    }
    return ans;
}

istream& operator >> (istream& in ,BigInt& n){
    char str[1205];
    cin>>str;
    n = BigInt(str);
    return in;
}

ostream& operator << (ostream& out,BigInt& n){
    if(n.sign==false)
        cout<<"-";
    bool start=false;
    bool first = true;
    for(int i=149;i>=0;i--){
        if(n.bigInt[i]!=0)
            start = true;
        if(start){
            if(first){
                cout<<n.bigInt[i];
                first=false;
            }
            else
                cout<<setw(8)<<setfill('0')<<n.bigInt[i];
        }
    }
    if(!start)
        cout<<"0";
    return out;

}

void solution(BigInt&tanjiro,BigInt&zenitsu,BigInt&inosuke,int n){
    for(int i=0;i<n;i++){
        BigInt mission;
        cin>>mission;
        if(inosuke>=tanjiro&&inosuke>=zenitsu)
            inosuke = inosuke-mission;
        else if (tanjiro >= inosuke && tanjiro >= zenitsu)
			tanjiro = tanjiro - mission;
		else if (zenitsu >= inosuke && zenitsu >= tanjiro)
			zenitsu = zenitsu - mission;
    }
}
