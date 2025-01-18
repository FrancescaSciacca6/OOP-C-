#ifndef VOICE_H
#define VOICE_H

#include <string>
#include <iostream>

using namespace std;

/**
 * @brief Structure representing an entry in a phoneBook.
 * An entry contains three informations: first name, last name and telephone number
 * of the contact in string format.
 * 
 * NOTE: a struct in C++ is a class that has all its content public by default.
 */
struct voice{
    string fname; //< contact first name
    string lname; //< contact last name
    string ntel; //< contact phone number

    /**
     * Secondary utility constructor. it is used to build 
     * an entry from the three informations.
     * @param fname contact first name 
     * @param lname contact last name
     * @param ntel contact telephone number
     */
    voice(const string &fname, const string &lname, const string &ntel);
    
    voice(); //< Default constructor.

    void setName(string fname);
    void setSurname(string lname);
    void setNtel(string ntel);

    string getName() const;
    string getSurname() const;
    string getNtel() const;


    virtual void print() const {
        std::cout << "Name: " << fname << ", Surname: " << lname << ", Phone: " << ntel << std::endl;
    }
};

/**
 * Redefining the output stream operator. Used to write content 
 * of an entry on an output stream.
 * @param outputStream output stream
 * @param voice entry to write
 * @return the output stream
 */
ostream &operator<<(ostream &outputStream, const voice &voice);

#endif // VOICE_H