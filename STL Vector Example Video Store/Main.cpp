#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

#include "Video.h"


using namespace std;

int changeoptions;
bool videolist;

string temp_name_of_tape, temp_type_of_movie, temp_cost, temp_released_date, temp_location,  temp_availability;

int main()
{
    vector<Videotape> list;//vector of list to dynamically increase the size of the number of videos
    
    int i = 0;//starting from list 0
    
    cout << "_______LIST OF VIDEOS_______" << endl;


    // Videotape(string name_of_tape, string type_of_movie, string released_date, string cost, string availability, string location)
    
    list.push_back(Videotape("Good_will_hunting", "Drama", "10/02/1997", "$10","Available" , "F-17"));

    list.at(i).Print();
   
    i = i + 1;
    
    list.push_back(Videotape("Parasite", "Horror",  "10/13/2003", "$8" ,"Not available", "A-19"));
    list.at(i).Print();
    i= i + 1;


    
    while (true)
    {
        cout << "\n______________________Options______________________\n 1.Add a video informations to save on the system \n 2.Show the current list of video files\nWrite 1 or 2  ";
        cin >> changeoptions;

        
            if (changeoptions == 1)
            {
                //string temp_name_of_tape, temp_type_of_movie, temp_released_date, temp_cost, temp_availability, temp_location, ;
                cin.ignore();

                list.push_back(Videotape("", "", "", "", "", ""));

                cout << "\nName of the tape?  ";
                getline(cin, temp_name_of_tape);


                cout << "Type of the movie?  ";
                getline(cin, temp_type_of_movie);


                cout << "Released date of the movie?  ";
                getline(cin, temp_released_date);


                cout << "Cost?  ";
                getline(cin, temp_cost);

                cout << "Is the video available? (Write Available or Not available)  ";
                getline(cin, temp_availability);


                cout << "Location?  ";
                getline(cin, temp_location);

                //using set method 
                list.at(i).setNAME_OF_TAPE(temp_name_of_tape);
                list.at(i).setTYPE_OF_MOVIE(temp_type_of_movie);
                list.at(i).setRELEASED_DATE(temp_released_date);
                list.at(i).setCOST(temp_cost);
                list.at(i).setAVAILABILITY(temp_availability);
                list.at(i).setLOCATION(temp_location);
                i = i + 1;
                changeoptions = 0;//set to defult option

            }
               
            else if (changeoptions == 2)

            {
                    cout << "\n\n_______LIST OF VIDEOS_______" << endl;

                    for (int j = 0; j < i; j++)
                    {
                        list.at(j).Print();
                    }
                    changeoptions = 0;//set to defult option
            }//end of else

        }//end of while true

    return 0;
}