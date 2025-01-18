#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "voice.h"
#include "businessVoice.h"
#include <vector>

#include <iostream>

class full_phoneBook_exception{};
class voice_not_found_exception{};
class duplicated_voice_exception {};
class file_error_exception{};


class phoneBook{
public:
    typedef unsigned int size_type; //< type used for phoneBok dimensions 

private:
    size_type _size; //< number of entries entered.
    size_type _capacity; //< maximum size of phonebook.
    voice **_voices; //< pointer to the array of Voice Struct.

    /**
     * Private helper function used by the public method 'find_voice'
     * @param ntel telephone number to search for
     * @return address of the found entry; nullptr otherwise
     */
    voice *find_voice_helper(const string &ntel) const;

public:
    phoneBook(); //< Default constructor. Builds an empty phoneBook and size is 0.
    ~phoneBook(); //< Destructor.

    /**
     * Copy constructor.
     * @param other phoneBook to copy into this
     */
    phoneBook(const phoneBook& other); 

    /**
     * Assignment operator.
     * @param other phoneBook to copy into this
     */
    phoneBook& operator=(const phoneBook &other); 

    /**
	 * Secondary constructor.
	 * Builds an phoneBook with a maximum capacity.
	 * @param newcap la capacità della rubrica  
     */
    explicit phoneBook(size_type newCapacity);

    size_type size() const; //< Getter. Returns number of entries entered.
    size_type capacity() const; //< Getter. Return the maximum size of phonebook.

    /**
     * Setter for phoneBook dimension.
     * If the number of entries in the directory is less than the new capacity,
     * the entries are kept. Otherwise they are all lost.
     * @param newCapacity new phoneBook dimension 
     */
    void set_capacity(size_type newCapacity);  

    /**
     * Read and write access to the entry in index position.
     * @param index index of the entry to be accessed
     * @return  the entry in index position
     */
    voice& operator[](size_type index);

    /**
     * Read access to the entry in index position.
     * @param index index of the entry to be accessed
     * @return  the entry in index position
     */
    const voice& operator[](size_type index) const;

    /**
     * Adding an entry to the phoneBook (string). If the phoneBook is full, it will be launched an exception. 
     * If the entry is already in the phoneBook (same phone number), it will be launched an exception.
     * @param fname contact first name 
     * @param lname contact last name
     * @param ntel contact telephone number
     * @throw phoneBook_full_exception if phoneBook is full
     * @throw duplicated_voice_exception if the entry already exist.
     */
    void add_voice(
        const string &fname,
        const string &lname,
        const string &ntel
    );

    void add_voice(const string &fname,
        const string &lname, 
        const string &ntel, 
        const string &email, 
        const string &company
    );

    void add_voice(const voice &voice,
        const string &email, 
        const string &company
    );

    /**
     * Adding an entry to the phoneBook (string). If the phoneBook is full, it will be launched an exception. 
     * If the entry is already in the phoneBook (same phone number), it will be launched an exception.
     * @param voice entry to be entered 
     * @throw phoneBook_full_exception if phoneBook is full
     * @throw duplicated_voice_exception if the entry already exist.
     */
    void add_voice(const voice &voice);

    void add_voice(const businessVoice &voice);


    /**
     * Function used to search for an entry given the telephone number.
	 * If the phone number is not found, an exception is thrown.
     * @param ntel phone number to search for
     * @return the found entry
     * @throw voice_not_found_exception the phone number does not exist in the phoneBook.
     */
    voice find_voice(const string &ntel) const;

    void clear(); //< Empty the contents of the phoneBook without changing its capacity.

    /**
     * Saving the contents of the phoneBook to a file.
     * @param filename destination file name
     * @throw file_error_exception if there are errors opening the file.
     */
    void save(const string &filename) const;

    /**
     * Swap function to exchange the contents of two phoneBooks.
     * @param other phoneBook to exchange content with
     */
    void swap(phoneBook &other);

    /**
     * Redefining the output stream operator. Used to write content of a phoneBook 
     * on an output stream.
     * @param outputStream output stream
     * @param pb phoneBook to write
     * @return the output stream
     */
    friend ostream& operator<<(ostream &outputStream, const phoneBook &pb);
};


#endif