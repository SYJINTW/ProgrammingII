#include "function.h"
#include <iostream>
#include <cstring>
using namespace std;
#define Guess 0
#define Less 1

Engineer::Engineer(){
    // TODO
    init();
}

Engineer::~Engineer(){
    // TODO
}
void Engineer::init(){
    // TODO
    count = 0;
    memset(value_history,-1,sizeof(value_history));
    memset(action_history,-1,sizeof(action_history));
    memset(answer_history,-1,sizeof(answer_history));
}

void Engineer::MakeQuery(char* query_str){
    // Interactive Version
    if(count==0){
        char temp[50] = "less -2147483648";
        strcpy(query_str,temp);
        action_history[count]=Less;
        value_history[count]=-2147483648;
    }
    else if(count==1){
        char temp[50] = "less 2147483647";
        strcpy(query_str,temp);
        action_history[count]=Less;
        value_history[count]=2147483647;
    }
    else{
        int min=0,max=0;
        for(int i=count-1;i>=0;i--){
            if(answer_history[i]==true){
                max=value_history[i];
                break;
            }
        }
        for(int i=count-1;i>=0;i--){
            if(answer_history[i]==false){
                min=value_history[i];
                break;
            }
        }

        if( min + 1 == max ){
            int ans = min;
            char temp[50];
            bool ans_is_neg = false;
            if(ans<0){
                ans_is_neg = true;
                ans*=-1;
            }
            int cursor=0;
            while(ans!=0){
                temp[cursor++] = (ans%10)+'0';
                ans/=10;
            }
            if(ans_is_neg)
                temp[cursor++] = '-';
            strcpy(query_str,"guess ");
            int i=6;
            for(int j=cursor-1;j>=0;i++,j--){
                query_str[i] = temp[j];
            }
            query_str[i]='\0';
            action_history[count]=Guess;
            value_history[count]=min;
        }
        else{
            int x = (min+max)/2;
            char temp[50];
            bool x_is_neg = false;
            if(x<0){
                x_is_neg = true;
                x*=-1;
            }
            int cursor=0;
            while(x!=0){
                temp[cursor++] = (x%10)+'0';
                x=x/10;
            }
            if(x_is_neg)
                temp[cursor++] = '-';
            strcpy(query_str,"less ");
            int i=5;
            for(int j=cursor-1;j>=0;j--,i++){
                query_str[i] = temp[j];
            }
            query_str[i]='\0';
            action_history[count] = Less;
            value_history[count] = (min+max)/2;
        }
    }
    // Determine the query string by history
    // TODO
}
void Engineer::GetAnswer(bool ans){
    // TODO
    answer_history[count++]=ans;
}
