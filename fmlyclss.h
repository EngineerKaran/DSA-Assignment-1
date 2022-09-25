#include <string>
using namespace std;

class Family
{
    public :
    Family *previous;
    string name;//FOR NAME OF THE MEMBER
    int age;
    Family *next;

    Family(string name, int age)
    {
        this->name = name;
        this->age = age;
        this->previous = NULL;
        this->next = NULL;
    }

};