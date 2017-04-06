#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char** argv){
    if(argc != 2)
    	cout << "Wrong format!!" << endl;
    else{
    	ifstream infile(argv[1], ifstream::in);
    	string buf;
    	getline(infile, buf);
    	while(infile.good()){
    		cout << buf << endl;
    		getline(infile, buf);
    	}
        infile.close();
    }
	return 0;
}