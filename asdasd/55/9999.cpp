#include <iostream>
#include <mariadb/conncpp.hpp>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <time.h>
int main()
{
    std::string line = "asdf,1234";
    std::stringstream input(line);
    std::string id;
    std::string pw;
    getline(input, id, ',');
    getline(input, pw, ',');
    std::cout << id << std::endl;
    std::cout << pw << std::endl;
}