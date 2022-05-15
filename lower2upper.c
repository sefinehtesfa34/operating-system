#include<stdio.h>
int main(int argc, char const *argv[])
{
    int c;
    while((c=getchar())!=EOF){
        if(c=='!'){
            break;
        }
        else if(c>='a'&&c<='z'){
            c+='A'-'a';
            putchar(c);
        }
        else{
            putchar(c);
        }
        
    }

    return 0;
}
