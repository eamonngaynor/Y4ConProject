/** Conleth Coughlan 
 * C00197482
 *
 * Eamonn Gaynor
 *C00197458
 *
 *Wator simulator
 *CDDProject
 *
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <string>
using namespace std;

class Fish{
public:
  string kind = "fish";
  bool exists=false;
  int breedAge=0;
};

class Shark: public Fish{
public:
  string kind="shark";
  int starveAge=0;
};



int main(void){
  int numShark=10;
  int numFish=10;
  int fishBreed=10;
  int sharkBreed=10;
  int starve=10;
  int gridRows=10;
  int gridColumns=10;
  /*int numShark, numFish, fishBreed, sharkBreed, starve, gridRows, gridColumns;
   cout << "Enter the number of sharks you want in the simulation:";
  cin >> numShark;
  cout << "Enter the number of fish you want in the simulation:";
  cin >> numFish;
  cout << "Enter the number of turns before a shark can breed:";
  cin >> sharkBreed;
  cout << "Enter the number of turns before a fish can breed:";
  cin >> fishBreed;
  cout << "Enter the number of turns before a shark starves:";
  cin >> starve;
  cout << "Enter the number of rows :";
  cin >> gridRows;
  cout << "Enter the number of columns:";
  cin >> gridColumns;
  */

  if((gridRows*gridColumns)<(numShark+numFish)){
    cout << "Not enough spaces for number of fish and sharks\n";
  } //end of if

  vector< vector<Fish> > ocean(gridColumns, vector<Fish>(gridRows));

  Fish fishStore [gridRows][gridColumns];
  for(int i=0; i<numFish; i++){
    bool foundLocation=false;
    while (foundLocation==false){
      int columnLocation = rand() % gridColumns;
      int rowLocation = rand() % gridRows;
      if((fishStore[rowLocation][columnLocation]).exists==false)
	{
	  fishStore[rowLocation][columnLocation].exists=true;
	  ocean[rowLocation][columnLocation] = fishStore[rowLocation][columnLocation];
	  foundLocation=true;
	}//end if
    }//end whileloop
    
    
  }//end fish forloop

  Shark sharkStore [gridRows][gridColumns];
  for(int i=0; i<numShark; i++){
    bool foundLocation=false;
    while (foundLocation==false){
      int columnLocation = rand() % gridColumns;
      int rowLocation = rand() % gridRows;
      if((ocean[rowLocation][columnLocation]).exists==false)
	{
	  sharkStore[rowLocation][columnLocation].exists=true;
	  ocean[rowLocation][columnLocation] = sharkStore[rowLocation][columnLocation];
	  foundLocation=true;
	}//end if
    }//end whileloop
    
    
  }//end shark forloop

  for (int i=0; i<gridRows; i++)
    {
      for(int j=0; j<gridColumns; j++)
	{
	  if(ocean[i][j].exists==true)
	    {
	      if(ocean[i][j].kind=="fish")
		{
		  cout << "F";
		} // end fish if
	      else
		{
		  cout << "S";
		} // end shark if
	    } //end exists if
	  else
	    {
	      cout << ".";
	    }
	  cout << " ";
	  
	} //end columns for

      cout << "\n";
    }//end rows forloop
  Fish fishy;
    cout << fishy.breedAge;

  
  
  
  return 0;
} // end of main
