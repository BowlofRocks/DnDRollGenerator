//Define iosteam.
#include <iostream>

//Include Math
#include <cmath>

//Include Vector
#include <vector>

//Import random.
#include <cstdlib>

//Std namespace.
using namespace std;


/************************************************************************
* GET ARRAY SIZE
* Prompt user for array size to generate array.
************************************************************************/
int getArraySize()
{
   int size;

   cout << "What is the array size? ";
   cin  >> size;

   return size;
}

/************************************************************************
* GET ARMOR CLASS
* Prompt user for armor class.
************************************************************************/
int getArmorClass()
{
   int ac;

   cout << "What is the armor class? ";
   cin  >> ac;

   return ac;
}

/************************************************************************
* GET HIT MODIFIER
* Prompt user for hit modifier to add to the values for array.
*************************************************************************/
int getHitModifier()
{
   int hitMod;

   cout << "What is the hit modifier number? ";
   cin  >> hitMod;

   return hitMod;
}

/************************************************************************
* CREATE ARRAY
* Create an array of random numbers between 1-20 based on the array size.
*************************************************************************/
vector<int> createArray(int arraySize, int hitModifier  )
{
   vector<int> array;

   for (auto i = 0; i < arraySize; i++)
   {
      int rolledVal = (rand() % 20 + 1) + hitModifier; 
      array.push_back(rolledVal);
   }
   return array;

}

/************************************************************************
* DISPLAY ARRAY
* Display to the user the array of numbers with the hit mod added into it.
*************************************************************************/
void displayArray(vector<int> array, int arraySize)
{
   cout << "Rolled Numbers: ";

   for (auto i = 0; i < arraySize; i++)
   {
      cout << array[i] << " ";
   }
}

/************************************************************************
* COUNT HITS
* Count the number of times a value of hit vector >= armor class. 
*************************************************************************/
int countHits(vector<int> hitArray, int hitMod, int arraySize, int armorClass)
{
   int counter = 0;

   for (auto i = 0; i < arraySize; i++)
   {
      if (hitArray[i] >= armorClass)
         counter += 1;
   }

   return counter;
}

/************************************************************************
* DISPLAY HITS
* Display how many times the array beat armor class.
*************************************************************************/
void displayHits(int numOfHits)
{
   cout << "This character has been hit " << numOfHits << " times!";
}

/***********************************************************************
* MAIN
* There can only be one
************************************************************************/
int main()
{
   //INPUT
   int arraySize        = getArraySize  ();
   int armorClass       = getArmorClass ();
   int hitModifier      = getHitModifier();
   vector<int> hitArray = createArray   (arraySize, hitModifier);
   int numberOfHits     = countHits     (hitArray, hitModifier, arraySize, armorClass);
   
   
   displayArray(hitArray, arraySize);
   displayHits (numberOfHits);

   return 0;
}

