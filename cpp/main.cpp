#include <stdio.h>
#include <unistd.h>
#include <memory>
#include <sstream>
#include <iostream>
#include"multimedia.h"
#include"photo.h"
#include"Video.h"
#include"Film.h"
#include"groupe.h"
#include"manager.h"
#include "tcpserver.h"


using namespace std;
using namespace cppu;

    const int PORT = 3331;
int main(int argc, const char* argv[])

{


        shared_ptr<TCPServer> server(new TCPServer());
        shared_ptr<Manager> m(new Manager());
        shared_ptr<Video> video = m->createVideo("video", "media/c++.mp4", 100);
        shared_ptr<Photo> photo = m->createPhoto("photo", "media/c++.png", 123, 321);
        shared_ptr<Groupe> group = m->createGroup("group");
        group->push_back(video);
        group->push_back(photo);
        group->printGroup(cout);

        server->setCallback(*m, &Manager::processRequest);

        cout << "Starting Server on port " << PORT << endl;
        int status = server->run(PORT);

        if (status < 0) {
          cerr << "Could not start Server on port " << PORT << endl;
          return 1;
        }




#ifdef OLD_VERSION

    //Multimedia* m= new  Multimedia("M","N");
  //m->afficher(std::cout);
  //p->afficher(std::cout);
  //Photo *photo1=new Photo("c++","media/c++.png",4,3);
  //photo1->play();
 /*Question 5
     int nbr = 2;
     Multimedia *multimedia[nbr];
     multimedia[0] = new Photo("c++", "media/c++.png", 213, 100);
     multimedia[1] = new Video("video", "media/c++.mp4", 100);

   for(int i = 0; i < nbr;i++) {
       multimedia[i]->play();
    }*/
    /*Question6
       Film *film = new Film("video", "media/c++.mp4.mp4", 100);
      int duration[] = {10, 10, 10,10, 10, 8, 12, 10, 10, 10};
      int numberChapters = 10;

      film->setChaptersDurations(duration, numberChapters);

       duration[0] = 0; duration[1] = 0; // on modifie duration

       film->afficher(cout);
       delete film;*/
       //int numberChapters = 10;
       //ilm *film1 = new Film("video", "video.mp4", 100);
       /*Film f("video", "video.mp4", 100);
       int* duration;
       f.setChaptersDurations(duration, numberChapters);

       Film  film2=f;

       duration[0] = 0, duration[1] = 0;
       film2.setChaptersDurations(duration, numberChapters);

       film2.afficher(cout);*/

       //film2.afficher(cout);
    /*question8 et9
        shared_ptr<Video> video(new Video("video", "media/video.mp4", 100));
        shared_ptr<Photo> photo(new Photo("tpt", "media/c++.png", 213, 100));
       Groupe* group(new Groupe(string("été")));

       cout << group->getName() << endl;
       group->push_back(video);
       gro"up->push_back(photo);
       group->printGroup(cout);
       video.reset();
       delete group;
*/
/*Question 10*/
    Manager manager;
       manager.createVideo("video", "media/c++.mp4", 100);
       manager.createPhoto("photo", "media/c++.png", 123, 321);
       manager.playMedia("video",cout);
#endif

}
