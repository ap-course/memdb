#ifndef DB_HEADER_
#define DB_HEADER_

#include <iostream>
#include <string>

class MemDB {
 public:
  MemDB(const MemDB&) = delete;
  void operator=(const MemDB&) = delete;

  static MemDB& get_instance() {
    static MemDB kDbInstance;
    return kDbInstance;
  }

  int size() const;

  bool ContainKey(std::string key) const;

  std::string GetValue(const std::string& key) const;
  void AddValue(std::pair<std::string, std::string> key_value);

 private:
  MemDB() {}

  int size_;
  std::pair<std::string, std::string>* data_;
};

#endif
