#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<map>
using namespace std;
vector<string> split(string str, char Delimiter)
{
    istringstream iss(str); // istringstream에 str을 담는다.
    string buffer;          // 구분자를 기준으로 절삭된 문자열이 담겨지는 버퍼

    vector<string> result;

    // istringstream은 istream을 상속받으므로 getline을 사용할 수 있다.
    while (getline(iss, buffer, Delimiter))
    {
        result.push_back(buffer); // 절삭된 문자열을 vector에 저장
    }

    return result;
}

class joinmap
{
private:
    string filename[12]={"NH_201401.csv","NH_201402.csv","NH_201403.csv","NH_201404.csv"
    ,"NH_201405.csv","NH_201406.csv","NH_201407.csv","NH_201408.csv","NH_201409.csv"
    ,"NH_201410.csv","NH_201411.csv","NH_201412.csv"};
    ifstream in;
    string buffer; 
    vector<string> result;
    int a;
    int price;
    int dome;
    int calmon;
    public:
    
    multimap<string,int> dtou;//물건이름 고유번호
    multimap<string,int> mtou;//시장이름 고유번호
    multimap<string,int> rtou;//지역이름 고유번호
    multimap<int,int>monthtou;//월 고유번호
    map<int,int> utop; //고유번호 가격
    map<int,string> utom;//고유번호 시장이름
    map<int,string> utod;//고유번호 물건이름
    map<int,string> utor;//고유번호 지역이름
    map<int,int> domain;//고유번호 도,소매코드 도매는 6 나머지 소매 (도매임)
    map<int,int>utomonth;//고유번호 월
    
    
    joinmap(/* args */)
    {
        int icount=11;
        cout<<"카운트다운"<<endl;
        for (int i = 0; i < 12; i++)
        {
            in.open(filename[i],ios_base::in);   
            
            while (getline(in,buffer))
            {
                
                result=split(buffer,',');
                a=stoi(result[0]);
                price=stoi(result[15]);
                dome=stoi(result[11]);
                calmon=stoi(result[1]);
                calmon=calmon%20140000;
                calmon=calmon/100;
                utop.insert(pair<int,int>(a,price));
                dtou.insert(pair<string,int>(result[6],a));
                mtou.insert(pair<string,int>(result[4],a));
                rtou.insert(pair<string,int>(result[2],a));
                utom.insert(pair<int,string>(a,result[4]));
                utod.insert(pair<int,string>(a,result[6]));
                utor.insert(pair<int,string>(a,result[2]));
                domain.insert(pair<int,int>(a,dome));
                utomonth.insert(pair<int,int>(a,calmon));
                monthtou.insert(pair<int,int>(calmon,a));

            }

            in.close();
            cout<<icount--<<endl;
        }        
    }
    ~joinmap()
    {   
    };
    
};