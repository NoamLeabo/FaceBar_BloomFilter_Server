#include "AL_class.h"
#include <iostream>
using namespace std;

int main() {
    Instrument inst("Trumpet", "Bb");
    if (!inst.bestInstrument())
    {
        return 1;
    }
    
    cout<<"Trumpet is the best instrument" <<endl;

    return 0;

}
