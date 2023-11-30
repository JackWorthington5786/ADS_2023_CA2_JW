# ADS_CA2_JackW_XMLFileReader
Each student is required to develop a file management system to allow users to view, retrieve
and remove files and folders from a Tree data structure. The solution must load in the file system
from an XML document after validating that the XML document is valid (see XML Validation for
the definition of a valid XML document).
The project should be developed in 3 stages:
1. Load the XML document into the Tree data structure (Including validation)
2. Implement the main functionality using the Tree data structure created in part 1
3. Develop a GUI for your solution using SFML
Github should be used regularly throughout the project and all functionality in stages 1 and 2
should be thoroughly unit tested.
Stage 1
(15 Marks)
Given an xml document containing a file tree, load the data into a tree data structure. The
structure of the XML document is as follows:
To validate the XML document the following rules must apply:
• XML documents must have a root element
• XML elements must have a closing tag
• XML elements must be properly nested
The validation should be implemented using a stack data structure.
Stage 2:
(60 Marks)
Using the tree created in part 1, write a command line application to allow the user to complete
the following tasks
a. Determine the number of items (Files or folders) within a given folder directory
(5 Marks)
b. Determine the amount of memory used by a given folder using a breadth first
algorithm.
(15 Marks)
c. Prune the tree to remove empty folders
(15 Marks)
d. Find a given file/folder given a partial or complete filename (no path). Generate the
path for the given file/folder (Depth first Search)
(15 Marks)
e. Display the contents of a given folder. The output should also include the size of files
(Not folders)
(10 Marks)
Stage 3:
(10 Marks)
For this stage you are required to implement a GUI using SFML. The overall look and feel of the UI
is up to you but you should ensure that all functionality described in stage 2 is available.
Note: You should only attempt this stage once all previous stages have been complete.
Unit Testing Requirements:
(10 Marks)
For this project you are required to follow a strict Test Driven Development (TDD) approach. This
means writing stubs for your classes and functions, writing a test, running the test, failing, refactoring your code, and re-running the test until success. For each function outlined in this
document should be thoroughly tested and
Note: Your project will NOT be graded in the absence of this requirement.
Repository & Design Requirements:
You are required to create a GitHub student repository for your project. This project must
have the following properties:
• Name format (i.e. “ADS_2023_CA2_studentinitials1_studentinitials2”)
• The project repository must be shared (read access) with your lecturer(s) on the
module.
You will be awarded a maximum of 5 marks for the regularity and commenting (clarity,
use of illustrative emojis) of your project commits.
Note: Your project will NOT be graded in the absence of this requirement.
(5 Marks)
Submission Requirements:
1) Source code must be submitted via a README containing a single link to your
GitHub repo.
2) The assignment must be entirely the work of each student group. Students are not
permitted to share any pseudocode or source code from their solution with any other
individual or group in the class. Students may not distribute the source code of their
solution to any student outside of their group in any format (i.e. electronic, verbal, or
hardcopy transmission).
3) Plagiarised assignments will receive a mark of zero. This also applies to the
individual/group allowing their work to be plagiarised.
4) Any plagiarism will be reported to the Head of Department and a report will be added
to your permanent academic record.
5) Late assignments will only be accepted if accompanied by the appropriate medical note.
This documentation must be received within 10 working days of the project deadline.
The penalty for late submission is as follows:
• Marked out of 80% if up to 24 hours late.
• Marked out of 60% if 24-48 hours late.
• Marked out of 40% if 48-72 hours late.
• Marked out of 20% if 72-96 hours late.
• Marked out of 0%, if over 96 hours late.
6) Each student group must complete and sign a single assignment cover sheet. Please
submit the signed cover sheet (via email) before 5 pm on the Friday of the week of the
deadline.
7) An interview will take place to assess the student’s work on this project. This interview
will be scheduled within 10 working days of the project deadline. Failure to attend
this interview will result in a grade of 0% in this component. Your final grade is
directly related to your performance in this interview. Each student will be asked
several questions related to the concepts covered in, and their contribution to, the
project. Failure to adequately answer a question will result in a penalty applied to the
final mark for that student.
