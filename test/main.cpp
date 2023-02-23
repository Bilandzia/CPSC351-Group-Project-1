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

    char test[50];
    int i = 1;

    while (1)
    {
        fgets(test,50,stdin);//reads input from user
        char* temptest= test;
        string please = temptest;// creates a string of the user input before strtok alters it
        char* arg1 = strtok(temptest, " ");
        char* arg2 = strtok(NULL, " ");
        string help(arg1);
        cout<<"COMMAND TYPED BY USER:"<<endl<<please<<endl<<endl<<"ARGUEMENT 0: "<<arg1<<endl;
        //<<"ARGUEMENT 1: "<<arg2<<endl;
        while(arg2 != NULL)
        {

        cout<<"ARGUEMENT "<<i<<": "<<arg2<<endl;
        arg2 = strtok(NULL, " ");
        i++;
        }//reads out the rest of the arguements
        // needs to check if its part of the list before calling the pthread***********
        i = 1;
        string dir = "dir ";
        string m = static_cast<string>(arg1);
        if(please.find("dir")!= std::string::npos||please.find("help")!= std::string::npos||please.find("vol")!= std::string::npos||please.find("path")!= std::string::npos||please.find("tasklist")!= std::string::npos||please.find("notepad")!= std::string::npos||please.find("echo")!= std::string::npos||please.find("color")!= std::string::npos||please.find("ping")!= std::string::npos)
        {if(please.find("help")!= std::string::npos)
            {
            string hp = please;
            string hel = please;
            hel.append(hel.begin()+4,hel.end());
            hp.append("man ",4);
            please = hp+hel;
            }
            else if(please.find("path")!= std::string::npos)
            {
            string pt = please;
            string pth = please;
            pth.append(pth.begin()+4,pth.end());
            pt.append("pwd ",4);
            please = pt+pth;
            }
            else if(please.find("vol")!= std::string::npos)
            {
            string pt = please;
            string pth = please;
            pt.append("df -l",5);//
            please = pt;
            }
            else if(please.find("tasklist")!= std::string::npos)
            {
            string pt = please;
            string pth = please;
            pt.append("ps  ",4);
            please = pt+pth;
            }
            else if(please.find("notepad")!= std::string::npos)/*change params of these from notepad to ping*/
            {
            string pt = please;
            string pth = please;
            pt.append("df -l",5);//
            please = pt;
            }
            else if(please.find("echo")!= std::string::npos)
            {
            string pt = please;
            string pth = please;
            pt.append("df -l",5);//
            please = pt;
            }
            else if(please.find("color")!= std::string::npos)
            {
            string pt = please;
            string pth = please;
            pt.append("df -l",5);//
            please = pt;
            }
            else if(please.find("ping")!= std::string::npos)
            {
            string pt = please;
            string pth = please;
            pt.append("df -l",5);//
            please = pt;
            }
        pthread_create(&cmd,NULL,ahhh,&please);// creates thread
        pthread_join(cmd,NULL);// waits for thread to finish
        }
        if(please.find("exit")!= std::string::npos)
        {
        cout<<"Thanks for using myShell!";
        exit(0);
        abort();
        }

        }

    return 0;
}

