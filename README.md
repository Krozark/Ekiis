SFML2---Box2D
=============

Développement d'un moteur de jeu 2D.
Utilisation de SFML2 + OpenGL pour le rendu graphique et Box2D pour le moteur physique.
Comme il n'utilise pas les même unités (dégrée / radian, pixel / mettre), le but est de mettre une interface 
permettant de ne jamais ce soucier des unitées, et mettant en place des objets de plus haut niveau 
(tel que des corps mous, non disponible dans Box2D )

vidéo démo :
http://www.dailymotion.com/video/xr76p2_sfml2-box2d_videogames


Requirement:
------------

    SFML-2.0
    Box2D-2.2+ (test with 2.2.1)


Exemple:
--------

```shell
git clone --recursive git@github.com:Krozark/Ekiis.git
cd Ekiis/project
make
./ekiis
```

Or your can buil it using the code::bloks file if your are a user of  windows (not test on it).


You can use the Up/Down/Left/Right arrow to wove the window, and Right clik/Left clik / Space to build some object.


SFML
====

Event
-----

Callbacks sur Evenements:

    static void f(const sf::Event& event,sf::RenderWindow* data) // ou f(sf::RenderWindow* data)
    {
        //faire qqchose
    };

    static void f2(sf::RenderWindow* data) // ou f2(const sf::Event& event,sf::RenderWindow* data)
    {
        //faire qqchose
    };

    static void f3(int a,sf::RenderWindow* data,char* c) // ou f3(const sf::Event& event, int b,sf::RenderWindow* data, char* c)
    {
        //faire qqchose
    };

    MainWindow app(VideoMode(WIDTH, HEIGHT, BPP), "Box2D",60);
    // avec des fonctions C simples
    app.addEvent(EventManager::createEvent<sf::RenderWindow*>(f,&app,sf::Event::MouseButtonPressed,sf::Mouse::Left));
    app.addEvent(EventManager::createEvent<sf::RenderWindow*>(f2,&app,sf::Event::MouseButtonPressed,sf::Mouse::Right));
    app.addEvent(EventManager::createEvent<int,sf::RenderWindow*,char*>(f3,42,&app,"test",sf::Event::KeyPressed,sf::Keyboard::Space)); 

    //avec des méthodes C++
    app.addEvent(EventManager::createEventObj(this,&MainWindow::close,sf::Event::Closed)); // <MainWindow> est optionel
    app.addEvent(EventManager::createEventObj(this,&MainWindow::close,sf::Event::KeyPressed,sf::Keyboard::Escape)); // idem


Vous pouvez passer tous les aguments que vous voulez lors de la créations des évents. Les seul limites sont:
* Pour récupérer l'évent dans la callback, la callback (C / C++)  doit déclarer "const sf::Event& ev" en premier argument.
* createEvent[Obj] doit avoir la forme suivante:
    * createEvent\<Args...\>(fontion\_name,Args ..., sf::Event ...)
    * createEventObj\<objetClassname,Args ...\>(&objet,&objet::methode,Args ..., sf::Event ...)


Le paramètre const sf::Event& bind peut etre remplacé par::

       (const sf::Event& ev);
       (const sf::Event::EventType &evtType);
       (const sf::Event::EventType &evtType,const sf::Mouse::Button button);
       (const sf::Event::EventType &evtType,const sf::Keyboard::Key code, bool alt=false, bool ctlr=false, bool shift=false, bool system=false);
       (const sf::Event::EventType &evtType,const int joyId, const int button);

Quand cet évèmement sera détecté dans la boucle principale, la callback sera exécutée (avec les éventuels paramètres passés)


MainWindow
----------

Class metant en place des statégie pour utiliser les évenemet simplement.
Permet également un resize de la fenètre sans zoom (agrendisement de la zone visible simple).
Elle prédéfinie également des évènemets close, activé par défaut par Esc.



Box2D
=====


SoftBody
--------

Un ajout à été réaliser afin de gérer des objets mous.
Pour le moments, il est seulement possible de créer des cercles mous (SoftCircle).



SFML & Box2D
============


Body
----

Classe body permetant de créer des objets à la fois pysique et dessinables.
Il existe:
* NotDrawableBody (pyhsique seulement)
    * NOtDrawableCircle

* Body (phyisique + dessinable)
    * Circle
    * Convex
    * Entity
    * Rect
    * SoftCircle


