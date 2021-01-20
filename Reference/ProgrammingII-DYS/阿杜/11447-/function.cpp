#include<cassert>
#include<iostream>
#include<map>
#include<ostream>
#include<string>
#include"function.h"
#include<set>

namespace oj{
    void insert(std::map<int,String> &ma,int key,const std::string &str){
        auto test = ma.find(key);
        std::string s;
        if(test!=ma.end()){
            s = str + test->second.str;
            ma.erase(test);
        }
        else{
            s = str;
        }
        ma.insert(std::pair<int,String> (key,String(s)));
    }

	void output(const std::map<int,String> &ma,int begin,int end){
        for(auto &i:ma){
            if(i.first>=begin&&i.first<=end){
                std::cout<<i.second<<' ';
            }
        }
	}

	void erase(std::map<int,String> &ma,int begin,int end){
        std::set<int> eraseKeys;
        for(auto &i:ma){
            if(i.first>=begin&&i.first<=end){
                eraseKeys.insert(i.first);
            }
        }
        for(auto key:eraseKeys){
            ma.erase(key);
        }
	}

	std::ostream& operator<<(std::ostream &o,const std::map<int,String> &ma){
        for(auto &i:ma){
            o<<i.second<<' ';
        }
        return o;
	}
}
