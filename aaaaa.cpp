#include <iostream>
#include <fstream>
using namespace std;


int main()
{
    ifstream iFile;
    string line = "", first = "";
    int location = 0;

    iFile.open("201402.csv");
    getline(iFile, line);
    // getline(iFile, line);
    while (getline(iFile, line))
    {
        location = line.find(',');
        first = line.substr(0, location);
        line = line.substr(location + 1, line.length());

        // cout << first << endl;
        // <<"line"<<line  <<endl;

        cout << line << endl;
    }
    return 0;
}