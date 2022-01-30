#ifndef VIDEO_H
#define VIDEO_H
#include"multimedia.h"

/**
 * @brief Type of media: Video
 */

class Video:public Multimedia
{private:
    /** Duration of the movie */
 int duree;
public:
 /**
  * Default constructor
  */
 Video();
 /**
  * parametric constructor
  * @param nom: the name of the video
  * @param nomFichier: the path to the video
  * @param duration:Duration of the video
  */

 Video(string nom, string nomFichier, int duration=0);
 void setDuree(int duration);
 int getDuree() const;
 virtual void afficher(std::ostream& s) const override;
 /**
 * Plays the movie.
 */
 void play() const override;

};

#endif // VIDEO_H
