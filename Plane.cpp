#include <iostream>
#include <string>
#include <vector>

#include "Plane.h"
#include "Table.h"
#include "Utils.h"

using namespace std;

// Static vectors need to be initialized
vector<Plane> Plane::planes = {};
vector<string> Plane::headers = {};

void Plane::load() {
  Table::parseFile(Table::readFile("Planes"), Plane::setHeaders, Plane::factory);
}

vector<vector<string>> Plane::serialize() {
  vector<vector<string>> result;
  result.push_back(Plane::headers);

  for(int i=0; i<Plane::planes.size(); i++) {
    vector<string> record;
    record.push_back(Plane::planes[i].planeID);
    record.push_back(to_string(Plane::planes[i].maxPassangersCount));

    result.push_back(record);
  }

  return result;
}

void Plane::setHeaders(vector<string> _headers) {
  headers = _headers;
}

void Plane::factory(int _entryLine, vector<string> rawData, bool fsSync) {
  Plane obj(_entryLine, rawData);
  planes.push_back(obj);
  if(fsSync) Table::writeFile("Plane", serialize());
}

Plane::Plane(int _entryLine, vector<string> rawData) {
  entryLine = _entryLine;

  planeID = rawData[0];
  maxPassangersCount = Utils::strToInt(rawData[1]);

  // cout << "Created flight #" << flightID << " on " << planeID << endl;
}
