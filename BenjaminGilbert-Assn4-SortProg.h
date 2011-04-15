/******************************************************************************
 * Filename     : BenjaminGilbert-Assn4-SortProg.cpp
 * Description  : 
 * Date         : 4/24/2011
 * Designer     : Reggi Benjamin
 *				  Nicholas Gilbert
 * Functions    : 
 ******************************************************************************/
#include <iostream>

using namespace std;

// Global Constants ////////////////////////////////////////////////////////////
const int MAX_ARRAY_SIZE = 100000;
const int MAX_NUMBER_USER_SELECTIONS = 2;

enum UserSelections
{
  SELECTION_BUBBLE = 0,
  SELECTION_INSERTION,
  SELECTION_MERGE,
  SELECTION_QUICK,
  SELECTION_EXIT,
  SELECTION_COUNT
};


// Prototypes //////////////////////////////////////////////////////////////////
void InitializeArrayOfRandomIntegers( int randomIntegers[] );


/******************************************************************************
 * Description  : 
 * OUTPUT
 *   Return     : 
 * Calls To     : 
 *****************************************************************************/
int main( int argc, char* argv[] )
{
  int randomIntegers[MAX_ARRAY_SIZE];
  UserSelections userSelections[SELECTION_COUNT];
  
  InitializeArrayOfRandomIntegers( randomIntegers );
  
  // system pause prior to program exit
  cin.ignore( 100, '\n');
  cout << endl << "Press ENTER to exit.";
  cin.get();
  cout << endl;
  return 0;
}

//*********************************************************************
// FUNCTION       : InitializeArrayOfRandomIntegers
// DESCRIPTION    : generates an array of random numbers between 1 and 
//			            30,000
// INPUT
//	   Parameters	: randomIntegers[]  int array to put numbers in
// OUTPUT   
//  	Parameters	: randomIntegers[]  int array to put numbers in
// CALLS TO	      : none
// IMPLEMENTED BY	: 
//**********************************************************************
void InitializeArrayOfRandomIntegers( int randomIntegers[] )
{
  const int RANDOM_MAX = 30000,
            RANDOM_MIN = 1;
  
  // seed random number generator
  srand( (unsigned)time(NULL) );
  
  // create random numbers
  for( int iter = 0; iter < MAX_ARRAY_SIZE; ++iter )
    listOfIntegers[iter] = rand() % RANDOM_MAX + RANDOM_MIN;
}

//*****************************************************************
// FUNCTION		: GetUserSelections
// DESCRIPTION	: gets user choices for sorts to run and times to 
//				run them
// INPUT
//	Parameters	: maxSelections	- number of sorts to select
// OUTPUT   
//  	Parameters	: iterations	- number of iterations to perform
//			  selections	- array of enumerated type Selections
// CALLS TO		: none
// IMPLEMENTED BY	: 
//**********************************************************************
void GetUserSelections( int maxSelections, int &iterations, Selections[] selections )
{
}


/******************************************************************************
// FUNCTION		    : 
// DESCRIPTION    	: 
// INPUT
//		Parameters	:
// OUTPUT   	
//  	Return Val	: 
//  	Parameters	: 
// CALLS TO			: 
// IMPLEMENTED BY 	: 
/*****************************************************************************/
