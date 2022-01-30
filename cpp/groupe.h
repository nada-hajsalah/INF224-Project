#ifndef GROUP_H
#define GROUP_H

#include <list>
#include <string>
#include <memory>
#include "multimedia.h"
#include "Video.h"
using namespace std;


class Groupe : public list<shared_ptr<Multimedia>>
{
    string name;

public:
    Groupe() {}

    Groupe(string name) : name(name) {}
    ~Groupe() {}

    string getName() const {
        return name;
    }


    void printGroup(ostream &s) {
        s << "Printing group :" << name << endl;

        for (auto it : *this)
           {
               it->afficher(s);
           }


    }


    void setName(string name) {
        this->name = name;
    }
    string listGroupe() {
        string result = "";
        for(auto e: *this) {
            result += "Name: "+ e->getNom()+"Path: " + e->getNomfichier();
        }
        return result;
    }

};

#endif // GROUP_H
