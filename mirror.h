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
};


#endif //MIRROR_H
