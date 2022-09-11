
Si manque de temps et surtout que la keymap installé convient, pas besoin d'en savoir plus. 
La keymap est ici : 

Si plus de temps et besoin de faire des modifications, il faut faire la configuration de QMK. Rien de compliqué non plus, du git et du C (à peu de chose prêt que des tableaux de touches).


## Setup QMK

https://docs.qmk.fm/#/newbs_getting_started à adapter en fonction de l'env

* Installer QMK MSYS 
* Lancer QMK MSYS 

* Aller dans le dossier git 

* Cloner https://github.com/qmk/qmk_firmware

* Executer la commande
	qmk setup 
	

	Info supplémentaire lors de mon installation : 
		Option -H pour donner le dossier. Sans ca, c'est chercher dans C/Users/{userName}
		Si dans le dossier git, lancer la commande  qmk setup -H ./qmk_firmware/ pour que ca fonctionne comme attendu

* Répondre Y à toutes les questions

## Compilation QMK 

Pour tester, compiler la keymap du clavier par défaut avec la commande
	qmk compile -kb cantor -km default

## Compiler & Flasher le clavier 


Actuellement, pour flasher, il faut utiliser la touche RESET. 

En son absence, if faut se mettre en bootloader mode en utilisant les boutons présent sur la carte Blackpill. Tiré de la documentation du Cantor : 

https://github.com/diepala/cantor 

To flash the firmware to the microcontroller connect the blackpill to your computer and set it to bootloader mode. To do this the first time:

	* Press and hold the BOOT0 button.
	* Press and release the NRST button.
	* Release the BOOT0 button.

The following times you want to flash the keyboard, it is much simpler thanks to bootmagic. Hold the top left key of the keyboard and plug the microcontroller. If flashing the right part, hold the top right key. --> Pas testé, à valider.

Puis, executer la commande : 

qmk flash -kb <keyboard_name> -km <keymap_name> 

La compilation uniquement permet de valider que le code est correct sans le pousser sur le clavier.
Pour compiler, il faut utiliser la commande 
qmk compile -kb <keyboard_name> -km  <keymap_name>


## Gestion du code 

Personnellement, j'ai créé un repository dedié à côté et je fais des liens symboliques de mes keymaps dans le dossier QMK, ca permet de mettre à jour facilement QMK si besoin de nouvelles fonctionnalités sans galérer à merge/rebase ou autre. 

https://github.com/aperrad/qmk-keymaps/cantor en lien symbolique aperrad dans qmk/qmk_firmare/keyboard/cantor/keymaps 
//FIXME La commande pour le faire sur Windows. Sinon le faire en copiant dedans est également faisable. 

J'ai créé une keymap french pour faciliter le démarrage. Pour les keycodes FR, il faut aller voir dans quantum\keymap_extras\keymap_french.h

Pour la compiler, il faut lancer la commande suivante depuis le repo QMK :
qmk compile -kb cantor -km french

Pour la flasher : 
qmk flash -kb cantor -km french



# Ressources

Repo du clavier https://github.com/diepala/cantor 

Dossier Cantor de QMK : https://github.com/qmk/qmk_firmware/tree/develop/keyboards/cantor 

Mes keymaps : https://github.com/aperrad/qmk-keymaps/ Avec des combos, un layer pour du debug Chrome / Eclipse et sûrement d'autres choses

# Inspiration 

Autres claviers connus avec beaucoup de keymaps d'exemple de fonctionnalités :
	* Corne https://github.com/qmk/qmk_firmware/tree/develop/keyboards/crkbd
	* Kyria https://github.com/qmk/qmk_firmware/tree/develop/keyboards/splitkb/kyria
	* Lily58 https://github.com/qmk/qmk_firmware/tree/develop/keyboards/lily58
	* Sofle https://github.com/qmk/qmk_firmware/tree/develop/keyboards/sofle
	* Et un peu tout dans le repo dans le dossier keyboards, c'est les principaux auquels je pense
 
Chercher sur les sites de ventes et voir les noms des claviers dans QMK/keyboards/XXX/keymaps

Reddit 
	https://www.reddit.com/r/MechanicalKeyboards/ 
	https://www.reddit.com/r/ErgoMechKeyboards/

De nombreux Discord 
	SplitKB
	LowProfile
	Absolem
	42Keebs
	40% club
	... 

En discuter :)