#include <iostream>
#include <fstream>
#include <string>
#include "mirror.h"
/* Reads the input file and returns the correct output into stream or a file if
 * a file is provided */
#define INPUT_MIN_SIZE 2
#define INPUT_MAX_SIZE 3

int main(int argc, char* argv[]){

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


  if (argc == INPUT_MAX_SIZE){
    outputFile.open(argv[2]);
    outputFile << encryption.getDecodedMsg() << std::endl;
    outputFile.close();
  }

  std::cout << encryption.getDecodedMsg() << std::endl;

  inputFile.close();
  return 0;
}
