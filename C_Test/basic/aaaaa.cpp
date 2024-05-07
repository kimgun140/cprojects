#include <iostream>
#include <fstream>

using namespace std;
int main()
{
    ifstream iFile;
    string line = "", first = "";
    int location = 0;

    iFile.open("birhtyears.csv");
    getline(iFile, line);
    getline(iFile, line);

    location = line.find(',');
    first = line.substr(0,location);
    cout << first << endl;
    return 0;
}