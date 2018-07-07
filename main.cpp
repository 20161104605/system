#include"define.h"
#include <iostream>
#include <cstring>
#include <String>
#include <stdio.h>
#include <sstream>
#include <fstream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    
    readstu(s);
    if(readstu(s)>0)
    {
        s[0].f=readstu(s);
    }
    else
    {
        s[0].f=0;
    }
    readref(r);
    while(1)
    {
        switch(menu_select())
        {
            case 1:
                inputstuinf(s);
                break;
            case 2:
                inputref(r);
                break;
            case 3:
                inputscore(s);
                break;
            case 4:
                searchlistmenu(s,r);
                break;
            case 5:
                outputallinf(s,r);
                break;
            case 6:
                Sort(s);
                break;
            case 7:
                writestu(s);
                writeref(r);
                printf("Thank you for using£¡\n");
                return 0;
        }
    }
}
