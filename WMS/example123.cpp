#include "gm.h"

class nhfind
{
public:
    string filename[12] = {"NH_201401.csv", "NH_201402.csv", "NH_201403.csv", "NH_201404.csv", "NH_201405.csv", "NH_201406.csv", "NH_201407.csv", "NH_201408.csv", "NH_201409.csv", "NH_201410.csv", "NH_201411.csv", "NH_201412.csv"};
    ifstream in;
    string buffer;
    vector<string> result;
    map<int, int> utop;         // 고유번호 가격
    multimap<string, int> dtou; // 물건이름 고유번호
    multimap<string, int> mtou; // 시장이름 고유번호
    multimap<string, int> rtou; // 지역이름 고유번호
    map<int, string> utom;      // 고유번호 시장번호
    map<int, string> utod;      // 고유번호 물건이름
    map<int, string> utor;      // 고유번호 지역이름
    int a;
    int price;
    int b = INT32_MAX;
    // int average = 0;
    string item;
    string market;
    string region;
    int c = 0;
    int icount = 11;
    multimap<string, int>::iterator iter;
    map<int, string>::iterator ater;
    string cc;
    string ck;
    string xx;
    string vv;
    void item_max()
    {
        cout << "아이템 입력";
        cin >> item;
        int cnt = 0;

        for (int i = 0; i < 12; i++)
        {
            in.open(filename[i], ios_base::in);

            while (getline(in, buffer))
            {
                result = split(buffer, ',');
                a = stoi(result[0]);
                price = stoi(result[15]);
                utop.insert(pair<int, int>(a, price));
                dtou.insert(pair<string, int>(result[6], a));
                mtou.insert(pair<string, int>(result[4], a));
                rtou.insert(pair<string, int>(result[2], a));
                utom.insert(pair<int, string>(a, result[4]));
                utod.insert(pair<int, string>(a, result[6]));
                utor.insert(pair<int, string>(a, result[2]));
            }

            in.close();
            cout << icount-- << endl;
        }
        for (iter = dtou.lower_bound(item); iter != dtou.upper_bound(item); ++iter)
        {
            if (c < utop[iter->second])
            {
                c = utop[iter->second];
                xx = utor[iter->second];
                vv = utom[iter->second];
            }

            if (b > utop[iter->second])
            {
                b = utop[iter->second];
                cc = utor[iter->second];
                ck = utom[iter->second];
            }
        }
        --iter;

        cout << xx << " " << xx << " " << iter->first << " 가장 비싼 가격: " << c << endl;
    }
    void item_min()
    {
        cout << "아이템 입력";
        cin >> item;
        int cnt = 0;

        int average = 0;
        for (int i = 0; i < 12; i++)
        {
            in.open(filename[i], ios_base::in);

            while (getline(in, buffer))
            {
                result = split(buffer, ',');
                a = stoi(result[0]);
                price = stoi(result[15]);
                utop.insert(pair<int, int>(a, price));
                dtou.insert(pair<string, int>(result[6], a));
                mtou.insert(pair<string, int>(result[4], a));
                rtou.insert(pair<string, int>(result[2], a));
                utom.insert(pair<int, string>(a, result[4]));
                utod.insert(pair<int, string>(a, result[6]));
                utor.insert(pair<int, string>(a, result[2]));
            }

            in.close();
            cout << icount-- << endl;
        }
        for (iter = dtou.lower_bound(item); iter != dtou.upper_bound(item); ++iter)
        {
            if (c < utop[iter->second])
            {
                c = utop[iter->second];
                xx = utor[iter->second];
                vv = utom[iter->second];
            }

            if (b > utop[iter->second])
            {
                b = utop[iter->second];
                cc = utor[iter->second];
                ck = utom[iter->second];
            }
        }
        --iter;

        cout << cc << " " << ck << " " << iter->first << "가장싼 가격: " << b << endl;
    }
    void item_average()
    {
        cout << "아이템 입력";

        int average = 0;
        cin >> item;
        int cnt = 0;

        for (int i = 0; i < 12; i++)
        {
            in.open(filename[i], ios_base::in);

            while (getline(in, buffer))
            {
                result = split(buffer, ',');
                a = stoi(result[0]);
                price = stoi(result[15]);
                utop.insert(pair<int, int>(a, price));
                dtou.insert(pair<string, int>(result[6], a));
                mtou.insert(pair<string, int>(result[4], a));
                rtou.insert(pair<string, int>(result[2], a));
                utom.insert(pair<int, string>(a, result[4]));
                utod.insert(pair<int, string>(a, result[6]));
                utor.insert(pair<int, string>(a, result[2]));
            }

            in.close();
            cout << icount-- << endl;
        }

        for (iter = dtou.lower_bound(item); iter != dtou.upper_bound(item); ++iter) // 고구마가 시작된느 부분 /끝나는 부분
        {
            average += utop[iter->second];
            cnt++;
        }
        cout << average << endl;
        cout << cnt << endl;
        average = average / cnt;
        --iter;
        cout << cc << " " << ck << " " << iter->first << " "
             << "평균 가격" << average << endl;
        ;
    }
    void market_item()
    {
        cout << "아이템 입력";
        cin >> item;
        int cnt = 0;

        int average = 0;
        cout << "시장 입력";
        cin >> market;
        for (int i = 0; i < 12; i++)
        {
            in.open(filename[i], ios_base::in);

            while (getline(in, buffer))
            {
                result = split(buffer, ',');
                a = stoi(result[0]);
                price = stoi(result[15]);
                utop.insert(pair<int, int>(a, price));
                dtou.insert(pair<string, int>(result[6], a));
                mtou.insert(pair<string, int>(result[4], a));
                rtou.insert(pair<string, int>(result[2], a));
                utom.insert(pair<int, string>(a, result[4]));
                utod.insert(pair<int, string>(a, result[6]));
                utor.insert(pair<int, string>(a, result[2]));
            }

            in.close();
            cout << icount-- << endl;
        }
        for (iter = mtou.lower_bound(market); iter != mtou.upper_bound(market); ++iter)
        {
            if (utod[iter->second].compare(item) == 0)
            {
                average += utop[iter->second];
                cnt++;
            }
        }
        average = average / cnt;
        --iter;
        cout << iter->first << " "
             << "평균 가격" << average << endl;
    }
    void market_item_max()
    {
        cout << "아이템 입력";
        cin >> item;
        int cnt = 0;

        int average = 0;
        cout << "시장 입력";
        cin >> market;
        for (int i = 0; i < 12; i++)
        {
            in.open(filename[i], ios_base::in);

            while (getline(in, buffer))
            {
                result = split(buffer, ',');
                a = stoi(result[0]);
                price = stoi(result[15]);
                utop.insert(pair<int, int>(a, price));
                dtou.insert(pair<string, int>(result[6], a));
                mtou.insert(pair<string, int>(result[4], a));
                rtou.insert(pair<string, int>(result[2], a));
                utom.insert(pair<int, string>(a, result[4]));
                utod.insert(pair<int, string>(a, result[6]));
                utor.insert(pair<int, string>(a, result[2]));
            }

            in.close();
            cout << icount-- << endl;
        }
        for (iter = mtou.lower_bound(market); iter != mtou.upper_bound(market); ++iter)
        {
            if (utod[iter->second].compare(item) == 0)
            {
                if (c < utop[iter->second])
                {
                    c = utop[iter->second];
                    xx = utor[iter->second];
                    vv = utom[iter->second];
                }
            }
        }
        average = average / cnt;
        --iter;
        cout << cc << iter->first << " "
             << "최대 가격" << c << endl;
    }
    void market_item_min()
    {
        cout << "아이템 입력";
        cin >> item;
        int cnt = 0;

        int average = 0;
        cout << "시장 입력";
        cin >> market;
        for (int i = 0; i < 12; i++)
        {
            in.open(filename[i], ios_base::in);

            while (getline(in, buffer))
            {
                result = split(buffer, ',');
                a = stoi(result[0]);
                price = stoi(result[15]);
                utop.insert(pair<int, int>(a, price));
                dtou.insert(pair<string, int>(result[6], a));
                mtou.insert(pair<string, int>(result[4], a));
                rtou.insert(pair<string, int>(result[2], a));
                utom.insert(pair<int, string>(a, result[4]));
                utod.insert(pair<int, string>(a, result[6]));
                utor.insert(pair<int, string>(a, result[2]));
            }

            in.close();
            cout << icount-- << endl;
        }
        for (iter = mtou.lower_bound(market); iter != mtou.upper_bound(market); ++iter)
        {
            if (utod[iter->second].compare(item) == 0)
            {
                if (b > utop[iter->second])
                {
                    b = utop[iter->second];
                    cc = utor[iter->second];
                    ck = utom[iter->second];
                }
            }
        }
        average = average / cnt;
        --iter;
        cout << cc << " " << ck << " " << iter->first << "가장싼 가격: " << b << endl;
    }
    void region_market_item_min()
    {
        cout << "아이템 입력";
        int average = 0;
        cin >> item;
        int cnt = 0;

        cout << "시장 입력";
        cin >> market;
        cout << "지역 입력";
        cin >> region;
        for (int i = 0; i < 12; i++)
        {
            in.open(filename[i], ios_base::in);

            while (getline(in, buffer))
            {
                result = split(buffer, ',');
                a = stoi(result[0]);
                price = stoi(result[15]);
                utop.insert(pair<int, int>(a, price));
                dtou.insert(pair<string, int>(result[6], a));
                mtou.insert(pair<string, int>(result[4], a));
                rtou.insert(pair<string, int>(result[2], a));
                utom.insert(pair<int, string>(a, result[4]));
                utod.insert(pair<int, string>(a, result[6]));
                utor.insert(pair<int, string>(a, result[2]));
            }

            in.close();
            cout << icount-- << endl;
        }
        for (iter = mtou.lower_bound(market); iter != mtou.upper_bound(market); ++iter)
        {
            if (utod[iter->second].compare(item) == 0)
            {
                if (utor[iter->second].compare(region) == 0)
                {
                    if (b > utop[iter->second])
                    {
                        b = utop[iter->second];
                        cc = utor[iter->second];
                        ck = utom[iter->second];
                    }
                }
            }
        }
        average = average / cnt;
        --iter;
        cout << cc << " " << ck << " " << iter->first << "가장싼 가격: " << b << endl;
    }
    void region_market_item_max()
    {
        int average = 0;
        cout << "아이템 입력";
        cin >> item;
        int cnt = 0;

        cout << "시장 입력";
        cin >> market;
        cout << "지역 입력";
        cin >> region;
        for (int i = 0; i < 12; i++)
        {
            in.open(filename[i], ios_base::in);

            while (getline(in, buffer))
            {
                result = split(buffer, ',');
                a = stoi(result[0]);
                price = stoi(result[15]);
                utop.insert(pair<int, int>(a, price));
                dtou.insert(pair<string, int>(result[6], a));
                mtou.insert(pair<string, int>(result[4], a));
                rtou.insert(pair<string, int>(result[2], a));
                utom.insert(pair<int, string>(a, result[4]));
                utod.insert(pair<int, string>(a, result[6]));
                utor.insert(pair<int, string>(a, result[2]));
            }
            in.close();
            cout << icount-- << endl;
        }
        for (iter = mtou.lower_bound(market); iter != mtou.upper_bound(market); ++iter)
        {
            if (utod[iter->second].compare(item) == 0)
            {
                if (utor[iter->second].compare(region) == 0)
                {
                    if (c < utop[iter->second])
                    {
                        c = utop[iter->second];
                        xx = utor[iter->second];
                        vv = utom[iter->second];
                    }
                }
            }
        }

        average = average / cnt;
        --iter;
        cout << xx << " " << xx << " " << iter->first << " 가장 비싼 가격: " << c << endl;
    }
    void region_market_item_average()
    {
        cout << "아이템 입력";
        int average = 0;
        cin >> item;
        int cnt = 0;

        cout << "시장 입력";
        cin >> market;
        cout << "지역 입력";
        cin >> region;
        for (int i = 0; i < 12; i++)
        {
            in.open(filename[i], ios_base::in);

            while (getline(in, buffer))
            {
                result = split(buffer, ',');
                a = stoi(result[0]);
                price = stoi(result[15]);
                utop.insert(pair<int, int>(a, price));
                dtou.insert(pair<string, int>(result[6], a));
                mtou.insert(pair<string, int>(result[4], a));
                rtou.insert(pair<string, int>(result[2], a));
                utom.insert(pair<int, string>(a, result[4]));
                utod.insert(pair<int, string>(a, result[6]));
                utor.insert(pair<int, string>(a, result[2]));
            }

            in.close();
            cout << icount-- << endl;
        }
        for (iter = mtou.lower_bound(market); iter != mtou.upper_bound(market); ++iter)
        {

            if (utod[iter->second].compare(item) == 0)
            {
                if (utor[iter->second].compare(region) == 0)
                {
                    average += utop[iter->second];
                    cnt++;
                }
            }
        }
        average = average / cnt;
        --iter;
        cout << region << " " << market << " " << item
             << "평균 가격: " << average << endl;
    }
};
class pricefind
{
public:
    void mamp()
    {
        joinmap a;
        multimap<int, int>::iterator iter;
        multimap<string, int>::iterator ater;
        multimap<string, int>::iterator bter;
        multimap<string, int>::iterator cter;
        int months;
        string area;
        string market;
        string prod;
        cout << "찾을 데이터 월을 입력해주세요: ";
        cin >> months;
        cout << "찾을 데이터 지역을 입력해주세요: ";
        cin >> area;
        cout << "찾을 시장을 입력해주세요: ";
        cin >> market;
        cout << "찾을 품목을 입력해주세요: ";
        cin >> prod;
        for (iter = a.monthtou.lower_bound(months); iter != a.monthtou.upper_bound(months); ++iter)
        {
            cout << "월: " << iter->first << " 지역: " << a.utor[iter->second] << " 시장이름: " << a.utom[iter->second]
                 << " 물품이름: " << a.utod[iter->second] << "가격: " << a.utop[iter->second] << endl
                 << endl;
        }
        for (ater = a.rtou.lower_bound(area); ater != a.rtou.upper_bound(area); ++ater)
        {
            cout << "월: " << a.utomonth[ater->second] << " 지역이름: " << a.utor[ater->second] << " 시장이름 : "
                 << a.utom[ater->second] << " 품목: " << ater->first << " 가격: " << a.utop[ater->second] << endl
                 << endl;
        }
        for (bter = a.mtou.lower_bound(market); bter != a.mtou.upper_bound(market); ++bter)
        {
            cout << "월: " << a.utomonth[bter->second] << " 지역이름: " << a.utor[bter->second] << " 시장이름 : "
                 << a.utom[bter->second] << " 품목: " << a.utod[bter->second] << " 가격: " << a.utop[bter->second] << endl
                 << endl;
        }
        for (cter = a.dtou.lower_bound(prod); cter != a.dtou.upper_bound(prod); ++cter)
        {
            cout << "월: " << a.utomonth[cter->second] << " 지역이름: " << a.utor[cter->second] << " 시장이름 : "
                 << a.utom[cter->second] << " 품목: " << a.utod[cter->second] << " 가격: " << a.utop[cter->second] << endl
                 << endl;
        }
    }
};
class SH
{
public:
    void addread()
    {
        ifstream file;       ////읽을 파일
        ofstream addfile;    ////추가할 새 파일
        string buffer = ","; ////입력 저장
        string name;         //////파일이름 입력
        cout << "열 파일 이름을 입력하세요: ";
        cin >> name;
        file.open(name, ios_base::out); /////추가할 데이터 ex) 202201 데이터
        getline(file, buffer);
        string addfilename; //////새 파일 이름
        cout << "추가할 파일 이름을 입력하세요: ";
        cin >> addfilename;
        int lll = file.tellg();
        addfile.open(addfilename, ios::app); /////데이터를 받을 파일(이름 새로 입력) 혹은 기존파일에 받던가
        while (getline(file, buffer))
        {
            addfile << "+" << buffer << endl; /// 추가됐는지 확인 후 출력임
        }
        file.close();
        addfile.close();
    }
    void re()
    {
        cout << "수정할 파일을 입력하세요: ";
        string filename;
        cin >> filename;
        ifstream in(filename, ios_base::in);
        cout << "저장할 파일을 입력하세요: ";
        string refilename;
        cin >> refilename;
        string s;
        in.seekg(0, ios::end); // 위치 지정자를 파일 끝으로 옮긴다.
        int size = in.tellg(); // 그리고 그 위치를 읽는다. (파일의 크기)
        s.resize(size);        // 그 크기의 문자열을 할당한다.
        in.seekg(0, ios::beg); // 위치 지정자를 다시 파일 맨 앞으로 옮긴다.
        in.read(&s[0], size);  // 파일 전체 내용을 읽어서 문자열에 저장한다.
        in.close();
        in.open(filename, ios_base::in);
        string buffer;
        getline(in, buffer);
        getline(in, buffer);
        string a;
        string b;
        cout << "수정할 부분의 텍스트를 입력:";
        cin >> a;
        cout << "수정할 내용을 입력: ";
        cin >> b;
        s.replace(s.find(a), buffer.length(), b); /////괄호안에 텍스트 입력

        ofstream of;
        in.close();
        of.open(refilename, ios_base::out);
        of << s;
    }
};

int main(void)
{
    pricefind jy;
    jy.mamp();
    nhfind gun;
    gun.region_market_item_average();
    SH sh;
    sh.addread();
    sh.re();

    return 0;
}