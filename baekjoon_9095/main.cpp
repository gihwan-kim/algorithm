#include <iostream>
#include <cstring>

using namespace std;

void calc(int number);
int main()
{
    int *number_arry = nullptr;
    int size = 0;

    cin >> size;
    number_arry = new int[size];
    memset(number_arry, 0, size);
    for (int idx = 0; idx < size; idx++)
        cin >> number_arry[idx];
    for (int idx = 0; idx < size; idx++)
        calc(number_arry[idx]);
}


void calc(int number)
{
    int idx = 0;
    int *arry = nullptr;
    int final = 0;

    arry = new int[number];
    memset(arry, 0, number);

    // arry 의 요소 값은 방법 수
    arry[0] = 1; // num 1
    arry[1] = 2; // num 2 : 1+1, 2
    arry[2] = 4; // num 3 : ...

    if (number == 1)
        final = arry[0];
    else if (number == 2)
        final = arry[1];
    else if (number == 3)
        final = arry[2];
    else
    {
        for (idx = 3 ; idx < number; idx++)
            arry[idx] = arry[idx-1] + arry[idx-2] + arry[idx-3];
        final = arry[idx-1];
    }
    cout<<final<<endl;
}