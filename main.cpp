#include <iostream>
#include <fstream>
#include <cmath> 
#include "slist.h"
#include "slist.cpp"

using namespace std;

void simpleSortTotal(Library l, int c, int i);
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);

int main()
{
    ifstream infile;
    int i=0;
    char cNum[1000] ;
    //Airport* airportArr[135000];			// Replace array with Linked List
    Library l;
    int   airportCount;
    Airport* a[13500];
    
    infile.open ("airport-codes_US.csv", ifstream::in);
    if (infile.is_open())
    {
      infile.getline(cNum, 256, ',');
        int   c=0;
        while (infile.good())
        {
          if (c == 22338) {
            break;
          }
          // airportArr[c] = new Airport();
          Airport* a = new Airport();
          
          // infile.getline(airportArr[c]->code, 256, ',');
          infile.getline(a->code, 256, ',');
          infile.getline(cNum, 256, ',');
          infile.getline(cNum, 256, ',');
          infile.getline(cNum, 256, ',');
          // airportArr[c]->longitude = atof(cNum);
          a->longitude = atof(cNum);
          infile.getline(cNum, 256, '\n');
          // airportArr[c]->latitude = atof(cNum);
          a->latitude = atof(cNum);

          l.add(a);

          // if (!(c % 1000))
            // cout << l.get(c)->code << " long: " << l.get(c)->longitude << " lat: " << l.get(c)->latitude << endl;
            
          // if (!(c % 1000))
          // {
          //     cout << airportArr[c]->code << " long: " << airportArr[c]->longitude << " lat: " << airportArr[c]->latitude <<  endl;
          //     cout << airportArr[c+1]->code << " long: " << airportArr[c+1]->longitude << " lat: " << airportArr[c+1]->latitude <<  endl;                               
          // }
  
          i++ ;
          c++;
        }
  
    
        airportCount = c-1;
        infile.close();
       
         // for (int c=0; c < airportCount - 1; c++) 
            //if (!(c % 1000))
            // {
               // cout << l.get(c).code << " long: " << l.get(c).longitude << " lat: " << l.get(c).latitude <<  endl;
               // cout << l.get(c+1).code << " long: " << l.get(c+1).longitude << " lat: " << l.get(c+1).latitude <<  endl;
                // cout <<"Distance between " << l.get(c).code << " and " << l.get(c).code << " is "
                //   << distanceEarth(l.get(c).longitude, l.get(c).latitude , l.get(c+1).longitude, l.get(c+1).latitude) << endl;
             // }
        

    int austin = l.findAustin();
    double refLong = l.get(austin)->longitude;
    double refLat = l.get(austin)->latitude;
    
    
    string farthest = "";
    double maxDist = 0;
    
    int loc = 0; 
    
    for (int i = 1; i < c; i++) {
      if (i == austin) {
        continue;
      }
      double distToRef = distanceEarth(refLat, refLong, l.getNode(i)->air->latitude, l.getNode(i)->air->longitude);
      
        if (distToRef > maxDist) {
          farthest = l.get(i)->code;
          maxDist = distToRef;
          loc = i;
        }
      }
      
      cout << "Farthest Airport from Austin (Distance in Miles)" << endl;
      cout << farthest << " " << maxDist * 0.621371 << endl;
  
      cout << endl;
      cout << "Closest Airports to Austin (Distance in Miles)" << endl;
      
      int counter = 0;
     
      for (int i = c; i >= 0; i--) {
        counter ++;
        
        simpleSortTotal(l, i, counter);
      }
    }
    else
    {
        cout << "Error opening file";
    }
}

#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

// This function converts decimal degrees to radians
double deg2rad(double deg) {
  return (deg * pi / 180);
}

//  This function converts radians to decimal degrees
double rad2deg(double rad) {
  return (rad * 180 / pi);
}

/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(lat2d);
  lon2r = deg2rad(lon2d);
  u = sin((lat2r - lat1r)/2);
  v = sin((lon2r - lon1r)/2);
  return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}

/*
	Provide sort routine on linked list
*/
/*
void simpleSortTotal()
{
}
*/

void simpleSortTotal(Library l, int c, int co) {
  int skip = l.findAustin();
  double refLong = l.get(skip)->longitude;
  double refLat = l.get(skip)->latitude;
  
  string closest = "";
  double minDist = 100000;
  
  int loc = 0; 
  for (int i = 1; i < c; i++) {
    if (i == skip) {
      continue;
    }
    double distToRef = distanceEarth(refLat, refLong, l.getNode(i)->air->latitude, l.getNode(i)->air->longitude);
    
    if (distToRef < minDist) {
      closest = l.get(i)->code;
      minDist = distToRef;
      loc = i;
    }
  }
  cout << co << " " << closest << " " << minDist * 0.621371 << endl;
  l.remove(loc);
}
