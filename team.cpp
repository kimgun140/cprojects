#include "joinmap.h"

class nhfind
{

public:
    void nhifnd()
    {
    }

    vector<string> item_max()
    {
        string buffer;
        ifstream ii;
        vector<string> sh;
        int max = 0;
        string namae = "";
        cout << "입력 플리즈" << endl;
        cin >> namae;
        string qqqq;
        vector<string> csvfile =
            {"NH_201401.csv", "NH_201402.csv", "NH_201403.csv",
             "NH_201404.csv", "NH_201405.csv", "NH_201406.csv",
             "NH_201407.csv", "NH_201408.csv", "NH_201409.csv",
             "NH_201410.csv", "NH_201411.csv", "NH_201412.csv"};

        for (int i = 1; i < 13; i++)
        { // 농수산물의 최대값 구하기 벡터로 할거임 벡터 배열에 각각 파일 이름 넣어 주면 되겠다.

            ii.open(csvfile[i], ios_base::in); // 파일 전체 다읽기

            while (getline(ii, buffer)) // 한 줄씩 읽기
            {
                vector<string> result = split(buffer, ',');
                vector<string>::iterator it = result.begin();
                joinmap cccc;

                string k = to_string(cccc.joinproduct(namae));

                if (result[6] == k)
                {
                    for (it; it != result.end(); ++it)
                    {
                        if (max < stoi(result[14]))
                        {
                            max = stoi(result[14]);
                            sh = {csvfile[i], buffer};
                        }
                    }
                }
            }
            ii.close();
        }
        cout << namae << "의 최고 가격은" << max << endl;
        cout << sh[0] << endl
             << sh[1] << endl;
        return sh;
    }
    vector<string> item_average()
    {
        string buffer;
        ifstream ii;
        vector<string> sh;

        int max = 0;
        int min = 0;
        int average = 0;
        int cnt = 0;
        string namae = "";
        cout << "입력 플리즈" << endl;
        cin >> namae;
        string qqqq;
        vector<string> csvfile =
            {"NH_201401.csv", "NH_201402.csv", "NH_201403.csv",
             "NH_201404.csv", "NH_201405.csv", "NH_201406.csv",
             "NH_201407.csv", "NH_201408.csv", "NH_201409.csv",
             "NH_201410.csv", "NH_201411.csv", "NH_201412.csv"};

        for (int i = 1; i < 13; i++)
        { // 농수산물의 최대값 구하기 벡터로 할거임 벡터 배열에 각각 파일 이름 넣어 주면 되겠다.

            ii.open(csvfile[i], ios_base::in); // 파일 전체 다읽기

            while (getline(ii, buffer)) // 한 줄씩 읽기
            {
                vector<string> result = split(buffer, ',');
                vector<string>::iterator it = result.begin();
                joinmap cccc;

                string k = to_string(cccc.joinproduct(namae));

                if (cccc.joinproduct(namae) != 1 && result[6] == k)
                {
                    for (it; it != result.end(); ++it)
                    {
                        average += stoi(result[14]);
                        cnt++;
                        sh = {csvfile[i], buffer};
                    }
                }
            }
            ii.close();
        }
        average = average / cnt;
        cout << namae << "의 평균 가격은" << average << endl;
        cout << sh[0] << endl
             << sh[1] << endl;
        return sh;
    }
    vector<string> item_min()
    {
        string buffer;
        ifstream ii;
        vector<string> sh;

        int max = 0;
        int min = INT32_MAX;
        int min1 = 0;
        int average = 0;
        int cnt = 0;
        string namae = "";
        cout << "입력 플리즈" << endl;
        cin >> namae;
        vector<string> csvfile =
            {"NH_201401.csv", "NH_201402.csv", "NH_201403.csv",
             "NH_201404.csv", "NH_201405.csv", "NH_201406.csv",
             "NH_201407.csv", "NH_201408.csv", "NH_201409.csv",
             "NH_201410.csv", "NH_201411.csv", "NH_201412.csv"};

        for (int i = 1; i < 13; i++)
        { // 농수산물의 최대값 구하기 벡터로 할거임 벡터 배열에 각각 파일 이름 넣어 주면 되겠다.

            ii.open(csvfile[i], ios_base::in); // 파일 전체 다읽기

            while (getline(ii, buffer)) // 한 줄씩 읽기
            {
                vector<string> result = split(buffer, ',');
                vector<string>::iterator it = result.begin();
                joinmap cccc;

                string k = to_string(cccc.joinproduct(namae));

                if (result[6] == k)
                {
                    min1 = stoi(result[14]);
                    for (it; it != result.end(); ++it)
                    {
                        if (min > min1)
                        {
                            min = min1;
                            sh = {csvfile[i], buffer};
                        }
                    }
                }
            }
        }
        ii.close();

        cout << namae << "의 최소 가격은" << min << endl;
        cout << sh[0] << endl
             << sh[1] << endl;
        return sh;
    }
    vector<string> market_item_max()
    {
        string buffer;
        string rebuffer;
        ifstream ii;
        vector<string> sh;

        int max = 0;
        int min = INT32_MAX;
        int min1 = 0;
        int average = 0;
        int cnt = 0;
        string namae = "";
        string marketnamae = "";
        string reigonnamae = "";
        cout << "지역 입력 플리즈" << endl;
        cin >> reigonnamae;
        cout << "시장 입력 플리즈" << endl;
        cin >> marketnamae;
        cout << "상품 입력 플리즈" << endl;
        cin >> namae;

        string qqqq;
        vector<string> csvfile =
            {"NH_201401.csv", "NH_201402.csv", "NH_201403.csv",
             "NH_201404.csv", "NH_201405.csv", "NH_201406.csv",
             "NH_201407.csv", "NH_201408.csv", "NH_201409.csv",
             "NH_201410.csv", "NH_201411.csv", "NH_201412.csv"};

        for (int i = 1; i < 13; i++)
        { // 농수산물의 최대값 구하기 벡터로 할거임 벡터 배열에 각각 파일 이름 넣어 주면 되겠다.

            ii.open(csvfile[i], ios_base::in); // 파일 전체 다읽기

            while (getline(ii, buffer)) // 한 줄씩 읽기
            {
                vector<string> result = split(buffer, ',');
                vector<string>::iterator it = result.begin();
                joinmap cccc;

                string k = to_string(cccc.joinproduct(namae));
                string region = to_string(cccc.joinregion(reigonnamae));
                string market = to_string(cccc.joinmarket(marketnamae));

                if (to_string(cccc.joinregion(reigonnamae)) == result[2] && to_string(cccc.joinmarket(marketnamae)) == result[4] && to_string(cccc.joinproduct(namae)) == result[6])
                {
                    for (it; it != result.end(); ++it)
                    {
                        if (max < stoi(result[14]))
                        {
                            max = stoi(result[14]);
                            sh = {csvfile[i], buffer};
                        }
                    }
                }
            }
            ii.close();
        }

        cout << marketnamae << "의" << namae << "의 최대 가격은" << max << endl;
        cout << sh[0] << endl
             << sh[1] << endl;
        return sh;
    }
    vector<string> market_item_min()
    {
        string buffer;
        ifstream ii;
        vector<string> sh;
        int max = 0;
        int min = INT32_MAX;
        int min1 = 0;
        int average = 0;
        int cnt = 0;
        string namae = "";
        string marketnamae = "";
        string reigonnamae = "";
        cout << "지역 입력 플리즈" << endl;
        cin >> reigonnamae;
        cout << "시장 입력 플리즈" << endl;
        cin >> marketnamae;
        cout << "상품 입력 플리즈" << endl;
        cin >> namae;
        string qqqq;
        vector<string> csvfile =
            {"NH_201401.csv", "NH_201402.csv", "NH_201403.csv",
             "NH_201404.csv", "NH_201405.csv", "NH_201406.csv",
             "NH_201407.csv", "NH_201408.csv", "NH_201409.csv",
             "NH_201410.csv", "NH_201411.csv", "NH_201412.csv"};

        for (int i = 1; i < 13; i++)
        { // 농수산물의 최대값 구하기 벡터로 할거임 벡터 배열에 각각 파일 이름 넣어 주면 되겠다.

            ii.open(csvfile[i], ios_base::in); // 파일 전체 다읽기

            while (getline(ii, buffer)) // 한 줄씩 읽기
            {
                vector<string> result = split(buffer, ',');
                vector<string>::iterator it = result.begin();
                joinmap cccc;

                string k = to_string(cccc.joinproduct(namae));
                string market = to_string(cccc.joinmarket(marketnamae));
                string region = to_string(cccc.joinregion(reigonnamae));

                if (result[2] == region) // 지역 코드확인
                {
                    if (result[4] == market) // 시장
                    {
                        if (result[6] == k) // 상품 가격
                        {
                            min1 = stoi(result[14]);
                            for (it; it != result.end(); ++it)
                            {
                                if (min > min1)
                                {
                                    min = min1;
                                    sh = {csvfile[i], buffer};
                                }
                            }
                        }
                    }
                }
            }
            ii.close();
        }

        cout << marketnamae << "의" << namae << "의 최소 가격은" << min << endl;
        cout << sh[0] << endl
             << sh[1] << endl;
        return sh;
    }
    vector<string> market_item_average()
    {
        string buffer;
        ifstream ii;
        vector<string> sh;
        int max = 0;
        int min = INT32_MAX;
        int min1 = 0;
        int average = 0;
        int cnt = 0;
        string namae = "";       // 상품
        string marketnamae = ""; // 시장
        string reigonnamae = ""; // 지역
        cout << "지역 입력 플리즈" << endl;
        cin >> reigonnamae;
        cout << "시장 입력 플리즈" << endl;
        cin >> marketnamae;
        cout << "상품 입력 플리즈" << endl;
        cin >> namae;
        string qqqq;
        vector<string> csvfile =
            {"NH_201401.csv", "NH_201402.csv", "NH_201403.csv",
             "NH_201404.csv", "NH_201405.csv", "NH_201406.csv",
             "NH_201407.csv", "NH_201408.csv", "NH_201409.csv",
             "NH_201410.csv", "NH_201411.csv", "NH_201412.csv"};

        for (int i = 1; i < 13; i++)
        { // 농수산물의 최대값 구하기 벡터로 할거임 벡터 배열에 각각 파일 이름 넣어 주면 되겠다.

            ii.open(csvfile[i], ios_base::in); // 파일 전체 다읽기

            while (getline(ii, buffer)) // 한 줄씩 읽기
            {
                vector<string> result = split(buffer, ',');
                vector<string>::iterator it = result.begin();
                joinmap cccc;

                string k = to_string(cccc.joinproduct(namae));           // 상품
                string market = to_string(cccc.joinmarket(marketnamae)); // 시장
                string reigon = to_string(cccc.joinregion(reigonnamae)); // 지역

                if (result[2] == reigon) // 지역 코드확인
                {
                    if (result[4] == market) // 시장 코드확인
                    {
                        if (result[6] == k) // 상품 코드 확인
                        {
                            for (it; it != result.end(); ++it)
                            {
                                average += stoi(result[14]);
                                cnt++;
                                sh = {csvfile[i], buffer};
                            }
                        }
                    }
                }
            }
            ii.close();
        }

        average = average / cnt;
        cout << marketnamae << "의" << namae << "의 평균 가격은" << average << endl;

        cout << sh[0] << endl
             << sh[1] << endl;
        return sh;
    }
    vector<string> region_item_average()
    {
        string buffer;
        ifstream ii;
        vector<string> sh;
        int max = 0;
        int min = INT32_MAX;
        int min1 = 0;
        int average = 0;
        int cnt = 0;
        string namae = "";
        string reigonnamae = "";
        cout << "지역 입력 플리즈" << endl;
        cin >> reigonnamae;

        cout << "상품 입력 플리즈" << endl;
        cin >> namae;

        string qqqq;
        vector<string> csvfile =
            {"NH_201401.csv", "NH_201402.csv", "NH_201403.csv",
             "NH_201404.csv", "NH_201405.csv", "NH_201406.csv",
             "NH_201407.csv", "NH_201408.csv", "NH_201409.csv",
             "NH_201410.csv", "NH_201411.csv", "NH_201412.csv"};

        for (int i = 1; i < 13; i++)
        { // 농수산물의 최대값 구하기 벡터로 할거임 벡터 배열에 각각 파일 이름 넣어 주면 되겠다.

            ii.open(csvfile[i], ios_base::in); // 파일 전체 다읽기

            while (getline(ii, buffer)) // 한 줄씩 읽기
            {
                vector<string> result = split(buffer, ',');
                vector<string>::iterator it = result.begin();
                joinmap cccc;

                string k = to_string(cccc.joinproduct(namae));
                string market = to_string(cccc.joinregion(reigonnamae));
                if (result[2] == market) // 지역
                {
                    if (result[6] == k) // 상품 최대 가격
                    {
                        for (it; it != result.end(); ++it)
                        {
                            average += stoi(result[14]);
                            cnt++;
                            sh = {csvfile[i], buffer};
                        }
                    }
                }
            }
            ii.close();
        }

        average = average / cnt;
        cout << reigonnamae << "의" << namae << "의 평균 가격은" << average << endl;
        cout << sh[0] << endl
             << sh[1] << endl;
        return sh;
    }
    vector<string> region_item_max()
    {
        string buffer;
        ifstream ii;
        vector<string> sh;
        int max = 0;
        int min = INT32_MAX;
        int min1 = 0;
        int average = 0;
        int cnt = 0;
        string namae = "";
        string reigonnamae = "";
        cout << "지역 입력 플리즈" << endl;
        cin >> reigonnamae;

        cout << "상품 입력 플리즈" << endl;
        cin >> namae;

        string qqqq;
        vector<string> csvfile =
            {"NH_201401.csv", "NH_201402.csv", "NH_201403.csv",
             "NH_201404.csv", "NH_201405.csv", "NH_201406.csv",
             "NH_201407.csv", "NH_201408.csv", "NH_201409.csv",
             "NH_201410.csv", "NH_201411.csv", "NH_201412.csv"};

        for (int i = 1; i < 13; i++)
        { // 농수산물의 최대값 구하기 벡터로 할거임 벡터 배열에 각각 파일 이름 넣어 주면 되겠다.

            ii.open(csvfile[i], ios_base::in); // 파일 전체 다읽기

            while (getline(ii, buffer)) // 한 줄씩 읽기
            {
                vector<string> result = split(buffer, ',');
                vector<string>::iterator it = result.begin();
                joinmap cccc;

                string k = to_string(cccc.joinproduct(namae));
                string market = to_string(cccc.joinregion(reigonnamae));
                if (cccc.joinregion(reigonnamae) != 1 && result[2] == market) // 지역
                {
                    if (cccc.joinproduct(namae) != 1 && result[6] == k) // 상품 최대 가격
                    {
                        for (it; it != result.end(); ++it)
                        {
                            if (max < stoi(result[14]))
                            {

                                max = stoi(result[14]);
                                sh = {csvfile[i], buffer};
                            }
                        }
                    }
                }
            }
            ii.close();
        }

        cout << reigonnamae << "의" << namae << "의 최대 가격은" << max << endl;
        // cout << namae << "의 최소 가격은" << min << endl;
        cout << sh[0] << endl
             << sh[1] << endl;
        return sh;
    }
    vector<string> region_item_min()
    {
        string buffer;
        ifstream ii;
        vector<string> sh;
        int max = 0;
        int min = INT32_MAX;
        int min1 = 0;
        int average = 0;
        int cnt = 0;
        string namae = "";
        string reigonnamae = "";
        cout << "지역 입력 플리즈" << endl;
        cin >> reigonnamae;

        cout << "상품 입력 플리즈" << endl;
        cin >> namae;

        string qqqq;
        vector<string> csvfile =
            {"NH_201401.csv", "NH_201402.csv", "NH_201403.csv",
             "NH_201404.csv", "NH_201405.csv", "NH_201406.csv",
             "NH_201407.csv", "NH_201408.csv", "NH_201409.csv",
             "NH_201410.csv", "NH_201411.csv", "NH_201412.csv"};

        for (int i = 1; i < 13; i++)
        { // 농수산물의 최대값 구하기 벡터로 할거임 벡터 배열에 각각 파일 이름 넣어 주면 되겠다.

            ii.open(csvfile[i], ios_base::in); // 파일 전체 다읽기

            while (getline(ii, buffer)) // 한 줄씩 읽기
            {
                vector<string> result = split(buffer, ',');
                vector<string>::iterator it = result.begin();
                joinmap cccc;

                string k = to_string(cccc.joinproduct(namae));
                string market = to_string(cccc.joinregion(reigonnamae));
                if (result[2] == market) // 지역
                {
                    if (result[6] == k) // 상품 최대 가격
                    {
                        min1 = stoi(result[14]);
                        for (it; it != result.end(); ++it)
                        {
                            if (min > min1)
                            {
                                min = min1;
                                sh = {csvfile[i], buffer};
                            }
                        }
                    }
                }
            }
            ii.close();
        }

        cout << reigonnamae << "의" << namae << "의 최소 가격은" << min << endl;
        cout << sh[0] << endl
             << sh[1] << endl;
        return sh;
    }
    vector<string> sh()
    {
        string buffer;
        string rebuffer;
        ifstream ii;
        vector<string> sh;
        int max = 0;
        int min = INT32_MAX;
        int min1 = 0;
        int average = 0;
        int cnt = 0;
        string namae = "";
        string marketnamae = "";
        string reigonnamae = "";
        cout << "지역 입력 플리즈" << endl;
        cin >> reigonnamae;
        cout << "시장 입력 플리즈" << endl;
        cin >> marketnamae;
        cout << "상품 입력 플리즈" << endl;
        cin >> namae;

        vector<string> csvfile =
            {"NH_201401.csv", "NH_201402.csv", "NH_201403.csv",
             "NH_201404.csv", "NH_201405.csv", "NH_201406.csv",
             "NH_201407.csv", "NH_201408.csv", "NH_201409.csv",
             "NH_201410.csv", "NH_201411.csv", "NH_201412.csv"};
        for (int i = 1; i < 13; i++)
        { // 농수산물의 최대값 구하기 벡터로 할거임 벡터 배열에 각각 파일 이름 넣어 주면 되겠다

            ii.open(csvfile[i], ios_base::in); // 파일 전체 다읽기

            while (getline(ii, buffer)) // 한 줄씩 읽기
            {
                vector<string> result = split(buffer, ',');
                vector<string>::iterator it = result.begin();
                joinmap cccc;

                string k = to_string(cccc.joinproduct(namae));
                string region = to_string(cccc.joinregion(reigonnamae));
                string market = to_string(cccc.joinmarket(marketnamae));

                if (to_string(cccc.joinregion(reigonnamae)) == result[2] && to_string(cccc.joinmarket(marketnamae)) == result[4] && to_string(cccc.joinproduct(namae)) == result[6])
                {
                    for (it; it != result.end(); ++it)
                    {
                        if (max < stoi(result[14]))
                        {
                            max = stoi(result[14]);
                            sh = {csvfile[i], buffer};
                        }
                    }
                }
            }
            ii.close();
        }

        cout << marketnamae << "의" << namae << "의 최대 가격은" << max << endl;
        cout << sh[0] << endl
             << sh[1] << endl;
        return sh;
    }
};
