#include <iostream>
#include "yaml-cpp/yaml.h"
#include <map>
using namespace std;
string yaml_path;

void outValues(const YAML::Node& values){
    for (auto c:values){
        string name = c.first.as<string>();
        string val = c.second.as<string>();
        cout << name << ": " << val << ";\n";
    }
}

void outDictionaries(const YAML::Node& values){
    for (auto dict:values){
        string name = dict.first.as<std::string>();
        cout << name << ": \n{\n";
        const YAML::Node& dictionary = dict.second;
        outValues(dictionary);
        cout << "};\n";
    }
}

void parseFile(const YAML::Node& node){
    for (const auto& item : node) {
        std::string key = item.first.as<std::string>();
        const YAML::Node& value = item.second;
        if (key=="constants"){
            outValues(value);
        }
        else if (key=="dictionaries"){
            outDictionaries(value);
        }
        else if (key=="calculations"){
            cout<<key<<endl;
        }
    }   
}

int main(int argc, char* argv[]){
    yaml_path = argv[1];
    YAML::Node config = YAML::LoadFile("config.yaml");
    parseFile(config);
   return 0;
}