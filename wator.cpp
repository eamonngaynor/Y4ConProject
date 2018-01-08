
/*
 |---------------------------------------------------------|
 | 							   |
 | Students: Eamonn Gaynor (C00197458)			   |
 |	     Conleth Coughlan (C00197482)		   |
 |							   |
 | Purpose: Wator Simulation 				   |
 |                                                         |
 |							   |
 | Date: 08/01/2017					   |
 |							   |
 |							   |
 ----------------------------------------------------------|
*/


#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
using namespace std;




// -------------------- Class declarations (Fish + Shark) ------------------------------------------------------------------------------------------------------

// Fish Class
class Fish {
public:
    string type = "fish";
    bool exists = false;
    int breedAge = 0;
    void setAge(int age)
    {
        breedAge = age;
    }
    int getBreedAge()
    {
        return this->breedAge;
    }
    void incrementBreedAge()
    {
        ++breedAge;
    }
    void resetBreedAge()
    {
        breedAge = 0;
    }
};

// Shark Class 
class Shark {
public:
    string type = "shark";
    bool exists = false;
    int breedAge = 0;
    int starveAge = 0;
    void incrementStarve()
    {
        ++starveAge;
    }
    int getStarve()
    {
        return this->starveAge;
    }
    void resetStarve()
    {
        starveAge = 0;
    }
    void setAge(int age)
    {
        breedAge = age;
    }
    int getBreedAge()
    {
        return this->breedAge;
    }
    void incrementBreedAge()
    {
        ++breedAge;
    }
    void resetBreedAge()
    {
        breedAge = 0;
    }
};







//-----------------------------------  FISH Direction method -----------------------------------------------------------------------------------------------------
int findDirection(int i, int j, int gridRows, int gridColumns, vector<vector<Fish> > fishMovedOcean, vector<vector<Shark> > sharkMovedOcean)
{
    //Initializing directions to false, declaring variables
    int checkCount = 0;
    bool direction[4];
    direction[0] = false;
    direction[1] = false;
    direction[2] = false;
    direction[3] = false;
    bool directionFound = false;
    while (directionFound == false)

    {

        //------------------------------- Fish going left -----------------------------------------------------

        int randDirection = rand() % 4;
        if (randDirection == 0 && direction[0] != true) //If returns 1 fish is going left
        {
            if (i == 0) {
                if (fishMovedOcean[gridColumns - 1][j].exists == true || sharkMovedOcean[gridColumns - 1][j].exists == true) {
                    direction[0] = true;
                    checkCount++;
                } //end if i is 0 exists check
                else {

                    return 1;
                } //end else if i is 0
            } //end if i is 0
            else {
                if (fishMovedOcean[(i - 1)][j].exists == true || sharkMovedOcean[(i - 1)][j].exists == true) {
                    direction[0] = true;
                    checkCount++;
                } //end if i not 0 exists check
                else {

                    return 1;

                } //end else if i non zero
            } //end else i is non zero
        } //end rand direction = 1

        //----------------------------- Fish going up --------------------------------------------------------------

        if (randDirection == 1 && direction[1] != true) //If returns 2 test if fish can go up
        {
            if (fishMovedOcean[i][(j + 1) % gridRows].exists == true || sharkMovedOcean[i][(j + 1) % gridRows].exists == true) {
                direction[1] = true;
                checkCount++;
            } //end if dir=2
            else {

                return 2;

            } //end else dir=2
        } //end outside if

        //----------------------------- Fish going right -------------------------------------------------------------

        if (randDirection == 2 && direction[2] != true) //If returns 3 fish trys to go right
        {
            if (fishMovedOcean[(i + 1) % gridColumns][j].exists == true || sharkMovedOcean[(i + 1) % gridColumns][j].exists == true) {
                direction[2] = true;
                checkCount++;
            } //end if dir=1
            else {

                return 3;

            } //end else dir=1
        } //end outside if

        //----------------------------- Fish going down ---------------------------------------------------------------

        if (randDirection == 3 && direction[3] != true) //If returns 4 fish tries to go down
        {
            if (j == 0) {
                if (fishMovedOcean[i][gridRows - 1].exists == true || sharkMovedOcean[i][gridRows - 1].exists == true) {
                    direction[0] = true;
                    checkCount++;
                } //end if j is 0 exists check
                else {

                    return 4;

                } //end else if j is 0
            } //end if j is 0
            else {
                if (fishMovedOcean[i][j - 1].exists == true || sharkMovedOcean[i][j - 1].exists == true) {
                    direction[0] = true;
                    checkCount++;
                } //end if i not 0 exists check
                else {

                    return 4;

                } //end else if i non zero
            } //end else i is non zero
        } //end outside if

        if (checkCount == 4) {
            return 0;
        }
    }
}
//------------------------------ /End - Fish direction method ---------------------------------------------------------------------------------------------------







//----------------------------------- SHARK Direction and Fish Search method -------------------------------------------------------------------------------------

int findSharkDirection(int i, int j, int gridRows, int gridColumns, vector<vector<Shark> > sharkMovedOcean, vector<vector<Fish> > fishMovedOcean)
{


    //Initializing directions to false, declaring variables
    int checkCount = 0;
    bool direction[4];
    direction[0] = false;
    direction[1] = false;
    direction[2] = false;
    direction[3] = false;
    bool freeSpaces[4];
    freeSpaces[0] = false;
    freeSpaces[1] = false;
    freeSpaces[2] = false;
    freeSpaces[3] = false;
    bool directionCheck[4];
    directionCheck[0] = false;
    directionCheck[1] = false;
    directionCheck[2] = false;
    directionCheck[3] = false;
    bool nearbyFishFound = false;
    while (nearbyFishFound == false) {
        int randDirection = rand() % 4;
        if (randDirection == 0 && direction[0] != true) //Check up for a fish
        { //if1
            if (i == 0) //if2
            {
                if (fishMovedOcean[gridColumns - 1][j].exists == true) {
                    return 1;

                } //end if i is 0 exists check
                else { //else1
                    direction[0] = true;
                    checkCount++;
                    if (fishMovedOcean[gridColumns - 1][j].exists == false && sharkMovedOcean[gridColumns - 1][j].exists == false) {
                        freeSpaces[0] = true;
                    } //end check if false
                } //end else1

            } //if2
            else { //else2
                if (fishMovedOcean[(i - 1)][j].exists == true) {
                    return 1;

                } //end if i not 0 exists check
                else { //else3
                    direction[0] = true;
                    checkCount++;
                    if (fishMovedOcean[i - 1][j].exists == false && sharkMovedOcean[i - 1][j].exists == false) {
                        freeSpaces[0] = true;
                    } //end check if false
                } //end else3
            } //end else2
        } //end if1

        //--------------------------------------------------------------------------------------------------------------------------------------
        if (randDirection == 1 && direction[1] != true) //If returns 2 shark goes right
        { //if3
            if (fishMovedOcean[i][(j + 1) % gridRows].exists == true) {
                return 2;
            }
            else { //else3
                direction[1] = true;
                checkCount++;
                if (fishMovedOcean[i][(j + 1) % gridRows].exists == false && sharkMovedOcean[i][(j + 1) % gridRows].exists == false) {
                    freeSpaces[1] = true;
                } //end check if false
            } //end else3
        } //end if3

        //---------------------------------------------------------------------------------------------------------------
        if (randDirection == 2 && direction[2] != true) //If returns 3 shark goes down
        { //if4
            if (fishMovedOcean[(i + 1) % gridColumns][j].exists == true) {
                return 3;
            }
            else { //else4
                direction[2] = true;
                checkCount++;
                if (fishMovedOcean[(i + 1) % gridColumns][j].exists == false && sharkMovedOcean[(i + 1) % gridColumns][j].exists == false) {
                    freeSpaces[2] = true;
                } //end check if false

            } //end else4
        } //end if4
        //-----------------------------------------------------------------------------------------------------------------
        if (randDirection == 3 && direction[3] != true) //If returns 4 shark goes left
        { //if5
            if (j == 0) { //if6
                if (fishMovedOcean[i][gridRows - 1].exists == true) {
                    return 4;
                }
                else { //else5
                    direction[3] = true;
                    checkCount++;
                    if (fishMovedOcean[i][gridRows - 1].exists == false && sharkMovedOcean[i][gridRows - 1].exists == false) {
                        freeSpaces[3] = true;
                    }

                } //end else5
            } //end if6
            else { //else6
                if (fishMovedOcean[i][j - 1].exists == true) {
                    return 4;
                }
                else { //else7
                    direction[3] = true;
                    checkCount++;
                    if (fishMovedOcean[i][j - 1].exists == false && sharkMovedOcean[i][j - 1].exists == false) {
                        freeSpaces[3] = true;
                    }
                } //end else7
            } //end else6
        } //end if5
       
        if (checkCount == 4) { //if6
            bool runThrough = true;
            while (runThrough == true) { //while7
                int randDirection = rand() % 4;

                int insideCheckCount = 0;
                if (randDirection == 0 && directionCheck[0] != true) { //if7
                    if (freeSpaces[0] == true) {
                        return 1;
                    }
                    else {
                        insideCheckCount++;
                        directionCheck[0] = true;
                    }
                } //end if7
                if (randDirection == 1 && directionCheck[1] != true) { //if8
                    if (freeSpaces[1] == true) {
                        return 2;
                    }
                    else {
                        insideCheckCount++;
                        directionCheck[1] = true;                        
                    }
                } //end if8
                if (randDirection == 2 && directionCheck[2] != true) { //if9
                    if (freeSpaces[2] == true) {
                        return 3;
                    }
                    else {
                        insideCheckCount++;
                        directionCheck[2] = true;
                    }
                } //end if9
                if (randDirection == 3 && directionCheck[3] != true) { //if10
                    if (freeSpaces[3] == true) {
                        return 4;
                    }
                    else {
                        insideCheckCount++;
                        directionCheck[3] = true;                        
                    }
                } //end if10

                if (insideCheckCount == 4) {
                    return 0;
                }
            } //end while7
        } //end if7
    } //end while direction found is false
}

//---------------------------------------------------- /End - SHARK Direction method -----------------------------------------------------------------------------










//------------------------------------ MAIN ----------------------------------------------------------------------------------------------------------------------

int main(void)
{


    //static variables for main
    int timeIn = 1;
    int numShark = 5;
    int numFish = 10;
    int fishBreed = 5;
    int sharkBreed = 5;
    int sharkStarve = 5;
    int gridRows = 10;
    int gridColumns = 10;

    /*----- Commented out input statements ---------------

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

//-------------------------------------------------------------

    if ((gridRows * gridColumns) < (numShark + numFish)) {
        cout << "Not enough spaces for number of fish and sharks\n";
    } //end of if


    vector<vector<Fish> > fishOcean(gridColumns, vector<Fish>(gridRows));
    vector<vector<Shark> > sharkOcean(gridColumns, vector<Shark>(gridRows));



    // Assigning Fish to Ocean ----------------------------------------------------
    srand((unsigned)time(NULL));
    Fish fishStore[gridRows][gridColumns];
    for (int i = 0; i < numFish; i++) {
        bool foundLocation = false;
        while (foundLocation == false) {

            int columnLocation = rand() % gridColumns;

            int rowLocation = rand() % gridRows;
            int fishAge = rand() % fishBreed;
            if ((fishStore[rowLocation][columnLocation]).exists == false) {
                fishStore[rowLocation][columnLocation].exists = true;
                fishStore[rowLocation][columnLocation].setAge(fishAge);
                fishOcean[rowLocation][columnLocation] = fishStore[rowLocation][columnLocation];
                foundLocation = true;
            } //end if
        } //end whileloop

    } //end fish forloop


    // Assigning Shark to Ocean ----------------------------------------------------
    Shark sharkStore[gridRows][gridColumns];
    for (int i = 0; i < numShark; i++) {
        bool foundLocation = false;
        while (foundLocation == false) {
            int columnLocation = rand() % gridColumns;
            int rowLocation = rand() % gridRows;
            int sharkAge = rand() % sharkBreed; //Getting random Shark age
            if ((fishOcean[rowLocation][columnLocation]).exists == false && (sharkOcean[rowLocation][columnLocation]).exists == false) {
                sharkStore[rowLocation][columnLocation].exists = true;
                sharkStore[rowLocation][columnLocation].setAge(sharkAge); //setSharkAge
                sharkOcean[rowLocation][columnLocation] = sharkStore[rowLocation][columnLocation];
                foundLocation = true;
            } //end if
        } //end whileloop

    } //end shark forloop




    //Output of Shark and Fish to the grid --------------------------------------------

    for (int i = 0; i < gridRows; i++) {
        for (int j = 0; j < gridColumns; j++) {
            if (fishOcean[i][j].exists == true || sharkOcean[i][j].exists == true) {
                if (fishOcean[i][j].exists == true) {
                    cout << "F";
                } // end fish if
                else {
                    cout << "S";
                } // end shark if
            } //end exists if
            else {
                cout << ".";
            }
            cout << " ";

        } //end columns for

        cout << "\n";
    } //end rows forloop

   // -----------------------------------------------------------------------------




    vector<vector<Fish> > fishMovedOcean(gridColumns, vector<Fish>(gridRows));
    fishMovedOcean = fishOcean;
    vector<vector<Shark> > sharkMovedOcean(gridColumns, vector<Shark>(gridRows));
    sharkMovedOcean = sharkOcean;


    //Counting number of Shark and Fish 
    int fishCount;
    int sharkCount;
    while (numFish != 0 || numShark != 0) {
        fishCount = 0;
        sharkCount = 0;
        for (int i = 0; i < gridRows; i++) {
            for (int j = 0; j < gridColumns; j++) {

                if (fishOcean[i][j].exists == true) {
                    bool breed = false;
                    ++fishCount;
                    if (fishOcean[i][j].getBreedAge() < fishBreed) {
                        fishOcean[i][j].incrementBreedAge();
                    }
                    if (fishOcean[i][j].getBreedAge() == fishBreed) {
                        breed = true;
                        fishOcean[i][j].resetBreedAge();
                    }
                    // sleep(2);
                    int fishDirection = findDirection(i, j, gridRows, gridColumns, fishMovedOcean, sharkMovedOcean);
                    if (fishDirection == 1) { //up
                        if (i == 0) {

                            fishMovedOcean[gridColumns - 1][j] = fishOcean[i][j];
                            fishMovedOcean[i][j].exists = false;
                        } //end of if i is 0
                        else {
                            fishMovedOcean[i - 1][j] = fishOcean[i][j];
                            fishMovedOcean[i][j].exists = false;
                        } //end of if i non zero
                    } //end of if fish direction is 1
                    else if (fishDirection == 2) { //right
                        fishMovedOcean[i][(j + 1) % gridRows] = fishOcean[i][j];
                        fishMovedOcean[i][j].exists = false;
                    } //end of if fish direction is 2
                    else if (fishDirection == 3) { //down
                        fishMovedOcean[(i + 1) % gridColumns][j] = fishOcean[i][j];
                        fishMovedOcean[i][j].exists = false;

                    } //end of if fish direction is 3
                    else if (fishDirection == 4) { //left
                        if (j == 0) {
                            fishMovedOcean[i][gridRows - 1] = fishOcean[i][j];
                            fishMovedOcean[i][j].exists = false;
                        } //end if j == 0
                        else {
                            fishMovedOcean[i][j - 1] = fishOcean[i][j];
                            fishMovedOcean[i][j].exists = false;
                        } //end else
                    } //end if fish direction 4

                    if (fishDirection != 0 && breed == true) {
                        fishMovedOcean[i][j].exists = true;
                        fishMovedOcean[i][j].resetBreedAge();
                        ++fishCount;
                    }
                } //end if type is fish
                //-----------------------------------------------------------------------------------------------------



                //-------------------------------------------------------------------------------------------------------
                if (sharkOcean[i][j].exists == true) {
                    ++sharkCount;

                    // sleep(2);

                    bool breed = false;
                    bool starve = false;
                    sharkOcean[i][j].incrementStarve();
                    if (sharkOcean[i][j].getBreedAge() < sharkBreed) {
                        sharkOcean[i][j].incrementBreedAge();
                    }

                    if (sharkOcean[i][j].getBreedAge() == sharkBreed) {
                        breed = true;
                        sharkOcean[i][j].resetBreedAge();
                    }
                    if (sharkOcean[i][j].getStarve() == sharkStarve) {
                        sharkMovedOcean[i][j].exists = false;
                        --sharkCount;
                    }
                    else {

                        int sharkDirection = findSharkDirection(i, j, gridRows, gridColumns, sharkMovedOcean, fishMovedOcean);
                        if (sharkDirection == 1) { //up
                            if (i == 0) {
                                sharkMovedOcean[gridColumns - 1][j] = sharkOcean[i][j];
                                sharkMovedOcean[i][j].exists = false;
                                if (fishMovedOcean[gridColumns - 1][j].exists == true) {
                                    fishMovedOcean[gridColumns - 1][j].exists = false;
                                    --fishCount;
                                    sharkMovedOcean[gridColumns - 1][j].resetStarve();
                                }
                            } //end of if i is 0
                            else {
                                sharkMovedOcean[i - 1][j] = sharkOcean[i][j];
                                sharkMovedOcean[i][j].exists = false;
                                if (fishMovedOcean[i - 1][j].exists == true) {
                                    fishMovedOcean[i - 1][j].exists = false;
                                    --fishCount;
                                    sharkMovedOcean[i - 1][j].resetStarve();
                                }
                            } //end of if i non zero
                        } //end of if fish direction is 1
                        else if (sharkDirection == 2) { //right
                            sharkMovedOcean[i][(j + 1) % gridRows] = sharkOcean[i][j];
                            sharkMovedOcean[i][j].exists = false;
                            if (fishMovedOcean[i][(j + 1) % gridRows].exists == true) {
                                fishMovedOcean[i][(j + 1) % gridRows].exists = false;
                                --fishCount;
                                sharkMovedOcean[i][(j + 1) % gridRows].resetStarve();
                            }
                        } //end of if fish direction is 2
                        else if (sharkDirection == 3) { //down
                            sharkMovedOcean[(i + 1) % gridColumns][j] = sharkOcean[i][j];
                            sharkMovedOcean[i][j].exists = false;
                            if (fishMovedOcean[(i + 1) % gridColumns][j].exists == true) {
                                fishMovedOcean[(i + 1) % gridColumns][j].exists = false;
                                --fishCount;
                                sharkMovedOcean[(i + 1) % gridColumns][j].resetStarve();
                            }
                        } //end of if fish direction is 3
                        else if (sharkDirection == 4) { //left
                            if (j == 0) {
                                sharkMovedOcean[i][gridRows - 1] = sharkOcean[i][j];
                                sharkMovedOcean[i][j].exists = false;
                                if (fishMovedOcean[i][gridRows - 1].exists == true) {
                                    fishMovedOcean[i][gridRows - 1].exists = false;
                                    --fishCount;
                                    sharkMovedOcean[i][gridRows - 1].resetStarve();
                                }
                            } //end if j == 0
                            else {
                                sharkMovedOcean[i][j - 1] = sharkOcean[i][j];
                                sharkMovedOcean[i][j].exists = false;
                                if (fishMovedOcean[i][j - 1].exists == true) {
                                    fishMovedOcean[i][j - 1].exists = false;
                                    --fishCount;
                                    sharkMovedOcean[i][j - 1].resetStarve();
                                }
                            } //end else
                        } //end if fish direction 4

                        if (sharkDirection != 0 && breed == true) {
                            sharkMovedOcean[i][j].exists = true;
                            ++sharkCount;
                            sharkMovedOcean[i][j].resetBreedAge();                        
                        }
                    } //end else shark starve
                } //end if type is shark

            } //end inside for loop
        } //end outside for loop
        fishOcean = fishMovedOcean;
        sharkOcean = sharkMovedOcean;
        sleep(2);
        system("clear");
        cout << "\n";
        for (int i = 0; i < gridRows; i++) {
            for (int j = 0; j < gridColumns; j++) {
                if (fishOcean[i][j].exists == true || sharkOcean[i][j].exists == true) {
                    if (fishOcean[i][j].exists == true) {
                        cout << "F";
                    } // end fish if
                    else {
                        cout << "S";
                    } // end shark if
                } //end exists if
                else {
                    cout << ".";
                }
                cout << " ";

            } //end columns for

            cout << "\n";
        } //end rows forloop
        cout << "Wator Simulation";
        cout << "\n";
        
        //Outputting Shark and Fish count 
        cout << "\n\n\n";
        cout << "Fish count: ";
        cout << fishCount;
        cout << "\n";
        cout << "Shark count: ";
        cout << sharkCount;
        cout << "\n";


 

    } //end while loop

    return 0;
} // end of main

