#include <iostream>
#include <ctime>
using namespace std;
 
int main()
{
    int hour, min, sec;
    time_t t;
    time(&t);
    tm   *tm    = localtime(&t);
    char *sDate = asctime(tm);
    cout<<"current time : "<<sDate;
    cout<<"enter time of shutdown\n";
    cout<<"hour   : ";cin>>hour;
    cout<<"minute : ";cin>>min;
    cout<<"second : ";cin>>sec;
    time(&t);
    tm    = localtime(&t);
    sDate = asctime(tm);
    long nSec   =   (hour - tm->tm_hour)*3600 + 
                    (min  - tm->tm_min)*60  + 
                    (sec  - tm->tm_sec);
    long start = clock();
    long tick;
    while(0 < nSec)
    {
        if((((tick = clock()) - start)/CLOCKS_PER_SEC) == 1)
        {
            system("cls");
            cout<<"time of start : "<<sDate;
            cout<<"Seconds for shutdown : "<<nSec<<endl;
            start = tick;
            nSec = nSec - 1;
        }
    }
    system("shutdown -s -t 5");
    return 0;
}