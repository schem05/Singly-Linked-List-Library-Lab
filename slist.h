#ifndef SLIST_H
#define SLIST_H

class Airport;
struct node;

#ifndef SLIST_H
class Library {
  public:
    Library();
    void add(Airport* a);
    void clear();
    bool equals(Library l);
    Airport* get(int i);
    node* getNode(int i);
    void insert(int index, Airport* value);
    void exchg(int index1, int index2);
    int swap(int index1, int index2);
    bool isEmpty();
    int remove(int i);
    int findAustin();
    void set(int index, Airport* value);
    int size(); 
    Library* subList(int start, int length);
    string toString();
};
#endif

#ifndef SLIST_H
void simpleSortTotal(Library l, int c, int i);
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);
double deg2rad(double deg);
double rad2deg(double rad);
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);
void simpleSortTotal(Library l, int c, int co);
#endif

#endif
