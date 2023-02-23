#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <pthread.h>
using namespace std;
void  *ahhh(void *arg)
{
    string s = *static_cast<string*>(arg);// creates string from pointer of the main function
    system(s.c_str());//executes system command
    pthread_exit(0);
}

int main()
{
    cout<<"Welcome to myShell"<<endl<<endl;
    pthread_t cmd; // thread identifier
    pthread_attr_t attr;
    char test[50];
    int i = 1;
    string dir = "dir";
    while (1)
    {
        fgets(test,50,stdin);//reads input from user
        char* temptest= test;
        string please = temptest;// creates a string of the user input before strtok alters it
        const char* please2 = please.c_str();
        char* arg1 = strtok(temptest, " ");
        char* arg2 = strtok(NULL, " ");
        cout<<"COMMAND TYPED BY USER:"<<endl<<please<<endl<<endl<<"ARGUEMENT 0: "<<arg1<<endl;
        //<<"ARGUEMENT 1: "<<arg2<<endl;
        while(arg2 != NULL)
        {

        cout<<"ARGUEMENT "<<i<<": "<<arg2<<endl;
        arg2 = strtok(NULL, " ");
        i++;
        }//reads out the rest of the arguements
        // needs to check if its part of the list before calling the pthread***********
        pthread_create(&cmd,NULL,ahhh,&please);// creates thread
        pthread_join(cmd,NULL);// waits for thread to finish
        if(please == "exit")
        {
        exit(0);
        abort();
        }

        }

    return 0;
}
