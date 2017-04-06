#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char** argv){
    if(argc != 2)
        cout << "Wrong Format!!" << endl;
    else{
        ifstream infile;
        infile.open(argv[1], ifstream::in);
        if(!infile.is_open())
            cout << "File is not open" << endl;
        else{
            string buf;
            getline(infile, buf);
            while(!infile.eof()){
                cout << buf << endl;
                getline(infile, buf);    
            }
        }
        infile.close();
    }
    return 0;
}