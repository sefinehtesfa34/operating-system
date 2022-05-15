#include<stdio.h>
#include <ctype.h>
int main(int argc, char const *argv[])
{
    int c;
    
    while((c=getchar())!=EOF){
            c=toupper(c);
            putchar(c);        
    }

    return 0;
}
