#include "mirror.h"

/* Constructor for Mirror class. Stores the cypher in encryption as a matrix and
 * stores the coded message at the end in codedMsg */
Mirror::Mirror(std::ifstream* input){
  encryption = new char*[SIZE_OF_ALPHABET];
  for(int i = 0; i < SIZE_OF_ALPHABET; ++i)
    encryption[i] = new char[SIZE_OF_ALPHABET];

  // Fills the matrix with spaces //
  for(int row = 0; row < SIZE_OF_ALPHABET; row++){
    for(int column = 0; column < SIZE_OF_ALPHABET; column++){
      encryption[row][column] = ' ';
    }
  }

  // Correctly reads and puts the encryption into a matrix //
  for(int row = 0; row < SIZE_OF_ALPHABET; row++){
    for(int column = 0; column < SIZE_OF_ALPHABET; column++){
      if(input->peek() == '\n'){
        input->get();
        break;
      }
      input->get(encryption[row][column]);
    }
  }

  // Get the message at the end
  std::getline(*input, codedMsg, '\n');

}

Mirror::~Mirror(){
  for(int row = 0; row < SIZE_OF_ALPHABET; row++){
      delete encryption[row];
      encryption[row] = NULL;
  }
  delete encryption;
  encryption = NULL;
}

char** Mirror::getEncryption(){
  return encryption;
}

std::string Mirror::getCodedMsg(){
  return codedMsg;
}
