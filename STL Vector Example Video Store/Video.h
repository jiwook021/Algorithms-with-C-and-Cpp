#include <iostream>
#include <string>
//prototypes
using namespace std;

class Videotape
{
    string NAME_OF_TAPE;
    string TYPE_OF_MOVIE;
    string RELEASED_DATE;
    string COST;
    string AVAILABILITY;
    string LOCATION;


public:

    Videotape(string name_of_tape, string type_of_movie, string RELEASED_DATE, string COST, string AVAILABILITY, string location);
    
    void setNAME_OF_TAPE(string a);
    void setTYPE_OF_MOVIE(string b);
    void setRELEASED_DATE(string c);
    void setCOST(string d);
    void setAVAILABILITY(string e);
    void setLOCATION(string f);

    string getNAME_OF_TAPE();
    string getTYPE_OF_MOVIE();
    string getRELEASED_DATE();
    string getCOST();
    string getAVAILABILITY();
    string getLOCATION();

    void Print();

};