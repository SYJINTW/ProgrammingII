#include <iostream>
#include "function.h"
#include <string>
#include <sstream>
#include <cctype>
void RleCodec::encode()
{
	int cnt = 0;
	char prev = '\0';
	std::stringstream ss;
	for (auto c : code_str) {
		if (c!=prev) {
			if (cnt>0) {
				if (cnt==1)
					ss << prev;
				else if (cnt==2)
					ss << prev << prev;
				else
					ss << cnt << prev;
			}
			prev = c;
			cnt = 1;
		} else {
			++cnt;
		}
	}
	if (cnt>0) {
		if (cnt==1)
			ss << prev;
		else if (cnt==2)
			ss << prev << prev;
		else
			ss << cnt << prev;
	}
	code_str = ss.str();
	encoded = true;
}
void RleCodec::decode()
{

    std::string int_ans;
    std::stringstream os;
    for(auto c:code_str){
        if(std::isdigit(c)){
            int_ans.push_back(c);
        }
        else{
            int cnt = 0;
            std::stringstream is{int_ans};
            is>>cnt;
            if(cnt==0){
                os<<c;
            }
            else{
                for(int i=0;i<cnt;i++){
                    os<<c;
                }
            }
            int_ans.clear();
        }
    }
    code_str = os.str();
    encoded = false;
   //No cheating : )
}
