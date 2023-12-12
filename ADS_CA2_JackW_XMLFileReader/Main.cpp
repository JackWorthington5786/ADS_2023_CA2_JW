#include "Main.h"

#include <fstream>
#include <iostream>
#include <stack>
#include <vector>

#include "Tree/Tree.h"
using namespace std;

// structs to store folder and file data
struct folder
{
    string name;
};
struct file 
{
    string name;
    int size;
    string type;
};

// function to read file into string
    string fileToString(string fname)
    {
        //load file
        ifstream fin(fname);
        //string to store file data
        string data = "";

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
        return data;
    }

    // function to check if xml is balanced using stack
    bool isBalanced(const string& Data) {
        // Stack to keep track of opening tags
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



    int main()
    {
        // read file convert into string
        string file;
        file = fileToString("C:/Users/jackw/Documents/AlgorithmsCA/ADS_2023_CA2_JW/ADS_CA2_JackW_XMLFileReader/Files/vs_sample_simple.xml");
        cout << file << endl;

        // run file through stack to verify xml is valid
        if (isBalanced(file)) {
            cout << "file is balanced" << endl;
        } 
        else {
            cout << "file is not balanced" << endl;
        }

        // create tree
        Tree<string> tree;

        return 1;
    }

