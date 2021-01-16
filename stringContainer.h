#ifndef STRINGCONAINTER_H
#define STRINGCONAINTER_H
#include <stdexcept>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;
namespace fs = std::filesystem;

class stringContainer
{
public:
    stringContainer(int maxNumber);
    ~stringContainer();
    //void push_back(const stringContainer &)
    void split3(const string &str, stringContainer &cont, char delim = ',');
    void push(const string &newDataItem);
    string pop();
    bool isEmpty() const;
    void showStructure() const;
    bool writeToFile(std::ofstream& inputRef,const string& input);
    int getCount();
    void findData();
    int getAttend();
    string getName() const;
    bool extractDateFilePath(fs::path filePath);
    string getDate() const;



private:
    class StackNode
    {
    public:
        StackNode(const string &nodeData, StackNode *nextPtr = nullptr);

        string dataItem;
        StackNode *next;
    };

    StackNode *top;
    int attended;
    string nameStudent;
    string dateStudent;
};

stringContainer::stringContainer(int maxNumber)
{
    top = nullptr;
    attended = 0;
    nameStudent = "NULL";
    dateStudent = "NULL";
}
stringContainer::StackNode::StackNode(const string & nodeData, StackNode *nextPtr)
{
    next = nextPtr;
    dataItem = nodeData;
}

bool stringContainer::extractDateFilePath(fs::path filePath){
    if(getCount() == 3){
      string pathName = filePath;
      //cout << pathName.substr(59,4) <<endl; //extract after 59
      dateStudent = pathName.substr(59,4); //I do not know if this will work everytime;
      return true;
    }else{
      return false;
    }
}


void stringContainer::split3(const string& str, stringContainer &cont, char delim)
{

    std::size_t current, previous = 0;
    current = str.find(delim);
    while (current != std::string::npos)
    {
        cont.push(str.substr(previous, current - previous));
        previous = current + 1;
        current = str.find(delim, previous);
    }
    cont.push(str.substr(previous, current - previous));
}
void stringContainer::push(const string &newDataItem){
    if (!top)
  {
    top = new StackNode(newDataItem);
  }
  else
  {
    if(newDataItem != " "){        
    StackNode*temp = new StackNode(newDataItem);
    temp->next = top;
    top = temp;
    
    }

  }
  /*if (isEmpty())
  {
    throw logic_error("Cannot push() no stack.");
  }*/
}
bool stringContainer::isEmpty() const
{
  if (!top)
  {
    return true;
  }
  else
  {
    return false;
  }
}
void stringContainer::showStructure() const
{
  if (isEmpty())
  {
    cout << "No stack" << endl;
  }
  else
  {
    int i = 0;
    for (StackNode *curr = top; curr != nullptr; curr = curr->next)
    {
    //cout << curr->dataItem.length() << endl;
      cout << "value of Stack Node: [" << i << "]"
           << "is: " << curr->dataItem << endl;
           i++;
    }
  }
}

string stringContainer::pop(){
  /*else if (!top->next)
  {
    return top->dataItem;
  }*/
  //else
  //{
    //StackNode *temp = top;
    string dataTop = top->dataItem;
    top = top->next;
    return dataTop;
    //delete temp;
  //}   
}
stringContainer::~stringContainer(){    
}

void stringContainer::findData(){
    string time, email, name, dateStart, dateEnd, emptyVal;
    if (getCount() == 3)
    { //always size of 3 or above in the nodes
        time = pop();
        email = pop();
        name = pop();
        int timeClass = stoi(time);
        if (timeClass >= 1)
        {
            ++attended;
            nameStudent = name;           
        }
    }
    else if (getCount() == 5)
    {
        time = pop();
        dateStart = pop();
        dateEnd = pop();
        email = pop();
        name = pop();
        int timeClass = stoi(time);
        if (timeClass >= 1)
        {
            ++attended;
            nameStudent = name;
            dateStudent = dateStart;

        }
    }
    else if (getCount() == 6)
    {
        emptyVal = pop();
        time = pop();
        dateStart = pop();
        dateEnd = pop();
        email = pop();
        name = pop();
        int timeClass = stoi(time);
        if (timeClass >= 1)
        {
            ++attended;
            nameStudent = name;
            dateStudent = dateStart;

        }
    }
}

bool stringContainer::writeToFile(std::ofstream& inputRef,const string& input)
{
    //std::ofstream classFile;
    inputRef.open(input,std::ios::app);
    for (StackNode *curr = top; curr != nullptr; curr = curr->next)
    {
        string output = curr->dataItem;
        inputRef << output << ",";
        if(curr == nullptr){
          inputRef  << endl;
        }
    }
    inputRef.close();
    return true;
}
int stringContainer::getCount()  
{  
    int count = 0; // Initialize count  
    StackNode* current = top; // Initialize current  
    while (current != NULL)  
    {  
        count++;  
        current = current->next;  
    }  
    return count;  
}  
int stringContainer::getAttend(){
    return attended;
}
string stringContainer::getName() const{
    return nameStudent;
}
string stringContainer::getDate() const{
    return dateStudent;
}

#endif		// #ifndef inputHeader_H
