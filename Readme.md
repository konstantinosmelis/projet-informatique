# Projet de programmation
## Image Pro

### Utilisation
#### Connexion
Lors de l'execution du programme un dossier doit être passé en paramètres. Ce dossier doit contenir un ou plusieurs fichiers nommés par un nom d'utilisateur.
Ce fichier doit suivre le format suivant:
```
mot_de_passe
entier
```

Le mot clé `mot_de_passe` correspond au mot de passe de l'utilisateur et l'`entier` au niveau d'accès de l'utilisateur (1 pour administrateur, 0 pour utilisateur simple).

#### Chargement d'une base de données
Pour charge une base de données, un dossier doit être sélectionné. Ce dossier doit contenir les fichies techniques des images sous forme des fichiers texte. Ces fichiers doivent suivre le format suivant:
```
chemin_vers_image
titre
source
auteur
niveau_d_acces
poids
```

Le niveau d'accès ne peut prendre que 2 valeurs textuelles ("public" ou "private").

#### Ajout d'une image
Pour ajouter une image il suffit de clicker sur le bouton déduié de l'interface, puis de compléter les informations demandées.

#### Application d'un traitement sur une image
Pour appliquer un traitement, clickez sur une des images dans le tableau et puis sur le bouton dédié de l'inteface. Une nouvelle interface apparaîtra dans laquelle plusieurs choix de traitement sont offerts. Notez que les traitements sont succéssifs sur l'image. Il est donc possible d'effectuer plusieurs traitements à la suite.

Lors de la sauvegarde de l'image, cette dernière sera accompagnée par sa fiche technique.