# Allocation
Weapon devrait etre allouer puisqu'en passant une copie de weapon a mon constructeur HumanA,
celle-ci se detruit a la fin du constructeur et `Weapon* _weapon` pointe donc vers une
adresse memoire invalide.

il faut donc passer une reference qu'il faut init insatnt (une reference
ne peut pas etre null).

