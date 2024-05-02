#pragma once

#include <string>
#include <vector>

// student record object that contains id name and age
// use getId, getName, and getAge as getters
class StudentRecord {
public:

  void static addRecord(int id, std::string name, int age, std::vector<StudentRecord*>& allRecords);
  static StudentRecord* fetchRecord(int id, std::vector<StudentRecord*>& allRecords);
  int getId();
  std::string getName();
  int getAge();
  StudentRecord();
  StudentRecord(int id);
  StudentRecord(int id, std::string name);
  StudentRecord(int id, std::string name, int age);

private:
  int id;
  std::string name;
  int age;

};