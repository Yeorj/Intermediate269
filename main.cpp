#include <iostream>
#include <fstream>
#include <string>
#include "mirror.h"
/* Reads the input file and returns the correct output into stream or a file if
 * a file is provided */
#define INPUT_MIN_SIZE 2
#define INPUT_MAX_SIZE 3

int main(int argc, char* argv[]){

  bool outToFile = false; // Whether to print to write to file or console TODO probably dont need this as there is a is_open() func
  std::ifstream inputFile;
  std::ofstream outputFile;

  if (argc < INPUT_MIN_SIZE){
    std::cerr << "Please provide the name of the input file.\n";
    return 1;
  } else if (argc > INPUT_MAX_SIZE){
    std::cerr << "Too many arguments. Please provide atleast an input file and a posssible output file.\n";
    return 1;
  }

  inputFile.open("input");

  Mirror encryption(&inputFile);
  char** array = encryption.getEncryption();

  for(int row = 0; row < SIZE_OF_ALPHABET; row++){
    for (int column = 0; column < SIZE_OF_ALPHABET; column++){
      std::cout << array[row][column];
    }
    std::cout<<std::endl;
  }

  // If there is less than 3 arguements then don't open the output file
  if (argc == INPUT_MAX_SIZE){
    outToFile = true;
    outputFile.open(argv[2]);
  }
  std::cout << std::endl << encryption.getDecodedMsg();


  inputFile.close();
  outputFile.close();
  return 0;
}
