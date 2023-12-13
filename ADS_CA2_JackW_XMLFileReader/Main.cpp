#include "Main.h"

#include <fstream>
#include <iostream>
#include <queue>
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
//getters
string getName(file* f) { return f->name; }
int getSize(file* f) { return f->size; }
string getType(file* f) { return f->type; }
//to string
string toString(file* f)
{
    //if type is dir
    if (f->type == "dir")
    {
        return "Folder - " + f->name;
    }
    else
    {
        return "File - " + f->name +
                 " - Size: " + to_string(f->size) + " b "
                 " - Type: " + f->type;
    }
    
}

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

// function to display tree
void displayTree(TreeIterator<file*> iter, string indent)
{
        cout << indent << toString(iter.node->data) << endl;
    
    if (iter.childValid())
    {
        while (iter.childValid())
        {
            TreeIterator<file*> iter2(iter.childIter.currentNode->data);
            displayTree(iter2, "\t" + indent);
            iter.childForth();
        }
    }
}

// function to print using a Depth First Search
void printDFS(TreeIterator<file*> iter)
{
    while (iter.childValid())
    {
        TreeIterator<file*> iter2(iter.childIter.currentNode->data);
        printDFS(iter2);
        iter.childForth();
    }
    cout << toString( iter.item()) << "\n";
}
// function to print using a Breadth first Search
void printBFS(Tree<file*> tree)
{
    queue<Tree<file*>> queue;
    queue.push(tree);
    while (!queue.empty())
    {
        DListIterator<Tree<file*>*> iter = queue.front().children->getIterator();
        while (iter.isValid())
        {
            queue.push(*iter.item());
            iter.advance();
        }
        cout << toString(queue.front().data) << "\n";
        queue.pop();
    }
}

// function to generate tree
void treeGen(string data, Tree<file*>*& tree)
{
    file* f = nullptr;
    TreeIterator<file*>* iter = nullptr;
    int pos = 0;
    
    //while there is a tag to read
    while (pos < data.length())
    {
        //find next tag
        pos = data.find('<', pos);
        int end = data.find('>', pos);
        //get tag
        string tag = data.substr(pos + 1, end - pos - 1);

        //if tag is dir
        if (tag == "dir")
        {
            //create new file
            f = new file();
            //set file type to dir
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
        else if (tag == "/dir")
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
            pos = data.find('>', nextOpen) - 1;
        }
        else if (tag == "length")
        {
            //find next tag
            int nextOpen = data.find('<', end);
            //get & set size
            string size = data.substr(end + 1, nextOpen - end);
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
    }
}

// line function
void line()
{
    cout << "----------------------------------------" << endl;
}

int numInFolder(Tree<file*>* tree)
{
    int count = 0;
    count = tree->count();
    return count;
}

// function to determine
Tree<file*>* findFile(Tree<file*>* tree, string name)
{
    //create child node
    Tree<file*>* node = nullptr;
    //create iterator for tree
    TreeIterator<file*>* iter = new TreeIterator<file*>(tree);
    //check if current node is folder
    if (iter->item()->type == "dir" && iter->item()->name == name)
    {
        //if yes return node
        return iter->node;
    }
    else
    {
        //else check if child is valid
        while (iter->childValid())
            {
                //check if child is folder
                node = findFile(iter->childIter.currentNode->data, name);
                //move to next child
                if(node!=nullptr)
                {
                    break;
                }
                iter->childForth();
            }
    }
    //return node
    return node;
}

// function to determine amount of memory used by a given folder using a breadth first algorithm
int memUsed(Tree<file*>* tree)
{
    int mem = 0;
    //create queue
    queue<Tree<file*>*> queue;
    //add tree to queue
    queue.push(tree);
    //while queue is not empty
    while (!queue.empty())
    {
        //create iterator for tree
        DListIterator<Tree<file*>*> iter = queue.front()->children->getIterator();
        //while iterator is valid
        while (iter.isValid())
        {
            //add child to queue
            queue.push(iter.item());
            //move to next child
            iter.advance();
        }
        //add size of file to mem
        mem += queue.front()->data->size;
        //remove tree from queue
        queue.pop();
    }
    //return mem
    return mem;
}

// function to prune the tree to remove empty folders

bool pruneTree(TreeIterator<file*> iter)
{
    if(!iter.childValid() && iter.item()->type == "dir")
    {
        return true;
    }
    while (iter.childValid())
    {
        TreeIterator<file*> child(iter);
        child.down();
        if(pruneTree(child))
        {
            iter.removeChild();
        }
        iter.childForth();
    }
    iter.resetIterator();
    if(!iter.childValid() && iter.item()->type == "dir")
    {
        return true;
    }
    return false;        
}

// function to find file given a partial or complete filename (no path). Generate the path for the given file/folder (Depth first Search)
bool getFile(string& search, TreeIterator<file*> iter, string& path, bool isTop)
{
    bool found = false;
    if (iter.item()->name == search)
    {
        if(isTop)
            path += iter.item()->name;
        else
            path += "/" + iter.item()->name;
        return true;
    }
    while (iter.childValid())
    {
        TreeIterator<file*> child(iter);
        child.down();
        found = getFile(search, child, path, false);
        if(found)
        {
            if(isTop)
                path += iter.item()->name ;
            else
                path += "/" + iter.item()->name ;
            return true;
        }
        iter.childForth();
    }
    return false;    
}

// function to display the contents of a given folder. The output should also include the size of files (Not folders)
void displayFolder(TreeIterator<file*> iter, string indent)
{
    if (iter.item()->type != "dir")
    {
        //cout << indent << toString(iter.node->data) << endl ;
        //display size
        cout << indent << "Size: " << getSize(iter.node->data) << " b" << endl;
    }
    if (iter.childValid()) 
    {
        while (iter.childValid())
        {
            TreeIterator<file*> iter2(iter.childIter.currentNode->data);
            displayFolder(iter2, "\t" + indent);
            iter.childForth();
        }
    }
}


int main()
{
    int choice = 0;
    //ask what file to read
    cout << "Chose file to read: " << endl;
    cout << "1. vs_sample.xml" << endl;
    cout << "2. vs_sample_simple.xml" << endl;
    cin >> choice;
    string fpath = "";
    if (choice == 1)
    {
        fpath = "C:/Users/jackw/Documents/AlgorithmsCA/ADS_2023_CA2_JW/ADS_CA2_JackW_XMLFileReader/Files/vs_sample.xml";
    }
    else if (choice == 2)
    {
        fpath = "C:/Users/jackw/Documents/AlgorithmsCA/ADS_2023_CA2_JW/ADS_CA2_JackW_XMLFileReader/Files/vs_sample_simple.xml";
    }
    else
    {
        cout << "Invalid choice" << endl;
        return 0;
    }
    
     string fname = getFileName(fpath);
    
    string fData = fileToString(fpath);

    // run file through stack to verify xml is valid
    if (isBalanced(fData)) {
        cout << "file is balanced" << endl;
    } 
    else
    {
        cout << "file is not balanced" << endl;
    }

    //new file
    file* f = new file(); 
    //set file name to fname
    f->name = fname; 
     
    Tree<file*>* tree = nullptr; 
    treeGen(fData, tree);

    //create iterator
    TreeIterator<file*> iter = TreeIterator<file*>(tree);

    
    cout << "display" << endl;
    //display tree
    displayTree(iter,"");

    /*
    //print using DFS
    cout << "DFS: " << endl;
    printDFS(iter);
    cout << endl;
    //print using BFS
    cout << "BFS: " << endl;
    printBFS(*tree);
    cout << endl;
    */
    
    line();
    cout << "1. Determine the number of items (Files or folders) within a given folder directory" << endl;
    string folder = "";
    cout << "Enter folder name: " << endl;
    cin >> folder;
    cout << "Number of items in " << folder << ": " << numInFolder(findFile(tree, folder)) << endl;

    line();
    cout << "2. Determine the amount of memory used by a given folder using a breadth first algorithm" << endl;
    cout << "Enter folder name: " << endl;
    cin >> folder;
    cout << "Memory used by " << folder << ": " << memUsed(findFile(tree, folder)) << " b" << endl;

    line();
    cout << "3. Prune the tree to remove empty folders" << endl;
    pruneTree(iter);
    //display tree
    displayTree(iter,"");
    
    line();
    cout << "4. Find a given file/folder given a partial or complete filename (no path). Generate the" << endl;
    //path for the given file/folder (Depth first Search)
    string file = "";
    cout << "Enter file name: " << endl;
    cin >> file;
    cout << "find file: " << file << endl;
    string path = "";
    getFile(file, iter, path, false);
    cout << "path: " << path << endl;
    

    line();
    cout << "5. Display the contents of a given folder. The output should also include the size of files (Not folders) "<< endl;
    cout << "Enter folder name: " << endl;
    cin >> folder;
    cout << "display folder :" << folder << " file sizes" << endl;
    displayFolder(findFile(tree, folder), "");
    
    return 1;
}

