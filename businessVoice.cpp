#include "businessVoice.h"
using namespace std;

businessVoice::businessVoice() {}//< Default constructor

businessVoice::businessVoice(voice v, const std::string &company, const std::string &email)
        : voice(v), company(company), email(email) {}

businessVoice::businessVoice(const std::string &fname, const std::string &lname, const std::string &ntel, const std::string &company, const std::string &email)
        : voice(fname, lname, ntel), company(company), email(email) {}

void businessVoice::setEmail(string email){
    this->email=email;
}

void businessVoice::setCompany(string company){
    this->company=company;
}

string businessVoice::getEmail() const{
    return this->email;
}

string businessVoice::getCompany() const{
    return this->company;
}

ostream &operator<<(ostream &outputStream, const businessVoice &businessVoice) {
    outputStream << "BusinessVoice: " << businessVoice.fname << " " << businessVoice.lname << " " << businessVoice.ntel
    << " " << businessVoice.email << " " << businessVoice.company;
    return outputStream;
}



