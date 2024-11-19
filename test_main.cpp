#define UNIT_TEST // предотвращает компиляцию main() в main.cpp
#include <iostream>
#include "main.cpp"
#include <gtest/gtest.h>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

TEST(AddTest, HandlesPositiveInput_1) {
    yaml_path = "./";
    comments = count_comments("config_test1.yaml");
    YAML::Node config = YAML::LoadFile(yaml_path+"config_test1.yaml");
    if (comments[0].first==0)
        outComments();
    parseFile(config);
    string prov = "/+\n This is the programm\n+/\nmaxLimit : 100; \ntimeout : 30; \ndiscount_rate : 0.15; \nvalue 20.150000\n\n";
    EXPECT_EQ(output,prov);
}

TEST(AddTest, HandlesPositiveInput_2) {
    output="";
    yaml_path = "./";
    comments = count_comments("config_test2.yaml");
    YAML::Node config = YAML::LoadFile(yaml_path+"config_test2.yaml");
    if (comments[0].first==0)
        outComments();
    parseFile(config);
    string prov = "/+\nThis is the program\n+/\nmyNumber : 100; \nmyOtherNumber : 30; \n/+\nthis is comment number 4\nthis is comment number 5\n+/\n\ndiscount : 0.15; \nuser_info: \n{\nusername : john_doe; \nemail : john@example.com; \n};\nserver_settings: \n{\nport : abc; \nactive : false; \n};\n";
    EXPECT_EQ(output,prov);
}

TEST(AddTest, HandlesPositiveInput_3) {
    output="";
    yaml_path = "./";
    comments = count_comments("config_test3.yaml");
    YAML::Node config = YAML::LoadFile(yaml_path+"config_test3.yaml");
    if (comments[0].first==0)
        outComments();
    parseFile(config);
    string prov = "/+\n This is the program\n+/\nmyNumber : 100; \nmyOtherNumber : 30; \ndiscount : 0.15; \nip_address 123.000000\n\nmaxLimit : 100; \ntimeout : 30; \ndiscount_rate : 0.15; \nvalue 20.150000\n\n";
    EXPECT_EQ(output,prov);
}

