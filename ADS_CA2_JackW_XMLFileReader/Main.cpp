#include "Main.h"

#include <fstream>
#include <iostream>
#include <stack>
#include <vector>

#include "Tree/Tree.h"
#include "Tree/TreeIterator.h"
using namespace std;

// structs to store folder and file data
struct file 
{
    string name;
    int size;
    string type;
};
//function the gets file name from path
string getFileName(string path)
{
    //find last slash
    int pos = path.find_last_of("\\");
    //get file name
    string name = path.substr(pos + 1, path.length() - pos);
    return name;
}


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
                data += line;
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

<<<<<<< Updated upstream
    int main()
=======
void treeGen(string data, Tree<file*>* tree)
{
    file* f = nullptr;
    TreeIterator<file*>* iter = nullptr;
    int pos = 0;
    
    //while there is a tag to read
    while (pos < data.length())
>>>>>>> Stashed changes
    {
        //find next tag
        int end = data.find('>', pos);
        pos = data.find('<', pos);
        //get tag
        string tag = data.substr(pos + 1, end - pos - 1);

        //if tag is div
        if (tag == "div")
        {
            //create new file
            f = new file();
            //set file type to div
            f->type = "dir";
            //if tree is empty
            if (tree == nullptr)
            {
                //create new tree
                tree = new Tree<file*>(f);
                iter = new TreeIterator<file*>(tree);
            }
            else
            {
                //add file to tree
                iter->appendChild(f);
                iter->childEnd();
                iter->down();
            }
            //move to next tag
            pos = end + 1;
        }
        else if (tag == "/div")
        {
            //move up tree
            iter->up();
            pos = end + 1;
        }
        else if (tag == "file")
        {
            //create new file
            f = new file();
            //add file to tree
            iter->appendChild(f);
            //move to next tag
            pos = end + 1;
        }
        else if (tag == "name")
        {
            //find next tag
            int nextOpen = data.find('<', end);
            //get & set name
            string name = data.substr(end + 1, nextOpen - end - 1);
            f->name = name;
            //move to next tag
            pos = data.find('>', nextOpen);
        }
        else if (tag == "length")
        {
            //find next tag
            int nextOpen = data.find('<', end);
            //get & set size
            string size = data.substr(end + 1, nextOpen - end - 1);
            f->size = stoi(size);
            //move to next tag
            pos = data.find('>', nextOpen);
        }
        else if (tag == "type")
        {
            //find next tag
            int nextOpen = data.find('<', end);
            string type = data.substr(end + 1, nextOpen - end - 1);
            //get & set type
            f->type = type;
            pos = data.find('>', nextOpen);
        }
        else
        {
            pos = end + 1;
        }
        cout << tag << endl;
    }
}


int main()
{
    // read file convert into string
    string data;
    string fpath = "C:/Users/jackw/Documents/AlgorithmsCA/ADS_2023_CA2_JW/ADS_CA2_JackW_XMLFileReader/Files/vs_sample_simple.xml";
    string fname = getFileName(fpath);
    
    data = fileToString(fpath);
    cout << data << endl;

    // run file through stack to verify xml is valid
    if (isBalanced(data)) {
        cout << "file is balanced" << endl;
       
    } 
    else {
        cout << "file is not balanced" << endl;
    }

    //new file
    file* f = new file(); 
    //set file name to fname
    f->name = fname; 
     
    Tree<file*>* tree = nullptr; 
    treeGen(data, tree); 


    return 1;
}

