#include <fstream>
#include <string>

#ifndef MIRROR_H
#define MIRROR_H

#define SIZE_OF_ALPHABET 13

class Mirror{
  public:
    Mirror(std::ifstream*);
    ~Mirror();

    char** getEncryption();
    char* getHiddenMsg();
    std::string getCodedMsg();



  private:
    char** encryption;
    std::string codedMsg;
    char library[26][2] = {{'A','n'}, {'B', 'o'}, {'C', 'p'}, {'D','q'}, {'E','r'},{'F','s'},
      {'G', 't'}, {'H','u'}, {'I','v'}, {'J','w'}, {'K','x'}, {'L', 'y'},
      {'M', 'z'}, {'N','a'}, {'O', 'b'}, {'P', 'c'}, {'Q', 'd'}, {'R', 'e'},
      {'S','f'}, {'T', 'g'}, {'U', 'h'}, {'V','i'}, {'W','j'}, {'X', 'k'},
      {'Y', 'l'}, {'Z', 'm'}};

    /* Translates the library */
    void translate();

    /* Returns the x and y coordinate of last position */
    char left(int*);
    char right(int*);
    char up(int*);
    char down(int*);
};


#endif //MIRROR_H
