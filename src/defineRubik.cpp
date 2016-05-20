#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <vector>
#include "defineRubik.h"
using namespace std;

#define RESET         "\x1b[0m"
#define RED           "\x1b[31m"
#define GREEN         "\x1b[32m"
#define YELLOW        "\x1b[33m"
#define BLUE          "\x1b[34m"
#define WHITE         "\x1b[37m"
#define BLACK         "\x1b[30m"
#define BT_ON         "\x1b[1m"
#define INTERMITTENT  "\x1b[42m"



// Auxiliary functions
void Rubik::explainMovements(vector<char> &solution, unsigned int& movement) const{
   while (movement <= (solution.size()-1)){
      cout << "- (" << movement + 1 << ") ";
      if (solution[movement] == 'F')
	      cout << "F --> Move frontal side in clockwise.\n\n";
      else if (solution[movement] == 'f')
	      cout << "f --> Move frontal side, not in clockwise.\n\n";
      else if (solution[movement] == 'W')
	      cout << "B --> Move back side left.\n\n";
      else if (solution[movement] == 'w')
	      cout << "b --> Move back side right.\n\n";
      else if (solution[movement] == 'R')
	      cout << "R --> Move right side backward.\n\n";
      else if (solution[movement] == 'r')
	      cout << "r --> Move right side to you.\n\n";
      else if (solution[movement] == 'L')
	      cout << "L --> Move left side to you.\n\n";
      else if (solution[movement] == 'l')
	      cout << "l --> Move left side backward.\n\n";
      else if (solution[movement] == 'U')
	      cout << "U --> Move top side left.\n\n";
      else if (solution[movement] == 'u')
         cout << "u --> Move top side right.\n\n";
      else if (solution[movement] == 'D')
	      cout << "D --> Move down side right.\n\n";
      else if (solution[movement] == 'd')
	      cout << "d --> Move down side left.\n\n";

	   movement++;
   }

}
int Rubik::equivalentNumber(const char &c) const{
   int number = 0;
   if (tolower(c) == 'w')
      number = 1;
   else if (tolower(c) == 'o')
      number = 2;
   else if (tolower(c) == 'g')
      number = 3;
   else if (tolower(c) == 'r')
      number = 4;
   else if (tolower(c) == 'l')
      number = 5;
   else if (tolower(c) == 'y')
      number = 6;

  return number;
}
int Rubik::searchEdge(char ar, char ab) const{
   int position;
   if( (side[0].up == ar && side[0].down == ab) || (side[0].up == ab && side[0].down == ar) )
      position = 0;
   else if( (side[1].up == ar && side[1].down == ab) || (side[1].up == ab && side[1].down == ar) )
      position = 1;
   else if( (side[2].up == ar && side[2].down == ab) || (side[2].up == ab && side[2].down == ar) )
      position = 2;
   else if( (side[3].up == ar && side[3].down == ab) || (side[3].up == ab && side[3].down == ar) )
      position = 3;
   else if( (side[4].up == ar && side[4].down == ab) || (side[4].up == ab && side[4].down == ar) )
      position = 4;
   else if( (side[5].up == ar && side[5].down == ab) || (side[5].up == ab && side[5].down == ar) )
      position = 5;
   else if( (side[6].up == ar && side[6].down == ab) || (side[6].up == ab && side[6].down == ar) )
      position = 6;
   else if( (side[7].up == ar && side[7].down == ab) || (side[7].up == ab && side[7].down == ar) )
      position = 7;
   else if( (side[8].up == ar && side[8].down == ab) || (side[8].up == ab && side[8].down == ar) )
      position = 8;
   else if( (side[9].up == ar && side[9].down == ab) || (side[9].up == ab && side[9].down == ar) )
      position = 9;
   else if( (side[10].up == ar && side[10].down == ab) || (side[10].up == ab && side[10].down == ar) )
      position = 10;
   else if( (side[11].up == ar && side[11].down == ab) || (side[11].up == ab && side[11].down == ar) )
      position = 11;

   return position;
}
int Rubik::searchCorner(char a, char iz, char de) const{
   int position;
   if ( ( (corner[0].up == a) && (corner[0].left == iz) && (corner[0].right == de) ) ||
             ( (corner[0].up == a) && (corner[0].left == de) && (corner[0].right == iz) ) ||
             ( (corner[0].up == iz) && (corner[0].left == a) && (corner[0].right == de) ) ||
             ( (corner[0].up == de) && (corner[0].left == iz) && (corner[0].right == a) ) ||
             ( (corner[0].up == de) && (corner[0].left == a) && (corner[0].right == iz) ) ||
             ( (corner[0].up == iz) && (corner[0].left == de) && (corner[0].right == a) ) )
      position = 0;
   else if ( ( (corner[1].up == a) && (corner[1].left == iz) && (corner[1].right == de) ) ||
             ( (corner[1].up == a) && (corner[1].left == de) && (corner[1].right == iz) ) ||
             ( (corner[1].up == iz) && (corner[1].left == a) && (corner[1].right == de) ) ||
             ( (corner[1].up == de) && (corner[1].left == iz) && (corner[1].right == a) ) ||
             ( (corner[1].up == de) && (corner[1].left == a) && (corner[1].right == iz) ) ||
             ( (corner[1].up == iz) && (corner[1].left == de) && (corner[1].right == a) ) )
      position = 1;
   else if ( ( (corner[2].up == a) && (corner[2].left == iz) && (corner[2].right == de) ) ||
             ( (corner[2].up == a) && (corner[2].left == de) && (corner[2].right == iz) ) ||
             ( (corner[2].up == iz) && (corner[2].left == a) && (corner[2].right == de) ) ||
             ( (corner[2].up == de) && (corner[2].left == iz) && (corner[2].right == a) ) ||
             ( (corner[2].up == de) && (corner[2].left == a) && (corner[2].right == iz) ) ||
             ( (corner[2].up == iz) && (corner[2].left == de) && (corner[2].right == a) ) )
      position = 2;
   else if ( ( (corner[3].up == a) && (corner[3].left == iz) && (corner[3].right == de) ) ||
             ( (corner[3].up == a) && (corner[3].left == de) && (corner[3].right == iz) ) ||
             ( (corner[3].up == iz) && (corner[3].left == a) && (corner[3].right == de) ) ||
             ( (corner[3].up == de) && (corner[3].left == iz) && (corner[3].right == a) ) ||
             ( (corner[3].up == de) && (corner[3].left == a) && (corner[3].right == iz) ) ||
             ( (corner[3].up == iz) && (corner[3].left == de) && (corner[3].right == a) ) )
      position = 3;
   else if ( ( (corner[4].up == a) && (corner[4].left == iz) && (corner[4].right == de) ) ||
             ( (corner[4].up == a) && (corner[4].left == de) && (corner[4].right == iz) ) ||
             ( (corner[4].up == iz) && (corner[4].left == a) && (corner[4].right == de) ) ||
             ( (corner[4].up == de) && (corner[4].left == iz) && (corner[4].right == a) ) ||
             ( (corner[4].up == de) && (corner[4].left == a) && (corner[4].right == iz) ) ||
             ( (corner[4].up == iz) && (corner[4].left == de) && (corner[4].right == a) ) )
      position = 4;
   else if ( ( (corner[5].up == a) && (corner[5].left == iz) && (corner[5].right == de) ) ||
             ( (corner[5].up == a) && (corner[5].left == de) && (corner[5].right == iz) ) ||
             ( (corner[5].up == iz) && (corner[5].left == a) && (corner[5].right == de) ) ||
             ( (corner[5].up == de) && (corner[5].left == iz) && (corner[5].right == a) ) ||
             ( (corner[5].up == de) && (corner[5].left == a) && (corner[5].right == iz) ) ||
             ( (corner[5].up == iz) && (corner[5].left == de) && (corner[5].right == a) ) )
      position = 5;
   else if ( ( (corner[6].up == a) && (corner[6].left == iz) && (corner[6].right == de) ) ||
             ( (corner[6].up == a) && (corner[6].left == de) && (corner[6].right == iz) ) ||
             ( (corner[6].up == iz) && (corner[6].left == a) && (corner[6].right == de) ) ||
             ( (corner[6].up == de) && (corner[6].left == iz) && (corner[6].right == a) ) ||
             ( (corner[6].up == de) && (corner[6].left == a) && (corner[6].right == iz) ) ||
             ( (corner[6].up == iz) && (corner[6].left == de) && (corner[6].right == a) ) )
      position = 6;
   else if ( ( (corner[7].up == a) && (corner[7].left == iz) && (corner[7].right == de) ) ||
             ( (corner[7].up == a) && (corner[7].left == de) && (corner[7].right == iz) ) ||
             ( (corner[7].up == iz) && (corner[7].left == a) && (corner[7].right == de) ) ||
             ( (corner[7].up == de) && (corner[7].left == iz) && (corner[7].right == a) ) ||
             ( (corner[7].up == de) && (corner[7].left == a) && (corner[7].right == iz) ) ||
             ( (corner[7].up == iz) && (corner[7].left == de) && (corner[7].right == a) ) )
      position = 7;
   else
      cout << "Problem with corner (" << a << "," << iz << "," << de << ").\n";
   return position;
}
void Rubik::sequence(string sec, vector<char> &solution){
   for (unsigned int i=0; i<sec.size(); ++i){
      if ( sec[i] == 'R' )
         R(solution);
      else if ( sec[i] == 'r')
         r(solution);
      else if ( sec[i] == 'L')
         L(solution);
      else if ( sec[i] == 'l')
         l(solution);
      else if ( sec[i] == 'D')
         D(solution);
      else if ( sec[i] == 'd')
         d(solution);
      else if ( sec[i] == 'U')
         U(solution);
      else if ( sec[i] == 'u')
         u(solution);
      else if ( sec[i] == 'F')
         F(solution);
      else if ( sec[i] == 'f')
         f(solution);
      else if ( sec[i] == 'B')
         B(solution);
      else if ( sec[i] == 'b')
         b(solution);
      else{
         ofstream of("fil.txt");
         of << sec[i];
      }

      cout << sec[i];
   }
   cout << endl;
}


// Parts of the solution
void Rubik::firstStep(vector<char> &solution){
   whiteCross(solution);
   cornersFirstStep(solution);
}
void Rubik::whiteCross(vector<char> &solution){
   int position = searchEdge('w', 'g'); // White, green.
   if (position == 0){
      if (side[0].down == 'w') // FuRU
         sequence("FuRU", solution);
   }
   else if (position == 1){
      if (side[1].up == 'w') // ruRU
         sequence("ruRU", solution);
      else // rf
         sequence("rf", solution);
   }
   else if (position == 2){
      if (side[2].up == 'w') // bR2f --> U2
         sequence("UU", solution);
      else // burU
         sequence("burU", solution);
   }
   else if (position == 3){
      if (side[3].up == 'w') // LUlu
         sequence("LUlu", solution);
      else // LF
         sequence("LF", solution);
   }
   else if (position == 4){
      if (side[4].up == 'w') // F2
         F2(solution);
      else // fuRU
         sequence("fuRU", solution);
   }
   else if (position == 5){
      if (side[5].up == 'w') // dF2
         sequence("dFF", solution);
      else // Rf
         sequence("Rf", solution);
   }
   else if (position == 6){
      if (side[6].up == 'w') // D2F2
         sequence("DDFF", solution);
      else // dRf
         sequence("dRf", solution);
   }
   else if (position == 7){
      if (side[7].up == 'w') // DF2
         sequence("DFF", solution);
      else // lF
         sequence("lF", solution);
   }
   else if (position == 8){
      if (side[8].up == 'w') // uRU
         sequence("uRU", solution);
      else // f
         sequence("f", solution);
   }
   else if (position == 9){
      if (side[9].up == 'w') // urU
         sequence("urU", solution);
      else // U2BU2
         sequence("UUBUU", solution);
   }
   else if (position == 10){
      if (side[10].up == 'w') // ULu
         sequence("ULu", solution);
      else // U2bU2
         sequence("UUbUU", solution);
   }
   else if (position == 11){
      if (side[11].up == 'w') // Ulu
         sequence("Ulu", solution);
      else // F
         sequence("F", solution);
   }

   position = searchEdge('w', 'r'); // White/red
   if (position == 1){
      if (side[1].down == 'w') // rUfu
         sequence("rUfu", solution);
   }
   else if (position == 2){
      if (side[2].up == 'w') // buBU
         sequence("buBU", solution);
      else // br
         sequence("br", solution);
   }
   else if (position == 3){
      if (side[3].up == 'w') // L2D2R2
         sequence("LLDDRR", solution);
      else // LUFu
         sequence("LUFu", solution);
   }
   else if (position == 4){
      if (side[4].up == 'w') // DR2
         sequence("DRR", solution);
      else // fRF
         sequence("fRF", solution);
   }
   else if (position == 5){
      if (side[5].up == 'w') // R2
         R2(solution);
      else // RUfu
         sequence("RUfu", solution);
   }
   else if (position == 6){
      if (side[6].up == 'w') // dR2
         sequence("dRR", solution);
      else // Br
         sequence("Br", solution);
   }
   else if (position == 7){
      if (side[7].up == 'w') // D2R2
         sequence("DDRR", solution);
      else // lUFu
         sequence("lUFu", solution);
   }
   else if (position == 8){
      if (side[8].up == 'w') // R
         sequence("R", solution);
      else // Ufu
         sequence("Ufu", solution);
   }
   else if (position == 9){
      if (side[9].up == 'w') // r
         sequence("r", solution);
      else // uBU
         sequence("uBU", solution);
   }
   else if (position == 10){
      if (side[10].up == 'w') // U2LU2
         sequence("UULUU", solution);
      else // ubU
         sequence("ubU", solution);
   }
   else if (position == 11){
      if (side[11].up == 'w') // U2lU2
         sequence("UUlUU", solution);
      else // UFu
         sequence("UFu", solution);
   }


   position = searchEdge('w', 'l'); // White/blue
   if (position == 2){
      if (side[2].down == 'w') // bUru
         sequence("bUru", solution);
   }
   else if (position == 3){
      if (side[3].up == 'w') // LulU
         sequence("LulU", solution);
      else // lb
         sequence("lb", solution);
   }
   else if (position == 4){
      if (side[4].up == 'w') // D2B2
         sequence("DDBB", solution);
      else // uFlU
         sequence("uFlU", solution);
   }
   else if (position == 5){
      if (side[5].up == 'w') // DB2
         sequence("DBB", solution);
      else // rBR
         sequence("rBR", solution);
   }
   else if (position == 6){
      if (side[6].up == 'w') // B2
         B2(solution);
      else // BUru
         sequence("BUru", solution);
   }
   else if (position == 7){
      if (side[7].up == 'w') // dB2
         sequence("dBB", solution);
      else // Lb
         sequence("Lb", solution);
   }
   else if (position == 8){
      if (side[8].up == 'w') // URu
         sequence("URu", solution);
      else // U2fU2
         sequence("UUfUU", solution);
   }
   else if (position == 9){
      if (side[9].up == 'w') // Uru
         sequence("Uru", solution);
      else // B
         B(solution);
   }
   else if (position == 10){
      if (side[10].up == 'w') // uLU
         sequence("uLU", solution);
      else // b
         b(solution);
   }
   else if (position == 11){
      if (side[11].up == 'w') // ulU
         sequence("ulU", solution);
      else // U2FU2
         sequence("UUFUU", solution);
   }


   position = searchEdge('w', 'o'); // White/orange
   if (position == 3){
      if (side[3].down == 'w') // LuFU
         sequence("LuFU", solution);
   }
   else if (position == 4){
      if (side[4].up == 'w') // dL2
         sequence("dLL", solution);
      else // Flf
         sequence("Flf", solution);
   }
   else if (position == 5){
      if (side[5].up == 'w') // D2L2
         sequence("DDLL", solution);
      else // dFlf
         sequence("dFlf", solution);
   }
   else if (position == 6){
      if (side[6].up == 'w') // DL2
         sequence("DLL", solution);
      else // bLB
         sequence("bLB", solution);
   }
   else if (position == 7){
      if (side[7].up == 'w') // L2
         L2(solution);
      else // luFU
         sequence("luFU", solution);
   }
   else if (position == 8){
      if (side[8].up == 'w') // U2RU2
         sequence("UURUU", solution);
      else //ufU
         sequence("ufU", solution);
   }
   else if (position == 9){
      if (side[9].up == 'w') // U2rU2
         sequence("UUrUU", solution);
      else // UBu
         sequence("UBu", solution);
   }
   else if (position == 10){
      if (side[10].up == 'w') // L
         L(solution);
      else // Ubu
         sequence("Ubu", solution);
   }
   else if (position == 11){
      if (side[11].up == 'w') // l
         l(solution);
      else // uFU
         sequence("uFU", solution);
  }
}
void Rubik::cornersFirstStep(vector<char> &solution){
   int position = searchCorner('w', 'g', 'r'); // White, green and red
   if (position == 0){
      if (corner[0].up == 'w') // LDlrdR
         sequence("LDlrdR", solution);
      else if (corner[0].right == 'w') // LrD2lRFDf
         sequence("LrDDlRFDf", solution);
      else if (corner[0].left == 'w') // LrDlR
         sequence("LrDlR", solution);
   }
   else if (position == 1){
      if (corner[1].right == 'w') // rdRDrdR
         sequence("rdRDrdR", solution);
      else if (corner[1].left == 'w') // rDRFDf
         sequence("rDRFDf", solution);
   }
   else if (position == 2){
      if (corner[2].up == 'w') // bdBFDf
         sequence("bdBFDf", solution);
      else if (corner[2].right == 'w') // bFdBf
         sequence("bFdBf", solution);
      else if (corner[2].left == 'w') // bDBdFDf
         sequence("bDBdFDf", solution);
   }
   else if (position == 3){ // BD2brdR
      if (corner[3].up == 'w')
         sequence("BDDbrdR", solution);
      else if (corner[3].right == 'w') // lFD2fL
         sequence("lFDDfL", solution);
     else if (corner[3].left == 'w') // BrD2Rb
        sequence("BrDDRb", solution);
   }
   else if (position == 4){
      if (corner[4].up == 'w') // rD2RFDf
         sequence("rDDRFDf", solution);
      else if (corner[4].right == 'w') // DrdR
         sequence("DrdR", solution);
      else if (corner[4].left == 'w') // rDR
         sequence("rDR", solution);
   }
   else if (position == 5){
      if (corner[5].up == 'w') // rD2RDrdR
         sequence("rDDRDrdR", solution);
      else if (corner[5].right == 'w') // rdR
         sequence("rdR", solution);
      else if (corner[5].left == 'w') // FDf
         sequence("FDf", solution);
   }
   else if (position == 6){
      if (corner[6].up == 'w') // FD2frdR
         sequence("FDDfrdR", solution);
      else if (corner[6].right == 'w') // Fdf
         sequence("Fdf", solution);
     else if (corner[6].left == 'w') // dFDf
        sequence("dFDf", solution);
   }
   else if (position == 7){
      if (corner[7].up == 'w') // rdRFDf
         sequence("rdRFDf", solution);
      else if (corner[7].right == 'w') // FD2f
         sequence("FDDf", solution);
      else if (corner[7].left == 'w') // rD2R
         sequence("rDDR", solution);
   }



   position = searchCorner('w', 'r', 'l'); // White, red and blue
   if (position == 0){
      if (corner[0].up == 'w') // LD2lbdB
         sequence("LDDlbdB", solution);
      else if (corner[0].right == 'w') // fRD2rF
         sequence("fRDDrF", solution);
      else if (corner[0].left == 'w') // LbD2Bl
         sequence("LbDDBl", solution);
   }
   else if (position == 2){
      if (corner[2].right == 'w') // bdBDbdB
         sequence("bdBDbdB", solution);
      else if (corner[2].left == 'w') // bDBRDr
         sequence("bDBRDr", solution);
   }
   else if (position == 3){
      if (corner[3].up == 'w') // BDbRD2r
         sequence("BDbRDDr", solution);
      else if (corner[3].right == 'w') // lRdLr
         sequence("lRdLr", solution);
      else if (corner[3].left == 'w') // BDB2D2B
         sequence("BDBBDDB", solution);
   }
   else if (position == 4){
      if (corner[4].up == 'w') // bdBRDr
         sequence("bdBRDr", solution);
      else if (corner[4].right == 'w') // RD2r
         sequence("RDDr", solution);
      else if (corner[4].left == 'w') // bD2B
         sequence("bDDB", solution);
   }
   else if (position == 5){
      if (corner[5].up == 'w') // bD2BRDr
         sequence("bDDBRDr", solution);
      else if (corner[5].right == 'w') // DbdB
         sequence("DbdB", solution);
      else if (corner[5].left == 'w') // bDB
         sequence("bDB", solution);
   }
   else if (position == 6){
      if (corner[6].up == 'w') // bD2BDbdB
         sequence("bDDBDbdB", solution);
      else if (corner[6].right == 'w') // bdB
         sequence("bdB", solution);
      else if (corner[6].left == 'w') // RDr
         sequence("RDr", solution);
   }
   else if (position == 7){
      if (corner[7].up == 'w') // RD2rbdB
         sequence("RDDrbdB", solution);
      else if (corner[7].right == 'w') // Rdr
         sequence("Rdr", solution);
      else if (corner[7].left == 'w') // dRDr
         sequence("dRDr", solution);
   }


   position = searchCorner('w', 'l', 'o'); // White, blue and orange
   if (position == 0){
      if (corner[0].up == 'w') // fdFBDb
         sequence("fdFBDb", solution);
      else if (corner[0].right == 'w') // fBdFb
         sequence("fBdFb", solution);
      else if (corner[0].left == 'w') // fDFdBDb
         sequence("fDFdBDb", solution);
   }
   else if (position == 3){
      if (corner[3].right == 'w') // BdbldL
         sequence("BdbldL", solution);
      else if (corner[3].left == 'w') // BDbdBDb
         sequence("BDbdBDb", solution);
   }
   else if (position == 4){
      if (corner[4].up == 'w') // fBD2Fb
         sequence("fBDDFb", solution);
      else if (corner[4].right == 'w') // Bdb
         sequence("Bdb", solution);
      else if (corner[4].left == 'w') // dBDb
         sequence("dBDb", solution);
   }
   else if (position == 5){
      if (corner[5].up == 'w') // LD2lBdb
         sequence("LDDlBdb", solution);
      else if (corner[5].right == 'w') // BD2b
         sequence("BDDb", solution);
      else if (corner[5].left == 'w') // lD2L
         sequence("lDDL", solution);
   }
   else if (position == 6){
      if (corner[6].up == 'w') // lD2LBDb
         sequence("lDDLBDb", solution);
      else if (corner[6].right == 'w') // DldL
         sequence("DldL", solution);
      else if (corner[6].left == 'w') // lDL
         sequence("lDL", solution);
   }
   else if (position == 7){
      if (corner[7].up == 'w') // BdblD2L
         sequence("BdblDDL", solution);
      else if (corner[7].right == 'w') // ldL --> DLdl
         sequence("ldL", solution);
         //sequence("DLdl", solution)
      else if (corner[7].left == 'w') // BDb
         sequence("BDb", solution);
   }
}

void Rubik::secondStep(vector<char> &solution){
   int position= searchEdge('g', 'o'); // Green/orange
   if(position == 4){
      if(side[4].down == 'g') // dfDF
         sequence("dfDF", solution);
      else if (side[4].up == 'g') // Ldl
         sequence("Ldl", solution);
   }
   else if(position == 5){
      if(side[5].down == 'g') // fdF
         sequence("fdF", solution);
      else if (side[5].up == 'g') // LD2l
         sequence("LDDl", solution);
   }
   else if(position == 6){
      if(side[6].up == 'g') // LDl
         sequence("LDl", solution);
      else if (side[6].down == 'g') // fD2F
         sequence("fDDF", solution);
   }
   else if(position == 7){
      if(side[7].down == 'g') // fDF
         sequence("fDF", solution);
      else if (side[7].up == 'g') // DLdl
         sequence("DLdl", solution);
   }
   else if(position == 8){
      if(side[8].down == 'g') // urD2RUfDF
         sequence("urDDRUfDF", solution);
      else if (side[8].up == 'g') // urdRULdl
         sequence("urdRULdl", solution);
   }
   else if(position == 9){
      if(side[9].down == 'g') // U2bdBU2LD2l
         sequence("UUbdBUULDDl", solution);
      else if (side[9].up == 'g') // U2bDBU2fDF
         sequence("UUbDBUUfDF", solution);
   }
   else if(position == 10){
      if(side[10].down == 'g') // UBD2buLdl
         sequence("UBDDbuLdl", solution);
      else if (side[10].up == 'g') // UBDbufDF
         sequence("UBDbufDF", solution);
   }
   else if(position == 11){
      if(side[11].down == 'g') // LDldfDF
         sequence("LDldfDF", solution);
   }

   U(solution); //
   position = searchEdge('o', 'l'); // Orange/blue
   if(position == 4){
      if(side[4].down == 'o') // ldL
         sequence("ldL", solution);
      else if (side[4].up == 'o') // BD2b
         sequence("BDDb", solution);
   }
   else if(position == 5){
      if(side[5].down == 'o') // lD2L
         sequence("lDDL", solution);
      else if (side[5].up == 'o') // BDb
         sequence("BDb", solution);
   }
   else if(position == 6){
      if(side[6].down == 'o') // lDL
         sequence("lDL", solution);
      else if (side[6].up == 'o') // DBdb
         sequence("DBdb", solution);
   }
   else if(position == 7){
      if(side[7].down == 'o') // DldL
         sequence("DldL", solution);
      else if (side[7].up == 'o') // Bdb
         sequence("Bdb", solution);
   }
   else if(position == 8){
      if(side[8].down == 'o') // U2rDRU2lDL
         sequence("UUrDRUUlDL", solution);
      else if (side[8].up == 'o') // U2rD2RU2Bdb
         sequence("UUrDDRUUBdb", solution);
   }
   else if(position == 9){
      if(side[9].down == 'o') // URDrulDL
         sequence("URDrulDL", solution);
      else if (side[9].up == 'o') // URD2ruBdb
         sequence("URDDruBdb", solution);
   }
   else if(position == 10){
      if (side[10].up == 'o') // BDbdlDL
         sequence("BDbdlDL", solution);
   }

   U(solution); //
   position = searchEdge('r', 'l'); // Blue/red
   if(position == 4){
      if(side[4].down == 'r') // RDr
         sequence("RDr", solution);
      else if (side[4].up == 'r') // bD2B
         sequence("bDDB", solution);
   }
   else if(position == 5){
      if(side[5].down == 'r') // dRDr
         sequence("dRDr", solution);
      else if (side[5].up == 'r') // bDB
         sequence("bDB", solution);
   }
   else if(position == 6){
      if(side[6].down == 'r') // Rdr
         sequence("Rdr", solution);
      else if (side[6].up == 'r') // dbDB
         sequence("dbDB", solution);
   }
   else if(position == 7){
      if(side[7].down == 'r') // RD2r
         sequence("RDDr", solution);
      else if (side[7].up == 'r') // bdB
         sequence("bdB", solution);
   }
   else if(position == 8){
      if(side[8].down == 'r') // UrdRuRDr
         sequence("UrdRuRDr", solution);
      else if (side[8].up == 'r') // UrdRubD2B
         sequence("UrdRubDDB", solution);
   }
   else if(position == 9){
      if (side[9].up == 'r') // bD2BRDr
         sequence("bDDBRDr", solution);
   }


   U(solution);
   position = searchCorner('w', 'o', 'g'); // White, orange and green
   if (position == 4){
      if (corner[4].up == 'w') // rD2RFDf
         sequence("rDDRFDf", solution);
      else if (corner[4].right == 'w') // DrdR
         sequence("DrdR", solution);
      else if (corner[4].left == 'w') // rDR
         sequence("rDR", solution);
   }
   else if (position == 5){
      if (corner[5].up == 'w') // rD2RDrdR
         sequence("rDDRDrdR", solution);
      else if (corner[5].right == 'w') // rdR
         sequence("rdR", solution);
      else if (corner[5].left == 'w') // FDf
         sequence("FDf", solution);
   }
   else if (position == 6){
      if (corner[6].up == 'w') // FD2frdR
         sequence("FDDfrdR", solution);
      else if (corner[6].right == 'w') // Fdf
         sequence("Fdf", solution);
      else if (corner[6].left == 'w') // dFDf
         sequence("dFDf", solution);
   }
   else if (position == 7){
      if (corner[7].up == 'w') // rdRFDf
         sequence("rdRFDf", solution);
      else if (corner[7].right == 'w') // FD2f
         sequence("FDDf", solution);
      else if (corner[7].left == 'w') // rD2R
         sequence("rDDR", solution);
   }
   else if (position == 1){
      if (corner[1].left == 'w') // rDRFDf
         sequence("rDRFDf", solution);
      else if (corner[1].right == 'w') // rdRDrdR
         sequence("rdRDrdR", solution);
   }


   U(solution); // Devolver la esquina a su sitio.
   position = searchEdge('g', 'r'); // Green/red
   if(position == 4){
      if(side[4].down == 'g') // drDRDFdf
         sequence("drDRDFdf", solution);
      else if (side[4].up == 'g') // D2FdfdrDR
         sequence("DDFdfdrDR", solution);
   }
   else if(position == 5){
      if(side[5].down == 'g') // D2rDRDFdf
         sequence("DDrDRDFdf", solution);
      else if (side[5].up == 'g') // DFdfdrDR
         sequence("DFdfdrDR", solution);
   }
   else if(position == 6){
      if(side[6].down == 'g') // DrDRDFdf
         sequence("DrDRDFdf", solution);
      else if (side[6].up == 'g') // FdfdrDR
         sequence("FdfdrDR", solution);
   }
   else if(position == 7){
      if(side[7].down == 'g') // rDRDFdf
         sequence("rDRDFdf", solution);
      else if (side[7].up == 'g') // dFdfdrDR
         sequence("dFdfdrDR", solution);
   }
   else if(position == 8){
      if(side[8].down == 'g') // rdRDFDfDrDRDFdf
         sequence("rdRDFDfDrDRDFdf", solution);
   }
}

void Rubik::thirdStep(vector<char> &solution){
    yellowCross(solution);
    finalCorners(solution);
}
void Rubik::yellowCross(vector<char> &solution){
	bool repeat;
   if ((side[4].down == 'y') && (side[5].down == 'y') &&
       (side[6].down == 'y') && (side[7].down == 'y')) 	// LDBdbl && frdRDF Yellow center
	   sequence("LDBdblfrdRDF", solution);
   else if ((side[4].down == 'y') && (side[5].down != 'y') &&
	    (side[6].down == 'y') && (side[7].down != 'y')) 	// frdRDF Horizontal line
	   sequence("frdRDF", solution);
   else if ((side[4].down != 'y') && (side[5].down == 'y') &&
	    (side[6].down != 'y') && (side[7].down == 'y')) 	// lfdFDL  Vertical line
	   sequence("lfdFDL", solution);

   else if ((side[4].down != 'y') && (side[5].down != 'y') &&
	    (side[6].down == 'y') && (side[7].down == 'y')) 	// LDBdbl 'L' case
      sequence("LDBdbl", solution);

   else if ((side[4].down != 'y') && (side[5].down == 'y') &&
	    (side[6].down == 'y') && (side[7].down != 'y')) 	// BDRdrb '_|' case
      sequence("BDRdrb", solution);
   else if ((side[4].down == 'y') && (side[5].down == 'y') &&
	    (side[6].down != 'y') && (side[7].down != 'y')) 	// RDFdfr '¬' case
      sequence("RDFdfr", solution);
   else if ((side[4].down == 'y') && (side[5].down != 'y') &&
	    (side[6].down != 'y') && (side[7].down == 'y')) 	// FDLdlf ' ¬' reverse case
      sequence("FDLdlf", solution);
   else{
      int yellows = 0;
      int whistleBlower1, whistleBlower2;
      for (int i=0; i < 4; ++i){
      	if (side[i].up == 'y'){
      	  yellows++;
      	  whistleBlower2 = i;
      	}
      	else
      	  whistleBlower1 = i;
      }
      if (yellows == 3)
	      cout << "This Rubik's cube has no solution, you neew change the orientation of the edge (" << side[whistleBlower1].up << "," << side[whistleBlower1].down << ").\n";
      else if (yellows == 1)
	      cout << "This Rubik's cube has no solution, you neew change the orientation of the edge (" << side[whistleBlower2].up << "," << side[whistleBlower2].down << ").\n";
   }


	// Orientate final edgess:
	repeat = true;
	int contador = 0;
   while(repeat){
      if ((side[4].down == 'r') && (side[5].down == 'g') &&
          (side[6].down == 'l') && (side[7].down == 'o')){ // bdBdbD2Bd '¬'
   	   sequence("bdBdbDDBd", solution);
         cout << "---------------------------"<<endl;
         repeat = false;
      }
      else if ((side[4].down == 'o') && (side[5].down == 'r') &&
   	    (side[6].down == 'l') && (side[7].down == 'g')){ 	// rdRdrD2Rd '¬' reverse
   	   sequence("rdRdrDDRd", solution);
   	   repeat = false;
      }
      else if ((side[4].down == 'g') && (side[5].down == 'r') &&
   	    (side[6].down == 'o') && (side[7].down == 'l')){ // fdFdfD2Fd 'L'
         sequence("fdFdfDDFd", solution);
   	   repeat = false;
      }
      else if ((side[4].down == 'g') && (side[5].down == 'l') &&
   	    (side[6].down == 'r') && (side[7].down == 'o')){ 	// ldLdlD2Ld '_|'
         sequence("ldLdlDDLd", solution);
   	   repeat = false;
      }
      else if ((side[4].down == 'l') && (side[5].down == 'r') &&
   	    (side[6].down == 'g') && (side[7].down == 'o')){ 	// rdRdrD2RD2 && bdBdbD2Bd '--'
         sequence("rdRdrDDRDDbdBdbDDBd", solution);
   	   repeat = false;
      }
      else if ((side[4].down == 'g') && (side[5].down == 'o') &&
   	    (side[6].down == 'l') && (side[7].down == 'r')){ 	// rdRdrD2R && fdFdfD2Fd '|'
   	   sequence("rdRdrDDRfdFdfDDFd", solution);
   	   repeat = false;
      }
      else if ((side[4].down == 'y') && (side[5].down == 'y') &&
   	    (side[6].down == 'y') && (side[7].down == 'y')){ 	//
         sequence("RldRldRldRldRldRldRldRld", solution);
   	   repeat = false;
      }
      else if ((side[4].down == 'g') && (side[5].down == 'r') &&
   	    (side[6].down == 'l') && (side[7].down == 'o')) 	//
   	   repeat = false;
      else {
      	D(solution);
      	++contador;
      	if(contador == 5){ // bdBdbD2Bd
      	   contador = 0;
            sequence("bdBdbDDBd", solution);
            return;
         }
      }
  } // endwhile
}
void Rubik::finalCorners(vector<char> &solution){
   permutationFinalCorners(solution);
   positionFinalCorners(solution);
}
void Rubik::permutationFinalCorners(vector<char> &solution){
	bool repeat = true;
   while (repeat){
      if (searchCorner('y', 'o', 'g') == 4){
      	if (searchCorner('y', 'r', 'l') == 5) // rDLdRDld
            sequence("rDLdRDld", solution);
      	else if(searchCorner('y', 'r', 'l') == 7) // BdfDbdFD
            sequence("BdfDbdFD", solution);

      	repeat = false;
      }
      else if (searchCorner('y', 'g', 'r') == 5){
      	if (searchCorner('y', 'r', 'l') == 4) // bDFdBDfd
            sequence("bDFdBDfd", solution);
      	else if (searchCorner('y', 'r', 'l') == 7) // LdrDldRD
            sequence("LdrDldRD", solution);

      	repeat = false;
      }
      else if (searchCorner('y', 'l', 'o') == 7){
      	if (searchCorner('y', 'r', 'l') == 4) // RdlDrdLD
            sequence("RdlDrdLD", solution);
      	else if (searchCorner('y', 'r', 'l') == 5) // fDBdFDbd
            sequence("fDBdFDbd", solution);

      	repeat = false;
      }
      else if (searchCorner('y', 'r', 'l') == 6){
      	if (searchCorner('y', 'o', 'g') == 5) // FdbDfdBD
            sequence("FdbDfdBD", solution);
      	else if (searchCorner('y', 'o', 'g') == 7) // lDRdLDrd
            sequence("lDRdLDrd", solution);

      	repeat = false;
      }
      else // LdrDldRD
         sequence("LdrDldRD", solution);
   }
}
void Rubik::positionFinalCorners(vector<char> &solution){
	// Orientate final corners

   cout << corner[4].up << " "<<corner[5].right << " "<<corner[7].up<<" "<<corner[6].left<<endl;


   if ((corner[4].up == 'y') && (corner[5].right == 'y') &&
      (corner[7].up == 'y') && (corner[6].left == 'y')) // RD2rdRdrlD2LDlDL
      sequence("RDDrdRdrlDDLDlDL", solution);
   else if ((corner[4].left == 'y') && (corner[5].up == 'y') &&
           (corner[7].right == 'y') && (corner[6].up == 'y')) // LD2ldLdlrD2RDrDR
      sequence("LDDldLdlrDDRDrDR", solution);
   else if ((corner[4].left == 'y') && (corner[5].right == 'y') &&
           (corner[7].right == 'y') && (corner[6].left == 'y')) // RD2rdRdrlD2LDlDL LD2ldLdlrD2RDrDR
      sequence("RDDrdRdrlDDLDlDLLDDldLdlrDDRDrDR", solution);
   else if ((corner[4].right == 'y') && (corner[5].left == 'y') &&
           (corner[7].up == 'y') && (corner[6].up == 'y')) // FD2fdFdfbD2BDbDB
      sequence("FDDfdFdfbDDBDbDB", solution);
   else if ((corner[4].up == 'y') && (corner[5].up == 'y') &&
           (corner[7].left == 'y') && (corner[6].right == 'y')) // BD2bdBdbfD2FDfDF
      sequence("BDDbdBdbfDDFDfDF", solution);
   else if ((corner[4].right == 'y') && (corner[5].left == 'y') && //
           (corner[7].left == 'y') && (corner[6].right == 'y')) // FD2fdFdfbD2BDbDB BD2bdBdbfD2FDfDF
      sequence("FDDfdFdfbDDBDbDBBDDbdBdbfDDFDfDF", solution);
   else if ((corner[4].up == 'y') && (corner[5].left == 'y') &&
           (corner[7].up == 'y') && (corner[6].right == 'y')) // ldLdlD2LRDrDRD2r
      sequence("ldLdlDDLRDrDRDDr", solution);
   else if ((corner[4].right == 'y') && (corner[5].up == 'y') &&
           (corner[7].left == 'y') && (corner[6].up == 'y')) // rdRdrD2RLDlDLD2l
      sequence("rdRdrDDRLDlDLDDl", solution);
   else if ((corner[4].up == 'y') && (corner[5].up == 'y') &&
           (corner[7].right == 'y') && (corner[6].left == 'y')) // fdFdfD2FBDbDBD2b
      sequence("fdFdfDDFBDbDBDDb", solution);
   else if ((corner[4].left == 'y') && (corner[5].right == 'y') &&
           (corner[7].up == 'y') && (corner[6].up == 'y')) // bdBdbD2BFDfDFD2f
      sequence("bdBdbDDBFDfDFDDf", solution);
   else if ((corner[4].left == 'y') && (corner[5].right == 'y') &&
           (corner[7].right == 'y') && (corner[6].left == 'y')) // fdFdfD2FBDbDBD2b bdBdbD2BFDfDFD2f
      sequence("fdFdfDDFBDbDBDDbbdBdbDDBFDfDFDDf", solution);
   else if ((corner[4].right == 'y') && (corner[5].left == 'y') &&
           (corner[7].right == 'y') && (corner[6].left == 'y')) // FD2fdFdfbD2BDbDB fdFdfD2FBDbDBD2b
      sequence("FDDfdFdfbDDBDbDBfdFdfDDFBDbDBDDb", solution);
   else if ((corner[4].left == 'y') && (corner[5].right == 'y') &&
           (corner[7].left == 'y') && (corner[6].right == 'y')) // bdBdbD2BFDfDFD2f BD2bdBdbfD2FDfDF
      sequence("bdBdbDDBFDfDFDDfBDDbdBdbfDDFDfDF", solution);
   else if ((corner[4].right == 'y') && (corner[5].right == 'y') &&
           (corner[7].left == 'y') && (corner[6].left == 'y')) // rdRdrD2RLDlDLD2l RD2rdRdrlD2LDlDL
      sequence("rdRdrDDRLDlDLDDlRDDrdRdrlDDLDlDL", solution);
   else if ((corner[4].left == 'y') && (corner[5].left == 'y') &&
           (corner[7].right == 'y') && (corner[6].right == 'y')) // LD2ldLdlrD2RDrDR ldLdlD2LRDrDRD2r
      sequence("LDDldLdlrDDRDrDRldLdlDDLRDrDRDDr", solution);

   //
   int yellows = 0;
   for (int i=0;i<4;i++){
      if (corner[4+i].up == 'y')
	      ++yellows;
   }
   if (yellows == 1){
      if (corner[4].up == 'y'){
         if (corner[5].right == 'y') // RUruRUrudRUruRUrudRUruRUruD2
            sequence("RUruRUrudRUruRUrudRUruRUruDD", solution);
   	   else if (corner[5].left == 'y') // fuFUfuFUdfuFUfuFUdfuFUfuFUD2
            sequence("fuFUfuFUdfuFUfuFUd fuFUfuFUDD", solution);
      }
      else if (corner[5].up == 'y'){
         if (corner[4].right == 'y') // FUfuFUfuDFUfuFUfuDFUfuFUfuD2
            sequence("FUfuFUfuDFUfuFUfuDFUfuFUfuDD", solution);
	      else if (corner[4].left == 'y') // luLUluLUDluLUluLUDluLUluLUD2
            sequence("luLUluLUDluLUluLUDluLUluLUDD", solution);
      }
      else if (corner[6].up == 'y'){
         if (corner[5].right == 'y') // RUruRUruDRUruRUruDRUruRUruD2
            sequence("RUruRUruDRUruRUruDRUruRUruDD", solution);
	      else if (corner[5].left == 'y') // fuFUfuFUDfuFUfuF UDfuFUfuFUD2
            sequence("fuFUfuFUDfuFUfuFUDfuFUfuFUDD", solution);
      }
      else if (corner[7].up == 'y'){
         if (corner[5].right == 'y') // RUruRUruDRUruRUruD2RUruRUruD
            sequence("RUruRUruDRUruRUruDDRUruRUruD", solution);
	      else if (corner[5].left == 'y') // fuFUfuFUDfuFUfuFUD2fuFUfuFUD
            sequence("fuFUfuFUDfuFUfuFUDDfuFUfuFUD", solution);
      }
   }
   else if (yellows == 2){
      if ((corner[4].up != 'y') && (corner[6].up != 'y')){
	      if (corner[4].left == 'y') // luLUluLUD2luLUluLUluLUluLUD2
            sequence("luLUluLUDDluLUluLUluLUluLUDD", solution);
	      else if (corner[4].right == 'y') // luLUluLUluLUluLUD2 luLUluLUD2
            sequence("luLUluLUluLUluLUDDluLUluLUDD", solution);
      }
	   else if ((corner[5].up != 'y') && (corner[7].up != 'y')){
	      if (corner[5].left == 'y') // fuFUfuFUD2fuFUfuFUfuFUfuFUD2
            sequence("fuFUfuFUDDfuFUfuFUfuFUfuFUDD", solution);
	      else if (corner[5].right == 'y') // fuFUfuFUfuFUf uFUD2fuFUfuFUD2
            sequence("fuFUfuFUfuFUfuFUDDfuFUfuFUDD", solution);
      }
	}
}


// Public interface
Rubik::Rubik(){
   corner[3].up = side[2].up = corner[2].up = side[3].up = center[0].center = side[1].up = 'w';
   corner[0].up = side[0].up = corner[1].up = 'w';
   corner[3].right = side[3].down = corner[0].left = side[10].down = center[4].center = side[11].down = 'o';
   corner[7].right = side[7].down = corner[4].left = 'o';
   corner[0].right = side[0].down = corner[1].left = side[11].up = center[1].center = side[8].up = corner[4].right = 'g';
   side[4].down =  corner[5].left = 'g';
   corner[1].right = side[1].down = corner[2].left = side[8].down = center[2].center = side[9].down = 'r';
   corner[5].right = side[5].down = corner[6].left = 'r';
   corner[2].right = side[2].down = corner[3].left = side[9].up = center[3].center = side[10].up = 'l';
   corner[6].right = side[6].down = corner[7].left = 'l';
   corner[4].up = side[4].up = corner[5].up = side[7].up = center[5].center = side[5].up = 'y';
   corner[7].up = side[6].up = corner[6].up = 'y';
}
Rubik::Rubik(const Rubik &rubik){
   *this = rubik;
}

void Rubik::mixRubik(){
   int num;
   srand(time(NULL));
   vector<char> cad;

   for (int i=0; i<300; ++i){
      num = 1 + rand()%(12);
      if (num == 1)
         R(cad);
      else if (num == 2)
	      r(cad);
      else if (num == 3)
	      L(cad);
      else if (num == 4)
	      l(cad);
      else if (num == 5)
	      F(cad);
      else if (num == 6)
	      f(cad);
      else if (num == 7)
	      B(cad);
      else if (num == 8)
	      b(cad);
      else if (num == 9)
	      U(cad);
      else if (num == 10)
	      u(cad);
      else if (num == 11)
	      D(cad);
      else if (num == 12)
	      d(cad);
   }
}
bool Rubik::isSolved(){
   bool success;
   if((corner[3].up == 'w')     &&
      (side[2].up == 'w')       &&
      (corner[2].up == 'w')     &&
      (side[3].up == 'w')       &&
      (center[0].center == 'w') &&
      (side[1].up == 'w')       &&
      (corner[0].up == 'w')     &&
      (side[0].up == 'w')       &&
      (corner[1].up == 'w')     &&

      (corner[3].right == 'o')  &&
      (side[3].down == 'o')     &&
      (corner[0].left == 'o')   &&
      (side[10].down == 'o')    &&
      (center[4].center == 'o') &&
      (side[11].down == 'o')    &&
      (corner[7].right == 'o')  &&
      (side[7].down == 'o')     &&
      (corner[4].left == 'o')   &&

      (corner[0].right == 'g')  &&
      (side[0].down == 'g')     &&
      (corner[1].left == 'g')   &&
      (side[11].up == 'g')      &&
      (center[1].center == 'g') &&
      (side[8].up == 'g')       &&
      (corner[4].right == 'g')  &&
      (side[4].down == 'g')     &&
      (corner[5].left == 'g')   &&

      (corner[1].right == 'r')  &&
      (side[1].down == 'r')     &&
      (corner[2].left == 'r')   &&
      (side[8].down == 'r')     &&
      (center[2].center == 'r') &&
      (side[9].down == 'r')     &&
      (corner[5].right == 'r')  &&
      (side[5].down == 'r')     &&
      (corner[6].left == 'r')   &&

      (corner[2].right == 'l')  &&
      (side[2].down == 'l')     &&
      (corner[3].left == 'l')   &&
      (side[9].up == 'l')       &&
      (center[3].center == 'l') &&
      (side[10].up == 'l')      &&
      (corner[6].right == 'l')  &&
      (side[6].down == 'l')     &&
      (corner[7].left == 'l')   &&

      (corner[4].up == 'y')     &&
      (side[4].up == 'y')       &&
      (corner[5].up == 'y')     &&
      (side[7].up == 'y')       &&
      (center[5].center == 'y') &&
      (side[5].up == 'y')       &&
      (corner[7].up == 'y')     &&
      (side[6].up == 'y')       &&
      (corner[6].up == 'y') )
	      success = true;
   else
	   success = false;

   return success;
}
int Rubik::validRubik(){
   int valid = 2;
   int vector[7] = {0};

   // Center
   ++vector[equivalentNumber(center[0].center)];
   ++vector[equivalentNumber(center[1].center)];
   ++vector[equivalentNumber(center[2].center)];
   ++vector[equivalentNumber(center[3].center)];
   ++vector[equivalentNumber(center[4].center)];
   ++vector[equivalentNumber(center[5].center)];
   for (int i=1; i<7;++i){
      if (vector[i] != 1)
	      valid= -1;
   }

   // Edge
   if (valid != -1){
      ++vector[equivalentNumber(side[0].up)];
      ++vector[equivalentNumber(side[0].down)];
      ++vector[equivalentNumber(side[1].up)];
      ++vector[equivalentNumber(side[1].down)];
      ++vector[equivalentNumber(side[2].up)];
      ++vector[equivalentNumber(side[2].down)];
      ++vector[equivalentNumber(side[3].up)];
      ++vector[equivalentNumber(side[3].down)];
      ++vector[equivalentNumber(side[4].up)];
      ++vector[equivalentNumber(side[4].down)];
      ++vector[equivalentNumber(side[5].up)];
      ++vector[equivalentNumber(side[5].down)];
      ++vector[equivalentNumber(side[6].up)];
      ++vector[equivalentNumber(side[6].down)];
      ++vector[equivalentNumber(side[7].up)];
      ++vector[equivalentNumber(side[7].down)];
      ++vector[equivalentNumber(side[8].up)];
      ++vector[equivalentNumber(side[8].down)];
      ++vector[equivalentNumber(side[9].up)];
      ++vector[equivalentNumber(side[9].down)];
      ++vector[equivalentNumber(side[10].up)];
      ++vector[equivalentNumber(side[10].down)];
      ++vector[equivalentNumber(side[11].up)];
      ++vector[equivalentNumber(side[11].down)];
   }
   for (int i=1; i<7;++i){
      if (vector[i] != 5)
	      valid= 0;
   }
   // Corners
   if ( (valid != -1) && (valid != 0) ){
      ++vector[equivalentNumber(corner[0].left)];
      ++vector[equivalentNumber(corner[0].right)];
      ++vector[equivalentNumber(corner[0].up)];
      ++vector[equivalentNumber(corner[1].left)];
      ++vector[equivalentNumber(corner[1].right)];
      ++vector[equivalentNumber(corner[1].up)];
      ++vector[equivalentNumber(corner[2].left)];
      ++vector[equivalentNumber(corner[2].right)];
      ++vector[equivalentNumber(corner[2].up)];
      ++vector[equivalentNumber(corner[3].left)];
      ++vector[equivalentNumber(corner[3].right)];
      ++vector[equivalentNumber(corner[3].up)];
      ++vector[equivalentNumber(corner[4].left)];
      ++vector[equivalentNumber(corner[4].right)];
      ++vector[equivalentNumber(corner[4].up)];
      ++vector[equivalentNumber(corner[5].left)];
      ++vector[equivalentNumber(corner[5].right)];
      ++vector[equivalentNumber(corner[5].up)];
      ++vector[equivalentNumber(corner[6].left)];
      ++vector[equivalentNumber(corner[6].right)];
      ++vector[equivalentNumber(corner[6].up)];
      ++vector[equivalentNumber(corner[7].left)];
      ++vector[equivalentNumber(corner[7].right)];
      ++vector[equivalentNumber(corner[7].up)];
   }
   for (int i=1; i<7; ++i){
      if (vector[i] != 9)
	      valid = 1;
   }

   return valid;
}
void Rubik::correctMistakes(){
   char letter;
   int number;
   do{
      printNumbers(cout);
      do{
         cout << "Choose the position with the wrong colour [1,54]\n";
         cin >> number;
      }while(number < 1 || number > 54);

      cout << "And the new colour is... [w, b, g, r, l, y]\n";
      if (number == 1)
         readSticker(cin, corner[3].up);
      else if (number == 2)
         readSticker(cin, side[2].up);
      else if (number == 3)
         readSticker(cin, corner[2].up);
      else if (number == 4)
         readSticker(cin, side[3].up);
      else if (number == 5)
         readSticker(cin, center[0].center);
      else if (number == 6)
         readSticker(cin, side[1].up);
      else if (number == 7)
         readSticker(cin, corner[0].up);
      else if (number == 8)
         readSticker(cin, side[0].up);
      else if (number == 9)
         readSticker(cin, corner[1].up);

      else if (number == 10)
         readSticker(cin, corner[3].right);
      else if (number == 11)
         readSticker(cin, side[3].down);
      else if (number == 12)
         readSticker(cin, corner[0].left);
      else if (number == 13)
         readSticker(cin, side[10].down);
      else if (number == 14)
         readSticker(cin, center[4].center);
      else if (number == 15)
         readSticker(cin, side[11].down);
      else if (number == 16)
         readSticker(cin, corner[7].right);
      else if (number == 17)
         readSticker(cin, side[7].down);
      else if (number == 18)
         readSticker(cin, corner[4].left);

      else if (number == 19)
         readSticker(cin, corner[0].right);
      else if (number == 20)
         readSticker(cin, side[0].down);
      else if (number == 21)
         readSticker(cin, corner[1].left);
      else if (number == 22)
         readSticker(cin, side[11].up);
      else if (number == 23)
         readSticker(cin, center[1].center);
      else if (number == 24)
         readSticker(cin, side[8].up);
      else if (number == 25)
         readSticker(cin, corner[4].right);
      else if (number == 26)
         readSticker(cin, side[4].down);
      else if (number == 27)
         readSticker(cin, corner[5].left);

      else if (number == 28)
         readSticker(cin, corner[1].right);
      else if (number == 29)
         readSticker(cin, side[1].down);
      else if (number == 30)
         readSticker(cin, corner[2].left);
      else if (number == 31)
         readSticker(cin, side[8].down);
      else if (number == 32)
         readSticker(cin, center[2].center);
      else if (number == 33)
         readSticker(cin, side[9].down);
      else if (number == 34)
         readSticker(cin, corner[5].right);
      else if (number == 35)
         readSticker(cin, side[5].down);
      else if (number == 36)
         readSticker(cin, corner[6].left);

      else if (number == 37)
         readSticker(cin, corner[2].right);
      else if (number == 38)
         readSticker(cin, side[2].down);
      else if (number == 39)
         readSticker(cin, corner[3].left);
      else if (number == 40)
         readSticker(cin, side[9].up);
      else if (number == 41)
         readSticker(cin, center[3].center);
      else if (number == 42)
         readSticker(cin, side[10].up);
      else if (number == 43)
         readSticker(cin, corner[6].right);
      else if (number == 44)
         readSticker(cin, side[6].down);
      else if (number == 45)
         readSticker(cin, corner[7].left);

      else if (number == 46)
         readSticker(cin, corner[4].up);
      else if (number == 47)
         readSticker(cin, side[4].up);
      else if (number == 48)
         readSticker(cin, corner[5].up);
      else if (number == 49)
         readSticker(cin, side[7].up);
      else if (number == 50)
         readSticker(cin, center[5].center);
      else if (number == 51)
         readSticker(cin, side[5].up);
      else if (number == 52)
         readSticker(cin, corner[7].up);
      else if (number == 53)
         readSticker(cin, side[6].up);
      else if (number == 54)
         readSticker(cin, corner[6].up);

      cout << *this;
      cout << "Do you want to change other colour?    ['Y'/'y' | 'O'/'o']\n";
      cin >> letter;
   }while (letter == 'y' || letter == 'Y');
}

// Movements
void Rubik::R (vector<char> &solution){
   Corner aux;
   Side laux;

   laux = side[1];
   side[1] = side[8];
   side[8] = side[5];
   side[5] = side[9];
   side[9] = laux;

   aux.left = corner[1].right;
   aux.right = corner[1].up;
   aux.up = corner[1].left;

   corner[1].left = corner[5].up;
   corner[1].right = corner[5].right;
   corner[1].up = corner[5].left;

   corner[5].left = corner[6].up;
   corner[5].right = corner[6].left;
   corner[5].up = corner[6].right;

   corner[6].left = corner[2].left;
   corner[6].right = corner[2].up;
   corner[6].up = corner[2].right;

   corner[2] = aux;
   solution.push_back('R');
}
void Rubik::R2(vector<char> &solution){
   R(solution);
   R(solution);
}
void Rubik::r (vector<char> &solution){
   Corner aux;
   Side laux;

   laux = side[1];
   side[1] = side[9];
   side[9] = side[5];
   side[5] = side[8];
   side[8] = laux;

   aux.left = corner[1].up;
   aux.right = corner[1].right;
   aux.up = corner[1].left;

   corner[1].left = corner[2].up;
   corner[1].right = corner[2].left;
   corner[1].up = corner[2].right;

   corner[2].left = corner[6].left;
   corner[2].right = corner[6].up;
   corner[2].up = corner[6].right;

   corner[6].left = corner[5].right;
   corner[6].right = corner[5].up;
   corner[6].up = corner[5].left;

   corner[5] = aux;
   solution.push_back('r');
}
void Rubik::L (vector<char> &solution){
   Corner aux;
   Side laux;

   laux = side[3];
   side[3] = side[10];
   side[10] = side[7];
   side[7] = side[11];
   side[11] = laux;

   aux.left = corner[0].left;
   aux.right = corner[0].up;
   aux.up = corner[0].right;

   corner[0].left = corner[3].right;
   corner[0].right = corner[3].up;
   corner[0].up = corner[3].left;

   corner[3].left = corner[7].up;
   corner[3].right = corner[7].right;
   corner[3].up = corner[7].left;

   corner[7].left = corner[4].up;
   corner[7].right = corner[4].left;
   corner[7].up = corner[4].right;

   corner[4] = aux;
   solution.push_back('L');
}
void Rubik::L2(vector<char> &solution){
   L(solution);
   L(solution);
}
void Rubik::l (vector<char> &solution){
   Corner aux;
   Side laux;

   laux = side[3];
   side[3] = side[11];
   side[11] = side[7];
   side[7] = side[10];
   side[10] = laux;

   aux.left = corner[0].up;
   aux.right = corner[0].left;
   aux.up = corner[0].right;

   corner[0].left = corner[4].left;
   corner[0].right = corner[4].up;
   corner[0].up = corner[4].right;

   corner[4].left = corner[7].right;
   corner[4].right = corner[7].up;
   corner[4].up = corner[7].left;

   corner[7].left = corner[3].up;
   corner[7].right = corner[3].right;
   corner[7].up = corner[3].left;

   corner[3] = aux;
   solution.push_back('l');
}
void Rubik::D (vector<char> &solution){
   Corner aux;
   Side laux;

   laux = side[4];
   side[4] = side[7];
   side[7] = side[6];
   side[6] = side[5];
   side[5] = laux;

   aux = corner[5];
   corner[5] = corner[4];
   corner[4] = corner[7];
   corner[7] = corner[6];
   corner[6] = aux ;
   solution.push_back('D');
}
void Rubik::D2(vector<char> &solution){
   D(solution);
   D(solution);
}
void Rubik::d (vector<char> &solution){
   Corner aux;
   Side laux;

   laux = side[4];
   side[4] = side[5];
   side[5] = side[6];
   side[6] = side[7];
   side[7] = laux;

   aux = corner[5];
   corner[5] = corner[6];
   corner[6] = corner[7];
   corner[7] = corner[4];
   corner[4] = aux ;
   solution.push_back('d');
}
void Rubik::U (vector<char> &solution){
   Corner aux;
   Side laux;

   laux = side[0];
   side[0] = side[1];
   side[1] = side[2];
   side[2] = side[3];
   side[3] = laux;

   aux = corner[0];
   corner[0] = corner[1];
   corner[1] = corner[2];
   corner[2] = corner[3];
   corner[3] = aux;
   solution.push_back('U');
}
void Rubik::U2(vector<char> &solution){
   U(solution);
   U(solution);
}
void Rubik::u (vector<char> &solution){
   Corner aux;
   Side laux;

   laux = side[0];
   side[0] = side[3];
   side[3] = side[2];
   side[2] = side[1];
   side[1] = laux;

   aux = corner[1];
   corner[1] = corner[0];
   corner[0] = corner[3];
   corner[3] = corner[2];
   corner[2] = aux;
   solution.push_back('u');
}
void Rubik::F (vector<char> &solution){
   Corner aux;
   Side laux;

   laux.down = side[0].up;
   laux.up = side[0].down;
   side[0].up = side[11].down;
   side[0].down = side[11].up;
   side[11].up = side[4].down;
   side[11].down = side[4].up;
   side[4].up = side[8].down;
   side[4].down = side[8].up;
   side[8] = laux;

   aux.left = corner[1].left;
   aux.right = corner[1].up;
   aux.up = corner[1].right;

   corner[1].left = corner[0].right;
   corner[1].right = corner[0].up;
   corner[1].up = corner[0].left;

   corner[0].left = corner[4].up;
   corner[0].right = corner[4].right;
   corner[0].up = corner[4].left;

   corner[4].left = corner[5].up;
   corner[4].right = corner[5].left;
   corner[4].up = corner[5].right;

   corner[5] = aux;
   solution.push_back('F');
}
void Rubik::F2(vector<char> &solution){
   F(solution);
   F(solution);
}
void Rubik::f (vector<char> &solution){
   Corner aux;
   Side laux;

   laux.up = side[8].down;
   laux.down = side[8].up;
   side[8].up = side[4].down;
   side[8].down = side[4].up;
   side[4].up = side[11].down;
   side[4].down = side[11].up;
   side[11].up = side[0].down;
   side[11].down = side[0].up;
   side[0] = laux;

   aux.left = corner[1].up;
   aux.right = corner[1].left;
   aux.up = corner[1].right;

   corner[1].left = corner[5].left;
   corner[1].right = corner[5].up;
   corner[1].up = corner[5].right;

   corner[5].left = corner[4].right;
   corner[5].right = corner[4].up;
   corner[5].up = corner[4].left;

   corner[4].left = corner[0].up;
   corner[4].right = corner[0].right;
   corner[4].up = corner[0].left;

   corner[0] = aux;
   solution.push_back('f');
}
void Rubik::B (vector<char> &solution){
   Corner aux;
   Side laux;

   laux.up = side[9].down;
   laux.down = side[9].up;
   side[9].up = side[6].down;
   side[9].down = side[6].up;
   side[6].up = side[10].down;
   side[6].down = side[10].up;
   side[10].up = side[2].down;
   side[10].down = side[2].up;
   side[2] = laux;

   aux.left = corner[2].right;
   aux.right = corner[2].up;
   aux.up = corner[2].left;

   corner[2].left = corner[6].up;
   corner[2].right = corner[6].right;
   corner[2].up = corner[6].left;

   corner[6].left = corner[7].up;
   corner[6].right = corner[7].left;
   corner[6].up = corner[7].right;

   corner[7].left = corner[3].left;
   corner[7].right = corner[3].up;
   corner[7].up = corner[3].right;

   corner[3] = aux;
   solution.push_back('W');
}
void Rubik::B2(vector<char> &solution){
   B(solution);
   B(solution);
}
void Rubik::b (vector<char> &solution){
   Corner aux;
   Side laux;

   laux.up = side[10].down;
   laux.down = side[10].up;
   side[10].up = side[6].down;
   side[10].down = side[6].up;
   side[6].up = side[9].down;
   side[6].down = side[9].up;
   side[9].up = side[2].down;
   side[9].down = side[2].up;
   side[2] = laux;

   aux.left = corner[3].up;
   aux.right = corner[3].left;
   aux.up = corner[3].right;

   corner[3].left = corner[7].left;
   corner[3].right = corner[7].up;
   corner[3].up = corner[7].right;

   corner[7].left = corner[6].right;
   corner[7].right = corner[6].up;
   corner[7].up = corner[6].left;

   corner[6].left = corner[2].up;
   corner[6].right = corner[2].right;
   corner[6].up = corner[2].left;

   corner[2] = aux;
   solution.push_back('w');
}




// Solve
void Rubik::solveStepByStep(vector<char> &solution){
   unsigned int mov = 0;
   char xar;
   solution.clear();

   Rubik aux(*this);
   aux.solve(solution);
   cout << "You will need " << solution.size() << " movements to solve it.\n";

   cout << "The rubik's cube has 12 different movements (and double movements: F2, B2, R2, L2, U2, D2).\n";
   cout << "\"FBRLUD\" movements indicates clockwise, \"fbrlud\" the opposite movement";
   cout << "\n\t F(ront), B(ack), R(igth), L(eft), U(p), D(own)";

   cout << "You will have 3 seconds per movement, there will be pauses to check.\n";
   cout << "Press any key: ";
   cin >> xar; cin.ignore(1024,'\n');

   cout << endl << "Initial rubik's cube: " << endl;
   cout << *this << endl;

   //sleep(2);
   whiteCross(solution);
   explainMovements(solution, mov); //
   cout << *this;
   cout << "\n### The white cross it's made.\n";
   cout << "Press any key: ";
   cin.ignore(1024, '\n');

   cornersFirstStep(solution);
   explainMovements(solution, mov);
   cout << *this;
   cout << "## You will need just a corner to complete first side.";
   cout << "We will do it later, it will be faster. \n";
   cout << "Press any key: ";
   cin.ignore(1024, '\n');

   secondStep(solution);
   explainMovements(solution, mov);
   cout << *this;
   cout << "## First side and central ring completed.\n";
   cout << "Press any key: ";
   cin.ignore(1024, '\n');

   yellowCross(solution);
   explainMovements(solution, mov);
   cout << *this;
   cout << "### The yellow cross it's made. ";
   cout << "Press any key: ";
   cin.ignore(1024, '\n');


   permutationFinalCorners(solution);
   explainMovements(solution, mov);
   cout << *this;
   cout << "### The final corners are good located, but probably not oriented. ";
   cout << "Press any key: ";
   cin.ignore(1024, '\n');

   positionFinalCorners(solution);
   explainMovements(solution, mov);
   cout << *this;
   printf (BT_ON "\n\n\t---> ¡¡ Good job :D !! <---\n" RESET);
}
void Rubik::solve(vector<char> &solution){
   solution.clear();
   firstStep(solution); // White face
   secondStep(solution); // Middle step
   thirdStep(solution); // Bottom face
}

// Input && output
void Rubik::exportRubik(std::ostream& os) const{
      os << corner[3].up << " " << side[2].up << " " << corner[2].up << " ";
      os << side[3].up << " " << center[0].center << " " << side[1].up << " ";
      os << corner[0].up << " " << side[0].up << " " << corner[1].up << " "<< endl;

      os << corner[3].right << " " << side[3].down << " " << corner[0].left << " ";
      os << side[10].down << " " << center[4].center << " " << side[11].down << " ";
      os << corner[7].right << " " << side[7].down << " " << corner[4].left << " " << endl;

      os << corner[0].right << " " << side[0].down << " " << corner[1].left << " ";
      os << side[11].up << " " << center[1].center << " " << side[8].up << " ";
      os << corner[4].right << " " << side[4].down << " " << corner[5].left << " "<< endl;

      os << corner[1].right << " " << side[1].down << " " << corner[2].left << " ";
      os << side[8].down << " " << center[2].center << " " << side[9].down << " ";
      os << corner[5].right << " " << side[5].down << " " << corner[6].left << " "<< endl;

      os << corner[2].right << " " << side[2].down << " " << corner[3].left << " ";
      os << side[9].up << " " << center[3].center << " " << side[10].up << " ";
      os << corner[6].right << " " << side[6].down << " " << corner[7].left << " " << endl;

      os << corner[4].up << " " << side[4].up << " " << corner[5].up << " ";
      os << side[7].up << " " << center[5].center << " " << side[5].up << " ";
      os << corner[7].up << " " << side[6].up << " " << corner[6].up << endl;
}
void Rubik::exportSolution(vector<char> &solution, std::ostream& os){
   unsigned int movement = 0;
   while ( movement != (solution.size()-1) ){
      os << "- (" << movement + 1 << ") ";
      if (solution[movement] == 'F')
         os << "F --> Move frontal face in clockwise.\n\n";
      else if (solution[movement] == 'f')
         os << "f --> Move frontal face in clockwise.\n\n";
      else if (solution[movement] == 'W')
         os << "B --> Move back face to left.\n\n";
      else if (solution[movement] == 'w')
         os << "b --> Move back face to right.\n\n";
      else if (solution[movement] == 'R')
         os << "R --> Move right face backward.\n\n";
      else if (solution[movement] == 'r')
         os << "r --> Move right face forward.\n\n";
      else if (solution[movement] == 'L')
         os << "L --> Move left face forward.\n\n";
      else if (solution[movement] == 'l')
         os << "l --> Move left face backward.\n\n";
      else if (solution[movement] == 'U')
         os << "U --> Move top face to left.\n\n";
      else if (solution[movement] == 'u')
         os << "u --> Move top face to right.\n\n";
      else if (solution[movement] == 'D')
         os << "D --> Move face of the bottom to right.\n\n";
      else if (solution[movement] == 'd')
         os << "d --> Move face of the bottom to left.\n\n";

      ++movement;
   }
}
void Rubik::printColour(char c) const{
   char colour = tolower(c);

   if (colour == 'w')
      printf(WHITE "W" RESET);
   else if (colour == 'o')
      printf(BLACK "O" RESET);
   else if (colour == 'g')
      printf(GREEN "G" RESET);
   else if (colour == 'r')
      printf(RED "R" RESET);
   else if (colour == 'l')
      printf(BLUE "L" RESET);
   else if (colour == 'y')
      printf(YELLOW "Y" RESET);
}
void Rubik::printNumbers(std::ostream &os){
   os << "                     _______________ \n";
   os << "                     | 01 | 02 | 03 |\n";
   os << "                     _______________ \n";
   os << "                     | 04 | 05 | 06 |\n";
   os << "                     _______________ \n";
   os << "                     | 07 | 08 | 09 |\n";
   os << "    _________________________________________________________________ \n";
   os << "    || 10 | 11 | 12 || 19 | 20 | 21 || 28 | 29 | 30 || 37 | 38 | 39 ||\n";
   os << "    _________________________________________________________________ \n";
   os << "    || 13 | 14 | 15 || 22 | 23 | 24 || 31 | 32 | 33 || 40 | 41 | 42 ||\n";
   os << "    _________________________________________________________________ \n";
   os << "    || 16 | 17 | 18 || 25 | 26 | 27 || 34 | 35 | 36 || 43 | 44 | 45 ||\n";
   os << "    _________________________________________________________________ \n";
   os << "                     | 46 | 47 | 48 |\n";
   os << "                     _______________ \n";
   os << "                     | 49 | 50 | 51 |\n";
   os << "                     _______________ \n";
   os << "                     | 52 | 53 | 54 |\n";
   os << "                     _______________ "<< endl;
}
void Rubik::printAll() const{
   cout << "                  _____________\n";
   cout << "                  | "; printColour(corner[3].up);
   cout << " | "; printColour(side[2].up);
   cout << " | "; printColour(corner[2].up); cout << " |\n";
   cout << "                  _____________\n";
   cout << "                  | "; printColour(side[3].up);
   cout << " | "; printColour(center[0].center);
   cout << " | "; printColour(side[1].up); cout << " |\n";
   cout << "                  _____________\n";
   cout << "                  | "; printColour(corner[0].up);
   cout << " | "; printColour(side[0].up);
   cout << " | "; printColour(corner[1].up); cout << " |\n";

   cout << "    ______________________________________________________\n";
   cout << "    || "; printColour(corner[3].right);
   cout << " | "; printColour(side[3].down);
   cout << " | "; printColour(corner[0].left);

   cout << " || "; printColour(corner[0].right);
   cout << " | "; printColour(side[0].down);
   cout << " | "; printColour(corner[1].left);

   cout << " || "; printColour(corner[1].right);
   cout << " | "; printColour(side[1].down);
   cout << " | "; printColour(corner[2].left);

   cout << " || "; printColour(corner[2].right);
   cout << " | "; printColour(side[2].down);
   cout << " | "; printColour(corner[3].left); cout << " ||\n";

   cout << "    ______________________________________________________\n";
   cout << "    || "; printColour(side[10].down);
   cout << " | "; printColour(center[4].center);
   cout << " | "; printColour(side[11].down);

   cout << " || "; printColour(side[11].up);
   cout << " | "; printColour(center[1].center);
   cout << " | "; printColour(side[8].up);

   cout << " || "; printColour(side[8].down);
   cout << " | "; printColour(center[2].center);
   cout << " | "; printColour(side[9].down);

   cout << " || "; printColour(side[9].up);
   cout << " | "; printColour(center[3].center);
   cout << " | "; printColour(side[10].up); cout << " ||\n";

   cout << "    ______________________________________________________\n";
   cout << "    || "; printColour(corner[7].right);
   cout << " | "; printColour(side[7].down);
   cout << " | "; printColour(corner[4].left);

   cout << " || "; printColour(corner[4].right);
   cout << " | "; printColour(side[4].down);
   cout << " | "; printColour(corner[5].left);

   cout << " || "; printColour(corner[5].right);
   cout << " | "; printColour(side[5].down);
   cout << " | "; printColour(corner[6].left);

   cout << " || "; printColour(corner[6].right);
   cout << " | "; printColour(side[6].down);
   cout << " | "; printColour(corner[7].left); cout << " ||\n";

   cout << "    ______________________________________________________\n";

   cout << "                  | "; printColour(corner[4].up);
   cout << " | "; printColour(side[4].up);
   cout << " | "; printColour(corner[5].up); cout << " |\n";
   cout << "                  _____________\n";
   cout << "                  | "; printColour(side[7].up);
   cout << " | "; printColour(center[5].center);
   cout << " | "; printColour(side[5].up); cout << " |\n";
   cout << "                  _____________\n";
   cout << "                  | "; printColour(corner[7].up);
   cout << " | "; printColour(side[6].up);
   cout << " | "; printColour(corner[6].up); cout << " |\n";
   cout << "                  _____________\n";
}

void Rubik::readSticker(std::istream& is, char &c){
   char caracter;
   c = 'f';
   do{
      is >> caracter;
      if( ( tolower(caracter) == 'w') || ( caracter == '1' ) )
         c = 'w';
      else if( ( tolower(caracter) == 'o') || ( caracter == '2' ) )
         c = 'o';
      else if( ( tolower(caracter) == 'g') || ( caracter == '3' ) )
         c = 'g';
      else if( ( tolower(caracter) == 'r') || ( caracter == '4' ) )
         c = 'r';
      else if( ( tolower(caracter) == 'l') || ( caracter == '5' ) )
         c = 'l';
      else if( ( tolower(caracter) == 'y') || ( caracter == '6' ) )
         c = 'y';
      else
         cout << "Invalid char. Try again:\n";
   }while (c == 'f');
}
void Rubik::readRubik(std::istream &is){
   bool success = true;
   if (is.fail())
      success = false;

   if (success){
      readSticker(is, corner[3].up);
      readSticker(is, side[2].up);
      readSticker(is, corner[2].up);
      readSticker(is, side[3].up);
      readSticker(is, center[0].center);
      readSticker(is, side[1].up);
      readSticker(is, corner[0].up);
      readSticker(is, side[0].up);
      readSticker(is, corner[1].up);

      readSticker(is, corner[3].right);
      readSticker(is, side[3].down);
      readSticker(is, corner[0].left);
      readSticker(is, side[10].down);
      readSticker(is, center[4].center);
      readSticker(is, side[11].down);
      readSticker(is, corner[7].right);
      readSticker(is, side[7].down);
      readSticker(is, corner[4].left);

      readSticker(is, corner[0].right);
      readSticker(is, side[0].down);
      readSticker(is, corner[1].left);
      readSticker(is, side[11].up);
      readSticker(is, center[1].center);
      readSticker(is, side[8].up);
      readSticker(is, corner[4].right);
      readSticker(is, side[4].down);
      readSticker(is, corner[5].left);

      readSticker(is, corner[1].right);
      readSticker(is, side[1].down);
      readSticker(is, corner[2].left);
      readSticker(is, side[8].down);
      readSticker(is, center[2].center);
      readSticker(is, side[9].down);
      readSticker(is, corner[5].right);
      readSticker(is, side[5].down);
      readSticker(is, corner[6].left);

      readSticker(is, corner[2].right);
      readSticker(is, side[2].down);
      readSticker(is, corner[3].left);
      readSticker(is, side[9].up);
      readSticker(is, center[3].center);
      readSticker(is, side[10].up);
      readSticker(is, corner[6].right);
      readSticker(is, side[6].down);
      readSticker(is, corner[7].left);

      readSticker(is, corner[4].up);
      readSticker(is, side[4].up);
      readSticker(is, corner[5].up);
      readSticker(is, side[7].up);
      readSticker(is, center[5].center);
      readSticker(is, side[5].up);
      readSticker(is, corner[7].up);
      readSticker(is, side[6].up);
      readSticker(is, corner[6].up);
   }
   else
      cout << "I can't read it.\n";

   int error = validRubik();
   if (error == -1){
      success = false;
      cout << "There are mistakes with centers.\n";
   }
   else if (error == 0){
      success = false;
      cout << "There are mistakes with edges.\n";
   }
   else if (error == 1){
      success = false;
      cout << "There are mistakes with corners.\n";
   }
}

Center Rubik::getCenter(int position) const{
   Center ret;
   ret.center = 'f';

   if (position >= 0 && position < 6)
      ret.center = center[position].center;

   return ret;
}
Side Rubik::getSide(int position) const{
   Side ret;
   ret.up = ret.down = 'f';

   if (position >= 0 && position < 12){
      ret.up   = side[position].up;
      ret.down = side[position].down;
   }

   return ret;
}
Corner Rubik::getCorner(int position) const{
   Corner ret;
   ret.up = ret.left = ret.right = 'f';

   if (position >= 0 && position < 8){
      ret.up    = corner[position].up;
      ret.left  = corner[position].left;
      ret.right = corner[position].right;
   }

   return ret;
}

Rubik& Rubik::operator = (const Rubik &rubik){
   if (this != &rubik){
      for (int i=0; i<6; ++i)
         center[i].center = rubik.getCenter(i).center;
      for (int i=0; i<12; ++i){
         side[i].up   = rubik.getSide(i).up;
         side[i].down = rubik.getSide(i).down;
      }

      for (int i=0; i<8; ++i){
         corner[i].up = rubik.getCorner(i).up;
         corner[i].left = rubik.getCorner(i).left;
         corner[i].right = rubik.getCorner(i).right;
      }
   }
   return *this;
}


// External methods
std::ostream& operator << (std::ostream& os, const Rubik &rubik){
   rubik.exportRubik(os);
   return os;
}
std::istream& operator >> (std::istream& is, Rubik &rubik){
   rubik.readRubik(is);
   return is;
}


// ---------------------------------------------------------------
//
// Presentation

void guide(){
   cout << "\tThe rubik's cube will be read from file or keyboard.\n";
   cout << "\tThe standard position for the rubik's cube is: green side in front of you and white side up.\n";

   cout << "\t-W (WHITE, top side)\t-O (ORANGE, left side)\t-G (GREEN, front side)\n";
   cout << "\t-R (RED, right side)" << "\t-L (BLUE, back side)" << "\t-Y (YELLOW, below side)\n";
   cout << "\tIf your rubik's cube has different patterns or colours, look at this:\n\t";
   printf (RED "-Example 1: " RESET);
   cout << "If the center of the left side is red, in all stickers you should select orange.\n\t";
   printf (RED "-Example 2: " RESET);
   cout << "If the center of the back side is black, in your black stickers you should select blue.\n";
   cout << "\tThe program will read 54 colours, one side each time.\n";

   Rubik rubik;
   rubik.printNumbers(cout);

   cout << "\tYou can use three different options: \n\t";
      printf (WHITE "W/w/1, " RESET);
      printf (BLACK "O/o/2" RESET " (\"orange\"), ");
      printf (GREEN "G/g/3, " RESET);
      printf (RED "R/r/4, " RESET);
      printf (BLUE "L/l/5, " RESET);
      printf (YELLOW "Y/y/6 " RESET "\n");
   cout << "\tYou will be able to change the colours." << endl;
}
void presentation(){
   cout << "\t";
   printf (BT_ON BLUE " #############################################################" RESET "\n");
   cout << "\t -";
	printf (BT_ON "This program solves rubik's cubes 3x3 with beginners method" RESET "\n");
   cout << "\t";
   printf (BT_ON BLUE " #############################################################" RESET "\n");
}
void movements(){
  cout << "\tThe rubik's cube has 12 different movements and double movements: F2, B2, R2, L2, U2, D2.\n";
  cout << "\t\"FBRLUD\" movements in clockwise, \"fbrlud\" the opposite movement.";
  cout << "\n\tF(ront), B(ack), R(igth), L(eft), U(p), D(own)";
}
Rubik randomRubik(){
   Rubik rubik;
   rubik.mixRubik();

   return rubik;
}
void arguments(){
	cout << "\tWithout arguments, the rubik's cube will be read from file or keyboard.\n";
	cout << "\tWith one argument it will read from this file.\n";
   printf (BLUE "\t%% Rubik readable_file.txt" RESET);
	cout << endl << "\tTwo arguments, read from first, show the solution on the other.\n";
   printf (BLUE "\t%% Rubik readable_file.txt solution.txt" RESET);
	cout << endl;
}
void fileExample(){
   Rubik rubik = randomRubik();
   rubik.exportRubik(cout);
   cout << "\nThis file is this rubik's cube:\n";
   cout << rubik;
}
