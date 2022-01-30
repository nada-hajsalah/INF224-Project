#include "manager.h"
using namespace std;

Manager::Manager()
{

}

shared_ptr<Photo> Manager::createPhoto(string nom, string nomFichier , float latitude, float longitude) {
    shared_ptr<Photo> photo_new(new Photo(nom, nomFichier, latitude, longitude));
    MultimediaTab[nom] = photo_new ;
    return photo_new;
}

shared_ptr<Video> Manager::createVideo(string nom, string nomFichier , int duration) {
    shared_ptr<Video> video_new(new Video(nom, nomFichier, duration));
    MultimediaTab[nom] = video_new;
    return video_new;
}

shared_ptr<Film> Manager::createFilm(string nom, string nomFichier , int duration, int chaptersNumber) {
    shared_ptr<Film> film_new(new Film(nom, nomFichier, duration, chaptersNumber));
    MultimediaTab[nom] = film_new;
    return film_new;
}


shared_ptr<Groupe> Manager::createGroup(const std::string groupname) {
    GroupeTab[groupname] = shared_ptr<Groupe>(new Groupe(groupname));
    return GroupeTab[groupname];
}

shared_ptr<Multimedia> Manager::findMultimedia(string name) {
    auto it = MultimediaTab.find(name);
    if(it == MultimediaTab.end())
        return nullptr;
    else
        return it->second;
}


shared_ptr<Groupe> Manager::findGroup(string name) {
    auto it = GroupeTab.find(name);
    if(it == GroupeTab.end())
        return nullptr;
    else
        return it->second;
}

void Manager::afficherMedia(string nom, ostream& s)  {
    auto multimedia = findMultimedia(nom);
    if(multimedia == nullptr) {
        s << "Error can't find " << nom  << " in multimedia table " << endl;
        return;
    }
    multimedia->afficher(s);
}


void Manager::playMedia(string nom,ostream& s) {
    auto multimedia = findMultimedia(nom);
    if(multimedia == nullptr) {
        s << "Error can't find " << nom  << " in multimedia table " << endl;
        return;
    }
    multimedia->play();
}

void Manager::listMedia() const
{
    for(auto it = MultimediaTab.begin(); it != MultimediaTab.end(); ++it) {
        cout<< it->first << ";";
    }
    cout << "\n";
}
void Manager::listGroups(std::ostream& stream)
{
    for(auto it = GroupeTab.begin(); it != GroupeTab.end(); ++it) {
        stream << it->first << ";";
    }
    stream << "\n";
}
void Manager::afficherGroup(std::string nom, std::ostream& s)
{
    auto groupe = findGroup(nom);
    if(groupe == nullptr) {
        s << "Error can't find " << nom   << endl;
        return;
    }
    groupe->printGroup(s);

}

bool Manager::processRequest(TCPConnection& cnx, const string& request, string& response) {

    cerr << "\nRequest: '" << request << "'" << endl;

    stringstream stream, response_stream;
    stream << request;

    string operation, name;
    stream >> operation >> name;

    TCPLock lock(cnx);

    if(operation == "Search") {
        shared_ptr<Multimedia> result = findMultimedia(name);
        if(result == nullptr) {
            response = "No multimedia found with name : " + name;
        }
        else {
            result->afficher(response_stream);
            response = response_stream.str();
        }
    }
    else if(operation == "Search_Group") {
        shared_ptr<Groupe> result = findGroup(name);
        if(result == nullptr) {
            response = "No group found with name : " + name ;
        }
        else {

            response = "Group: " +result->getName()+ " contains " + result->listGroupe();
        }
    }
    else if(operation == "Play") {
        shared_ptr<Multimedia> result = findMultimedia(name);
        if(result == nullptr) {
            response = "No multimedia found with name : " + name;
        }
        else {
            result->play();
            response =  name + " is runing on server ";
        }
    }

    else if(operation == "quit") {

        return false;
    }
    else {
        response = " Try again , your request is false";
    }
    cerr << "response: " << response << endl;


    return true;
}
