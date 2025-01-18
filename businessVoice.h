#ifndef BUSINESSVOICE_H
#define BUSINESSVOICE_H

#include <string>
#include <iostream>
#include "voice.h"

using namespace std;

struct businessVoice : public voice{
public:
    std::string company;
    std::string email;

    businessVoice();//< Default constructor
    businessVoice(voice v, const std::string &company, const std::string &email);
    businessVoice(const std::string &fname, const std::string &lname, const std::string &ntel, const std::string &company, const std::string &email);
    
    virtual void print() const override {
        voice::print();
        std::cout << "Company: " << company << ", Email: " << email << ". BusinessVoice: YES" << std::endl;
    } //Inheritance and Polymorphism from Voice

    void setEmail(string email);
    void setCompany(string company);
    string getEmail() const;
    string getCompany() const;

};

ostream &operator<<(ostream &outputStream, const businessVoice &businessVoice);

#endif // BUSINESSVOICE_H