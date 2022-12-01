#include "slist.h"
#include <iostream>
#include <fstream>
#include <cmath> 
#include <string>
using namespace std;

class Airport
{
public:
    char    code[5];
    double   longitude;
    double   latitude;
    
};

struct node {
  Airport* air;
  struct node* nextLoc;
};

/*
Class Library 
*/
class Library {
  private:
    node* head;
    node* tail;

  // Constructor
  public:
    Library() {
      head = NULL;
      tail = NULL;
    }

    // Destructor
    // ~Library() {
    //   for (int i = 0; i < size(); i++) {
    //     delete getNode(i);
    //   }
    // }

    // add(value)				//Adds a new value to the end of this list.
    void add(Airport* a) {
      node* newAirport;
      newAirport = (node*)malloc(sizeof(node));
      if (head == NULL) {
        head = newAirport;
        head->nextLoc = tail;
        tail = newAirport;
      }
      else {
        tail->nextLoc = new node();
        tail = tail->nextLoc;
        tail->air = a;
        tail->nextLoc = nullptr;
      }
    }

    // clear()					//Removes all elements from this list.
    void clear() {
      head = NULL;
      tail = NULL;
    }
  
    // equals(list)				//Returns true if the two lists contain the same elements in the same order.
    bool equals(Library l) {
      if (l.size() != size()) {
        return false;
      }
      for (int i = 0; i < size(); i++) {
        Airport* a1 = get(i);
        Airport* a2 = l.get(i);
        if (a1->code != a2->code) {
          return false;
        }
        if (a1->latitude != a2->latitude) {
          return false;
        }
        if (a1->longitude != a2->longitude) {
          return false;
        }
      }
      return true;
    }

    //get(index)				//Returns the element at the specified index in this list.
    Airport* get(int i) {
      node* start = head;
      int currLoc = 0;
      for (int currLoc = 0; currLoc <= i; currLoc++) {
        if (currLoc == i) {
          return start->air;
        }
        start = start->nextLoc;
      }
    }

    node* getNode(int i) {
      node* start = head;
      if (start == nullptr) {
          return start;
      }
      int currLoc = 0;
      for (int currLoc = 0; currLoc <= i; currLoc++) {
        if (currLoc == i) {
          return start;
        }
        start = start->nextLoc;
      }
  }

    //insert(index, value)		//Inserts the element into this list before the specified index.
    void insert(int index, Airport* value) {
      node* newNode;
      newNode->air = value;
      newNode->nextLoc = getNode(index);
      getNode(index - 1)->nextLoc = newNode;
    }
  
    //exchg(index1, index2)		//Switches the payload data of specified indexex.
    void exchg(int index1, int index2) {
      node* i1 = getNode(index1);
      node* i2 = getNode(index2);
      getNode(index1 - 1)->nextLoc = i2;
      i2->nextLoc = getNode(index1+1);
      getNode(index2 - 1)->nextLoc = i1;
      i1->nextLoc = getNode(index2+1);
    }
    
    //swap(index1,index2)		//Swaps node located at index1 with node at index2
    int swap(int index1, int index2) {
      if (index1 == 0) {
        node* n1 = getNode(index1);
        node* n2 = getNode(index2);
        node* n1_next = n1->nextLoc;
        node* n2_next = n2->nextLoc;
        node* n2_prev = getNode(index2 - 1);
        
        head = n2;
        head->nextLoc = n1_next;
        n2_prev->nextLoc = n1;
        n1->nextLoc = n2_next;
        return 1;
      }
      if (index2 == size()) {
        node* n1 = getNode(index1);
        node* n2 = getNode(index2);
        node* n1_next = n1->nextLoc;
        node* n1_prev = getNode(index1 - 1);
        node* n2_prev = getNode(index2 - 1);
        n1_prev->nextLoc = n2;
        n2->nextLoc = n1_next;
        n2_prev->nextLoc = n1;
        return 1;
      }
      node* n1 = getNode(index1);
      node* n2 = getNode(index2);
      node* n1_next = n1->nextLoc;
      node* n2_next = n2->nextLoc;
      node* n1_prev = getNode(index1 - 1);
      node* n2_prev = getNode(index2 - 1);
      n1_prev->nextLoc = n2;
      n2->nextLoc = n1_next;
      n2_prev->nextLoc = n1;
      n1->nextLoc = n2_next;
      return 1;
    }
    
    // isEmpty()				//Returns true if this list contains no elements.
    bool isEmpty() {
      return head == NULL && tail == NULL;
    }
    
    // remove(index)			//Removes the element at the specified index from this list.
    int remove(int i) {
      node* prev = getNode(i - 1);
      node* curr = getNode(i);
      node* next = getNode(i + 1);
      if (prev == nullptr) {
        head = head->nextLoc;
        delete curr;
        return 0;
      }
      prev->nextLoc = next;
      delete curr;
      return i;
    }
    
    int findAustin() {
        node* start = head;
        int currLoc = 0;
        for (int currLoc = 1; currLoc <= size(); currLoc++) {
          if (get(currLoc)->code[0] == 'K' && get(currLoc)->code[1] == 'A' && get(currLoc)->code[2] == 'U' && get(currLoc)->code[3] == 'S') {
            return currLoc;
          }
        }
    }
    
    // set(index, value)		//Replaces the element at the specified index in this list with a new value.
    void set(int index, Airport* value) {
      getNode(index)->air = value;
    }
    
    // size()					//Returns the number of elements in this list.
    int size() {
        node* start = head;
        int currLoc = 0;
        while (start != nullptr) {
          currLoc++;
          start = start->nextLoc;
        }
      return currLoc;
    }
    // subList(start, length)	//Returns a new list containing elements from a sub-range of this list.
    Library* subList(int start, int length) {
      Library* newL = new Library();
      newL->head = getNode(start);
      for (int i = start; i < start + length; i++) {
        newL->add(get(i));
      }
      return newL;
    }
    
    // toString()				//Converts the list to a printable string representation.
    string toString() {
      string display;
      for (int i = 0; i < size(); i++) {
        string c = "";
        for (int i = 0; i < 5; i++) {
          c += get(i)->code[i];
        }
        display = c;
        display += get(i)->longitude + get(i)->latitude + '\n';
      }
      return display;
    }
};
