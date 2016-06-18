#include "mirror.h"

/* Constructor for Mirror class. Stores the cypher in encryption as a matrix and
 * stores the coded message at the end in codedMsg */
Mirror::Mirror(std::ifstream* input){
  decodedMsg = "";

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
    for(int column = 0; column <= SIZE_OF_ALPHABET; column++){
      if(input->peek() == '\n'){
        input->get();
        break;
      }
      input->get(encryption[row][column]);
    }
  }

  // Get the message at the end
  std::getline(*input, codedMsg, '\n');


  //Initialize dictionary //
  for(int alpha = 0; alpha < SIZE_OF_ALPHABET*2; alpha++){
    oriDict[alpha] = (char)(alpha + START_BIG_ALPHA);
    oriDict[alpha+(SIZE_OF_ALPHABET*2)] = (char)(alpha + START_SMALL_ALPHA);
  }

  translate();
  
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

std::string Mirror::getDecodedMsg(){
  return decodedMsg;
}

void Mirror::translate(){

  for(int row = 0; row < SIZE_OF_ALPHABET; row++){
    int start[2] = {row,0};
    encryptDict[row] = right(start, true);
  }
  for(int col = SIZE_OF_ALPHABET; col < SIZE_OF_ALPHABET*2; col++){
    int start[2] = {SIZE_OF_ALPHABET, col - SIZE_OF_ALPHABET};
    encryptDict[col] = up(start, true);
  }
  for(int col = SIZE_OF_ALPHABET*2; col < SIZE_OF_ALPHABET*3; col++){
    int start[2] = {0, col - SIZE_OF_ALPHABET * 2};
    encryptDict[col] = down(start, true);
  }
  for(int row = SIZE_OF_ALPHABET*3; row < SIZE_OF_ALPHABET*4; row++){
    int start[2] = {row - SIZE_OF_ALPHABET*3, SIZE_OF_ALPHABET};
    encryptDict[row] = left(start, true);
  }

  decode();
}

void Mirror::decode(){

  for(unsigned int index = 0; index < codedMsg.length(); index++)
    for(int lcv = 0; lcv < (SIZE_OF_ALPHABET * 4); lcv++)
      if (codedMsg[index] == encryptDict[lcv])
        decodedMsg += oriDict[lcv];
}

char Mirror::left(int* start, bool first /*= false*/){
  while(true){
    if (!first || start[1] == 13)
      start[1]--;
    if (start[1] == -1){
      return oriDict[start[0]];
    }else if(encryption[start[0]][start[1]] == '\\'){
      return up(start);
    }else if(encryption[start[0]][start[1]] == '/'){
      return down(start);
    }
    first = false;
  }
}

char Mirror::right(int* start, bool first /*= false*/){
  while (true){
    if (!first || start[1] == -1)
      start[1]++;
    if(start[1] == 13){
      return oriDict[start[0]+ (SIZE_OF_ALPHABET * 3)]; /* Times 3 beacause you need to get passed first alphabet plus first half of letters */
    }else if(encryption[start[0]][start[1]] == '\\'){
      return down(start);
    }else if(encryption[start[0]][start[1]] =='/'){
      return up(start);
    }
    first = false;
  }//end of while

}

char Mirror::up(int* start, bool first /*= false*/){

  while(true){
    if (!first || start[0] == 13)
      start[0]--;
    if (start[0] == -1){
      return oriDict[start[1] + (SIZE_OF_ALPHABET * 2)]; // Pass the first alphabet
    }else if(encryption[start[0]][start[1]] == '\\'){
      return left(start);
    }else if(encryption[start[0]][start[1]] == '/'){
      return right(start);
    }
    first = false;
  }

}

char Mirror::down(int* start, bool first/* = false*/){
  while (true){
    if (!first || start[0] == -1)
      start[0]++;
    if(start[0] == 13){
      return oriDict[start[1] + SIZE_OF_ALPHABET];
    }else if(encryption[start[0]][start[1]] == '\\'){
      return right(start);
    }else if(encryption[start[0]][start[1]] =='/'){
      return left(start);
    }
    first = false;
  }
}
