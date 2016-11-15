#include <iostream>

using namespace std;

int binarySearch(int [],int,int,int);

// in main
int main()
{
  //initalize the sorted list
  int myList[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
  //hold the size of the array
  int listSize = 10;
  //holds position of the fron element
  int myfirst = 0;
  //holds the position of the last element
  int mylast = listSize-1;
  //holds the element that we are supposed to look for
  int findthis;

  //Have user enter the number they would like to look for
  cout << "What number would you like to look for? " << endl;
  cin >> findthis;

    //calls recoursive binary function
  int resultloc = binarySearch(myList, findthis, myfirst, mylast);

  //This is the fail case in the situation where the element was not found
    if (resultloc == -1)
    {
        cout << findthis << " was not found in the array" << endl;
    }

    else
    {
  cout << "Element " << findthis << " was found in position " << resultloc << "!" << endl;
    }
}


// the function – note that floor means round down
int binarySearch(int L[],int x,int first,int last)
{
  // splits array in half by adding the postion of the fist and last numbers in the array, rounds down
  int middle = (first+last)/2;

  //cout << "Looking in position " << middle << endl;

  //compares the requested element against the middle element, returns position +1 if true
  if (x == L[middle])
    {
        //adds a one to reperesent the correct position in the array, since it started at 0, instead of 1
      return middle+1;
    }

    if (first == last)
    {
        //returns negative one to signify that the element was not found in the array
        //negative number because even if the array changes size, position will never be negative
        return -1;
    }

  //if requested number is less than the middle number, make the middle number the largest number in the next search, cutting the array in half
  else if (x < L[middle])
    {
      last = middle - 1; // go to first half
    }

  //if requested number is greater than the middle number, make the middle number the smallest number in the next search, cutting the array in half
   else if (x > L[middle])
     {
       first = middle + 1; // go to second half
     }

    // recursive call
  return binarySearch(L, x, first, last);
}
