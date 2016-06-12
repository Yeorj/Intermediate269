#include <iostream>
#include <fstream>
#include <string>
/* Reads the input file and returns the correct output into stream or a file if
 * a file is provided */
#define SIZE_OF_ALPHABET 13
#define INPUT_MIN_SIZE 2
#define INPUT_MAX_SIZE 3

char** readFile(std::ifstream*);

int main(int argc, char* argv[]){

  // bool outToFile = false; // Whether to print to write to file or console TODO probably dont need this as there is a is_open() func
  std::ifstream inputFile;
  // std::ofstream outputFile;

  if (argc < INPUT_MIN_SIZE){
    std::cerr << "Please provide the name of the input file.\n";
    return 1;
  } else if (argc > INPUT_MAX_SIZE){
    std::cerr << "Too many arguments. Please provide atleast an input file and a posssible output file.\n";
    return 1;
  }

  inputFile.open("input");

  char** array = readFile(&inputFile);

  for(int row = 0; row < SIZE_OF_ALPHABET; row++){
    for (int column = 0; column < SIZE_OF_ALPHABET; column++){
      std::cout << array[row][column];
    }
  }


  // If there is less than 3 arguements then don't open the output file
  // if (argc == INPUT_MAX_SIZE){
  //   outToFile = true;
  //   outputFile.open(argv[2]);
  // }
  //


  inputFile.close();
  // outputFile.close();
  return 0;
}

/* Input is a file with correct format to read the mirror encryption file.
 * Returns an array of characters for each character */
char** readFile(std::ifstream* input){
  char** retMat = new char*[SIZE_OF_ALPHABET];
  for(int i = 0; i < SIZE_OF_ALPHABET; ++i)
    retMat[i] = new char[SIZE_OF_ALPHABET];

  // Fills the matrix with spaces //
  for(int row = 0; row < SIZE_OF_ALPHABET; row++){
    for(int column = 0; column < SIZE_OF_ALPHABET; column++){
      retMat[row][column] = ' ';
    }
  }

  // Correctly reads and puts the encryption into a matrix //
  for(int row = 0; row < SIZE_OF_ALPHABET; row++){
    for(int column = 0; column < SIZE_OF_ALPHABET; column++){
      if(input->peek() == '\n'){
        input->get();
        break;
      }
      input->get(retMat[row][column]);
    }

  }

  return retMat;
}
