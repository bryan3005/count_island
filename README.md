# count_island
Fonctions Autorisées :
 open, close, read, write, malloc, free
Fichiers à rendre :
 *.c, *.h
 
 •
 Le programme prend en paramètre un ﬁchier contenant une serie de lignes de lon-gueurs égales contenant soit le caractere ’.’ soit le caractere ’X’. Ces lignes formentun rectangle de ’.’ comportant des ilots de ’X’.
•
 Une ligne est une suite de caractères ’.’ et de caracteres ’X’ qui se termine par unretour à la ligne. Les lignes font toutes la même taille. La taille maximum d’uneligne est 1024 caractères.
•
 Une colonne de caractères est formée par l’ensemble des caractères dans un ﬁchierqui sont séparés par le même nombre de caractères du début de leur ligne respective.
•
 On dit que deux caractères se touchent s’ils sont soit sur la même ligne et contigus,soit sur la même colone et sur des lignes contigues.
•
 Un ilot de ’X’ est forme par l’ensemble des caractères qui se touchent.
•
 Le programme doit parcourir le ﬁchier ligne par ligne et l’aﬃcher à l’écran enremplacant tous les ’X’ des ilots par leur numéro d’apparition dans le ﬁchier. Leprogramme devra eﬀectuer ce traitement en commancant par le debut du ﬁchier.
•
 Il ne peut pas y avoir deux résultats diﬀérents pour un même ﬁchier.
•
 Si le ﬁchier est vide, qu’une erreur s’est produite (lignes de taille diﬀérentes parexemple) ou que aucun ﬁchier n’est passé en paramètre, le programme ecrit simple-ment le caractère du retour à la ligne sur sa sortie standard.
•
 Le ﬁchier comporte au maximum 10 ilots.
•
 Vous trouverez dans le repertoire
 misc/
 des exemples de ﬁchier.
