#include "Main.h"

#include <fstream>
#include <iostream>

namespace std
{
    void fileToString(string fname, string data)
    {
        //load file
        ifstream fin(fname);

        //check if file is open
        if(fin)
        {
            //read file into string
            string line;
            //while there is a line to read
            while(getline(fin, line))
            {
                //add line to data
                data += line + "\n";
            }
            fin.close();
        }
        //if file is not open
        else
        {
            cout << "Error opening file" <<endl;
        }
    }


    int main()
    {
        string file;
        fileToString("vs_sample_simple.xml", file);

        return 1;
    }
}
