// // 07.2
// #include <iostream>
// void cheers(int);

// double cube(double x);

// int main(void)
// {

//     using namespace std;
//     cheers(5);
//     cout << "하나의 수를 입력하십시오: ";
//     double side;
//     cin >> side;
//     double volume = cube(side);
//     cout << "한 변의 길이가" << side << " 센티미터인 정육면체의 부피는 ";
//     cout << volume << " 세제곱 센티미터입니다. \n";
//     cheers(cube(2));
//     return 0;
// }

// void cheers(int n)
// {

//     using namespace std;
//     for (int i = 0; i < n; i++)
//         cout << "Cheers! ";
//     cout << endl;

// }
// double cube(double x)
// {
//     return x * x * x;
//
// #include<iostream>
// const int ArSize = 8;
// int sum_arr(const int * begin, const int * end);
// int main(){
//     using namespace std;
//     int cookies[ArSize] = {1,2,4,8,16,32,64,128};
//     //어떤 시스템에서는 앞에 static을 넣어야 배열으 ㄹ초기화할 수 있다.
//     int sum = sum_arr(cookies, cookies + ArSize);
//     cout << "먹은 과자 수 합계: " <<sum << endl;
//     sum = sum_arr(cookies, cookies +3);
//     cout << "처음 세 사람은 과자 " << sum << "개를 먹었습니다. \n";
//     sum = sum_arr(cookies + 4, cookies + 8);
//     cout << "마지막 네 사람은 과자  " << sum << "개를 먹었습니다.\n";
//     return 0;
// }

// //정수 배열의 합계를 리턴한다.
// int sum_arr(const int * begin, const int * end){
//     const int * pt;
//     int total = 0;

//     for (pt = begin; pt !=end; pt++)
//     total = total + *pt;
//     return total;
// }
// //total max min average 를 리턴해서 1차원 배열을 받아서 ??
// 2차원 배열을 매개변수로 받아서 계산 후
// 1차원 배열을 리턴하는 함수를 만들어보자

#include <iostream>
// int sum((*ar2[4], int size);
int* sum_arr(int data[][4],int size);
int main()
{
    using namespace std;
    int data[3][4] = {{1, 2, 3, 4},
                      {9, 8, 7, 6},
                      {2, 4, 6, 8}};
    const int size = 5;
    cout << *sum_arr(data, 3);

    // int sum = sum_arr(*data);
    // int average = average_arr(*data, sum);
    // int max = max_arr(*data, sum);
    // int min = min_arr(*data, max);
    // int * arrrrrr = new int[4];

    return 0;
}

int* sum_arr(int data[][4], int size)
{
    using namespace std;
    int sum = 0;
    // int total = sum(data,3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            sum += data[i][j];
        }
    }
    int average = 0;
     int count = 0;
     for (int i = 0; i < 3; i++)
     {
         for (int j = 0; j < 4; j++)
         {
             count += 1;
         }
     }
     average = sum / count;
    // return sum;
     int max = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (data[i][j] < max)
            {
                max = data[i][j];
            }
        }
    }

int min = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (data[i][j] < data[i][j+1])
            {
                min = data[i][j];
            }
        }
    }
//sum,average, max, min
static int bb[4] = {sum,average,max,min};

return bb;
}

// int average_arr(int *data[], int sum)
// {
//
/*
int a=1;
int b=2;
in c=;
int *data={&a,&b,&c};
int data[][]
*/

// int average = 0;
//      int count = 0;
//      for (int i = 0; i < 3; i++)
//      {
//          for (int j = 0; j < 4; j++)
//          {
//              count += 1;
//          }
//      }
//      average = sum / count;
//      return average;
//  }
//  int max_arr(int *data[], int sum)
//  {
//      int max = 0;

//     for (int i = 0; i < 3; i++)
//     {
//         for (int j = 0; j < 4; j++)
//         {
//             if (data[i][j] < max)
//             {
//                 max = data[i][j];
//             }
//         }
//     }
//     return max;
// }
// int min_arr(int *data[], int max)
// {
//     int min = 0;
//     for (int i = 0; i < 3; i++)
//     {
//         for (int j = 0; j < 4; j++)
//         {
//             if (min < max)
//             {
//                 min = data[i][j];
//             }
//         }
//     }
//     return min;
// }

// #include <iostream>
// char *buildstr(char c, int n);
// int main()
// {

//     using namespace std;
//     int times;
//     char ch;
//     cout << "문자를 하나 입력하십시오: ";
//     cin >> ch;

//     cout <<"정수 하나를 입력하십시오: ";
//     cin >> times;
//     char * ps = buildstr(ch, times);
//     cout << ps << endl;
//     delete [] ps;
//     ps = buildstr('+', 20);
//     cout << ps << "-DONE-" << ps << endl;
//     delete [] ps;
//     return 0;
// }

// char * buildstr(char c, int n){
//     char * pstr = new char[n -3];
//     // 공간의 크기가 마이너스인데 그게 공간이 있는건가? 배열의 크기가 마이너스가 된다는게 가능한건가?
//     // 크기가 마이너스 이면 뭔데 그냥 공간을
//     pstr[n] = '\0';
//     while ( n -- > 0)
//         pstr[n] = c;
//     return pstr;
// }

// // 구조체를 복사하는 방식 p.453
// #include <iostream>
// struct travel_time
// {
//     int hours;
//     int mins;
// };
// const int MIns_per_hr = 60;

// travel_time sum(travel_time t1, travel_time t2);
// void show_time(travel_time t);

// int main()
// {
//     using namespace std;
//     travel_time day1 = {5, 45};
//     cin >> day1.hours;
//     cin >> day1.mins;

//     travel_time day2 = {4, 55};

//     travel_time trip = sum(day1, day2);
//     cout << "이틀간 소요시간: ";
//     show_time(trip);

//     travel_time day3 = {4, 32};
//     cout << "사흘간 소용 시간: ";
//     show_time(sum(trip, day3));

//     return 0;
// }

// travel_time sum(travel_time t1, travel_time t2)
// {
//     travel_time total;

//     total.mins = (t1.mins + t2.mins) % MIns_per_hr;
//     total.hours = t1.hours + t2.hours + (t1.mins + t2.mins) / MIns_per_hr;
//     return total;
// }

// void show_time(travel_time t)
// {
//     using namespace std;
//     cout << t.hours << "시간 "
//          << t.mins << "분 \n";
// }
// void updateTravel_time(travel_time day)
// {
//     using namespace std;
//     cout << "시간";
//     cin >> day.hours;
//     cout << "분";
//     cin >> day.mins;
// }

// travel_time upTravel_time(travel_time day)
// {
//     using namespace std;
//     cout << "시간";
//     cin >> day.hours;
//     cout << "분";
//     cin >> day.mins;
//     return day;
// }