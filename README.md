# Репозиторий с 3 заданием по конфигурационному управлению
Перед загрузкой репозитория необходимо установить **cmake** https://cmake.org/download/
## Загрузка репозитория на компьютер
1. Откройте терминал
2. Перейдите в папку, где вы хотите разместить проект
3. Выполните команду:
```
git clone https://github.com/jack1591/yaml_to_uch.git
```
## Запуск программы
1. Перейти в папку build из папки third в терминале
```
cd third/build
```  
2. При первом запуске программы ввести следующие команды:
```
cmake -G "MinGW Makefiles" ..
cmake ..
mingw32-make
```  

## Задание
Разработать инструмент командной строки для учебного конфигурационного
языка, синтаксис которого приведен далее. Этот инструмент преобразует текст из
входного формата в выходной. Синтаксические ошибки выявляются с выдачей
сообщений.  
Входной текст на языке yaml принимается из файла, путь к которому задан
ключом командной строки. Выходной текст на учебном конфигурационном
языке попадает в стандартный вывод.  
  
**Многострочные комментарии**:  
/+  
Это многострочный  
комментарий  
+/  
  
**Словари**:  
{  
 имя = значение  
 имя = значение  
 имя = значение  
 ...  
}    
  
**Имена**:  
[a-z]+  
  
**Значения**:  
• Числа.  
• Словари.
  
Объявление константы на этапе трансляции:  
имя: значение;  
  
Вычисление константного выражения на этапе трансляции (инфиксная  
форма), пример:  
![имя + 1]  
  
Результатом вычисления константного выражения является значение.  
Для константных вычислений определены **операции и функции**:  
1. Сложение.  
2. Вычитание.  
3. min().
  
Все конструкции учебного конфигурационного языка (с учетом их  
возможной вложенности) должны быть покрыты тестами. Необходимо показать 3  
примера описания конфигураций из разных предметных областей.  

## Функции программы
### calculate
Функция вычисления константных выражений на этапе трансляции (сложение, вычитание, min)

### outComments
Функция вывода текущего комментария (если несколько комментариев идут подряд - в выводе будет один многострочный комментарий)

### outValues
Функция вывода текущих констант (во входном файле они инициализируются после ключевого слова constants)

### outValuesInMap
Функция вывода полей текущего словаря (написание на выходе отличается от написания констант)

### outDictionaries
Функция вывода содержимого словаря - выводит имя словаря и вызывается функцию outValuesInMap

### parseFile
Функция парсинга исходного yaml-файла

### count_comments
Функция подсчёта комментариев и их позиций в исходном файле

### main
Передается ключ - путь до yaml файла, файл открывается и вызывается функция parseFile

## Запуск .exe файлов
Запуск .exe файла программы:
```
./third.exe ./
```

Запуск .exe файла с тестами:
```
./tests.exe
```

## Примеры описания конфигураций
### Первый пример
Содержимое исходного файла  
![example11](https://github.com/user-attachments/assets/fe6e0118-d801-4bc8-8d66-59b2a5bc2a4a)  
  
Результат  
![example12](https://github.com/user-attachments/assets/47ad8842-ee0f-4a9c-a6d4-b7d80496ac1e)  

### Второй пример
Содержимое исходного файла  
![example21](https://github.com/user-attachments/assets/12c422d9-31bc-4c0f-8042-29646d135f02)  
  
Результат  
![example22](https://github.com/user-attachments/assets/c91980a2-7d80-44c8-b10e-fa1015e8461d)  

### Третий пример
Содержимое исходного файла  
![example31](https://github.com/user-attachments/assets/3bde23eb-afef-4aa8-b933-389827d84df7)  
  
Результат  
![example32](https://github.com/user-attachments/assets/96b01bbd-d457-4744-8554-77ec912a2e46)    
  
## Тестирование
Список тестов:
1. **Преобразование файла config_test1.yaml - константы**
2. **Преобразование файла config_test2.yaml - константы и словари**
3. **Преобразование файла config_test3.yaml - вычисления константного выражения и переопределение переменной**

Содержимое файла test_main.cpp:
```
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
    string prov = "/+\n This is the program\n+/\nmyNumber : 100; \nmyOtherNumber : 30; \ndiscount : 15; \nip_address 123.000000\n\nmaxLimit : 100; \ndiscount : 30; \ndiscount_rate : 0.15; \nvalue 20.150000\n\n";
    EXPECT_EQ(output,prov);
}
```

Результаты тестирования
![tests](https://github.com/user-attachments/assets/f0c9a37a-ec05-4037-92d6-01fb49fbc007)
