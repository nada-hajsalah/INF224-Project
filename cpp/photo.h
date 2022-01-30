#ifndef PHOTO_H
#define PHOTO_H
#include"multimedia.h"

/**
 * @brief Type of media: Photo
 */
class Photo: public Multimedia
{
private:
    /** latitude of the photo*/
    float lat;
     /** longitude of the photo*/
    float longt;
public:
    /**
     * parametric constructor
     * @param n: the name of the photo
     * @param nf: the path to the photo
     * @param lat: latitude of the photo
     * @param longt: longitude of the  media.
     */

    Photo(string n,string nf,float lat, float longt):Multimedia(n, nf), lat(lat), longt(longt) { }
    float getLat()const{return lat;}
    void setLat(float l1){lat=l1;}
    float getLongt()const{return longt;}
    void setLongt(float l2){longt=l2;}
    void afficher(std::ostream & s) const override { s<< "This multimedia file is a photo "  <<"**";Multimedia::afficher(s);
                                                     s<< "The longitude of this photo is : "<< longt <<"**";
                                                   s << "The latitude of this photo is : "<< lat<<"**";}
    /**
    * @brief plays the photo
    */
    void play() const override {
            string command = "mpv " + nomfichier+ " &";
            cout << "Executing command:" << endl;
            system(command.c_str());
        }
    ~Photo(){}
};

#endif // PHOTO_H
