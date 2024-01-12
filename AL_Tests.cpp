#include "AL_src/AL_class.h"
#include <iostream>
using namespace std;

int main() {
    Instrument inst("Trumpet", "Bb");
    if (!inst.bestInstrument())
    {
        return 1;
    }

}
