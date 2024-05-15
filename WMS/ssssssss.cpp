#include "joinmap.h"
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
    cout << "지역 입력 플리즈";
    cin >> reigonnamae;
    cout << "시장 입력 플리즈";
    cin >> marketnamae;
    cout << "상품 입력 플리즈";
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
int main()
{
    sh();
}