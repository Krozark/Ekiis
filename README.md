SFML2---Box2D
=============

Développement d'un moteur de jeu 2D.
Utilisation de SFML2 + OpenGL pour le rendu graphique et Box2D pour le moteur physique.
Comme il n'utilise pas les même unités (dégrée / radian, pixel / mettre), le but est de mettre une interface 
permettant de ne jamais ce soucier des unitées, et mettant en place des objets de plus haut niveau 
(tel que des corps mous, non disponible dans Box2D )

vidéo démo :
http://www.dailymotion.com/video/xr76p2_sfml2-box2d_videogames


Callbacks sur Evenements:
------------------------

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
    // avec des fonctions C
    app.addEvent(EventManager::createEvent<sf::RenderWindow*>(f,&app,sf::Event::MouseButtonPressed,sf::Mouse::Left));
    app.addEvent(EventManager::createEvent<sf::RenderWindow*>(f2,&app,sf::Event::MouseButtonPressed,sf::Mouse::Right));
    app.addEvent(EventManager::createEvent<int,sf::RenderWindow*,char*>(f3,42,&app,"test",sf::Event::KeyPressed,sf::Keyboard::Space)); 

    //avec des méthodes C++
    app.addEvent(EventManager::createEvent<MainWindow>(this,&MainWindow::close,sf::Event::Closed));
    app.addEvent(EventManager::createEvent<MainWindow>(this,&MainWindow::close,sf::Event::KeyPressed,sf::Keyboard::Escape));


Vous pouvez passer tous les aguments que vous voulez lors de la créations des évents. Les seul limites sont:
Pour récupérer l'évent dans la callback, la callback (C / C++)  doit déclarer "const sf::Event& ev" en premier argument.
parametrer createEvent avec les types des variables / constantes qui sont passées en paramètre :
    createEvent<int,char,Perso>(ma_fonction,42,"char de test",heros,const sf::Event& bind)

Le paramètre const sf::Event& bind peut etre remplacé par::

       (const sf::Event& ev);
       (const sf::Event::EventType &evtType);
       (const sf::Event::EventType &evtType,const sf::Mouse::Button button);
       (const sf::Event::EventType &evtType,const sf::Keyboard::Key code, bool alt=false, bool ctlr=false, bool shift=false, bool system=false);
       (const sf::Event::EventType &evtType,const int joyId, const int button);

Quand cet évèmement sera détecté dans la boucle principale, la callback sera exécutée (avec les éventuels paramètres passés)



