#include <iostream>
#include <cassert>
#include "phoneBook.h"

void test_voice(void) {

	std::cout<<"*** TEST VOICE ***" << std::endl << std::endl;

	voice v;

	std::cout << v << std::endl;
	assert(v.fname=="");
	assert(v.lname=="");
	assert(v.ntel=="");

	voice v2("Paolino","Paperino","313");
	std::cout << v2 << std::endl;
	assert(v2.fname=="Paolino");
	assert(v2.lname=="Paperino");
	assert(v2.ntel=="313");

    businessVoice v3(v2, "PK", "v3.campus@pk.com");
	std::cout << v3 << std::endl;
	assert(v3.fname=="Paolino");
	assert(v3.lname=="Paperino");
	assert(v3.ntel=="313");
    assert(v3.company=="PK");
    assert(v3.email=="v3.campus@pk.com");

    v = v2;
    std::cout << v << std::endl;
    assert(v.fname=="Paolino");
    assert(v.lname=="Paperino");
    assert(v.ntel=="313");

    v.fname = "Mickey";
    v.lname = "Mouse";
    v.ntel = "111";
    std::cout << v << std::endl;
    assert(v.fname=="Mickey");
    assert(v.lname=="Mouse");
    assert(v.ntel=="111");
}

void test_phoneBook(){
    std::cout<<std::endl<<"*** TEST PHONEBOOK ***"<<std::endl<<std::endl;

    phoneBook pb1;  //<empty phoneBook.
    std::cout<<pb1<<std::endl;

    phoneBook pb2(10);  //<capacity is 10.
    std::cout<<pb2<<std::endl;

    pb1=pb2; //Assignment operator.
    std::cout<<pb1<<std::endl;

    phoneBook pb3 = pb2; //Copy constructor.
    try{
        //Add 4 entries (NOTE: Capacity of pb3 is 10)
        pb3.add_voice("name1", "surname1", "11111");
        pb3.add_voice("name2", "surname2", "22222", "uania@22.com", "comapani2g");
        pb3.add_voice("name3", "surname3", "33333", "uania@33.com", "comapani3g");
        pb3.add_voice("name4", "surname4", "44444");
    }
    catch(full_phoneBook_exception &e){
        std::cout<<"!!! ERROR: your phoneBook is full !!!"<<std::endl;
    }
    std::cout<<pb3<<std::endl;


    phoneBook pb4(5);
    try{
        //Add 6 entries (NOTE: Capacity of pb3 is 5)
        pb4.add_voice("name1", "surname1", "11111");
        pb4.add_voice("name2", "surname2", "22222", "uania@22.com", "comapani2g");
        pb4.add_voice("name3", "surname3", "33333", "uania@33.com", "comapani3g");
        pb4.add_voice("name4", "surname4", "44444");
        pb4.add_voice("name5", "surname5", "55555", "uania@55.com", "compani5g");
        pb4.add_voice("name6", "surname6", "66666");
    }
    catch(full_phoneBook_exception &e){
        std::cout<<"!!! ERROR: your phoneBook is full !!!"<<std::endl;
    }
    std::cout<<pb4<<std::endl;


    try{
        voice v = pb3.find_voice("33333");
    }
    catch(voice_not_found_exception){
        std::cout<<"!!! ERROR: entry not found !!!"<<std::endl;
    }

    pb3[0]=voice("Francesca", "Sciacca", "77777");
    assert(pb3[0].fname=="Francesca");
    assert(pb3[0].lname=="Sciacca");
    assert(pb3[0].ntel=="77777");

}


void interactive_test(){
    std::cout<< std::endl <<"*** INTERACTIVE TEST ***" << std::endl << std::endl;

    phoneBook pb;
    unsigned int capacity;
    std::cout<<"Insert the capacity of phoneBook: ";
    std::cin>> capacity;

    if(capacity==0){
        std::cout << pb << std::endl;
        return;
    }

    pb.set_capacity(capacity);
    std::string fname, lname ,ntel;
    
    do{
        std::cout<<"Insert an entry"<<std::endl;
        std::cout<<" Name (* for terminate): ";
        std::cin>>fname;

        if(fname!="*"){
            std::cout<<" Surname: ";
            std::cin>> lname;

            std::cout<<" Telephone Number: ";
            std::cin>> ntel;

            try{
                pb.add_voice(fname, lname, ntel);
            }
            catch(full_phoneBook_exception){
                std::cout<<"***** PhoneBook is full! ******"<<std::endl;
                fname="*";
            }
            catch(duplicated_voice_exception &e){
                std::cout<<"***** Duplicated entry. Insert another entry. ******"<<std::endl;
            }

        }
    } while(fname!="*");

	std::string answer, filename;

	std::cout<<"Do you want to save the phoneBook (y/n)?";
	std::cin >> answer;

	if (answer[0]=='n') return;

	std::cout<<"Nome del file: ";
	std::cin >> filename;
	try {
		pb.save(filename);
		std::cout<<"PhoneBook pb saved."<<std::endl;
	}
	catch(file_error_exception &e) {
		std::cout << "****** Errore File!"<<std::endl;
	}
}


int main(int argc, char *argv[]){
    test_voice();
    test_phoneBook();
    interactive_test();
    return 0;
}

