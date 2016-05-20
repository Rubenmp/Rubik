#include <iostream>
#include <fstream>
#include <stdlib.h>     /* abs */
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
   int number;
   char character, c;
   vector<char> solution;

   presentation();
   cout << "We want: \n";
   rubik.printAll();
   cout << endl;

   if ( argc == 1 ) {
      do{
         cout << endl << "\t";
         printf (BT BLUE "Select an option: " RESET "\n");
         cout << "\t1. Presentation\n";
         cout << "\t2. Guide of the program\n";
         cout << "\t3. Explain movements\n";
         cout << "\t4. Example of a valid file of a rubik's cube\n";
         cout << "\t5. Example of resolution of a random rubik's cube\n";
         cout << "\t6. Arguments with terminal\n";
         cout << "\t7. --> Start to solve a rubik's cube\n";
         cout << "\t8. --> Exit\n";

         do{
            cout << "\n\t";
            cin >> c;
            if (c < '0' || c > '8'){
               cout << "Invalid number" << endl;
               cin.ignore(1024, '\n');
            }
         }while(c < '0' || c > '9');
         number = atoi(&c);

         if (number == 1){
            cout << endl << "\t";
            printf(GREEN "1. Presentation:" RESET "\n");
            presentation();
         }
         else if (number == 2){
            cout << endl << "\t";
            printf(GREEN "2. Guide of the program:" RESET "\n");
            guide();
         }
         else if (number == 3){
            cout << endl << "\t";
            printf(GREEN "3. Explain movements:" RESET "\n");
            movements();
         }
         else if (number == 4){
            cout << endl << "\t";
            printf(GREEN "4.  Example of a valid file of a rubik's cube:" RESET "\n");
            fileExample();

            cout << "\n\n\tLetters can be in capital letters, lowercase or number in [1, 6].";
            cout << "\n\tEach line is a face of rubik's cube, the program read from ";
            cout << "left to right \n\tand from top to bottom without spaces, tabulator";
            cout << "or new lines.";
            cout << "\n\tEach face is read: top three colours, middle, and down colours.";
            cout << endl << "\t1 2 3\n\t4 5 6\n\t7 8 9" << endl;
            cout << "\tOrder: top, left, frontal, right, back and down faces." << endl;
         }
         else if (number == 5){
            Rubik aux;
            bool boolean= true;
            cout << endl << "\t";
            printf(GREEN "5. Example of resolution of a random rubik's cube:" RESET "\n");

            while (boolean){
               rubik = randomRubik();
               aux = rubik;

               rubik.solve(solution);
               if (rubik.isSolved())
                  boolean= false;
            }

            cout << aux << endl;
            cout << "Solution: ";


            //cout << solution.size();
            for (unsigned int i=0; i<solution.size(); ++i)
               cout << solution[i];

            cout << endl << endl << rubik << endl;
            cout << "(If you want you will have the option of step by step ";
            cout << "solution with explanations\n";
         }
         else if (number == 6){
            cout << endl << "\t";
            printf(GREEN "7. Arguments with terminal:" RESET "\n");
            arguments();
         }
         else if (number == 8)
            return 1;

         cout << endl;
      }while(number != 7);

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
         	cout << "Create an file \"./data/rubik.dat\" with colours in valid order.\n";
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
      }
      else{
   	   cout << "Reading rubik's cube...\n";
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
   // ---------------- Two arguments ------------------
   else if (argc == 2){
      ifstream file(argv[1]);
      if (!file) {
         cerr << "Error, not readable file " << argv[1] <<endl;
         return 1;
      }
      else{
         file >> rubik;
         rubik.printAll();

         do{
            cout << "Do you want to correct any position (y/Y) | (n/N)?\n";
            cin >> character;
         }while (tolower(character) != 'y' && tolower(character) != 'n');

         if (tolower(character) == 'y')
            rubik.correctMistakes();

         rubik.solveStepByStep(solution);
      }
   }
   // ---------------- Three arguments ------------------
   else if (argc == 3){
      ifstream file(argv[1]);
      ofstream outFile(argv[2]);
      Rubik auxiliar;
      if (!file) {
         cerr << "Error: not readable " << argv[1] <<endl;
         return 1;
      }
      else{
         file >> rubik;
         auxiliar = rubik;
         outFile << rubik;
         rubik.solve(solution);
         rubik.exportSolution(solution, outFile);
         outFile << rubik;
      }
      do{
         cout << "Do you want to see the sequence in terminal (y/Y)|(n/N)?\n";
         cin >> character;
      }while (tolower(character) != 'y' && tolower(character) != 'n');

      if (tolower(character) == 'y')
         auxiliar.solveStepByStep(solution);
   }
   else{
      cout << "Invalid number of arguments.\n";
      return 1;
   }

   cout << endl;
   return 0;
}
