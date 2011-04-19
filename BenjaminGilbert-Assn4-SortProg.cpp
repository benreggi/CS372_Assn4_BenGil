/******************************************************************************
 * Filename     : GilbertReggi-Assn4-SortProg.cpp
 * Description  : 
 * Date         : 4/26/2011
 * Designer     : Reggi Benjamin
 *				        Nicholas Gilbert
 * Functions    : InitializeArrayOfRandomIntegers  ( int randomIntegers[] );
 *                GetUserSelections
 *                PerformSort
 *                PerformBubbleSort
 *                PerformInsertionSort
 *                PerformMergeSort
 *                MergeSort
 *                MergeList
 *                PerformQuickSort
 *                QuickSort
 *                VerifySortedArray
 *                DisplayResultAverage
 ******************************************************************************/
#include <iostream>
#include <string>
#include <cctype>
#include <ctime>

using namespace std;

typedef void (*pt2SortFunction)(int unorderedIntegers[]);

// Global Constants ////////////////////////////////////////////////////////////
const int SORT_ERROR = -1;
const int MAX_ARRAY_SIZE = 10;
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
void InitializeArrayOfRandomIntegers  ( int randomIntegers[] );
void GetUserSelections                ( int &iterations,
                                        UserSelections selections[] );
int PerformSort                       ( void (*pt2SortFunction)
                                             (int randomIntegers[]) );
void PerformBubbleSort                ( int unorderedIntegers[] );
void PerformInsertionSort             ( int unorderedIntegers[] );
void PerformMergeSort                 ( int unorderedIntegers[] );
void MergeSort                        ( int unorderedList[],
                                        int lowIdx,
                                        int highIdx );
void MergeList                        ( int unorderedList[],
                                        int lowIdx,
                                        int midIdx,
                                        int highIdx );
void PerformQuickSort                 ( int unorderedIntegers[] );
void QuickSort                        ( int unorderedList[],
                                        int lowIdx,
                                        int highIdx);
bool VerifySortedArray                ( int sortedIntegers[] );
void DisplayResultAverage             ( int **sortTimesByType );

// TEMPORARY METHOD TO PRINT ARRAY
void PrintArray(int array[])
{
  for( int i = 0; i < MAX_ARRAY_SIZE; ++i )
    cout << array[i] << ", ";
}

//*********************************************************************
// FUNCTION       : main
// DESCRIPTION    : calls functions to let user choose 2 types of sorts
//                  and compare the time taken to sort identical lists
//                  using both methods
// INPUT
//	Parameters    : none
// OUTPUT   	
//  	Return Val	: 
// CALLS TO       : GetUserSelections, PerformSort, DisplayResults
// IMPLEMENTED BY	: Nick
//**********************************************************************
int main( int argc, char* argv[] )
{
  int iterations = 0;
  UserSelections userSelections[SELECTION_COUNT];
  pt2SortFunction sortFunctions[SELECTION_COUNT-1] = { NULL };
  sortFunctions[SELECTION_BUBBLE] = &PerformBubbleSort;
  sortFunctions[SELECTION_INSERTION] = &PerformInsertionSort;
  sortFunctions[SELECTION_MERGE] = &PerformMergeSort;
  sortFunctions[SELECTION_QUICK] = &PerformQuickSort;
  int **sortTimes = new int *[SELECTION_COUNT];
  
  GetUserSelections( iterations, userSelections );
  
  for( int sortSelectionIter = 0; sortSelectionIter < 1; ++sortSelectionIter )
  {
    sortTimes[userSelections[sortSelectionIter]] = new int[iterations];
    for( int iter = 0; iter < iterations; ++iter )
      sortTimes[userSelections[sortSelectionIter]][iter] = PerformSort(sortFunctions[userSelections[sortSelectionIter]]);
  }
  
  DisplayResultAverage( sortTimes );
  
  // system pause prior to program exit
  cin.ignore( 100, '\n');
  cout << endl << "Press ENTER to exit.";
  cin.get();
  cout << endl;
  return 0;
}

//*****************************************************************
// FUNCTION       : GetUserSelections
// DESCRIPTION    : gets user choices for sorts to run and times to 
//                  run them
// INPUT
//	Parameters    : maxSelections	- number of sorts to select
// OUTPUT   
//  	Parameters	: iterations	- number of iterations to perform
//                  selections	- array of enumerated type Selections
// CALLS TO       : none
// IMPLEMENTED BY : Ben
//**********************************************************************
void GetUserSelections( int &iterations, UserSelections selections[] )
{
}

//*********************************************************************
// FUNCTION       : InitializeArrayOfRandomIntegers
// DESCRIPTION    : generates an array of random numbers between 1 and 
//			            30,000
// INPUT
//	   Parameters	: unorderedIntegers[]  int array to put numbers in
// OUTPUT   
//  	Parameters	: unorderedIntegers[]  int array to put numbers in
// CALLS TO	      : none
// IMPLEMENTED BY	: Nick
//**********************************************************************
void InitializeArrayOfRandomIntegers( int unorderedIntegers[] )
{
  const int RANDOM_MAX = 30000,
            RANDOM_MIN = 1;
  
  // seed random number generator
  srand( (unsigned)time(NULL) );
  
  // create random numbers
  for( int iter = 0; iter < MAX_ARRAY_SIZE; ++iter )
    unorderedIntegers[iter] = rand() % RANDOM_MAX + RANDOM_MIN;
}

//*********************************************************************
// FUNCTION       : PerformSort
// DESCRIPTION    : Executes the passed in sort function and monitors
//                  the time it takes to execute.
// INPUT
//	Parameters    : (*pt2SortFunction)   - pointer to function
// OUTPUT   
//	Return        : int				           - time taken to execute
// CALLS TO       : InitializeArrayOfRandomIntegers
//                  pt2SortFunction
//                  VerifyOrderedArray
// IMPLEMENTED BY : Nick
//*********************************************************************
int PerformSort(void (*pt2SortFunction)(int unorderedIntegers[]))
{
  int startTime, endTime;
  int unorderedIntegers[MAX_ARRAY_SIZE];
  
  InitializeArrayOfRandomIntegers( unorderedIntegers );
  
  startTime = clock();  
  (*pt2SortFunction)(unorderedIntegers);    
  endTime = clock();
  
   if( VerifySortedArray( unorderedIntegers ) )
    return endTime - startTime;
  
  return SORT_ERROR;
}

//*********************************************************************
// FUNCTION       : PerformBubbleSort
// DESCRIPTION	  : sorts an array of integers using the bubble sort
//                  method
// INPUT
//	Parameters	  : unorderedIntegers[] - array of unordered integers
// OUTPUT   
//  	Parameters	: unorderedIntegers[] - int array of sorted numbers
//	Return        : void
// CALLS TO       : 
// IMPLEMENTED BY	: Ben
//*********************************************************************
void PerformBubbleSort( int unorderedIntegers[] )
{
}

//*********************************************************************
// FUNCTION       : PerformInsertionSort
// DESCRIPTION    : sorts an array of integers using the insertion sort
//                  method
// INPUT
//	Parameters    : unorderedIntegers[] - array of unordered integers
// OUTPUT   
//  	Parameters	: unorderedIntegers[] - int array of sorted numbers
//	Return        : void	- time taken to sort
// CALLS TO		    : 
// IMPLEMENTED BY	: Nick
//*********************************************************************
void PerformInsertionSort( int unorderedIntegers[] )
{
  int remainTopIdx = 1,
      lastIdx = MAX_ARRAY_SIZE - 1,
      insertValue = 0,
      currentIdx = 0;
  
  while( remainTopIdx <= lastIdx )
  {
    insertValue = unorderedIntegers[remainTopIdx];
    currentIdx = remainTopIdx - 1;
    
    while( currentIdx >= 0 && insertValue < unorderedIntegers[currentIdx] )
    {
      unorderedIntegers[currentIdx + 1] = unorderedIntegers[currentIdx];
      currentIdx--;
    }
    
    unorderedIntegers[currentIdx + 1] = insertValue;
    remainTopIdx++;
  }
}

//*********************************************************************
// FUNCTION       : PerformMergeSort
// DESCRIPTION    : sorts an array of integers using the merge sort
//                  method
// INPUT
//	Parameters    : unorderedIntegers[] - array of unordered integers
// OUTPUT   
//  	Parameters	: unorderedIntegers[] - array of sorted integers
//	Return        : void
// CALLS TO       : MergeSort
//                  MergeList
// IMPLEMENTED BY : Nick
//*********************************************************************
void PerformMergeSort( int unorderedIntegers[] )
{
  MergeSort( unorderedIntegers, 0, MAX_ARRAY_SIZE );
}

//*********************************************************************
// FUNCTION       : MergeSort
// DESCRIPTION    : Recursive implementation of merge sort algorithm
// INPUT
//	Parameters    : lowIdx		- low index of range in list to merge
//                  highIdx		- high index of range “ “ “ “
// OUTPUT   
//  	Parameters	: unorderedList[] 	- array fully or partially ordered numbers
//    Return      : void
// CALLS TO       : MergeList 
// IMPLEMENTED BY : Nick
//*********************************************************************
void MergeSort (int unorderedList[], int lowIdx, int highIdx )
{
  int midIdx = 0;
  
  if(lowIdx < highIdx)
  {
    midIdx = (lowIdx + highIdx) / 2;
    
    MergeSort(unorderedList, lowIdx, midIdx);
    MergeSort(unorderedList, midIdx + 1, highIdx);
    MergeList(unorderedList, lowIdx, midIdx, highIdx);
  }
}

//*********************************************************************
// FUNCTION       : MergeList
// DESCRIPTION    : Merges, in order, two sections of a list created
//                  by merge sort.
// INPUT
//	Parameters    : lowIdx		- low index of range in list to merge
//                  midIdx		- middle index of range “ “ “ “
//                  highIdx		- high index of range “ “ “ “
// OUTPUT   
//  	Parameters	: unorderedList[] 	- array fully or partially ordered numbers
//    Return      : void
// CALLS TO       : none
// IMPLEMENTED BY : Nick
//*********************************************************************
void MergeList( int unorderedList[], int lowIdx, int midIdx, int highIdx )
{
  int temp[MAX_ARRAY_SIZE];  
  int leftIdx = lowIdx;
  int rightIdx = midIdx + 1;
  int tempPos = lowIdx;
  
  while((leftIdx <= midIdx) && (rightIdx <= highIdx))
  {
    if(unorderedList[leftIdx] <= unorderedList[rightIdx])
    {
      temp[tempPos] = unorderedList[leftIdx];
      ++leftIdx;
    }
    else
    {
      temp[tempPos] = unorderedList[rightIdx];
      ++rightIdx;
    }
    ++tempPos;
  }
  
  // loop additional elements on left side
  while(leftIdx <= midIdx)
  {
    temp[tempPos] = unorderedList[leftIdx];
    ++tempPos;
    ++leftIdx;
  }
  
  // loop additional elements on right side
  while(rightIdx <= highIdx)
  {
    temp[tempPos] = unorderedList[rightIdx];
    ++tempPos;
    ++rightIdx;
  }
  
  for(int i=lowIdx;i<tempPos;i++)
		unorderedList[i]= temp[i];
}

//*********************************************************************
// FUNCTION       : PerformQuickSort
// DESCRIPTION    : sorts an array of integers using the quick sort
//                  method
// INPUT
//    Parameters	: unorderedIntegers[] - array of unordered integers
// OUTPUT   
//  	Parameters	: unorderedIntegers[] - int array of sorted numbers
//    Return      : void
// CALLS TO       : 
// IMPLEMENTED BY : Ben
//*********************************************************************
void PerformQuickSort( int unorderedIntegers[] )
{
}

//*********************************************************************
// FUNCTION       : QuickSort
// DESCRIPTION    : Recursive implementation of quick sort algorithm
// INPUT
//	Parameters    : lowIdx		- low index of range in list to merge
//			            highIdx		- high index of range “ “ “ “
// OUTPUT   
//  	Parameters	: unorderedIntegers[] 	- array fully or partially ordered numbers
//    Return      : void
// CALLS TO       : PerformInsertionSort
// IMPLEMENTED BY : Ben
//*********************************************************************
void QuickSort( int unorderedIntegers[], int lowIdx, int highIdx )
{
}

//*********************************************************************
// FUNCTION       : VerifySortedArray
// DESCRIPTION    : verifies that an array of numbers has been sorted
//                  and outputs an error message to the screen if it 
//                  is not
// INPUT
//    Parameters	: sortedIntegers[] - int array to be verified
// OUTPUT   	
//  	Return Val	: bool	 - true if sorted
//    CALLS TO    : none
// IMPLEMENTED BY : Ben
//*********************************************************************
bool VerifySortedArray( int sortedIntegers[] )
{
}

//*********************************************************************
// FUNCTION       : DisplayResults
// DESCRIPTION    : displays average sort times for each sort type
// INPUT
//	Parameters    : sortTimesByType[] - 2 dimensional array
//						      [type][times]
// OUTPUT   	
//  	Return Val	: void
// CALLS TO       : none
// IMPLEMENTED BY : Ben
//*********************************************************************
void DisplayResultAverage( int **sortTimesByType )
{
}
