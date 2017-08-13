#include <iostream>
#include <fstream>
#include <string.h>
#include "defineRubik.h"
using namespace std;

int main(int argc, char* argv[]){
   Rubik rubik, aux;
   ofstream os;
   vector<char> solution;
   bool boolean = true;
   string file;
   int i = 1;

   if (argv[1][0] == '-' && argv[1][1] == 's' && argc == 2){ // Search mode
     for (unsigned int j=0; j<100000 && boolean; j++){
       aux = rubik = Rubik::randomRubik();
       
       rubik.solve(solution);
       if(!rubik.isSolved()){
         file += "./data/error" + i;
         os.open(file);
         
         // Original rubik is solved, we want original positions to debug
         os << aux;
         os.close();

         file = "";
         boolean = false;
         ++i;
       }
     }
     if (!boolean)
       cout << "There are bugs :D" << endl;
     else
       cout << "There aren't any bugs" << endl;
   }
   else{ // Fix bugs mode
     ifstream is(argv[1]);

     is >> rubik;
     cout << rubik;

     rubik.solveStepByStep(solution);
     cout << rubik;
   }
   
   cout << endl;
}
