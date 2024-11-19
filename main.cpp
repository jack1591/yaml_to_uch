#include <iostream>
#include "yaml-cpp/yaml.h"
#include <map>
#include <fstream>
#include <Windows.h>
#include <vector>
using namespace std;
string yaml_path, output;
int cnt,tek;
map<string,string> constants;

struct tek_comment{
    int first;
    string second;
    int pos;
};

vector <tek_comment> comments;

void outComments(){
    int i = tek;
    //cout<<"/+\n"<<comments[i].second<<endl;
    output+="/+\n"+comments[i].second+"\n";
    i++;
    while (i<comments.size() && comments[i].first==comments[i-1].first){
        //cout<<comments[i].second<<endl;
        output+=comments[i].second+"\n";
        i++;
    }
    //cout<<"+/\n";
    output+="+/\n";
    tek = i;
    if (i==comments.size())
        tek = 0;
}

void calculate(string name,string val){
    string x = "";
    for (int i = 2;i<val.size()-1;i++)
        x+=val[i];
    val = x;

    if (val.find('+')!=string::npos){
        string first="",second="";
        for (int i=0;i<val.find('+');i++)
            first+=val[i];
        for (int i=val.find('+')+1;i<val.size();i++)
            second+=val[i];
        //cout<<first<<" "<<second<<endl;
        if (first[0]>='0' && first[0]<='9' && second[0]>='0' && second[0]<='9')
            constants[name] = to_string(stod(first)+stod(second));
        else {
            if (first[0]>='0' && first[0]<='9'){
                if (constants[second]==""){
                    output="Error - uninitialized variable!\n";
                    std::cerr << "Error - uninitialized variable!\n" << endl;
                    //cout<<"Error!\n";
                    exit(1);
                }
                    
                else constants[name] = to_string(stod(first)+stod(constants[second]));
            }
            else if (second[0]>='0' && second[0]<='9'){
                if (constants[first]==""){
                    output="Error - uninitialized variable!\n";
                    std::cerr << "Error - uninitialized variable!\n" << endl;
                    //cout<<"Error!\n";
                    exit(1);
                }
                else constants[name] = to_string(stod(second)+stod(constants[first]));
            }
            else {
                if (constants[first]=="" || constants[second]==""){
                    output="Error - uninitialized variable!\n";
                    std::cerr << "Error - uninitialized variable!\n" << endl;
                    //cout<<"Error!\n";
                    exit(1);
                }
                else constants[name] = to_string(stod(constants[first])+stod(constants[second]));
                
            }
        }
    }
    else if (val.find('-')!=string::npos){
        string first="",second="";
        for (int i=0;i<val.find('-');i++)
            first+=val[i];
        for (int i=val.find('-')+1;i<val.size();i++)
            second+=val[i];
        //cout<<first<<" "<<second<<endl;
        if (first[0]>='0' && first[0]<='9' && second[0]>='0' && second[0]<='9')
            constants[name] = to_string(stod(first)-stod(second));
        else {
            if (first[0]>='0' && first[0]<='9'){
                if (constants[second]==""){
                    output="Error - uninitialized variable!\n";
                    std::cerr << "Error - uninitialized variable!\n" << endl;
                    //cout<<"Error!\n";
                    exit(1);
                }
                else constants[name] = to_string(stod(first)-stod(constants[second]));
            }
            else if (second[0]>='0' && second[0]<='9'){
                if (constants[first]==""){
                    output="Error - uninitialized variable!\n"; 
                    std::cerr << "Error - uninitialized variable!\n" << endl;
                    //cout<<"Error!\n";
                    exit(1);
                }
                else constants[name] = to_string(stod(constants[first])-stod(second));
            }
            else {
                if (constants[first]=="" || constants[second]==""){
                    output="Error - uninitialized variable!\n";
                    std::cerr << "Error - uninitialized variable!\n" << endl;
                    //cout<<"Error!\n";
                    exit(1);
                }
                else constants[name] = to_string(stod(constants[first])-stod(constants[second]));
                
            }
        }
    }
    else if (val.find("min")==0){
        string first="",second="";
        string x = "";
        for (int i = 4; i<val.size()-1;i++)
            x+=val[i];
        val = x;

        for (int i=0;i<val.find(',');i++)
            first+=val[i];
        for (int i=val.find(',')+1;i<val.size();i++)
            second+=val[i];
        //cout<<first<<" "<<second<<endl;
        if (first[0]>='0' && first[0]<='9' && second[0]>='0' && second[0]<='9')
            constants[name] = to_string(min(stod(first),stod(second)));
        else {
            if (first[0]>='0' && first[0]<='9'){
                if (constants[second]==""){
                    output="Error - uninitialized variable!\n";
                    std::cerr << "Error - uninitialized variable!\n" << endl;
                    //cout<<"Error!\n";
                    exit(1);
                }
                else constants[name] = to_string(min(stod(first),stod(constants[second])));
            }
            else if (second[0]>='0' && second[0]<='9'){
                if (constants[first]==""){
                    output="Error - uninitialized variable!\n";
                    std::cerr << "Error - uninitialized variable!\n" << endl;
                    //cout<<"Error!\n";
                    exit(1);
                }
                else constants[name] = to_string(min(stod(constants[first]),stod(second)));
            }
            else {
                if (constants[first]=="" || constants[second]==""){
                    output="Error - uninitialized variable!\n";
                    std::cerr << "Error - uninitialized variable!\n" << endl;
                    //cout<<"Error!\n";
                    exit(1);
                }
                else constants[name] = to_string(min(stod(constants[first]),stod(constants[second])));
                
            }
        }
    }
    else output="Error - no such operation!\n";//cout<<"Error - no such operation!\n";
    //cout<<name<<" "<<constants[name]<<endl;
    output+=name+" "+constants[name]+"\n";
}

void outValues(const YAML::Node& values){
    for (auto c:values){
        cnt++;
        string name = c.first.as<string>();
        string val = c.second.as<string>();

        if (val.find("![")==0 && val.find("]")==val.size()-1)
             calculate(name,val);
        else {
            constants[name]=val;
            output+=name+" : "+val+"; ";
            //cout << name << " : " << val << "; ";
        }

        if (cnt+1==comments[tek].first && comments[tek].pos==0){
            //cout<<"\n";
            output+="\n";
            outComments();
        }
        else if (cnt==comments[tek].first && comments[tek].pos!=0)
            outComments();           
        //cout<<"\n";
        output+="\n";
    }
}

void outValuesInMap(const YAML::Node& values){
    for (auto c:values){
        cnt++;
        string name = c.first.as<string>();
        string val = c.second.as<string>();

        if (val.find("![")==0 && val.find("]")==val.size()-1)
             calculate(name,val);
        else {
            constants[name]=val;
            output+=name+" : "+val+"; ";
            //cout << name << " : " << val << "; ";
        }
        
        if (cnt+1==comments[tek].first && comments[tek].pos==0){
            //cout<<"\n";
            output+="\n";
            outComments();
        }
        else if (cnt==comments[tek].first && comments[tek].pos!=0)
            outComments();           
        //cout<<"\n";
        output+="\n";
    }
}
void outDictionaries(const YAML::Node& values){
    for (auto dict:values){
        string name = dict.first.as<std::string>();
        cnt++;
        //cout << name << ": \n{\n";
        output+=name+": \n{\n";
        if (cnt+1==comments[tek].first && comments[tek].pos==0){
            //cout<<"\n";
            output+="\n";
            outComments();
        }
        else if (cnt==comments[tek].first && comments[tek].pos!=0)
            outComments();  
        const YAML::Node& dictionary = dict.second;
        outValuesInMap(dictionary);
        //cout << "};\n";
        output+="};\n";
    }
}

void parseFile(const YAML::Node& node){
    for (const auto& item : node) {
        std::string key = item.first.as<std::string>();
        cnt++;
        const YAML::Node& value = item.second;
        if (key=="constants"){
            
            if (cnt+1==comments[tek].first && comments[tek].pos==0){
                //cout<<"\n";
                output+="\n";
                outComments();
            }
            else if (cnt==comments[tek].first && comments[tek].pos!=0)
                outComments();
            
            outValues(value);
        }
        else if (key=="dictionaries"){
            //cout<<key<<" "<<cnt<<endl;
            if (cnt+1==comments[tek].first && comments[tek].pos==0){
                //cout<<"\n";
                output+="\n";
                outComments();
            }
            else if (cnt==comments[tek].first && comments[tek].pos!=0)
                outComments();
            outDictionaries(value);
        }
        /*
        else if (key=="calculations"){
            //cout<<key<<" " <<cnt<<endl;
            if (cnt+1==comments[tek].first && comments[tek].pos==0){
                output+="\n";
                //cout<<"\n";

                outComments();
            }
            else if (cnt==comments[tek].first && comments[tek].pos!=0)
                outComments();

            for (const auto& calc : value){
                std::string expression = calc.as<std::string>();
                std::cout << "Expression: " << expression << "\n";
                cnt++;
            }
        }
        */
    }   
}

vector<tek_comment> count_comments(string name_of_file){
    int count_real = 0;
    vector<tek_comment> comm;
    ifstream fin(yaml_path+name_of_file);
    string tek="";
    while (getline(fin,tek))
        if (tek.size()>0){  
            while (tek[0]==' ')
                tek = tek.substr(1,tek.size()-1);  
            if (tek.find('#')==string::npos || tek.find('#')>0)
                count_real++;

            if (tek.find('#')!=string::npos){
                int count = count_real;
                if (tek.find('#')==0 && count_real>0 && comm.size()>0 && comm[comm.size()-1].pos==0) //&& comm[comm.size()-1].first!=count_real)
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

#ifndef UNIT_TEST
int main(int argc, char* argv[]){
    yaml_path = argv[1];
    comments = count_comments("example3.yaml");
    YAML::Node config = YAML::LoadFile(yaml_path+"example3.yaml");
    if (comments[0].first==0)
        outComments();
    parseFile(config);
    cout<<output;
   return 0;
}
#endif