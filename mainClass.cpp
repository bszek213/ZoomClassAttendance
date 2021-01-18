#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <sstream> 
//#include "student.h"
#include "stringContainer.h"
namespace fs = std::filesystem;
int main()
{   
    std::string nameFileLoc = "/home/bszekely/Desktop/attendance_code/Names.txt";
    std::string inputZoomLogsLoc = "/home/bszekely/Desktop/attendance_code/Zoom_Attendance_Logs/";
    //std::cout << "Input Directory where the files at" << std::endl;
    //std::string inputString1 = nameFileLoc;
    //std::cin >> inputString; // "~/Desktop/PSY301_code/Zoom Attendance Logs/"
    std::fstream fin;
    std::fstream fin2;
    std::ofstream classFile;
    std::string line;
    std::string line2;
    std::string path = inputZoomLogsLoc; // "/home/bszekely/Desktop/PSY301_code/practice";
   
    fin2.open(nameFileLoc);
    int numfiles=0;
    /* Get num of elements in file */
    int temp = 0;
    std::string *arrNames;
    while (getline(fin2, line2))
    {
        temp++;
    }
    /* read strings into buffered array */
    arrNames = new std::string[temp];
    fin2.close();
    fin2.open(nameFileLoc);
    int arraySize = 0;
    while (getline(fin2, line2))
    {
        arrNames[arraySize] = line2;
        arraySize++;
        
    }

    //int len = sizeof(arrNames) / sizeof(arrNames[0]);
    /* Read all files from folder */
    for (const auto &entry : fs::directory_iterator(path))
    {
       
        /* Run for loop for all names per file */
        for (int i = 0; i < arraySize; i++)
        {
            //int count = 0;
            /* Read data from folder path */
            auto lol = entry.path();
            std::cout << entry.path() << std::endl;
            fin.open(lol);
            std::string line;
            stringContainer sample(arraySize);
            /* READ ALL LINES FROM FILE */
            while (!fin.eof()) //getline(fin, line)
            {
                getline(fin,line);
                if (line.find(arrNames[i]) != std::string::npos)
                {           
                    //cout << "ARRAY NAME IS: " << arrNames[i] << endl;
                    sample.split3(line, sample,',');
                    sample.showStructure();
                    cout << sample.extractDateFilePath(entry.path())<< endl;;
                    sample.findData();
                    //cout << sample.getAttend() << endl;
                    if(sample.getAttend() ==1){
                        string fullName = "/home/bszekely/Desktop/attendance_code/txtfiles/" +sample.getName()+ ".txt";
                        cout <<"Fullname is : "  <<fullName << endl;
                        classFile.open(fullName,std::ios::app);
                        classFile << sample.getName() << " " << sample.getAttend() << " " << sample.getDate() << endl;
                        classFile.close();
                    }
                }
            }

            fin.close();
            //count= 0;
        }

        //Close file to write to it
        //myfile.close();

        //++count;
        ++numfiles;
    }
    /* NOW OPEN THE OUTPUT FILE AND SUM FOR EVERY TIME A NAME IS PRESENT AND THEN RESAVE */
    cout << numfiles << endl;
    return 0;
}
