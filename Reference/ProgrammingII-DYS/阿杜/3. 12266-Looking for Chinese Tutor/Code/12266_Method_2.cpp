#include <iostream>
#include <string>
#include <map>
#include <fstream>
using namespace std;

//map construction
//Initialized in global
std::map<std::string, std::string> mapping = {
	{"Wa",	"Waninoko"},
    {"Mi",  "Milotic"},
	{"Ma",	"Magikarp"},
	{"Va",	"Vaporeon"},
	{"Sh",	"Sharpedo"},
	{"Tapu","Tapu Fini"},
	{"Em",	"Empoleon"},
	{"La",	"Lapras"},
	{"Pi",	"Pikachu"},
	{"Pe",	"Pikachu"},
	{"Me",	"Mega Gyarados"}
};

int main(){
    int N;
	std::string name, school;

	//map construction
	//Initialized in main
	//std::map<std::string, std::string> mapping;
	//mapping["Wa"] = "Waninoko";
	//mapping["Mi"] = "Milotic";
	//mapping["Ma"] = "Magikarp";
	//mapping["Va"] = "Vaporeon";
	//mapping["Sh"] = "Sharpedo";
	//mapping["Tapu"] = "Tapu Fini";
	//mapping["Em"] = "Empoleon";
	//mapping["La"] = "Lapras";
	//mapping["Pi"] = "Pikachu";
	//mapping["Pe"] = "Pikachu";
	//mapping["Me"] = "Mega Gyarados";

	//Taking input
	std::cin >> N;

	while(N--){
		//Each case
		std::cin >> name >> school;

        bool canTeach = false;
        for(auto &p : mapping)//Do the key matchings by ourselves!
        {
            // p.first = beginning rhyme, p.second = pokemon
            if(name.substr(0, p.first.size()) == p.first)
            {
                canTeach = true;
                std::cout << name << " the " << school << ' ' << p.second << '\n';
                break;
            }
        }
        if(!canTeach) std::cout << name << " is looking for a Chinese tutor, too!\n";
	}
}
