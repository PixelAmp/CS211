//=========================================================
//HW#: HW2P2
//Your name: Raul Perez
//Complier:  g++
//File type: source code file
//===========================================================

#include <iostream>
#include <vector>
using namespace std;

void combine(const vector<int>, const vector<int>, vector<int>&);

//Algorithm:: This program combines and sorts two user entered arrays by comparing the elements from top to bottom,
//adding them into a new array in ascending order by using merge sort

int main()
{
  //declaration of the vectors used in the program
  vector <int> L1,L2,L3;
  int i; //temporary integer, holds user input
  int arrSize; //holds the amount of elements that will be in the arrays


  //gets the amount of items in each of the arrays
  cout << "How many items in each array?" << endl;
  cin >> arrSize;

  //gets numbers to be stored in the first array
  cout << "Enter numbers for the first array, one at a time\n" << endl;
  for (int j=0; j<arrSize; j++) //L1
    {
      cout << "L1." << (j+1) << ": " ;
      cin >> i;

      L1.push_back(i); //pushes number into the array
    }

  //gets numbers to be stored in second array
  cout << "Enter numbers for the first array, one at a time\n" << endl;
  for (int j=0; j<arrSize; j++) //L2
    {
      cout << "L2." << (j+1) << ": " ;
      cin >> i;

      L2.push_back(i); //pushes number into the array
    }


  //Puts the size of the array into L3 so that I dont have to pass another variable, will be removed once in the combine function
  L3.push_back((arrSize));

  //calls sort function
  combine(L1,L2,L3);

  //makes space, I dunno
  cout << endl;


  cout << "The sorted array:" << endl;
  //outputs the sorted array, array size is doubled because the two arrays were combined
  for (int j=0; j<(arrSize*2); j++)
    {
      cout << L3[j] << " " ;
    }

  cout << endl;

  return 0;
}

void combine(const vector<int> L1, const vector<int> L2, vector<int>& L3)
{
  //moves count from vector to a holder variable
  int amount = L3[0];

  //removes the number from the vector, leaving it empty and ready to the sorted elements
  L3.pop_back();

  int loopCount = 0; //counts the amount of thimes the loop has looped

  int p1 = 0, p2 = 0; //points to the front element of the designated array


  //program keeps running while there are still elements in the vectors
  while(loopCount != (amount*2))//(p1 != amount) && (p2 != amount))
    {
      //if the first vector has been depleted, but the second one has not, pushes back elements from the second vector
      if ((p1 == amount) && (p2 != amount))
        {
	  L3.push_back(L2[p2]);
	  p2++; //increments the position of the front pointer
        }

      //if the second vector has depleted but the first one has not, pushes back elements from the first vector
      else if ((p1 != amount) && (p2 == amount))
        {
	  L3.push_back(L1[p1]);
	  p1++; //increments the position of the front pointer
        }

      //if the numbers are equal just grabs the number from vector L1
      else if (L1[p1] == L2[p2])
        {
	  cout << "comparison" << endl;
	  L3.push_back(L1[p1]);
	  p1++; //increments the position of the front pointer
        }

      //if the element in the first array is bigger, moves it to the sorted array
      else if (L1[p1] < L2[p2])
        {
	  cout << "comparison" << endl;
	  L3.push_back(L1[p1]);
	  p1++; //increments the position of the front pointer
        }

      //if the element in the second array is bigger, moves it to the sorted array
      else if (L1[p1] > L2[p2])
        {
	  cout << "comparison" << endl;
	  L3.push_back(L2[p2]);
	  p2++; //increments the position of the front pointer
        }

      loopCount++;
    }
}

