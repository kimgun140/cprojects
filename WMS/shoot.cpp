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
    int average = 0;
    int cnt;
    string item;
    cout << "아이템 입력";
    cin >> item;
    string market;
    cout << "시장 입력";
    cin >> market;
    string region;
    cout << "지역 입력";
    cin >> region;
    int c = 0;
    int icount = 11;
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
    multimap<string, int>::iterator iter;
    map<int, string>::iterator ater;
    string cc;
    string ck;
    string xx;
    string vv;
    for (iter = mtou.lower_bound(market); iter != mtou.upper_bound(market); ++iter)
    {
        // cout << utod[iter->second]<< endl;
        // cout << utor[iter->second] << endl;

        // cout << utod[iter->second] << endl;
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
        // for (iter = dtou.lower_bound(item); iter != dtou.upper_bound(item); ++iter) // 고구마가 시작된느 부분 /끝나는 부분
        // {
        // if (c < utop[iter->second])
        // {
        //     c = utop[iter->second];
        //     xx = utor[iter->second];
        //     vv = utom[iter->second];
        // }

        // if (b > utop[iter->second])
        // {
        //     b = utop[iter->second];
        //     cc = utor[iter->second];
        //     ck = utom[iter->second];
        // }
        //     average += utop[iter->second];
        //     cnt++;
        // }
    }
    // cout << average << endl;
    // cout << cnt << endl;
    average = average / cnt;
    --iter;
    // cout << cc<< iter->first << " "<< "최대 가격" << c << endl;
    // cout << "최대 가격" << b << endl;
    // cout << cc << " " << ck << " " << iter->first << "가장싼 가격: " << b << endl;

    cout << xx << " " << xx << " " << iter->first << " 가장 비싼 가격: " << c << endl;
