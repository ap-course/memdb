#include <iostream>

#include "db.h"

int main() {
  while (true) {
    std::string command;
    std::cin >> command;

    if (command == "exit") {
      break;
    }

    if (command == "add") {
      std::string key, value;
      std::cin >> key;
      std::cin.ignore();
      getline(std::cin, value);

      auto key_value = std::make_pair(key, value);
      MemDB::get_instance().AddValue(key_value);
    } else if (command == "get") {
      std::string key;
      std::cin >> key;

      std::cout << MemDB::get_instance().GetValue(key) << std::endl;
    } else if (command == "size") {
      std::cout << MemDB::get_instance().size() << std::endl;
    }
  }

  return 0;
}
