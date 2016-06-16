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

  //Initialize dictionary //
  for(int alpha = 0; alpha < SIZE_OF_ALPHABET*2; alpha++){
    oriDict[alpha] = (char)(alpha + START_BIG_ALPHA);
    oriDict[alpha+(SIZE_OF_ALPHABET*2)] = (char)(alpha + START_SMALL_ALPHA);
  }
  translate();
  std::cout << "\n \\ \n";
  for(int alpha = 0; alpha < SIZE_OF_ALPHABET*2; alpha++){
    std::cout << oriDict[alpha] << " -> " << encryptDict[alpha];
    std::cout << "||\t||"<< oriDict[alpha + SIZE_OF_ALPHABET*2] << " -> " << encryptDict[alpha+(SIZE_OF_ALPHABET*2)] << std::endl;
  }

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

  for(int lcv = 0; lcv < SIZE_OF_ALPHABET; lcv++){
    int start[2] = {0,lcv};
    encryptDict[lcv] = right(start);
  }
  for(int lcv = SIZE_OF_ALPHABET; lcv < SIZE_OF_ALPHABET*2; lcv++){
    int start[2] = {lcv - SIZE_OF_ALPHABET,SIZE_OF_ALPHABET};
    encryptDict[lcv] = up(start);
  }
  for(int lcv = SIZE_OF_ALPHABET*2; lcv < SIZE_OF_ALPHABET*3; lcv++){
    int start[2] = {lcv - SIZE_OF_ALPHABET * 2, 0};
    encryptDict[lcv] = down(start);
  }
  for(int lcv = SIZE_OF_ALPHABET*3; lcv < SIZE_OF_ALPHABET*4; lcv++){
    int start[2] = {13, lcv - SIZE_OF_ALPHABET*3};
    encryptDict[lcv] = left(start);
  }

  for(int index = 0; index < codedMsg.length(); index++){
    std::cout << codedMsg[index];
    for(int lcv = 0; lcv < SIZE_OF_ALPHABET * 2; lcv++){
      if (codedMsg[index] == encryptDict[lcv]){
        decodedMsg += oriDict[lcv];
      }
    }
  }

}


char Mirror::left(int* start){
  while(true){
    start[0]--;
    if (start[0] == -1){
      return oriDict[start[1]];
    }else if(encryption[start[0]][start[1]] == '\\'){
      return up(start);
    }else if(encryption[start[0]][start[1]] == '/'){
      return down(start);
    }
  }
}

char Mirror::right(int* start){
  while (true){
    start[0]++;
    if(start[0] == 13){
      return oriDict[start[1]+ (SIZE_OF_ALPHABET * 3)]; /* Times 3 beacause you need to get passed first alphabet plus first half of letters */
    }else if(encryption[start[0]][start[1]] == '\\'){
      return down(start);
    }else if(encryption[start[0]][start[1]] =='/'){
      return up(start);
    }
  }//end of while

}

char Mirror::up(int* start){

  while(true){
    start[1]--;
    if (start[1] == -1){
      return oriDict[start[0] + (SIZE_OF_ALPHABET * 2)]; // Pass the first alphabet
    }else if(encryption[start[0]][start[1]] == '\\'){
      return left(start);
    }else if(encryption[start[0]][start[1]] == '/'){
      return right(start);
    }
  }

}

char Mirror::down(int* start){
  while (true){
    start[1]++;
    if(start[1] == 13){
      return oriDict[start[0] + SIZE_OF_ALPHABET];
    }else if(encryption[start[0]][start[1]] == '\\'){
      return right(start);
    }else if(encryption[start[0]][start[1]] =='/'){
      return left(start);
    }
  }
}
