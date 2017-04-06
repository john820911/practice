#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    char str[256];
    cout << "Type a string:" << endl;
    gets(str);
    cout << "The string you typed:" << endl;
    puts(str);
    cout << "Type a string again(0 to stop)" << endl;
    char c;
    c = getchar();
    while(c != '0'){
    	if(c == '\n'){
            putchar(c);
            puts("Type a string again(0 to stop)");
            c = getchar();
    	}
    	else{
    	    putchar(c);
    	    c = getchar();
    	}
    }
    cout << endl;
   
	return 0;
}