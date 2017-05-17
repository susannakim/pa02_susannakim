// sequence1.cxx - implements sequence class as defined in sequence1.h
// Susanna Kim, 4/27/2017

#include <cassert> // provides assert
#include <cstdlib> // provides size_t
#include "sequence1.h" // defines what must be implemented

namespace main_savitch_3 {
  sequence::sequence() {
    current_index = 0;
    used = 0;
  }

  void sequence::start() {
    if (used > 0)
      current_index = 0;
  }

  void sequence::advance() {
    assert(is_item());
    if (current_index == used - 1)
      current_index = used;
    else 
      current_index++;
  }

  void sequence::insert(const value_type& entry) {
    assert(size() < CAPACITY);
    if (is_item()) {
      for (size_type i = used; i > current_index; i--) {
	data[i] = data[i-1];
      }
      used++;
      data[current_index] = entry;
    }
    else {
      for (size_type j = used; j > 0; j--) {
	data[j] = data[j-1];
      }
      used++;
      current_index = 0;
      data[current_index] = entry;
    }
  }

  void sequence::attach(const value_type& entry) {
    assert(size() < CAPACITY);
    if (is_item()) {
      for (size_type i = used; i > current_index + 1; i--) {
	data[i] = data[i-1];
      }
      used++;
      current_index++;
      data[current_index] = entry;
    }
    else {
      used++;
      current_index = used - 1;
      data[current_index] = entry;
    }
  }

  void sequence::remove_current() {
    assert(is_item());
    for (size_type i = current_index; i < used - 1; i++)
      data[i] = data[i+1];
    used--;
  }

  sequence::size_type sequence::size() const {
    return used;
  }

  bool sequence::is_item() const {
    return(current_index != used);
  }

  sequence::value_type sequence::current() const {
    assert(is_item());
    return data[current_index];
  }
}  
    
  
