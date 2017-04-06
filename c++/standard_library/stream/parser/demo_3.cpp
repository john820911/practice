#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    FILE* pfile;
    pfile = fopen("parser.txt", "r");
    if(pfile == NULL)
    	cout << "Fail to open file!!" << endl;
    else{
    	char c;
    	c = getc(pfile);
    	FILE* qfile;
    	qfile = fopen("parser_write.txt", "wt");
    	while(c != EOF){
    		putc(c, qfile);
    		c = getc(pfile);
    	}
        fclose(qfile);
    }
    fclose(pfile);
    return 0;
}