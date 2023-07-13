#include <iostream>
#include <stdio.h>
#include <string>
#include "work_station.h"

WorkStation::WorkStation()
{
    _counts_A = 0;
    _counts_B = 0;
    _counts_C = 0;

}

WorkStation::~WorkStation()
{

}

int WorkStation::checkProcess(string &order)
{
    int length = order.length();
    int valid = 0;
    for (int i = 0; i < length; i++)
    {
        if (order[i] >= 65 && order[i]<=68){
            if (i == 0 && order[i] == 68)
            {
                valid = 0;
                printf("Process D cannot be the first process");
                break;
            }

            if (order[i] == 68)
            {
                order[i] = order[i-1];
            }
            
            valid = 1;
        }
        else{
            valid = 0;
            break;
        }
    }
    return valid;
}

void WorkStation::setProcess(string order)
{
    int length = order.length();
    for (int i = 0; i < length; i++)
    {
        switch(order[i]){
            case 'A':
                processA();
                break;
            case 'B':
                processB();
                break;
            case 'C':
                if (_value % 2 == 0){
                    i++;
                }
                _counts_C +=1;
                break;

        }
    }
    printf("after the whole process, the output value is %d\n", _value);
}

void WorkStation::setInit(int input)
{
    _value = input;
}

void WorkStation::processA()
{
    _value = _value+1;
    _counts_A +=1;
}

void WorkStation::processB()
{
    _value = _value-1;
    _counts_B +=1;
}

void WorkStation::showTimes()
{
    printf("process A %d times\n", _counts_A);
    printf("process B %d times\n", _counts_B);
    printf("process C %d times\n", _counts_C);
}

int WorkStation::getResult()
{
    return _value;
}