#ifndef inputHeader_H
#define inputHeader_H
#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;

template<typename T>
class student
{
private:
    int count;
    float timeAtt;
    T name;
    
public:
    student(T inputStudent,float inputTime);
    ~student();
    bool timeAttend(float value);
};

template<typename T>
student<T>::student(T inputStudent,float inputTime): name(inputStudent)
{
}

template<typename T>
student<T>::~student()
{
}

/*bool isNumber(string s)
{
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;
 
    return true;
}*/

#endif		// #ifndef inputHeader_H