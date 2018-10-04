#ifndef Entry_h
#define Entry_h

// type code here
struct Entry {

    std::string newName, newLastname, newEmail;

    void setName(std::string name){
		newName = name;
	}

    void setLastname(std::string lastname){
		newLastname = lastname;
	}

    void setEmail(std::string email){
		newEmail = email;
	}

	void print(){

		std::cout << "First Name: " << newName << "\nLast Name: " << newLastname << "\nEmail: " << newEmail << std::endl;

	}

};

#endif /* Entry.h */
