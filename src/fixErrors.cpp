#include <iostream>
#include <fstream>
#include <string.h>
#include "defineRubik.h"
using namespace std;

int main(){
   Rubik rubik;
   ifstream is("./data/error.dat");
   vector<char> solution;

   is >> rubik;
   cout << rubik;

   rubik.solveStepByStep(solution);
   cout << rubik;

   cout << endl;
}
