Romain D'hem
Bienvenue sur mon ReadMe! 

Pour lancer mon jeu vous devez avoir Qt creator avec la version 5.15.2 de QT et le compilateur MinGW 8.1.0 64-bit
Ensuite il faut ouvrir le fichier CmakeLists.txt dans le fichier Projet2 puis lancer avec play

Pour jouer à mon jeu il faut utiliser ZQSD pour ce déplacer et espace pour sauter.
Un menu Pause est proposé avec P et un menu déroulant en haut à gauche permet de restart, quitter et de voir le meilleur score.
Un god mod est aussi implémenté mais reste expérimental avec G
Le jeu possède système de checkpoint, de zone dangereuse ainsi que des pièces
Tomber dans le vide vous permet de revenir au dernier checkpoint

BUT DU JEU
Trouvez le Nyan Cat perdu qui cherche son ami Pedro l'ours.

Voici les bugs que j'ai rencontrés : 
- la plateforme qui bouge en x décale le personnage petit à petit.
- l'affiche du chrono et pièce est acrochée à la scène et non la vue
- la plateforme qui bouge en x peut-être transpercé sur la gauche et droite
- le bouton quitté à la fin ne ferme pas le jeu de manière très propre
- les petites plateformes peuvent avoir des problèmes de collisions par le bas
- mon god mod doit être activé en étant statique
- mon meilleur score ne s'actualise que lorsqu'on relance le jeu
- il y a un décalage entre la hitbox et l'image du personnage car le programme ne peux faire deux calcul en même temps



J'ai besoin de l'aide de chat GPT pour :
- lecture de mon fichier
- mon chronomètre

J'ai aussi reçu de l'aide oral (Pier) pour l'animation de mon personnage

