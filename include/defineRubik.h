/**
  * @file defineRubik.h
  * @brief Definition of a rubik's cube
  *
  * @author Rubén Morales Pérez
  * @date 20/05/2016
  *
  */
#ifndef def_rubik_h
#define def_rubik_h

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


/**
 * @struct Center
 * @brief Central sticker of a face.
 *
 */
struct Center{
   char center;
};

/**
 * @struct Edge
 * @brief Piece with two stickers.
 *
 */
struct Edge{
   char up, down;
};

/**
 * @struct Corner
 * @brief Piece with three stickers, the orientation doesn't change.
 *
 */
struct Corner{
   char up, left, right;
};



/**
 * @class Class to interact with an instance of Rubik's Cube
 *
 */
class Rubik{
   private:
      /**
       * @brief Centers of rubik's cube
       * \note Order of centers: top(0), frontal(1), right(2), back(3), left(4), bottom(5)
       *
       */
      Center center[6];

      /**
       * @brief Edges of rubik's cube
       * \note Order of edges:
       *  top(0, 1, 2, 3) and bottom(4, 5, 6, 7), central ring(8, 9, 10, 11)
       *
       */
      Edge edge[12];

      /**
       * @brief Corners of rubik's cube
       * \note Order of corners:
       *  top(0, 1, 2, 3) and bottom(4, 5, 6, 7)
       *
       */
      Corner corner[8];

      // Auxiliary functions
      /**
        * @brief Develop each movement in natural language
        * @param vector<char>& solution Movements to explain, part of the real solution
        * @param const unsigned int& movement First movement to explain
        * @return void
        * @pre char of solution are limited in class
        * @pre movement < solution.size()
        * @see Movements
        *
        */
      void explainMovements(vector<char>& solution, unsigned int& movement) const;

      /**
        * @brief Calculate number asociated
        * @param const char& c
        * @return int asociated
        * @retval [1, 6]
        * @pre c limited with rubik's colours
        *
        */
      int equivalentNumber(const char& c) const;

      /**
        * @brief Look for specific edge
        * @param const char& ar
        * @param const char& ab
        * @return int
        * @retval [0, 11]
        * @pre ar && ab valid colours with centers not opposite
        * @see Edge
        *
        */
      int searchEdge(const char& ar, const char& ab) const;

      /**
        * @brief Look for specific specific corner
        * @param const char& a
        * @param const char& iz
        * @param const char& de
        * @return int
        * @retval [0, 7]
        * @pre a, iz, de valid colours with center not opposite
        * @see Corner
        *
        */
      int searchCorner(const char& a, const char& iz, const char& de) const;

      /**
        * @brief Execution of sec.size() movements in string sec
        * @param string sec string with movements
        * @param vector<char>& solution where we will append movements from sec
        * @return void
        * @pre Valid chars in string
        * @see explainMovements()
        *
        */
      void sequence(const string& sec, vector<char>& solution);



      // Parts of the solution
      /**
        * @brief It complete top face (white)
        * @param vector<char>& solution will store the solution
        * @param vector<char>& solution
        * @return void
        * @pre solution.size() == 0, it will be deleted
        *
        */
      void firstStep(vector<char>& solution);

      /**
        * @brief First part of top face
        * @param vector<char>& solution
        * @return void
        * @see firstStep()
        *
        */
      void whiteCross(vector<char>& solution);

      /**
        * @brief First three corners of top face
        * @param vector<char>& solution
        * @return void
        * @pre firstStep()
        * @see firstStep()
        *
        */
      void cornersFirstStep(vector<char>& solution);


      /**
        * @brief Central ring of rubik's cube
        * @param vector<char>& solution
        * @return void
        * @pre firstStep()
        * @see thirdStep()
        *
        */
      void secondStep(vector<char>& solution);


      /**
        * @brief Last part of solution
        * @param vector<char>& solution
        * @return void
        * @pre firstStep()
        * @pre secondStep()
        *
        */
      void thirdStep(vector<char>& solution);


      /**
        * @brief First part of bottom face
        * @param vector<char>& solution
        * @return void
        * @see thirdStep()
        *
        */
      void yellowCross(vector<char>& solution);

      /**
        * @brief Last four corners
        * @param vector<char>& solution
        * @return void
        * @pre yellowCross()
        *
        */
      void finalCorners(vector<char>& solution);

      /**
        * @brief It moves corner to their position
        * @param vector<char>& solution
        * @return void
        * @see finalCorners()
        *
        */
      void permutationFinalCorners(vector<char>& solution);

      /**
        * @brief Last step
        * @param vector<char>& solution
        * @return void
        * @pre permutationFinalCorners()
        * @see
        *
        */
      void positionFinalCorners(vector<char>& solution);

   public:
      /**
        * @brief Constructor without arguments
        * @see validRubik()
        *
        */
      Rubik();

      /**
        * @brief Constructor with an instance of Rubik class
        * @param const Rubik& rubik
        * @pre *this != &rubik
        *
        */
      Rubik(const Rubik& rubik);


      /**
        * @brief It builds a random rubik
        * @param const int &number of random movements
        * @return void
        * \note It is modified
        *
        */
      void mixRubik(const int& number=300);

      /**
        * @brief Check if our rubik's cube is solved
        * @return bool
        * @see validRubik()
        *
        */
      bool isSolved() const;

      /**
        * @brief Check if there are logic errors in colour distribution
        * @return int
        * @retval -1 wrong centers
        * @retval -2 wrong edges
        * @retval -3 wrong corners
        *
        */
      int logicErrors() const;

      /**
        * @brief Error modifier
        * @return void
        * @pre readRubik()
        *
        */
      void correctMistakes();


      // Movements
      /**
        * @brief Move right side backward.
        * @param vector<char>& solution
        * @return void
        * @see r()
        *
        */
      void R(vector<char>& solution);

      /**
        * @brief Move right side backward two times
        * @param vector<char>& solution
        * @return void
        *
        */
      void R2(vector<char>& solution);

      /**
        * @brief Move right side to you
        * @param vector<char>& solution
        * @return
        * @see R()
        *
        */
      void r(vector<char>& solution);

      /**
        * @brief Move left side to you
        * @param vector<char>& solution
        * @return void
        * @see l()
        *
        */
      void L(vector<char>& solution);

      /**
        * @brief  Move left side to you two times
        * @param vector<char>& solution
        * @return void
        *
        */
      void L2(vector<char>& solution);

      /**
        * @brief Move left side backward
        * @param vector<char>& solution
        * @return void
        * @see L()
        *
        */
      void l(vector<char>& solution);

      /**
        * @brief Move down side right
        * @param vector<char>& solution
        * @return void
        * @see d()
        *
        */
      void D(vector<char>& solution);

      /**
        * @brief Move down side right two times
        * @param vector<char>& solution
        * @return void
        *
        */
      void D2(vector<char>& solution);

      /**
        * @brief Move down side left
        * @param vector<char>& solution
        * @return void
        * @see D()
        *
        */
      void d(vector<char>& solution);

      /**
        * @brief Move top side left
        * @param vector<char>& solution
        * @return void
        * @see u()
        *
        */
      void U(vector<char>& solution);

      /**
        * @brief Move top side left two times
        * @param vector<char>& solution
        * @return void
        *
        */
      void U2(vector<char>& solution);

      /**
        * @brief Move top side right
        * @param vector<char>& solution
        * @return void
        * @see U()
        *
        */
      void u(vector<char>& solution);

      /**
        * @brief Move frontal side in clockwise
        * @param vector<char>& solution
        * @return void
        * @see f()
        *
        */
      void F(vector<char>& solution);

      /**
        * @brief Move frontal side in clockwise two times
        * @param vector<char>& solution
        * @return void
        *
        */
      void F2(vector<char>& solution);

      /**
        * @brief Move frontal side, not in clockwise
        * @param vector<char>& solution
        * @return void
        * @see F()
        *
        */
      void f(vector<char>& solution);

      /**
        * @brief Move back side left
        * @param vector<char>& solution
        * @return void
        * @see b()
        *
        */
      void B(vector<char>& solution);

      /**
        * @brief Move back side left two times
        * @param vector<char>& solution
        * @return void
        *
        */
      void B2(vector<char>& solution);

      /**
        * @brief Move back side right
        * @param vector<char>& solution
        * @return void
        * @see B()
        *
        */
      void b(vector<char>& solution);



      // Solve
      /**
        * @brief It solves rubik's cube in intervals
        * @param vector<char>& solution
        * @return void
        * @pre solution empty, it's modified
        * @see solve()
        *
        */
      void solveStepByStep(vector<char>& solution);

      /**
        * @brief It solves rubik cube with private auxiliary functions
        * @param vector<char>& solution
        * @return void
        * @pre solution empty, it's modified
        * @see solveStepByStep()
        *
        */
      void solve(vector<char>& solution, const char& method='B');


      // Input && output

      /**
       * @brief Rubik example file
       * @return void
       *
       */
      static void fileExample();

      /**
        * @brief It export rubik's cube in a format readable for readRubik)=
        * @param std::ostream& os=cout
        * @return void
        * @see readRubik()
        *
        */
      void exportRubik(std::ostream& os=cout) const;

      /**
        * @brief Export steps to solve rubik's cube
        * @param std::ostream& os=cout
        * @return void
        * @pre (logicErrors() == 0)
        * @see exportSupervisedSolution()
        *
        */
      void exportSolution(std::ostream& os=cout) const;

      /**
        * @brief Export steps with explanations
        * @param std::ostream& os=cout
        * @return void
        * @pre (logicErrors() == 0)
        * @see exportSolution()
        *
        */
      void exportSupervisedSolution(std::ostream& os=cout) const;

      /**
        * @brief Print sticker with specific colour
        * @param const char& c
        * @return void
        * @pre valid char
        *
        */
      void printColour(const char& c) const;

      /**
        * @brief Print a rubik's cube with numbers to correct mistakes
        * @param std::ostream& os=cout
        * @return void
        * @see correctMistakes()
        *
        */
      //static
      static void printNumbers(std::ostream& os=cout);

      /**
        * @brief Print rubik's cube with respective colours
        * @return void
        * @see printColour()
        *
        */
      void printAll() const;


      /**
        * @brief Read specific sticker from rubik's cube
        * \note Rubik is modified
        * @param char& c, is modified
        * @param std::istream& is=cin
        * @return void
        * @pre char& c is a sticker of the instance
        * @see readRubik()
        *
        */
      void readSticker(char& c, std::istream& is=cin);

      /**
        * @brief Read rubik's cube
        * \note It's modified
        * @param std::istream& is=cin
        * @return void
        * @pre Readable istream with correct rubik's format
        * @see readSticker()
        *
        */
      void readRubik(std::istream& is=cin);


      // Getter
      /**
        * @brief Getter of center piece
        * @param const int& position
        * @return Center
        * @pre Valid position
        * @see Center
        *
        */
      Center getCenter(const int& position) const;

      /**
        * @brief Getter of specific edge
        * @param const int& position
        * @return Edge
        * @pre Valid position
        * @see Edge
        *
        */
      Edge getEdge(const int& position) const;

      /**
        * @brief Getter of specific corner
        * @param const int& position
        * @return Corner
        * @pre Valid position
        * @see Corner
        *
        */
      Corner getCorner(const int& position) const;

      /**
       * @brief It creates a random rubik's cube
       * @return Rubik
       *
       */
      static Rubik randomRubik();

      // Operators
      /**
        * @brief Assigment operator
        * \note It's modified
        * @param const Rubik& r
        * @return Rubik&
        * @retval *this
        * @pre r different rubik's cube
        * @see operator ==
        *
        */
      Rubik& operator = (const Rubik& r);

      /**
        * @brief Operator ==
        * @param const Rubik& r
        * @return bool
        * @pre r different rubik's cube
        *
        */
      bool operator == (const Rubik& rubik);

      /**
        * @brief Operator !=
        * @param const Rubik& r
        * @return bool
        * @pre r different rubik's cube
        *
        */
      bool operator != (const Rubik& rubik);
};

/**
 * @brief Ostream in readable format
 * @param std::ostream& os
 * @param const Rubik& rubik
 * @return std::ostream&
 *
 */
std::ostream& operator << (std::ostream& os, const Rubik& rubik);

/**
 * @brief Istream of a rubik's cube in readable format
 * @param std::istraem& is
 * @param Rubik& rubik, it's modified
 * @return std::istream&
 *
 */
std::istream& operator >>(std::istream& is, Rubik &rubik);


// Presentation
/**
 * @brief Guide of program
 * @return void
 *
 */
void guide();

/**
 * @brief Presentation of program
 * @return void
 *
 */
void presentation();

/**
 * @brief Explication of valid movements
 * @return void
 *
 */
void movements();

/**
 * @brief Explication of program's arguments
 * @param string name of main program
 * @return void
 *
 */
void arguments(string name);


#endif
