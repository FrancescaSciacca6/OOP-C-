#include "voice.h"
using namespace std;

voice::voice() {}


voice::voice(const string &fname, const string &lname, const string &ntel) 
    : lname(lname), fname(fname), ntel(ntel) {}


void voice::setName(string fname){
    this->fname=fname;
}

void voice::setSurname(string lname){
    this->lname=lname;
}

void voice::setNtel(string ntel){
    this->ntel=ntel;
}

string voice::getName() const{
    return this->fname;
}

string voice::getSurname() const{
    return this->lname;
}

string voice::getNtel() const{
    return this->ntel;
}

ostream &operator<<(ostream &outputStream, const voice &voice) {
    outputStream << "Voice: " << voice.fname << " " << voice.lname << " " << voice.ntel;
    return outputStream;
}


