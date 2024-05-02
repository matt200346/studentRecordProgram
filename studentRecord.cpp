#include "studentRecord.h"
#include "not_found_err.h"

// constructor with default values
StudentRecord::StudentRecord() {
  this->id = 0;
  this->name = "INVALID";
  this->age = 0;
}

// overloaded constructor with id specified
StudentRecord::StudentRecord(int id) {
  this->id = id;
  this->name = "INVALID";
  this->age = 0;
}

// overloaded constructor with id and name specified
StudentRecord::StudentRecord(int id, std::string name) {
  this->id = id;
  this->name = name;
  this->age = 0;
}

// overloaded constructor with id, name and age specified
StudentRecord::StudentRecord(int id, std::string name, int age) {
  this->id = id;
  this->name = name;
  this->age = age;
}

// create a student record and push back the pointer to the vector in argument
// function is > 80 chars, but I dunno how to make it look good split...
void StudentRecord::addRecord(int id, std::string name, int age, std::vector<StudentRecord*>& allRecords) {
  StudentRecord* record = new StudentRecord(id, name, age);
  allRecords.push_back(record);

}

// find and fetch a specific record and return the pointer to the record in
// function is > 80 chars, but I dunno how to make it look good split...
StudentRecord* StudentRecord::fetchRecord(int id, std::vector<StudentRecord*>& allRecords) {
  for (auto i : allRecords) {
    if (i->id == id)
      return i;
  }
  // throw if not found
  throw (not_found_err());
}

//--------------getters------------------------

// get the id from a specific student record
int StudentRecord::getId() {
  return this->id;
}

std::string StudentRecord::getName() {
  return this->name;
}

int StudentRecord::getAge() {
  return this->age;
}