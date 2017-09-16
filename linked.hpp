//
//  linked.hpp
//
//
//  Created by Ziyan Mo on 9/6/17.
//
//

#ifndef linked_hpp
#define linked_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

#endif /* linked_hpp */

struct hashCell {
    string key;
    void * value;
    hashCell * next;
};

class hashMap {
public:
    bool set(string key, void * value);
    float load();
    void * get(string key);
    void deleted(string key);
    hashMap(long nsize);  // This is the constructor
    
private:
    hashCell ** array;
    bool * fullEmpty;
    hash<string> hashstr;
    long size;
    long cursize;
};



