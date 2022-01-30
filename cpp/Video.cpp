#include "Video.h"



Video::Video(std::string nom, std::string nomFichier,int duration):Multimedia(nom,nomFichier), duree(duration)
{}
//Video::Video():Multimedia(){duree=0;}


void Video::setDuree(int d)
{
    this->duree = d;
}

int Video::getDuree() const
{
    return this->duree;
}

void Video::afficher(std::ostream &s) const
{
    Multimedia::afficher(s);
    s << "The duration of this video file is : "<< duree <<"**";
}


void Video::play() const
{
    string command = "mpv " + nomfichier+ " &";
    cout << "Executing command:" << endl;
    system(command.c_str());
}
