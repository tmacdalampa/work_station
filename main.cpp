#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <exception>
#include "work_station.h"

using namespace std;

int main()
{
    int manual_input = 1;
    int init_value;
    ofstream ofs;
    ifstream myfile("initial_value.txt");
    if (myfile.is_open()){
        try{
            string mystring;
            myfile >> mystring;
            init_value = stoi(mystring);
            manual_input = 0;
        }
        catch(exception &e){
            printf("error in initial_value.txt\n");
        }
        myfile.close();
    }
    //else{
    //    printf("file doesn't exist, user input value\n");
    //}
    WorkStation A;
    while (1)
    {
        string working_process;
        
        while(1)
        { 
            cout << "please input working process" << endl;
            cin >> working_process;
            int check_res = A.checkProcess(working_process);
            
            if (check_res == 1)
            {
                break;
            }
            else{
                cout << "invalid input process, plese try again" << endl;
            }
        }
        if (manual_input == 1)
        {
            while (1){
                cout << "please input initial value\n";
                string input_value;
                cin >> input_value;
                try{
                    init_value = stoi(input_value);
                    break;
                }
                catch(exception e)
                {
                    printf("init value invalid, please try again\n");
                }
            }
        }
        manual_input = 1;
        
        A.setInit(init_value);
        A.setProcess(working_process);
        A.showTimes();
        int n = A.getResult();
        ofs.open("initial_value.txt", ofstream::trunc);
        ofs << n << "\n";
        ofs.close();
        
    }
    return 0;
}
