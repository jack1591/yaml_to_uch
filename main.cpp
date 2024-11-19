#include <iostream>
#include "yaml-cpp/yaml.h"
#include <map>
using namespace std;
string yaml_path;
int cnt;

void outValues(const YAML::Node& values){
    for (auto c:values){
        cnt++;
        string name = c.first.as<string>();
        string val = c.second.as<string>();
        cout << name << ": " << val << ";\n";
    }
}

void outDictionaries(const YAML::Node& values){
    for (auto dict:values){
        string name = dict.first.as<std::string>();
        cnt++;
        cout << name << " "<< cnt << " : \n{\n";
        const YAML::Node& dictionary = dict.second;
        outValues(dictionary);
        cout << "};\n";
    }
}

void parseFile(const YAML::Node& node){
    for (const auto& item : node) {
        std::string key = item.first.as<std::string>();
        cnt++;
        const YAML::Node& value = item.second;
        if (key=="constants"){
            cout<<key<<" "<<cnt<<endl;
            outValues(value);
        }
        else if (key=="dictionaries"){
            outDictionaries(value);
        }
        else if (key=="calculations"){
            cout<<key<<" " <<cnt<<endl;
            for (const auto& calc : value){
                    std::string expression = calc.as<std::string>();
                    std::cout << "Expression: " << expression << "\n";
                    cnt++;
            }
            /*
            for (auto c:value){
                string out = c.as<string>();
                cout<<out<<endl;
            }
            */
        }

    }   
}

int main(int argc, char* argv[]){
    yaml_path = argv[1];
    YAML::Node config = YAML::LoadFile("config.yaml");
    parseFile(config);
   return 0;
}