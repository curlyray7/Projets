/**
*
* \brief Programme d'un puissance 4.
*
* \author El younsi Rayane
*
* \version 1.0
*
* \date 21 novembre 2022
*
* Ce programme propose à 2 joueurs de jouer à un puissance 4 , la partie se termine lorsque 1 joueurs 
*	affiche 4 pions horizontalement , verticalement ou diagonalement alignés ou que la grille de jeu est pleine .
*
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

/*****************************************************
 		       * LISTE DES CONSTANTES *
*****************************************************/

/**
*
* \def NBLIG
*
* \brief constante pour le nombre de lignes dans la grille
*/
#define NBLIG 7

/**
*
* \def NBCOL
*
* \brief constante pour le nombre de colonnes dans le grille 
*/
#define NBCOL 7

/**
*
* \def COLONNE_DEBUT
*
* \brief constante pour l'affichage du jeton au milieu de la premiere ligne de la grille
*/
#define COLONNE_DEBUT NBCOL/2

/**
*
* \def PION_A
*
* \brief constante pour le jeton 'X'
*/
#define PION_A 'X'

/**
*
* \def PION_B
*
* \brief constante pour le jeton 'O' 
*/
#define PION_B 'O'

/**
*
* \def VIDE
*
* \brief constante pour une case vide 
*/
#define VIDE ' '

/**
*
* \def DROITE
*
* \brief constante pour le deplacement du jeton à droite 
*/
#define DROITE 'd'

/**
*
* \def GAUCHE
*
* \brief constante pour le deplacement du jeton à gauche 
*/
#define GAUCHE 'q'

/**
*
* \def VICTOIRE
*
* \brief constante pour l'alignement des jetons 
*/	
const int VICTOIRE = 4;

/**
*
* \def INCONNU
*
* \brief constante aucun vainqueur.
*
*/
const char INCONNU = ' ';

/**
*
* \def Oui
*
* \brief constante pour la réponse 'oui'.
*
*/
const char OUI[4] = "oui";

/**
*
* \def NON
*
* \brief constante pour la réponse 'non'.
*
*/
const char NON[4] = "non";

/**
*
* \def PLEIN
*
* \brief constante pour le nombre de jetons max dans une grille.
*
*/
const int PLEIN = 42;

/*****************************************************
 		   * LISTE DEFINITION TYPE *
*****************************************************/

/**
*
* \typedef chaine
*
* \brief type chaine de 19 caractères
*
* Le type chaine sert de stockage pour le nom des 2 joueurs
*
*/
typedef char chaine[20];

/**
*
* \typedef tab
*
* \brief type tableau à 2 dimensions de NBLIG lignes et NBCOL colonnes
*
* Le type tab sert de stockage pour la grille de jeu
*
*/
typedef int tab[NBLIG][NBCOL];

/*****************************************************
 		   * LISTE PROCÉDURES/FONCTIONS *
*****************************************************/

/**
*
* \fn void initGrille(tab grille)
*
* \brief Procédure qui initialise un tableau.
*
* \param grille : Le tableau à initialiser
*
* \return rien.
*
* Consiste à initialiser un tableau donné en parametre.
*
*/
void initGrille(tab grille);

/**
*
* \fn void afficher(tab grille,char pion, int colonne,chaine nomjoueur).
*
* \brief Procédure qui affiche un tableau.
*
* \param grille : Le tableau à afficher.
*
* \param pion : Le pion du joueur qui doit jouer .
*
* \param colonne : la colonne où l'on doit afficher le pion du joueur qui doit jouer.
*
* \param nomjoueur : Le nom du joueur qui doit jouer.
* 
* \return rien.
*
* Consiste à afficher un tableau donner en parametre ainsi que les pions qui seront jouer au fur et à mesure de la partie .
* De plus , le pion du joueur qui doit jouer s'affiche tout en haut de la grille au milieu .
*
*
*/
void afficher(tab grille,char pion, int colonne,chaine nomjoueur);

/**
*
* \fn bool grillePleine(tab grille).
*
* \brief Fonction qui indique si le tableau est plein ou non.
*
* \param grille : Le tableau l'où doit vérifier si il est plein. 
*
* \return true si le tableau est plein et false sinon.
*
* Consiste à vérigier que le tableau que le tableau ne soit pas plein , si c'est le cas la partie s'arréte et c'est donc une égalité.
*
*
*/
bool grillePleine(tab grille);

/**
*
* \fn void jouer(tab grille,char pion , int *ligne , int *colonne , chaine nomjoueur1 , chaine nomjoueur2).
*
* \brief Procédure qui permet de poser son jeton dans la grille.
*
* \param grille : La grille de jeu où poser son jeton.
*
* \param pion : Le pion à poser dans la grille .
*
* \param ligne : Appel la fonction choisirLigne et indique en parametre de sortie l'indice de la ligne où poser le jeton.
*
* \param colonne : Appel la fonction chisirColonne et indique en paramètre de sortie l'indice de la ligne où poser le jeton. 
*				   Si l'indice est égale à -1 , cela veut dire que la colonne est pleine.
* \param nomjoueur1 : Le nom du joueur 1.
* 
*\param nomjoueur2 : Le nom du joueur 2
*
* \return rien.
*
* Consiste à poser le jeton d'un des 2 joueurs chacun son tour . 
*
*
*/
void jouer(tab grille,char pion , int *ligne , int *colonne , chaine nomjoueur1 , chaine nomjoueur2);

/**
*
* \fn int choisirColonne(tab grille,char pion , int *ligne , int *colonne , chaine nomjoueur1 , chaine nomjoueur2).
*
* \brief Fonction qui indique la colonne où poser son jeton.
*
* \param grille : La grille de jeu où poser son jeton.
*
* \param pion : Le pion à poser dans la grille .
*
* \param colonne : La colonne de la grille à choisir.
*
* \param nomjoueur1 : Le nom du joueur 1.
* 
*\param nomjoueur2 : Le nom du joueur 2
*
* \return l'indice de la colonne où poser le jeton.
*
* On déplace le jeton avec 'q' à gauche et 'd' à droite et si l'on rentre ESPACE , on retourne l'indice de la colonne choisie.
*
*
*/
int choisirColonne(tab grille , char pion , int colonne,chaine nomjoueur1 , chaine nomjoueur2);

/**
*
* \fn int trouverLigne(tab grille , int colonne).
*
* \brief Fonction qui indique la ligne où poser son jeton.
*
* \param grille : La grille de jeu où choisir la ligne.
*
* \param colonne : La colonne de la ligne choisie
*
* \return l'indice de la ligne où poser le jeton.
*
* Tant que la colonne est vide , on descend en bas du tableau jusqu'à ce que un pion soit présent ou que l'on arrive tout en bas de la grille.
*
*
*/
int trouverLigne(tab grille , int colonne);

/**
*
* \fn bool estVainqueur(tab grille , int ligne ,int colonne).
*
* \brief Fonction qui indique si un joueur à aligner 4 jetons.
*
* \param grille : La grille de jeu où chercher si 4 jetons sont alignés.
*
* \param ligne : L''indice de ligne où chercher.

* \param colonne : L'indece de la colonne où chercher0
*
* \return true si un joueur à aligner 4 jetons d'affilées.
*
* 
*
*
*/
bool estVainqueur(tab grille , int ligne , int colonne);

/**
*
* \fn void finDePartie(char pion,chaine nomjoueur1 , chaine nomjoueur2,char recommencer[4]).
*
* \brief Procédure qui annonce la fin de partie et qui propose de recommencer une partie.
*
* \param nomjoueur1 : le nom du joueur 1.
*
* \param nomjoueur2 : le nom du joueur 2.

* \param recommencer : Chaine qui stock le choix des joueurs pour recommencer une partie (oui ou non) .
*
* \return rien.
*
* Si le pion X remporte la partie  le vainqueur est le joueur 1 , si le pion O remporte le vainqueur est le joueur2 .
* A la fin , la procédure propose aux joueurs de recommencer une partie ou non .
*
*
*/
void finDePartie(char pion,chaine nomjoueur1 , chaine nomjoueur2,char recommencer[4]);

/**
*
* \fn void age(chaine nomjoueur1 , chaine nomjoueur2 ).
*
* \brief Procédure qui désigne le joueur 1 et 2 en leur demandant leurs noms et âges .
*
* \param nomjoueur1 : Le nom du joueur 1.
*
* \param nomjoueur2 : Le nom du joueur 2.
*
* \return rien.
*
* La procédure commence par demander les prénoms des 2 joueurs puis leurs demandent leurs âges car le plus jeune commencera .
* si jamais ils ont le même âge , le joueur 1 sera par défault la première personne à avoir rentrer son nom.
*
*
*/
void age(chaine nomjoueur1 , chaine nomjoueur2 );


/*****************************************************
 				* PROGRAMME PRINCIPAL *
*****************************************************/

int main(){
	
	char recommencer[4] ="oui";				//** Chaine de 3 caractères qui stock 'oui'/'non' , afin de savoir si les joueurs veulent recommencer une partie */
	
	while(strcmp(recommencer , OUI ) == 0){ 		//** Tant que les joueurs veulent recommencer une partie ... */
		char vainqueur;
    	chaine joueur1 ;		//** Nom du joueur 1 */
    	chaine joueur2 ;		//** Nom du joueur 2 */
    	int ligne ,colonne;
		tab grille;				//** La grille de jeu de 7 lignes et 7 colonnes */
	
		initGrille(grille);		//** Appel de la procédure initGrille pour initialisé le tableau. */
		vainqueur = INCONNU;	//** Aucun vainqueur pour le moment. */

    	age(joueur1,joueur2);	//** Appel de la procédure age pour savoir qui sera le joueur 1 et qui sera le joueur 2. */
	
		while ((vainqueur == INCONNU) && (grillePleine(grille) == false)){		//** Tant que il n'y a pas de vainqueur et que la grille n'est pas pleine ... */
			jouer(grille,PION_A,&ligne ,&colonne,joueur1 , joueur2);		//** Appel de la procédure jouer qui permet au joueur 1 de poser son jeton . */
			afficher(grille,PION_B,COLONNE_DEBUT, joueur2);			//** Appel de procédure afficher qui affiche la grille ainsi que le nom du joueur 2. */

			/*!
			*
			* \brief Si 4 pions 'X' sont alignés dans la grille , le vainqueur est le joueur 2
			*
			*/
			if(estVainqueur(grille,ligne,colonne) == true){		
				vainqueur = PION_A;  
			}

			/*!
			*
			* \brief Si il n'y a pas de vainqueur , c'est au tour du joueur 2 de poser son jeton. 
			*
			*/
 			else if(grillePleine(grille)==false){
				jouer(grille,PION_B,&ligne,&colonne,joueur1,joueur2);
				afficher(grille,PION_A,COLONNE_DEBUT,joueur1);
			
			/*!
			*
			* \brief Si 4 pions 'O' sont alignés dans la grille , le vainqueur est le joueur 2
			*
			*/
				if(estVainqueur(grille,ligne,colonne) == true){
					vainqueur = PION_B;
				}
			}
		}
			/*!
			*
			* \brief On annonce la fin de la partie et on propose de relancer une partie .
			*
			*/
		finDePartie(vainqueur,joueur1 , joueur2,recommencer);
	}
	return EXIT_SUCCESS;
}

/*****************************************************
 				 * FONCTION AGE *
*****************************************************/

	void age(chaine nomjoueur1 , chaine nomjoueur2 ){

    chaine nom1; 		//** Chaine qui stock le premier nom */
    chaine nom2;		//** Chaine qui stock le deuxième nom */
    int age1 , age2;	//** Stock l'âge du premier nom */
    char reponse[4];	//** Stock l'âge du deuxième nom */

	/*!
	*
	* \brief On récupérer le nom des joueurs ainsi que leurs âges
	* 			
	*/
    printf("\nBienvenue au jeu du Puissance 4 !\n");
    printf("\nNous allons choisir qui sera le joueur 1 et le joueur 2\nLe joueur 1 aura le jeton 'X' et le joueur 2 aura le jeton 'O' \n");
    
    printf("\nEntrez un premier nom : ");
    scanf("%s" , nom1);
    printf("Entrez un deuxieme nom : ");
    scanf("%s" , nom2);

    printf("\nEnchanté %s et %s !\nPour savoir qui commence je vais vous demandez vos âges , le plus jeune commencera ...\n", nom1 , nom2);
    printf("\n%s , quel âge avez vous : ",nom1);
    scanf("%d",&age1);
    printf("%s , quel âge avez vous : ",nom2);
    scanf("%d",&age2);

	/*!
	*
	* \brief On compare les âges , le plus jeune commence (sauf si ils ont le même âge )
	*
	*/
    if(age1 < age2){
        printf("\n%s est le plus jeune et sera donc le joueur 1, %s vous serez donc le joueur 2\n",nom1 , nom2);
        strcpy(nomjoueur1,nom1);
        strcpy(nomjoueur2,nom2);
    }
    else if(age1 > age2){
        printf("\n%s est le plus jeune et sera donc le joueur 1 , %s vous serez donc le joueur 2 \n",nom2 , nom1);
        strcpy(nomjoueur1,nom2);
        strcpy(nomjoueur2,nom1);
    }
    else if(age1 == age2){
        printf("\nVous avez le même age ... Le joueur 1 sera par default %s et le joueur 2 %s\n" , nom1 , nom2);
        strcpy(nomjoueur1,nom1);
        strcpy(nomjoueur2,nom2);
    }

	/*!
	*
	* \brief On demande aux joueurs si ils sont prêt , si oui on lance la partie .
	*
	*/
    while(strcmp(reponse , OUI) != 0){
        printf("\nEtes vous prêt(e)s ? Si oui , entrez 'oui : ");
        scanf("%s" , reponse); 
        if(strcmp(reponse , OUI) != 0){
            printf("Erreur , Veuillez entrez une saisie valide !\n");
        }
    }
    printf("Bonne partie !");
}

/*****************************************************
 				* PROCEDURE INITGRILLE *
*****************************************************/
void initGrille(tab grille){

    int i;
	int j;
	
	/*!
	*
	* \brief Initialisation en parcourant et en affectant la constante VIDE à chaque case du tableau. 
	*
	*/
    for (i = 0; i < NBLIG; i++)
	{
		for ( j = 0; j < NBCOL; j++)
		{
			grille[i][j] = VIDE;
		}
	}
}

/*****************************************************
 				* PROCEDURE AFFICHER *
*****************************************************/
void afficher(tab grille,char pion,int colonne , chaine nomjoueur){
	
	int i = 0;
	int j;
	/*!
	*
	* \brief En tete de la grille
	*
	*/
	printf("\n-+-+-+-+-+-+-+-+-+-+-\n");
	printf("     PUISSANCE 4\n");
	printf("-+-+-+-+-+-+-+-+-+-+-\n");
	printf("Au tour de: %s\n", nomjoueur);

	/*!
	*
	* \brief On efface le précédent pion pour le prochain en parcourant et en affecant la premiere ligne à VIDE
	*
	*/
	for(j=0; j<NBCOL ; j++){
		grille[i][j] = VIDE;
	}

	grille[0][colonne] = pion ; 		//** Le pion du joueur est d'abord affiché au milieu de la premiere ligne */

	/*!
	*
	* \brief On affiche le corps de la grille 
	*
	*/
	for (i = 0; i < NBLIG; i++)
	{
		
		printf("*---*---*---*---*---*---*---*\n");
		printf("|");
		
		for (j = 0; j < NBCOL; j++)
		{
			printf(" %c |", grille[i][j]);
		}
		printf("\n");
		}
	printf("*---*---*---*---*---*---*---*\n");
	printf("  1   2   3   4   5   6   7 \n");
}

/*****************************************************
 			 * FONCTION GRILLEPLEINE *
*****************************************************/

bool grillePleine(tab grille){

	int i , j;
	int compteur = 0;		 // Compte le nombre de jetons dans la grille */
	bool test = false;		//** Pour le moment la grille n'est pas pleine */

	/*!
	*
	* \brief On parcourt la grille et si une case contient un jeton 'X' ou 'O' , on ajoute 1 au compteur
	*
	*/
	for (i = NBLIG ; i > 0; i--){
		for( j =0 ; j < NBCOL; j++){
			if (grille[i][j] == PION_A || grille[i][j] == PION_B){
				compteur++;
			} 
		}
	}
	if(compteur == PLEIN){			//** Si le compteur est égale à 42 , la grille est donc pleine. */
		test = true;
	}
	
	return test;			// On retourne vrai si la grille est pleine , sinon false. */
}

/*****************************************************
 			* FONCTION TROUVERLIGNE *
*****************************************************/

int trouverLigne(tab grille , int colonne){
	
    int i = 1;
	if(grille[i][colonne]!=VIDE){			//** Si la premiere case de la colonne contient un jeton , la colonne est pleine */
		i = -1;
	}
	
	/*!
	*
	* \brief Tant que la case de la colonne est vide , on continue de descendre dans la colonne 
	*
	*/
    while((i<NBLIG-1)&&(grille[i+1][colonne]==VIDE)){			
        i=i+1;
    }
    return i;		//** On retourne l'indice de la colonne disponible , et -1 si la colonne est pleine */
}

/*****************************************************
 			 * FONCTION CHOISIRCOLONNE *
*****************************************************/

int choisirColonne(tab grille , char pion,int colonne, chaine nomjoueur1 , chaine nomjoueur2){
    
	char direction;
    int pos = colonne;			//** On récupére l'indice de la colonne où est le jeton */
	int i = 0;

    printf("Deplacez vous avec q ou d :");			//** On demande au joueur où souhaite t-il se déplacer (Gauche ou Droite) */
    scanf("%c" , &direction);
    
	/*!
	*
	* \brief Tant que le joueur n'entre pas la touche ENTREE , on déplace le jeton à gauche ou à droite 
	*
	*/
    while(direction!=VIDE){		

        if(direction == GAUCHE){
			if(pos == 0){				//** Si le jeton dépasse la premiere colonne , le jeton apparait de l'autre coté dans la case d'indice 7 */
				pos = 7;
			}
            grille[i][pos-1] = pion;		  //** On déplace le jeton d'une case à gauche */ 
            grille[i][pos] = VIDE;			 //** On efface le précédent jeton */
            pos = pos-1;					//** On récupére le nouvel indice de la colonne du jeton déplacé */
        }
        if(direction == DROITE){
			if(pos == 6){			 //** Si le jeton dépasse la dernière colonne , le jeton apparait de l'autre coté dans la premiere colonne */
				pos = -1;			 
			}
            grille[i][pos+1] = pion;		  //** On déplace le jeton d'une case à droite */
            grille[i][pos] = VIDE;			 //** On efface le précédent jeton */
            pos = pos+1;					//** On récupére le nouvel indice de la colonne du jeton déplacé */
        }

		/*!
		*
		* \brief On affiche la grille en fonction du jeton , 'X' pour le joueur 1 ou 'O' pour le joueur 2
		*
		*/
        if(pion == PION_A){
            afficher(grille,pion,pos,nomjoueur1);
        }
        else if(pion == PION_B){
            afficher(grille , pion ,pos ,nomjoueur2);
        }
        printf("Deplacez vous avec q ou d : ");
        scanf("%c" , &direction);
        
    }
    return pos;			//** On retourne l'indice de la colonne où est posé le jeton */
}

/*****************************************************
 				* PROCEDURE JOUER *
*****************************************************/

void jouer(tab grille,char pion , int *ligne , int *colonne,chaine nomjoueur1 , chaine nomjoueur2){

		/*!
		*
		* \brief On demande au joueur de choisir une colonne tant que celle-ci est pleine
		*
		*/
	do{
		*colonne = choisirColonne(grille , pion ,COLONNE_DEBUT,nomjoueur1,nomjoueur2);
		*ligne = trouverLigne(grille , *colonne);
		if(*ligne == -1){
			printf("\nColonne pleine recommence\n");
		}
	}while((*ligne==-1));
	
	
	grille[*ligne][*colonne] = pion;		//** On pose le jeton dans la grille dans la colonne choisie et la ligne la plus basse possible */

}

/*****************************************************
 				* FONCTION ESTVAINQUEUR *
*****************************************************/

bool estVainqueur(tab grille , int ligne , int colonne){


	int i = ligne ; 									//** On récupére l'indice de la ligne du dernier jeton poser */
	int j = colonne;								   //** On récupére l'indice de la colonne du dernier jeton poser */
	int compteur = 0;								  //** Permet de compter le nombre de mêmes jetons 'X' ou 'O' alignés */
	bool res = false;			   					 //** Il n'y a pas 4 mêmes jetons alignés pour le moment */
	char pion = grille[ligne][colonne]; 			//** On récupére le dernier jeton poser pour savoir lequel chercher */

	/*!
	*
	* \brief On cherche en partant du dernier jeton poser jusqu'en bas , si on trouve le même jeton : compteur + 1 et on continue de chercher, sinon on s'arrete
	*
	*/
	while(grille[i][colonne] == pion){
		compteur++;
		i++;
	}

	i = ligne;			 //** On réinitialise i à l'indice de la ligne du dernier jeton poser */
	j = colonne;		//** On réinitialise j à l'indice de la colonne du dernier jeton poser */

	/*!
	*
	* \brief On cherche en partant du dernier jeton poser jusqu'en haut , si on trouve le même jeton : compteur + 1 et on continue de chercher, sinon on s'arrete
	*
	*/
	while(grille[i][colonne] == pion){
		compteur++;
		i--;
	}

	/*!
	*
	* \brief Si le compteur est supérieur à la constante VICTOIRE , il y'a donc 4 même jetons alignés en colonne
	*
	*/
	if(compteur > VICTOIRE ){
		res = true;
	}
	
	compteur = 0;					  //** On réinitialise le tableau à 0 pour chercher au niveau des lignes */		
	i = ligne;						 //** On réinitialise i à l'indice de la ligne du dernier jeton poser */
	j = colonne;					//** On réinitialise j à l'indice de la colonne du dernier jeton poser */

	/*!
	*
	* \brief On cherche en partant du dernier jeton poser et on part à droite , si on trouve le même jeton : compteur + 1 et on continue de chercher ,sinon on s'arrete
	*
	*/
	while(grille[ligne][j] == pion){
		compteur++;
		j++;
	}

	i = ligne;						 //** On réinitialise i à l'indice de la ligne du dernier jeton poser */
	j = colonne;					//** On réinitialise j à l'indice de la colonne du dernier jeton poser */

	/*!
	*
	* \brief On cherche en partant du dernier jeton poser et on part à gauche , si on trouve le même jeton : compteur + 1 et on continue de chercher , sinon on s'arrete
	*
	*/
	while(grille[ligne][j] == pion){
		compteur++;
		j--;
	}

	/*!
	*
	* \brief Si le compteur est supérieur à la constante VICTOIRE , il y'a donc 4 même jetons alignés en ligne
	*
	*/
	if(compteur > VICTOIRE ){
		res = true;
	}
	

	compteur = 0;					  //** On réinitialise le tableau à 0 pour chercher au niveau des diagonales */
	i = ligne;						 //** On réinitialise i à l'indice de la ligne du dernier jeton poser */
	j = colonne;					//** On réinitialise j à l'indice de la colonne du dernier jeton poser */

	/*!
	*
	* \brief On cherche en partant du dernier jeton poser et on part en diagonale - bas - droite , si on trouve le même jeton : compteur + 1 et on continue de chercher , sinon on s'arrete
	*
	*/
	while(grille[i][j] == pion){
		compteur++;
		j++;
		i++;
	}

	i = ligne;							 //** On réinitialise i à l'indice de la ligne du dernier jeton poser */
	j = colonne;						//** On réinitialise j à l'indice de la colonne du dernier jeton poser */

	/*!
	*
	* \brief On cherche en partant du dernier jeton poser et on part en diagonale - haut - gauche , si on trouve le même jeton : compteur + 1 et on continue de chercher , sinon on s'arrete
	*
	*/
	while(grille[i][j] == pion){
		compteur++;
		j--;
		i--;
	}

	/*!
	*
	* \brief Si le compteur est supérieur à la constante VICTOIRE , il y'a donc 4 même jetons alignés en diagonale
	*
	*/
	if(compteur > VICTOIRE ){
		res = true;
	}
	

	compteur = 0;							  //** On réinitialise le tableau à 0 pour chercher au niveau des diagonales */
	i = ligne;								 //** On réinitialise i à l'indice de la ligne du dernier jeton poser */
	j = colonne;							//** On réinitialise j à l'indice de la colonne du dernier jeton poser */
	
	/*!
	*
	* \brief On cherche en partant du dernier jeton poser et on part en diagonale - haut - droite , si on trouve le même jeton : compteur + 1 et on continue de chercher , sinon on s'arrete
	*
	*/
	while(grille[i][j] == pion){
		compteur++;
		j++;
		i--;
	}

	i = ligne;						 //** On réinitialise i à l'indice de la ligne du dernier jeton poser */
	j = colonne;					//** On réinitialise j à l'indice de la colonne du dernier jeton poser */
	
	/*!
	*
	* \brief On cherche en partant du dernier jeton poser et on part en diagonale - bas - gauche , si on trouve le même jeton : compteur + 1 et on continue de chercher , sinon on s'arrete
	*
	*/
	while(grille[i][j] == pion){
		compteur++;
		j--;
		i++;
	}

	/*!
	*
	* \brief Si le compteur est supérieur à la constante VICTOIRE , il y'a donc 4 même jetons alignés en diagonale 
	*
	*/
	if(compteur > VICTOIRE ){
		res = true;
	}

	return res;				//** On retroune true si il y a 4 mêmes jetons alignés , sinon false */
}

/*****************************************************
 				* PROCEDURE FINDEPARTIE *
*****************************************************/

void finDePartie(char pion, chaine nomjoueur1 , chaine nomjoueur2, char recommencer[4]){

	/*!
	*
	* \brief Si le dernier jeton joué est 'X' ou 'O' , le vainqueur est le joueur qui posséde ce jeton , sinon il y a égalité
	*
	*/
	if(pion == PION_A){
		printf("VICTOIRE ! \nLe vainqueur est %s",nomjoueur1);
	}
	else if(pion == PION_B){
		printf("VICTOIRE ! \nLe vainqueur est %s",nomjoueur2);
	}
	else{
		printf("Egalité !");
	}

	/*!
	*
	* \brief on propose aux joueurs si ils veulent recommencer une partie , si oui le programme se relance à zéro , sinon fin de partie
	*
	*/
    printf("\nVoulez vous recommencer ? oui - non : ");
	scanf("%s" , recommencer);

	if(strcmp(recommencer,NON) == 0){
		printf("Au revoir !");
	}
	
	/*!
	*
	* \brief Tant que la saisie de la réponse n'est pas égale à 'oui' ou 'non' , on redemande au joueur d'écrire sa réponse car saisie incorrect
	*
	*/
	while((strcmp(recommencer , OUI)!=0) && (strcmp(recommencer,NON) != 0)){
		
		if((strcmp(recommencer , OUI)!=0) && (strcmp(recommencer,NON) != 0)){
			printf("\nErreur ! Veuillez entrer une saisie valide");
		}
		
		printf("\nVoulez vous recommencer ? oui - non : ");
		scanf("%s" , recommencer);

		if(strcmp(recommencer,NON) == 0){
			printf("Au revoir !");
		}
	}
}


	
	
	