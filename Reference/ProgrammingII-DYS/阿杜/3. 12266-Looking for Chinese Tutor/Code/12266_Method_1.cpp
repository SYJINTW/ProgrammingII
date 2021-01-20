#include <iostream>
#include <string>
#include <map>
#include <fstream>
using namespace std;

//map construction
//Initialized in global
//std::map<std::string, std::string> mapping = {
//	{"Wa",	"Waninoko"},
//  {"Mi",  "Milotic"},
//	{"Ma",	"Magikarp"},
//	{"Va",	"Vaporeon"},
//	{"Sh",	"Sharpedo"},
//	{"Tapu","Tapu Fini"},
//	{"Em",	"Empoleon"},
//	{"La",	"Lapras"},
//	{"Pi",	"Pikachu"},
//	{"Pe",	"Pikachu"},
//	{"Me",	"Mega Gyarados"}
//};

int main(){
    int N;
	std::string name, school;

	//map construction
	//Initialized in main
	std::map<std::string, std::string> mapping;
	mapping["Wa"] = "Waninoko";
	mapping["Mi"] = "Milotic";
	mapping["Ma"] = "Magikarp";
	mapping["Va"] = "Vaporeon";
	mapping["Sh"] = "Sharpedo";
	mapping["Tapu"] = "Tapu Fini";
	mapping["Em"] = "Empoleon";
	mapping["La"] = "Lapras";
	mapping["Pi"] = "Pikachu";
	mapping["Pe"] = "Pikachu";
	mapping["Me"] = "Mega Gyarados";

	//Taking input
	std::cin >> N;

	while(N--){
		//Each case
		std::cin >> name >> school;

		//Use mapping.find() to find out if the sub_name can be found in mapping
		std::map<std::string, std::string>::iterator it;
		it = mapping.find(name.substr(0, 4));//matching the first four characters
		if(it != mapping.end())
			std::cout << name << " the " << school << ' ' << mapping[name.substr(0, 4)] << '\n';
		else
        {
            it = mapping.find(name.substr(0, 2));//matching the first two characters
            if(it != mapping.end())
                std::cout << name << " the " << school << ' ' << mapping[name.substr(0, 2)] << '\n';
			else
                std::cout << name << " is looking for a Chinese tutor, too!\n";
        }
	}
}
