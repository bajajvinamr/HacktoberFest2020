#include <iostream>
#include <ctime>
using namespace std;

int main(){
    int birth_day, birth_month, birth_year;
    struct tm date = {0};
    cout<<"Enter Your Date of Birth ( Year Month Day): ";
    cin>>birth_year>>birth_month>>birth_day;
    date.tm_year = birth_year-1900;
    date.tm_mon  = birth_month-1;
    date.tm_mday = birth_day;
    time_t normal = mktime(&date);
    time_t current;
    time(&current);
    int age = (difftime(current, normal) + 86400L/2) / 86400L;
    cout<<"You are "<<age/365<<" years old.";
    return 0;
}
