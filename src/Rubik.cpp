#include <iostream>
#include <fstream>
#include <stdlib.h>     /* abs */
#include <string.h>
#include <vector>
#include "defineRubik.h"
using namespace std;


int main(int argc, char* argv[]){
   Rubik rubik;
   char character;
   vector<char> solution;

   // Options
   if (argc == 1) {
     // Print help and exit
     arguments(argv[0]);
     return 1;    
   }
   else if (argc <= 4){
     // Probably there are better implementations to handle options
     if (argv[1][0] == '-'){
       if (strlen(argv[1]) != 2){ // Two or more options
         if (argv[1][1] == 'M'){ // Execute movement
           ifstream is;
           is.open(argv[2]);
         
           if (!is){
             cerr << "Error: not readable file " << argv[2] << "." << endl;
             return 1;
           }
           is >> rubik; // Read cube
           is.close();

           char mov = argv[1][2];
           if (mov == 'F')
             rubik.F(solution);
           else if (mov == 'f')
             rubik.f(solution);
           else if (mov == 'B')
             rubik.B(solution);
           else if (mov == 'b')
             rubik.b(solution);
           else if (mov == 'R')
             rubik.R(solution);
           else if (mov == 'r')
             rubik.r(solution);
           else if (mov == 'L')
             rubik.L(solution);
           else if (mov == 'l')
             rubik.l(solution);
           else if (mov == 'U')
             rubik.U(solution);
           else if (mov == 'u')
             rubik.u(solution);
           else if (mov == 'D')
             rubik.D(solution);
           else if (mov == 'd')
             rubik.d(solution);
           else{
             cerr << "Error: invalid movement (" << mov << ") to execute." << endl;
             return 1;
           }
           ofstream os;
           os.open(argv[2]);
           
           if (!os){
             cerr << "Error: not writable file " << argv[2] << endl;
             return 1;
           }
           os << rubik; // Write cube
           os.close();
         }
         else{
           cerr << "Error: too many options " << argv[1] << endl;
           return 1;
         }
       }
       else if ((argv[1][1] == 's' || argv[1][1] == 'p') && argc == 3){
         ifstream is;
         is.open(argv[2]);
         
         if (!is){
           cerr << "Error: not readable file " << argv[2] << endl;
           return 1;
         }
         is >> rubik; // Read cube
         is.close();
         if (argv[1][1] == 's'){
           if (rubik.isSolved())
             cout << "y" << endl;
           else
             cout << "n" << endl;
         }
         else
           rubik.printAll();
       }
       else{ // See options
         if (argv[1][1] == 'e') // Example
           Rubik::fileExample();
         else if (argv[1][1] == 'h') // Help
           arguments(argv[0]);
         else if (argv[1][1] == 'i'){ // Interactive mode
           char entry;
           do{
             cout << "Do you want to read of an file (1) or keyboard (2)." << endl;
             cin >> entry;
             cin.ignore(1024, '\n');
           }while(entry != '1' && entry != '2');
           
           if (entry == '1'){
             bool repeat = true;
             char anyKey[100];
             ifstream is;
             
             while (repeat){
               strcpy(anyKey, "");
               cout << "Create a file \"./data/rubik.dat\" with colours in valid order (see -e for explanation of valid file). ";
               cout << "Press any key to continue." << endl;
               cin.getline(anyKey, '\n');
               is.open("./data/rubik.dat");
               if (is)
                 repeat = false;
               else
                 cout << "It's imposible open \"./data/rubik.dat\"" << endl;
               
               is.close();
             }
             
             is.open("./data/rubik.dat");
             is >> rubik;
             is.close();
           }
           else{
             cout << "Reading rubik's cube in terminal (not recommended):" << endl;
             cin >> rubik;
           }
           
           rubik.printAll();
           do{
             cout << "Do you want to correct any position [y/n]?" << endl;
             cin >> character;
           }while (tolower(character) != 'y' && tolower(character) != 'n');
           
           if (tolower(character) == 'y')
             rubik.correctMistakes();
           
           rubik.solveStepByStep(solution);
         }
         else if (argv[1][1] == 'm') // Explain movements
           movements();
         else if (argv[1][1] == 'r'){ // Random solution
           bool boolean = true;
           Rubik aux;
           while (boolean){
             /*
               This is a trick, it will not fail ever... or you will not notice
               (Supposedly it will never repeat the loop if program is correct)
              */
             rubik = Rubik::randomRubik();
             aux = rubik;
             rubik.solve(solution);
             
             if (rubik.isSolved())
               boolean = false;
           }
           aux.printAll();
           cout << endl;
           cout << "Solution: ";
           for (unsigned int i=0; i<solution.size(); ++i)
             cout << solution[i];

           cout << endl << endl;
           rubik.printAll();
           cout << endl;
         }
         else if (argv[1][1] == 'R') // Random Rubik's cube
           cout << Rubik::randomRubik();
         else{
           if (argv[1][1] == 's'){
             cerr << "Error: -s option needs extra argument <input_file>." << endl;
             return 1;
           }
           else{
             cerr << "Error: invalid argument '" << argv[1][1] << "'." << endl;
             return 1;
           }
         }
       }
     }
     else if (argc <= 3) { // Files configuration
       ifstream file;
       file.open(argv[1]);
       if (!file) {
         cerr << "Error: not readable file " << argv[1] << "." << endl;
         return 1;
       }
       else{
         file >> rubik;
         file.close();
         rubik.solve(solution);
         
         if (argc == 2){
           for (unsigned int i=0; i<solution.size(); ++i)
             cout << solution[i];
           cout << endl;
         }
         else if (argc == 3){
           ofstream outFile(argv[2]);
           if (outFile.is_open()) {
             for (unsigned int i=0; i<solution.size(); ++i)
               outFile << solution[i];
             outFile << endl;
             outFile.close();
           }
           else{
             cerr << "Error: can not open " << argv[2] << "." << endl;
             return 1;
           }
         }
         else{
           cerr << "Error: invalid arguments, -h for help." << endl;
           return 1;
         }        
       }
     }
   }  
   else{
     cerr << "Error: invalid number of arguments." << endl;
     return 1;
   }

   return 0;
}
