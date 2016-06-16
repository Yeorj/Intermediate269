#include <fstream>
#include <string>
#include <iostream>
#include <cctype>

#ifndef MIRROR_H
#define MIRROR_H

#define SIZE_OF_ALPHABET 13
#define START_BIG_ALPHA 65
#define START_SMALL_ALPHA 97
class Mirror{
  public:
    Mirror(std::ifstream*);
    ~Mirror();

    char** getEncryption();
    char* getHiddenMsg();
    std::string getCodedMsg();
    std::string getDecodedMsg();


  private:
    char** encryption;
    std::string codedMsg;
    std::string decodedMsg;
    char oriDict[52];
    char encryptDict[52];

    /* Translates the library */
    void translate();

    /* Returns the x and y coordinate of last position */
    char left(int*);
    char right(int*);
    char up(int*);
    char down(int*);
};


#endif //MIRROR_H
