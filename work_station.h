#include <string>
using namespace std;
class WorkStation
{
public:
    WorkStation();
    ~WorkStation();
    void processA();
    void processB();
    void processC();
    void processD();
    void showResult();
    void showTimes();
    void setProcess(string order);
    void setInit(int input);
    int checkProcess(string &order);
    int getResult();
private:
    int _counts_A;
    int _counts_B;
    int _counts_C;
    int _value;
};

enum ProcessType{
    A,
    B,
    C,
    D
};