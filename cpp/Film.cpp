#include "Film.h"


//Film::Film():Video(){}

Film::Film(std::string name, std::string pathname,
           int duration, int chaptersNumber, int* chaptersDurations):
    Video(name, pathname, duration)
{
    this->setChaptersDurations(chaptersDurations,chaptersNumber);
}

Film::Film(const Film& from) : Video(from)
{
    chaptersNumber = from.chaptersNumber;
    if (from.chaptersDurations)
    {
        this->setChaptersDurations(from.chaptersDurations, from.chaptersNumber);
    }
    else
        chaptersDurations = nullptr;
}

Film& Film::operator=(const Film& from)
{
    Video::operator=(from);
    chaptersNumber = from.chaptersNumber;
    if (chaptersDurations && from.chaptersDurations)
        *chaptersDurations = *(from.chaptersDurations);
    else
    {
        delete chaptersDurations;
        if (from.chaptersDurations)
        {
            this->setChaptersDurations(from.chaptersDurations, from.chaptersNumber);
        }
        else
            chaptersDurations = nullptr;
    }
    return *this;
}
int Film::getChaptersNumber() const
{
    return this->chaptersNumber;
}
const int*Film::getChaptersDurations() const{
       return chaptersDurations;
   }

void Film::setChaptersDurations(const int* chaptersDurations,int chaptersNumber)
{
    this->chaptersNumber = chaptersNumber;

            delete this->chaptersDurations;
            this->chaptersDurations = nullptr;

            if(chaptersNumber > 0)
                this->chaptersDurations = new int[chaptersNumber];

            for(int i = 0; i <chaptersNumber; i++) {
                this->chaptersDurations[i] = chaptersDurations[i];}

}
void Film::afficher(std::ostream& stream) const
{
    Video::afficher(stream);
    stream << "Number of chapters : " <<chaptersNumber  <<"**";
            for(int i = 0; i < chaptersNumber; i++) {
                stream << "Duration chapter num" << i + 1 << ": " << chaptersDurations[i] <<"**";
            }
}


Film::~Film()
{
    delete chaptersDurations;
}

