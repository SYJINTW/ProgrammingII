#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include "function.h"

void RleCodec::encode()
{
	int cnt = 0;
	char prev = '\0';
	std::stringstream ss;

	code_str.push_back('$');
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
	code_str = ss.str();
	encoded = true;
}

void RleCodec::decode()
{
	std::stringstream os;
	std::string int_str;
	for (auto c : code_str) {
		if (std::isdigit(c)) {
			int_str.push_back(c);
		} else {
			int cnt = 0;
			std::stringstream is{int_str};
			is >> cnt;
			if (cnt==0) {
				os << c;
			} else {
				for (int i=0; i<cnt; ++i)
					os << c;
			}
			int_str.clear();
		}
	}

	code_str = os.str();
	encoded = false;
}


