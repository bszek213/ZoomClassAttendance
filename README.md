# Attendance Code via Zoom logs

##Run makefile

## Usage
change these lines to your file locations:

```cpp

11 std::string nameFileLoc = "/home/bszekely/Desktop/attendance_code/Names.txt";
12 std::string inputZoomLogsLoc = "/home/bszekely/Desktop/attendance_code/Zoom_Attendance_Logs/";
72 string fullName = "/home/bszekely/Desktop/attendance_code/txtfiles/"

```
The main function (mainClass.cpp) uses the container (stringContainer.h) that stores each students'
data: Name, time, and date (if available) every time a new file is read in.

```cpp
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
```
