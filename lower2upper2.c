#include<stdio.h>
#include <ctype.h>
int main(int argc, char const *argv[])
{
    int c;
    
    while((c=getchar())!=EOF){
        if(c=='!'){
            break;
        }
        else if(islower(c)){
            c=toupper(c);
            putchar(c);
        }
        else{
            putchar(c);
        }
        
    }

    return 0;
}
