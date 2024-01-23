#include "App.h"
#include "AddUrl.h"
#include "HashNo1.h"
#include "HashNo2.h"
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    vector<HashFunc*> funcBank;
    HashNo1 f1;
    HashNo2 f2;
    funcBank.push_back(&f1);
    funcBank.push_back(&f2);
    App app(funcBank);
    app.run();
    return 0;
}
