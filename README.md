# Attendance Code via Zoom logs

## Run makefile
```bash
workingDir$ make
workingDir$ ./mainClass
```
## Usage
change these lines to your file locations:

```cpp

11 std::string nameFileLoc = "/home/bszekely/Desktop/attendance_code/Names.txt"; //Your list of students' first and last name as how they show up in the zoom logs
12 std::string inputZoomLogsLoc = "/home/bszekely/Desktop/attendance_code/Zoom_Attendance_Logs/"; //list of zoom .csv files
72 string fullName = "/home/bszekely/Desktop/attendance_code/txtfiles/"; //output location for the txt files of students' names

```
The main function (mainClass.cpp) uses a stack container (stringContainer.h) that stores each students'
data: Name, time, and date (if available) every time a new file is read in.

```cpp
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
the split3 function:
```cpp
sample.split3(line, sample,',');
```
splits the comma separated data into nodes on the stack.
The  find data section is the one you may need to edit yourself. 
```cpp
sample.findData();
```
This is popping each node from the stack until it gets to the time. if the student has been present in the class more 
than a specific time, in this case 1 min, then they are considered present. their name,date, and attended status will
be added to the containers (see stringContainer.h) private data members.
## Output
Once the above the aforementioned data have been added to the students' stack container. I then use getHelper 
methods to add the invdividuals name, attend status, and date to the txt file.
```cpp
    if(sample.getAttend() ==1){
	string fullName = "/home/bszekely/Desktop/attendance_code/txtfiles/" +sample.getName()+ ".txt";
	cout <<"Fullname is : "  <<fullName << endl;
	classFile.open(fullName,std::ios::app);
	classFile << sample.getName() << " " << sample.getAttend() << " " << sample.getDate() << endl;
	classFile.close();
    }
```
The txt file name will be written as "firstnamelastname.txt" form. The first time that a students' txt file is created,
every new instance of that students' name will be added to the pre-existing respective txt file. 
