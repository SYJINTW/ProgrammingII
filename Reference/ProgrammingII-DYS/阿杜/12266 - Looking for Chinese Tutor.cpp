#include<iostream>
#include<map>
using namespace std;
map<string,string> pokemon = {{"Wa","Waninoko"},{"Mi","Milotic"},
{"Ma","Magikarp"},{"Va","Vaporeon"},{"Sh","Sharpedo"},
{"Tapu","Tapu Fini"},
{"Em","Empoleon"},
{"La","Lapras"},
{"Pi","Pikachu"},
{"Pe","Pikachu"},
{"Me","Mega Gyarados"}};
int main(){
    int N;
    string name,school;
    cin>>N;
    while(N--){
        cin>>name>>school;
        map<string,string>::iterator it;
        for(it = pokemon.begin();it!=pokemon.end();it++){
            string first_name = name.substr(0,it->first.size());
            if(first_name == it->first){
                cout<<name<<" the "<<school<<" "<<it->second<<endl;
                break;
            }
        }
        if(it==pokemon.end()){
            cout<<name<<" is looking for a Chinese tutor, too!\n";
        }
    }
}
