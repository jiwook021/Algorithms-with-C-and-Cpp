#include "Matrix.h"
#include "Image.h"
#include "processing.h"
#include <iostream>
#include <cassert>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <fstream>


using namespace std;


int main(int argc, char *argv[])

{
    if((4>argc)||(5 < argc))
    {
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]" << endl;
        cout << "WIDTH and HEIGHT must be less than or equal to original" << endl;
        return 0;
    }

    string sFilename = string(argv[1]);
    string sOutputfilename = string(argv[2]);    
    int iNewwidth = atoi(argv[3]);
    int iNewheight;
    if(argc==5)
    {
    iNewheight = atoi(argv[4]);
    }


    ifstream fin(sFilename.c_str(),ios_base::out | ios_base::binary);
    
    if(!fin.is_open()){
        cout << "Error opening file: " << sFilename << endl;
        return 0;
    }

    Image img;  
    Image_init(&img, fin);
    fin.close();
  
    if(!(0 < iNewwidth && iNewwidth <= MAX_MATRIX_WIDTH) 
    || !(0 < iNewheight && iNewheight <= MAX_MATRIX_HEIGHT))
    {
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]" << endl;
        cout << "WIDTH and HEIGHT must be less than or equal to original" << endl;
        return 0;
    }
    
    seam_carve(&img, iNewwidth, iNewheight);


    ofstream fout(sOutputfilename.c_str());     
    
    Image_print(&img,fout); 
    
    fout.open(sOutputfilename.c_str(), ios::out | ios::in | ios_base::binary);


    fin.close();
    fout.close();
   
    return 0; 
}
