#include "phoneBook.h"
#include <algorithm> //swap
#include <cassert>
#include <fstream>

phoneBook::phoneBook() : _size(0), _capacity(0), _voices(nullptr){} 

phoneBook::~phoneBook() {
    delete[] _voices;
    _voices = nullptr;
    _size = 0;
    _capacity = 0;
}

phoneBook& phoneBook::operator=(const phoneBook &other){
    if (this != &other){
        phoneBook tmp(other);
        std::swap(this->_size, tmp._size);
        std::swap(this->_capacity, tmp._capacity);
        std::swap(this->_voices, tmp._voices);
    }
    return *this;
}

phoneBook::phoneBook(const phoneBook& other) : _size(0), _capacity(0), _voices(nullptr){
    _voices = new voice*[other._capacity];
    for(size_type i=0; i<other._size; i++)
        _voices[i] = other._voices[i];
    _size = other._size;
    _capacity = other._capacity;
}

phoneBook::phoneBook(size_type newCapacity) 
    : _size(0), _capacity(newCapacity), _voices(new voice*[newCapacity]) {}

phoneBook::size_type phoneBook::size() const{
    return _size;
}

phoneBook::size_type phoneBook::capacity() const{
    return _capacity;
}

void phoneBook::set_capacity(size_type newcap){
    if(newcap > _size){
        voice **tmp = new voice*[newcap];
        for(size_type i=0; i<_size; i++)
            tmp[i] = _voices[i];
        _capacity = newcap;
        delete[] _voices;
        _voices = tmp;
    }
    else if(newcap < _size){
        phoneBook tmp(newcap);
        std::swap(this->_size, tmp._size);
        std::swap(this->_capacity, tmp._capacity);
        std::swap(this->_voices, tmp._voices);
    }
}

voice& phoneBook::operator[](size_type index){
    assert(index < _size);
    return *_voices[index];
}


const voice& phoneBook::operator[](size_type index) const{
    assert(index < _size);
    return *_voices[index];
}

void phoneBook::add_voice(const string &fname, const string &lname, const string &ntel){
    add_voice(voice(fname, lname, ntel));
}

void phoneBook::add_voice(const voice &v, const string &email, const string &company){
    add_voice(v, email, company);
}

void phoneBook::add_voice(const string &fname, const string &lname, const string &ntel, 
                        const string &email, const string &company){
    add_voice(businessVoice(fname, lname, ntel, email, company));
}

void phoneBook::add_voice(const voice &v){
    if(_size < _capacity){
        voice *tmp = nullptr;
        tmp = find_voice_helper(v.ntel);
        if(tmp == nullptr){
            _voices[_size] = new voice (v);
            _size++;
        }
        else
            throw duplicated_voice_exception();
    }
    else{
        throw full_phoneBook_exception();
    }
}

void phoneBook::add_voice(const businessVoice &bv){
    if(_size < _capacity){
        voice *tmp = nullptr;
        tmp = find_voice_helper(bv.ntel);
        if(tmp == nullptr){
            _voices[_size] = new businessVoice(bv);
            _size++;
        }
        else
            throw duplicated_voice_exception();
    }
    else{
        throw full_phoneBook_exception();
    }
}

voice phoneBook::find_voice(const std::string &ntel) const{
    voice *result = nullptr;
    result = find_voice_helper(ntel);
    if(result == nullptr)
        throw voice_not_found_exception();
    else
        return *result;
}

voice *phoneBook::find_voice_helper(const std::string &ntel) const{
    for(size_type i=0; i<_size; i++){
        if(ntel == _voices[i]->ntel)
            return _voices[i];
    }
    return nullptr;
}

void phoneBook::clear(){
    _size = 0;
}

void phoneBook::swap(phoneBook &other){
    std::swap(_voices, other._voices);
    std::swap(_size, other._size);
    std::swap(_capacity, other._capacity);
}

void phoneBook::save(const std::string &filename) const{
    std::ofstream ofs;
    ofs.open(filename);
    if(ofs.is_open()){
        ofs << *this;
    }
    else
        throw file_error_exception();
    ofs.close();
}

std::ostream& operator<<(std::ostream &outputStream, const phoneBook &pb) {
    outputStream << "Capacity: " << pb.capacity() << std::endl;
    outputStream << "Size: " << pb.size() << std::endl;

    for (phoneBook::size_type i = 0; i < pb.size(); ++i) {
        if (pb._voices[i] != nullptr) { // Check if not nullptr
            std::cout << "Printing voice number " << i+1 << std::endl;
            pb._voices[i]->print(); 
            outputStream<< *pb._voices[i];   
            if (i < pb.size() - 1) {
                outputStream << std::endl;
            }
        }
    }
    return outputStream;
}




