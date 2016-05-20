#include <iostream>
#include <fstream>
#include <string.h>
#include "defineRubik.h"
using namespace std;

int main(){
   Rubik rubik, aux;
   ofstream os;
   vector<char> solution;
   bool boolean = true;

	for (unsigned int j=0; j<100000 && boolean; j++){
	   os.close();
	   os.open("error.dat");
      aux = rubik = randomRubik();
      //cout << rubik;

      rubik.solve(solution);
		if(!rubik.isSolved()){
			boolean = false;
         aux.exportRubik(os);
      }
   }
   if (!boolean)
      cout << "Errors..." << endl;

   cout << endl;
}
