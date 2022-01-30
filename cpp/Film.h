#ifndef FILM_H
#define FILM_H

#include "Video.h"
/**
 * @brief Represents a movie, with chapters.
 */

class Film : public Video
{
private:
    /** Number of chapters. */
    int chaptersNumber;
    /** The length of each chapter */
    int* chaptersDurations;

public:
    Film(std::string nom, std::string nomfichier, int duration=0, int chaptersNumber=0, int* chaptersDurations=nullptr);
    /**
    * Default constructor
    */
    Film();




    //Copy constructor and operator=
    /**
     * @brief Film copy constructor to handle deep copies
     * @param from
     */
    Film(const Film& from);
    /**
     * @brief operator = redefining the operator= to handle deep copies
     * @param from
     * @return
     */
    Film& operator=(const Film& from);


    void setChaptersDurations(const int* chaptersDurations, int chaptersNumber);
    const int * getChaptersDurations() const;
    int getChaptersNumber() const;

    void afficher(std::ostream& stream = std::cout) const override;

    virtual ~Film();

};

#endif // FILM_H
