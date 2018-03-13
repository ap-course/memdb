#include "db.h"

int MemDB::size() const { return size_; }

bool MemDB::ContainKey(std::string key) const {
  for (auto i = 0; i < size_; ++i) {
    if (data_[i].first == key) {
      return true;
    }
  }
  return false;
}

std::string MemDB::GetValue(const std::string& key) const {
  for (auto i = 0; i < size_; ++i) {
    if (data_[i].first == key) {
      return data_[i].second;
    }
  }
  return "";
}

void MemDB::AddValue(std::pair<std::string, std::string> key_value) {
  if (ContainKey(key_value.first)) {
    return;
  }

  auto bigger_data = new std::pair<std::string, std::string>[++size_];
  for (auto i = 0; i < size_ - 1; ++i) {
    bigger_data[i] = data_[i];
  }
  delete[] data_;
  data_ = bigger_data;

  data_[size_ - 1] = key_value;
}
