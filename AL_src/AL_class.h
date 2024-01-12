#include <iostream>
using namespace std;

class Instrument {        
  public:          
    string type;  
    string pitch;  

    Instrument(string x, string y) { 
      type = x;
      pitch = y;
    }
    bool bestInstrument(){
      return this->type == "Trumpet";
    }
};
