/** Conleth Coughlan
 * C00197482
 */

#include <iostream>
#include <thread>
#include <mutex>

int main(void){
  int numShark, numFish, fishBreed, sharkBreed, starve, gridRows, gridColumns;
  std::cout << "Enter the number of sharks you want in the simulation:";
  std::cin >> numShark;
  std::cout << "Enter the number of sharksfish you want in the simulation:";
  std::cin >> numFish;
  std::cout << "Enter the number of turns before a shark can breed:";
  std::cin >> sharkBreed;
  std::cout << "Enter the number of turns before a fish can breed:";
  std::cin >> fishBreed;
  std::cout << "Enter the number of turns before a shark starves:";
  std::cin >> starve;
  std::cout << "Enter the number of rows :";
  std::cin >> gridRows;
  std::cout << "Enter the number of columns:";
  std::cin >> gridColumns;

  if((gridRows*gridColumns)<(numShark+numFish)){
    std::cout << "Not enough spaces for number of fish and sharks";
  } //end of if

  
  
  return 0;
} // end of main
