#include "Main.h"

#include <fstream>
#include <iostream>
#include <stack>
#include <vector>

#include "Tree/Tree.h"

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

    //Todo: run file through stack to verify xml is valid

    bool isBalanced(const string& Data) {
        stack<string> tagStack;

        size_t i = 0;
        while (i < Data.length()) {
            // Find the next opening
            size_t start = Data.find('<', i);
            if (start == string::npos) {
                break;  // No more tags found
            }

            // Find the next closing tag (if one exists)
            size_t end = Data.find('>', start);
            if (end == string::npos) {
                break;  // Malformed XML, no closing angle bracket found
            }

            // Extract the tag
            string tag = Data.substr(start + 1, end - start - 1);

            // Check if it's an opening or closing tag
            if (tag[0] != '/') {
                // If opening tag, push it onto the stack
                tagStack.push(tag);
            } else {
                // If closing tag, check if it matches the top of the stack
                if (tagStack.empty() || tagStack.top() != tag.substr(1)) {
                    return false;  // Mismatched closing tag
                }

                // Pop the matching opening tag
                tagStack.pop();
            }

            // Move to the next character after the closing angle bracket
            i = end + 1;
        }

        // The XML is balanced if the stack is empty at the end
        return tagStack.empty();
    }

    
    //Todo: make tree from string file and print tree to console
    
    int main()
    {
        string file;
        fileToString("vs_sample_simple.xml", file);
        cout << file << endl;

        //run file through stack to verify xml is valid
        if (isBalanced(file)) {
            cout << "file is balanced" << endl;
        } else {
            cout << "file is not balanced" << endl;
        }

        
        return 1;
    }
}
