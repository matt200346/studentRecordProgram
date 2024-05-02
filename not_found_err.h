#pragma once

class not_found_err : public std::exception {
public:
  // override what() and return custom message
  const char* what() {
    return "Item not found!\n";
  }
};