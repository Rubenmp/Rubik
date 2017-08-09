#include <iostream>
#include <fstream>
#include <stdlib.h>     /* abs */
//#include <cstdlib>
#include <string.h>
#include <vector>
#include "defineRubik.h"
using namespace std;

#define RESET             "\x1b[0m"
#define BT                "\x1b[1m"
#define INTERMITENT       "\x1b[42m"
#define BLUE              "\x1b[34m"
#define GREEN             "\x1b[42m"

int main(int argc, char* argv[]){
   Rubik rubik;
   char character;
   vector<char> solution;
   // Options
   
   if ( argc == 1 ) {
     arguments(argv[0]);
     return 1;    
   }
   else if (argc <= 4){
     // Probably there are better implementations to handle options
     if (argv[1][0] == '-'){
       if (strlen(argv[1]) != 2){
         cerr << "Error: too many options " << argv[1] << endl;
         return 1;
       }
       else if (argv[1][1] == 's' && argc == 3){
         ifstream is;
         is.open(argv[2]);
         
         if (!is){
           cerr << "Error: not readable file " << argv[2] << endl;
           return 1;
         }
         is >> rubik; // Read cube
         if (rubik.isSolved())
           cout << "y" << endl;
         else
           cout << "n" << endl;
       }
       else{ // See options
         if (argv[1][1] == 'e')
           Rubik::fileExample();
         else if (argv[1][1] == 'h')
           arguments(argv[0]);
         else if (argv[1][1] == 'i'){
           char entry;
           do{
             cout << "Do you want to read of an file (1) or keyboard (2).\n";
             cin >> entry;
             cin.ignore(1024, '\n');
           }while(entry != '1' && entry != '2');
           
           if (entry == '1'){
             bool repeat = true;
             char anyKey[100];
             ifstream is;
             
             while (repeat){
               strcpy(anyKey, "");
               cout << "Create a file \"./data/rubik.dat\" with colours in valid order (see -e for explanation of valid file).\n";
               cout << "Press any key to continue.\n";
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
             cout << "Reading rubik's cube in terminal (not recommended):\n";
             cin >> rubik;
           }
           
           rubik.printAll();
           do{
             cout << "Do you want to correct any position (y/Y) | (n/N)?\n";
             cin >> character;
           }while (tolower(character) != 'y' && tolower(character) != 'n');
           
           if (tolower(character) == 'y')
             rubik.correctMistakes();
           
           rubik.solveStepByStep(solution);
         }
         else if (argv[1][1] == 'm') // Explain movements
           movements();
         else if (argv[1][1] == 'R'){ // Random solution
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
         else if (argv[1][1] == 'r'){ // Random Rubik's cube
           rubik = Rubik::randomRubik();
           rubik.exportRubik();
         }
         else{
           if (argv[1][1] == 's'){
             cerr << "Error: -s option needs extra argument <input_file>" << endl;
             return 1;
           }
           else{
             cerr << "Error: invalid argument" << endl;
             return 1;
           }
         }
       }
     }
     else{ // Files configuration
       ifstream file(argv[1]);
       if (!file) {
         cerr << "Error: not readable file " << argv[1] << endl;
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
             rubik.exportSolution(outFile);
             outFile.close();
           }
           else{
             cerr << "Error: can not open " << argv[2] << ".\n";
             return 1;
           }
         }
         else{
           cerr << "Error: invalid arguments, -h for help.\n";
           return 1;
         }        
       }
     }
   }
   else{
      cerr << "Error: invalid number of arguments.\n";
      return 1;
   }

   flush(cout);
   return 0;
}
