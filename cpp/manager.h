#ifndef MANAGER_H
#define MANAGER_H

#include "multimedia.h"
#include "groupe.h"
#include "photo.h"
#include "Video.h"
#include "Film.h"
#include "tcpserver.h"
#include <string>
#include <memory>
#include <map>
#include <sstream>
using namespace cppu;
using namespace std;
/**
 * @brief The Manager class to handle the media creation
 */
class Manager
{

private:
    /** hashTable(map)for media objects */
    std::map<std::string,std::shared_ptr<Multimedia>> MultimediaTab;
    /**  hashTable(map) for groups of medias */
    std::map<std::string,std::shared_ptr<Groupe>> GroupeTab;

public:
    Manager();
    /**
    * Creats a photo and inserts it into the hashtable for media objects
    */
    std::shared_ptr<Photo> createPhoto(string nom, string nomFichier , float latitude, float longitude);
    /**
    * Creats a video and inserts it into the hashtable for media objects
    */
    std::shared_ptr<Video> createVideo(string nom, string nomFichier , int duration);
    /**
    * Creats a film and inserts it into the hashtable for media objects
    */
    std::shared_ptr<Film> createFilm(string nom, string nomFichier , int duration, int chaptersNumber);
    /**
    * Creats a group and inserts it into the hashtable for groups of ùedoa
    */
    shared_ptr<Groupe> createGroup(const std::string groupname);
    /** Find a media by name
    * @param  name: The name of the searched media
    * @returns a pointer to the object, or nullptr if didn't found it
     */
    shared_ptr<Multimedia> findMultimedia(string name);
    /** Find a group by name
    * @param  name: The name of the searched group
    * @returns a pointer to the object, or `nullptr` if didn't found it.
     */
     shared_ptr<Groupe> findGroup(string name);

    void afficherMedia(string nom, ostream& s) ;

    /** Plays a media
     * @param nom: The name of the media
     * @param s: The flow
     */
    void playMedia(std::string nom, std::ostream& s);
    void afficherGroup(std::string nom, std::ostream& s);
    string listMultimedia();
    void listGroups(std::ostream& stream);
    void listMedia() const;
    /**
        * @brief processRequest
        * @param cnx : connexion between client and server
        * @param request:request of client
        * @param response: the answer of server to send it to the client
        * @return
        */
    bool processRequest(TCPConnection& cnx, const string& request, string& response);
};

#endif // MANAGER_H
