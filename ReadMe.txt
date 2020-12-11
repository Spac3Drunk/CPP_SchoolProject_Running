Le parcours en haut à gauche est la vue de coté avec les pentes.
Le parcours en bas à gauche est la vue aérienne avec les déviations droite, gauche.
les 2 parcours sont synchronisé en terme de longeur sur l'affichage.
Les "barres bleues" sont les point de ravitallement en eau.

la "boussole" à gauche indique la direction du vent et sa vitesse en m/s.
le vent est calculé suivant la déviation/angle droite, gauche du parcours, de l'angle du vent, de la vitesse du vent et des caractéristiques des coureurs.

Dans le "main.cpp" entre la ligne 142 et 147 vous avez le choix de charger le dernier parcours à partir d'un txt ou d'en générer un nouveau.

Les résultats de la dernière course sont sauvegardées dans "Classement.txt".

Dans "DefVal.hpp" vous pouvez modifier des caractériques relative à l'affichage et la simulation, (comme par exemple la vitesse de simulation.)