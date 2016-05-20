#ifndef def_rubik_h
#define def_rubik_h

#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
using namespace std;

struct Center{
   char center;
};

struct Side{
   char up, down;
};

struct Corner{
   char up, left, right;
};

class Rubik{
   private:
      Center center[6];
      Side side[12];
      Corner corner[8];

      // Auxiliary functions
      void explainMovements(vector<char> &solution, unsigned int& movement) const;
      int equivalentNumber(const char &c) const;
      int searchEdge(char ar, char ab) const;
      int searchCorner(char a, char iz, char de) const;
      void sequence(string sec, vector<char> &movements);

      // Parts of the solution
      void firstStep(vector<char> &solution);
      void whiteCross(vector<char> &solution);
      void cornersFirstStep(vector<char> &solution);

      void secondStep(vector<char> &solution);

      void thirdStep(vector<char> &solution);
      void yellowCross(vector<char> &solution);
      void finalCorners(vector<char> &solution);
      void permutationFinalCorners(vector<char> &solution);
      void positionFinalCorners(vector<char> &solution);

   public:
      Rubik();
      Rubik(const Rubik& rubik);

      void mixRubik();
      bool isSolved();
      int validRubik();
      void correctMistakes();

      // Movements
      void R (vector<char> &solution);
      void R2(vector<char> &solution);
      void r (vector<char> &solution);
      void L (vector<char> &solution);
      void L2(vector<char> &solution);
      void l (vector<char> &solution);
      void D (vector<char> &solution);
      void D2(vector<char> &solution);
      void d (vector<char> &solution);
      void U (vector<char> &solution);
      void U2(vector<char> &solution);
      void u (vector<char> &solution);
      void F (vector<char> &solution);
      void F2(vector<char> &solution);
      void f (vector<char> &solution);
      void B (vector<char> &solution);
      void B2(vector<char> &solution);
      void b (vector<char> &solution);



      // Solve
      void solveStepByStep(vector<char> &solution);
      void solve(vector<char> &solution);

      // Input && output
      void exportRubik(std::ostream& os=cout) const;
      void exportSolution(vector<char> &solution, std::ostream &os=cout);
      void printColour(char c) const;
      void printNumbers(std::ostream &os=cout);
      void printAll() const;

      void readSticker(std::istream &is, char &c);
      void readRubik(std::istream &is);

      // Getter
      Center getCenter(int position) const;
      Side getSide(int position) const;
      Corner getCorner(int position) const;

      // Operator
      Rubik& operator = (const Rubik &r);
};


std::ostream& operator << (std::ostream &os, const Rubik &rubik);
std::istream& operator >>(std::istream &is, Rubik &rubik);

// Presentation
void guide();
void presentation();
void movements();
Rubik randomRubik();
void arguments();
void fileExample();

#endif
