#include <iostream>
#include <string>
#include "Video.h"

#pragma once

#include <iostream>
#include <string>

using namespace std;




    Videotape:: Videotape(string name_of_tape, string type_of_movie, string released_date, string cost, string availability, string location)
    {
        NAME_OF_TAPE = name_of_tape;
        TYPE_OF_MOVIE = type_of_movie;
        RELEASED_DATE = released_date;
        COST = cost;
        AVAILABILITY = availability;
        LOCATION = location;
    }

    void Videotape::setNAME_OF_TAPE(string a)
    {        
        NAME_OF_TAPE = a;
    }

    void Videotape::setTYPE_OF_MOVIE(string b) {
        TYPE_OF_MOVIE = b;
    }

    void Videotape::setRELEASED_DATE(string c) {
        RELEASED_DATE = c;
    }

    void Videotape:: setCOST(string d) {
        COST = d;
    }

    
    void Videotape::setAVAILABILITY(string e) {
       AVAILABILITY = e;
    }
    void Videotape::setLOCATION(string f) {
        LOCATION = f;
    }

    string Videotape::getNAME_OF_TAPE() {
        return NAME_OF_TAPE;
    }

    string Videotape::getTYPE_OF_MOVIE() {
        return TYPE_OF_MOVIE;
    }

    string Videotape::getRELEASED_DATE() {
        return RELEASED_DATE;
    }
    
    string Videotape::getCOST() {
        return COST;
    }

    

    string Videotape::getAVAILABILITY() 
    {
        return AVAILABILITY;
    }
    string Videotape::getLOCATION() 
    {
        return LOCATION;
    }

    void Videotape::Print()
    {
        cout << "\n\nName: " << NAME_OF_TAPE << endl;
        cout << "Type of movie: " << TYPE_OF_MOVIE << endl;
        cout << "Released date : " << RELEASED_DATE << endl;
        cout << "Cost: " << COST << endl;
        cout << "AVAILABILITY: " << AVAILABILITY << endl;
        cout << "Location: " << LOCATION << "\n\n";
    }
