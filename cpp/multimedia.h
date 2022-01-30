#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H
#include <string>
#include <iostream>

/*!
 * \file multimedia.h
 * \brief Base type of media
 * \author hajsalah-nada
 */
using namespace std;
class Multimedia
{
protected:
    /** Name of the media */
    string nom;
    /**  Path of the media  */
    string nomfichier;

public:
    /**
     * Default constructor
      */
    Multimedia(): nom(""), nomfichier(""){}
    /**
     * parametric constructor
     * @param n: the name of the media
     * @param nf: the path to the media.
     */

    Multimedia(string n, string nf){nom=n;
                                             nomfichier=nf;}
    /**
     * returns the name of the media
     */
    string getNom()const{return nom;}
    /**
     * Sets the name of the media
     */
    void setNom(string n){nom=n;}
    /**
     * returns the path of the media
     */
    string getNomfichier()const{return nomfichier;}
    /**
     * Sets the path of the media
     */
    void setNomfichier(string nf){nomfichier=nf;}
    virtual ~Multimedia(){}
    /**
     * Prints the representation of the media.
     * @param s: the outputstream (flow)
     */
    virtual void afficher(std::ostream & s) const {
    s << getNom() <<"**";
    s<< getNomfichier() <<"**";
    }
    string listatt() {
        string result = "";

            result = "Name : '" + getNom()+ "Path:"+getNomfichier() ;

        return result;
    }
    /**
    * Play the media
    */
    virtual void play() const = 0;

};

#endif // MULTIMEDIA_H
