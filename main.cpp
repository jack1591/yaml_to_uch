#include <iostream>
#include "yaml-cpp/yaml.h"
using namespace std;
string yaml_path;

int main(int argc, char* argv[]){
    cout<<"TESTik\n";
    yaml_path = argv[1];
    YAML::Node config = YAML::LoadFile("config.yaml");
    
    std::map<std::string, double> constants;
        if (config["constants"]){
            for (const auto& item : config["constants"]){
                constants[item.first.as<string>()] = item.second.as<double>();
            }
            for (auto c:constants)
                cout<<c.first<<" "<<c.second<<endl;
        }   
    

    /*
        if (config["constants"]) {
            for (const auto& item : config["constants"]){
                constants[item.first.as<std::string>()] = item.second.as<int>();
            }
            for (auto c:constants)
                cout<<c.first<<" "<<c.second<<endl;
        }
    */

    
    
    
   return 0;
}