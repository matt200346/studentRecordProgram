
///////////////////////////////////////////////////////////////////////////////
// Displays a menu that lets the user add a student record, find a record
// or quit the program
// finding the record currently works in O(n) as it is just linear search
// 
// future things to do:
// validate user input
// add the abillity to display all records
// sort the records or make the search faster
// make the menu and record display nicer
// 
///////////////////////////////////////////////////////////////////////////////

#include "studentRecord.h"
#include "not_found_err.h"
#include <iostream>
#include <string>
#include <conio.h>
void displayMenu();

int main() {

  // the vector where the studentrecord object pointers are stored
  std::vector<StudentRecord*> allRecords;
  std::string id;
  std::string name;
  std::string age;
  bool running = true;
  // temp pointer for a strudentrecord object
  StudentRecord* temp = new StudentRecord();

  // main while loop
  while (running) {
    // clear the screen
    system("CLS");

    displayMenu();
    int userInput = _getch();

    switch (userInput)
    {

    case(49):
      // get user input
      // TODO validate user input
      std::cout << "Please enter the ID of the student: ";
      getline(std::cin, id);
      std::cout << "Please enter the name of the student: ";
      getline(std::cin, name);
      std::cout << "Please enter the age of the student: ";
      getline(std::cin, age);

      StudentRecord::addRecord(stoi(id), name, stoi(age), allRecords);

      std::cout << "Record added! Please press any key to continue\n";
      _getch();
      break;

    case(50):
      // get user input
      // TODO validate user input
      std::cout << "Please enter the ID of the student: ";
      getline(std::cin, id);
      try
      {
        temp = StudentRecord::fetchRecord(stoi(id), allRecords);
        std::cout << "ID: " << temp->getId() << " Name: " << temp->getName()
          << " Age: " << temp->getAge() << "\n";
      }
      catch (not_found_err err)
      {
        std::cout << err.what();
      }
      std::cout << "Please enter any key to continue\n";
      _getch();
      break;

    case(51):
      running = false;
      continue;
      break;

    default:
      std::cout << "Invalid Choice please press any key and try again." << std::endl;
      _getch();
      break;
    }
  }

}

void displayMenu() {
  std::printf("-----------------------------------------------------------\n");
  std::printf("|             WELCOME PLEASE SELECT AN OPTION             |\n");
  std::printf("| 1. Add Record                                           |\n");
  std::printf("| 2. Find Record by ID                                    |\n");
  std::printf("| 3. Quit                                                 |\n");
  std::printf("-----------------------------------------------------------\n");
}
