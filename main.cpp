#include <iostream>
#include "yaml-cpp/yaml.h"
#include <map>
#include <fstream>
#include <Windows.h>
#include <vector>
using namespace std;
string yaml_path;
int cnt,tek;

struct tek_comment{
    int first;
    string second;
    int pos;
};

vector <tek_comment> comments;

void outComments(){
    int i = tek;
    cout<<"/+\n"<<comments[i].second<<endl;
    i++;
    while (i<comments.size() && comments[i].first==comments[i-1].first){
        cout<<comments[i].second<<endl;
        i++;
    }
    cout<<"+/\n";
    tek = i;
    if (i==comments.size())
        tek = 0;
}

void outValues(const YAML::Node& values){
    for (auto c:values){
        cnt++;
        string name = c.first.as<string>();
        string val = c.second.as<string>();
        cout << name << ": " << val << "; ";
        
        if (cnt+1==comments[tek].first && comments[tek].pos==0){
            cout<<"\n";
            outComments();
        }
        else if (cnt==comments[tek].first && comments[tek].pos!=0)
            outComments();           
        cout<<"\n";
    }
}

void outDictionaries(const YAML::Node& values){
    for (auto dict:values){
        string name = dict.first.as<std::string>();
        cnt++;
        cout << name << ": \n{\n";
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
            
            if (cnt+1==comments[tek].first && comments[tek].pos==0){
                cout<<"\n";
                outComments();
            }
            else if (cnt==comments[tek].first && comments[tek].pos!=0)
                outComments();
            
            outValues(value);
        }
        else if (key=="dictionaries"){
            //cout<<key<<" "<<cnt<<endl;
            if (cnt+1==comments[tek].first && comments[tek].pos==0){
                cout<<"\n";
                outComments();
            }
            else if (cnt==comments[tek].first && comments[tek].pos!=0)
                outComments();
            outDictionaries(value);
        }
        else if (key=="calculations"){
            cout<<key<<" " <<cnt<<endl;
            for (const auto& calc : value){
                std::string expression = calc.as<std::string>();
                std::cout << "Expression: " << expression << "\n";
                cnt++;
            }
        }

    }   
}

vector<tek_comment> count_comments(){
    int count_real = 0;
    vector<tek_comment> comm;
    ifstream fin("config.yaml");
    string tek="";
    while (getline(fin,tek))
        if (tek.size()>0){  
            while (tek[0]==' ')
                tek = tek.substr(1,tek.size()-1);  
            if (tek.find('#')==string::npos || tek.find('#')>0)
                count_real++;

            if (tek.find('#')!=string::npos){
                int count = count_real;
                if (tek.find('#')==0 && count_real>0 && comm.size()>0 && comm[comm.size()-1].pos==0 && comm[comm.size()-1].first!=count_real)
                    count++;
                //cout<<count<<" "<<tek.substr(tek.find('#')+1,tek.size()-tek.find('#')-1)<<" "<<tek.find('#')<<endl;
                tek_comment comment;
                comment.first = count;
                comment.second = tek.substr(tek.find('#')+1,tek.size()-tek.find('#')-1);
                comment.pos = tek.find('#');
                comm.push_back(comment);
            }
        }
    
    fin.close();
    return comm;
}

int main(int argc, char* argv[]){
    yaml_path = argv[1];
    //cout<<"path to yaml file is "<<yaml_path<<endl;
    comments = count_comments();
    YAML::Node config = YAML::LoadFile("config.yaml");
    if (comments[0].first==0)
        outComments();
    parseFile(config);
   return 0;
}