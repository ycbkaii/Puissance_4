/**
 * \brief Programme permettant de jouer au Puissance 4
 * \page Général
 * 
 * \author Chiouar Yanis
 * \version 1.0
 * \date 23 novembre 2022
 * 
 * 
 * Ce programme est composé de plusieurs procédures et fonctions
 * qui permettent de fabriquer le jeu Puissance_4 
 * 
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
#include <string.h> 
#include <stdbool.h> 

/**
 * \def NBLIG
 * \brief Nombre de lignes maximum dans la grille
*/
#define NBLIG 6


/**
 * \def NBCOL
 * \brief Nombre de colonnes maximum dans la grille
*/
#define NBCOL 7


/**
 * \def BLEU
 * \brief Definition de la couleur bleu pour la console Linux
*/
#define BLEU "\033[00;34m" 

/**
 * \def VERT
 * \brief Definition de la couleur verte pour la console Linux
*/
#define VERT "\033[00;32m"

/**
 * \def NOIR
 * \brief Definition de la couleur noire pour la console Linux
*/
#define NOIR "\033[00m"

/**
 * \var ZERO
 * \brief Constante où on assigne la valeur 0
*/
const int ZERO =0;


/**
 * \var PION_A
 * \brief On définit la constante du pion du Joueur 1
*/
const char PION_A = 'X';


/**
 * \var PION_B
 * \brief On définit la constante du pion du Joueur 2
*/
const char PION_B = 'O';



/**
 * \var INCONNU
 * \brief On définit une constante avec une chaine vide lorsqu'on ne connait pas la valeur(INCONNU)
*/
const char INCONNU = ' ';

/**
 * \var VIDE
 * \brief On définit la constante avec une chaine vide lorsque qu'il y a rien(VIDE)
*/
const char VIDE = ' ';


/**
 * \var J1
 * \brief On définit l'intitulé du premier joueur
*/
const char J1[10] = "Joueur 1";

/**
 * \var J2
 * \brief On définit l'intitulé du second joueur
*/
const char J2[10] = "Joueur 2";

/**
 * \var COLONNE_DEBUT
 * \brief On définit le numéro de colonne où sera affiché le prochain pion du joueur
*/
const int COLONNE_DEBUT = NBCOL/2;


/**
     * \var BARRE
     * \brief Barre de la grille qui sera affiché pour faire la disparité entre chaque colonne
    */
    const char BARRE = '|';

    /**
     * \var LIGNE_0
     * \brief Constante qui définit la première ligne de la grille permettant d'afficher la légende du joueur 1
    */
    const int LIGNE_0 = 0;

    /**
     * \var LIGNE_1
     * \brief Constante qui définit la première ligne de la grille permettant d'afficher la légende du joueur 2
    */
    const int LIGNE_1 = 1;

    /**
     * \var UN
     * \brief Constante qui définit un entier 1
    */
    const int UN = 1;

/**
     * \var PAS_POSSIBLE
     * \brief Constante qui définit un entier -1 permettant de voir si la colonne est pleine
    */
    const int PAS_POSSIBLE = -1;



/**
     * \var PUISSANCE_4
     * \brief Constante qui définit un entier permettant de voir si il y a un puissance 4
    */
    const int PUISSANCE_4 = 4;


    /**
     * \var ARRET
     * \brief Constante qui permet de définir le mot quand le joueur voudra arréter la partie
    */
    const char ARRET[4] ="FIN";

    /**
     * \var ENTRER
     * \brief Constante qui permet de définir le mot quand le joueur voudra continuer la partie
    */
    const char ENTRER[7] = "ENTRER";

    /**
     * \var GAUCHE
     * \brief Constante définissant la touche lorsque le joueur veut déplacer le pion vers la gauche 
    */
    const char GAUCHE = 'q';

    /**
     * \var DROITE
     * \brief Constante définissant la touche lorsque le joueur veut déplacer le pion vers la droite 
    */
    const char DROITE = 'd';

    /**
     * \var LANCER_PION
     * \brief Constante définissant la touche lorsque le joueur veut placer le pion
    */
    const char LANCER_PION = ' ';

    /**
     * \var MIN
     * \brief Constante définissant un entier 0 qui montre la première colonne
    */
    const int MIN = 0;

    /**
     * \var MAX
     * \brief Constante définissant un entier NBCOL-1 qui montre la dernière colonne
    */
    const int MAX = NBCOL-1;

    /**
     * \var REFAIRE_JOUER
     * \brief Constante qui définit un entier montrant le fait de rejouer si les saisies ne sont pas bonnes
    */
    const int REFAIRE_JOUER = -1;

/**
 * \typedef Grille
 * \brief Définition d'une grille de jeu de NBLIG lignes et de NBCOL colonnes
*/
typedef char Grille[NBLIG][NBCOL];


void initGrille(Grille g);


void afficher(Grille g, char pion, int colonne);


bool grillePleine(Grille g);


void jouer(Grille g, char pion, int *ligne, int *colonne, char joueur_1[50], char joueur_2[50]);


int choisirColonne(Grille g, char pion, int colonne);


int trouverLigne(Grille g, int colonne);


bool estVainqueur(Grille g, int ligne, int colonne);


void finDePartie(char vainqueur, char joueur_1[50], char joueur_2[50], bool *continuer);


void saisiNom(char joueur_1[50], char joueur_2[50]);


char commenceAJouer(char pionA, char pionB);



void recommencerPartie(bool *continuer); 


/**
 * \fn int main()
 * \brief Programme principal.
 * \return entier : Code de sortie du programme '0' => sortie normale
 * 
 * Programme principal permettant de jouer au puissance 4 en
 * utilisant toutes les fonctions proposées ci-dessus
 *  
*/

int main(){
    char vainqueur,pion_commence;
    char joueur_1[50], joueur_2[50];
    int ligne, colonne;
    bool continuer;

    continuer = true;

    Grille g;

    initGrille(g);

    vainqueur = INCONNU;
    
    afficher(g, INCONNU, COLONNE_DEBUT);
    
    saisiNom(joueur_1, joueur_2);
    
    pion_commence = commenceAJouer(PION_A, PION_B);
    
    afficher(g, pion_commence, COLONNE_DEBUT);

    while ((vainqueur == INCONNU && !grillePleine(g)) || continuer == true)
    {
        if(pion_commence == PION_A){
            jouer(g, PION_A, &ligne, &colonne, joueur_1, joueur_2);
            afficher(g, PION_B, COLONNE_DEBUT);
        }
        else if(pion_commence == PION_B){
            jouer(g, PION_B, &ligne, &colonne, joueur_1, joueur_2);
            afficher(g, PION_A, COLONNE_DEBUT);
        }
        
        if(estVainqueur(g, ligne, colonne) == true){
            vainqueur = pion_commence;
        }
        else if(!grillePleine(g)){

            if(pion_commence == PION_A){
                pion_commence = PION_B;
                jouer(g, PION_B, &ligne, &colonne, joueur_1, joueur_2);
                afficher(g, PION_A, COLONNE_DEBUT);
            }
            else{
                pion_commence = PION_A;
                jouer(g, PION_A, &ligne, &colonne, joueur_1, joueur_2);
                afficher(g, PION_B, COLONNE_DEBUT);
            }
            
            if(estVainqueur(g, ligne, colonne) == true){
                vainqueur = pion_commence;
            }
        }

        if(pion_commence == PION_A)
        {
            pion_commence = PION_B;
        }else{ 
            pion_commence = PION_A;
        }
        
        if(grillePleine(g) || vainqueur != INCONNU){
            finDePartie(vainqueur, joueur_1, joueur_2, &continuer);
            
            //Si le joueur veut continuer
            if(continuer == true)
            {
                initGrille(g);
                afficher(g, pion_commence, COLONNE_DEBUT);
                vainqueur = INCONNU;
            }
            
        }

        
    }
    
    return EXIT_SUCCESS;
}



/**
 * \fn void initGrille(Grille g)
 * \brief Procédure permettant d'initialiser la grille 
 * \param g : paramètre d'entrée/sortie qui représente le tableau (la grille) qui doit être initialisé
*/
void initGrille(Grille g){
    int i,j;
    for(i=ZERO; i< NBLIG; i++){
        for(j=ZERO; j< NBCOL; j++){
            g[i][j] = VIDE;
        }
    }
}


/**
 * \fn void afficher(Grille g, char pion, int colonne) 
 * \brief Procédure permettant d'afficher la grille de jeu
 * \param g : paramètre d'entrée qui représente la grille de jeu à parcourir (un tableau)
 * \param pion : paramètre d'entrée qui représente le caractère à mettre au dessus de la grille pour montrer qui jouera au prochain round
 * \param colonne : paramètre d'entrée qui représente un entier qui place au milieu et au dessus de la grille le prochain pion qui va jouer
 * 
*/
void afficher(Grille g, char pion, int colonne){
    

    int i, j, numero, placementPionAuDessus;
    char couleurPionAuDessus[15], couleurPion[15];
    
    //On assigne la couleur au pion qui est au dessus de la grille
    if(PION_A == pion)
    {
        strcpy(couleurPionAuDessus,BLEU);
    }else if(PION_B == pion){
        strcpy(couleurPionAuDessus,BLEU);
    }else{
        strcpy(couleurPionAuDessus, NOIR);
    }
    
    for(placementPionAuDessus =ZERO; placementPionAuDessus <= colonne; placementPionAuDessus++){
        if(placementPionAuDessus == colonne){
            printf(" ");
            printf(" ");
            printf("%s%c" NOIR,couleurPionAuDessus,pion);
            printf(" ");
        }else{
            printf(" ");
            printf(" ");
            printf(" ");
            printf(" ");
        }
    }
    printf("\n");
    for(i =ZERO; i < NBLIG; i++){
        for(j =ZERO; j < NBCOL; j++){
            
            //On assigne la couleur au pion qui est au dessus de la grille
            if(PION_A == g[i][j])
            {
                strcpy(couleurPion,BLEU);
            }else if(PION_B == g[i][j]){
                strcpy(couleurPion,VERT);
            }else{
                strcpy(couleurPion, NOIR);
            }
            
            printf("%c",BARRE);
            printf(" ");
            printf("%s%c" NOIR,couleurPion,g[i][j]);
            printf(" ");
        }
        
        printf("%c",BARRE);
        
        //Permet d'afficher au début de la partie qui joue quel pion
        if(pion == INCONNU && i == LIGNE_0){
            printf(BLEU "nom(Joueur 1) " NOIR);
            printf("utilise le caractere ");
            printf(BLEU "%c" NOIR,PION_A);
        }else if(pion == INCONNU && i == LIGNE_1){
            printf(VERT "nom(Joueur 2) " NOIR);
            printf("utilise le caractere ");
            printf(VERT "%c" NOIR,PION_B);
        }
        printf("\n");
    }

    //Permet d'afficher les numéros de colonnes
    for(numero = UN; numero <= NBCOL; numero++){
        printf(" ");
        printf(" ");
        printf("%d",numero);
        printf(" ");
    }
    printf("\n");
    
}


/**
 * \fn bool grillePleine(Grille g)
 * \brief Fonction permettant de vérifier si la grille est pleine ou non
 * \param g : paramètre d'entrée qui représente la grille de jeu à parcourir (tableau)
 * \return boolean : true si la grille est pleine, false sinon
*/
bool grillePleine(Grille g){
    int j,i;
    bool plein;
    plein = true;
    for(i=ZERO; i<NBLIG && plein == true; i++){
        for(j=ZERO; j<NBCOL && plein == true; j++){
            if(g[i][j]== VIDE){
                plein = false;
            }
        }

    }
    return plein;
}


/**
 * \fn void finDePartie(char pion, char joueur_1[50], char joueur_2[50], bool *continuer)
 * \brief Procédure déclarant la fin de la partie de puissance 4
 * \param pion : paramètre d'entrée qui représente le pion gagnant
 * \param joueur_1 : paramètre d'entrée qui représente une chaine qui est le nom du joueur n°1
 * \param joueur_2 : paramètre d'entrée qui représente une chaine qui est le nom du joueur n°2
 * \param continuer : paramètre de sortie qui représente un booléen permettant de savoir si le joueur veut continuer la partie
*/
void finDePartie(char pion, char joueur_1[50], char joueur_2[50], bool *continuer){
    if(pion == PION_A){
        printf("Bravo ");
        printf(BLEU "%s(%s) " NOIR,joueur_1,J1); //Mettre en couleur
        printf("vous avez gagne la partie de Puissance 4 !\n");

        printf("Dommage ");
        printf(VERT "%s(%s) " NOIR,joueur_2,J2); //Mettre en couleur
        printf("vous avez perdu la partie de Puissance 4 !\n");

    }else if(pion == PION_B){
        printf("Bravo ");
        printf(VERT "%s(%s) " NOIR,joueur_2,J2); //Mettre en couleur
        printf("vous avez gagne la partie de Puissance 4 !\n");

        printf("Dommage ");
        printf(BLEU "%s(%s) " NOIR,joueur_1,J1); //Mettre en couleur
        printf("vous avez perdu la partie de Puissance 4 !\n");

    }else{
        printf("Dommage ");
        printf(VERT "%s(%s) " NOIR,joueur_2,J2); //Mettre couleur
        printf("et ");
        printf(BLEU "%s(%s)" NOIR,joueur_1,J1); //Mettre couleur
        printf(", il y a égalite !\n");

    }
    recommencerPartie(&(*continuer));
}



/**
 * \fn int trouverLigne(Grille g, int col)
 * \brief Fonction qui permet de vérifier si la colonne n'est pas pleine
 * \param g : paramètre d'entrée qui représente la grille de jeu à parcourir(tableau)
 * \return entier : si elle n'est pas pleine la fonction renvoie la colonne, -1 sinon
*/
int trouverLigne(Grille g, int col){

    int i, possible;
    possible = PAS_POSSIBLE;
    for(i=NBLIG; i>=ZERO; i--){
        if(g[i][col] == VIDE){
            possible = col;
        }
    }
    return possible;
}


/**
 * \fn bool estVainqueur(Grille g, int ligne, int colonne)
 * \brief Fonction qui permet de voir si il y a un puissance 4 sur le dernier pion placé
 * \param g : paramètre d'entrée qui représente la grille de jeu (tableau) à parcourir
 * \param ligne : paramètre d'entrée qui représente un entier qui est la ligne où le joueur a joué dernièrement
 * \param colonne : paramètre d'entrée qui représente un entier qui est la colonne où le joueur a joué dernièrement
 * \return boolean : true si la fonction trouve un puissance 4 dans la grille, false sinon
*/
bool estVainqueur(Grille g, int ligne, int colonne){

    bool gagner;
    int i, j, compte, erreurDiago_1, erreurDiago_2, diagoPossible;
    char pion;
    pion = g[ligne][colonne];
    compte = 0;
    gagner = false;

    //On vérifie si il y a un puissance 4 dans la colonne récemment joué
    for (i = ZERO; i < NBLIG; i++)
    {
        if(g[i][colonne] == pion  && compte < PUISSANCE_4){
            compte++;
            if(compte == PUISSANCE_4){
                gagner = true;
            }
        }else if(compte == PUISSANCE_4){
            gagner = true;
        }
        else{
            compte = 0;
        }
        
    }
    
    if(gagner == false){

        //On vérifie si il y a un puissance 4 dans la ligne récemment joué
        for (j = ZERO; j < NBCOL; j++)
        {
            if (g[ligne][j] == pion && compte < PUISSANCE_4)
            {
                compte++;
                if(compte == PUISSANCE_4){
                    gagner = true;
            }
            }else if(compte == PUISSANCE_4){
                gagner = true;
            }
            else{
                compte = ZERO;
            }
            
        
        }
    }
    //On vérifie si il y a un puissance 4 sur la diagionale d'en bas à gauche à en haut à droite
    if(gagner == false){
        compte = 1;
        erreurDiago_1 = ZERO;
        erreurDiago_2 = ZERO;
        diagoPossible = 4;
        for (i = 1; i <= diagoPossible; i++)
        {
            if((ligne + i < NBLIG && colonne - i >= ZERO) && erreurDiago_1 != 1 && compte != PUISSANCE_4){
                if(g[ligne+i][colonne-i] == pion)
                {
                    compte++;
                }else{
                    erreurDiago_1++;
                }
                
            }
            if((ligne - i >= ZERO && colonne + i < NBCOL)&& erreurDiago_2 != 1 && compte != PUISSANCE_4)
            {
                if(g[ligne-i][colonne+i] == pion)
                {
                    compte++;
                }else{
                    erreurDiago_2++;
                }
            }
            
        }  
        if (erreurDiago_1 + erreurDiago_2 == 2)
        {
            compte = ZERO;
        }else if(compte == PUISSANCE_4){
            gagner = true;
        }   

    }

    //On vérifie si il y a un puissance 4 sur la diagionale d'en bas à droite à en haut à gauche
    if(gagner == false){
        compte = 1;
        erreurDiago_1 = ZERO;
        erreurDiago_2 = ZERO;
        diagoPossible = 4;
        for (i = 1; i <= diagoPossible; i++)
        {
            if((ligne + i < NBLIG && colonne + i < NBCOL) && erreurDiago_1 != 1 && compte != PUISSANCE_4){
                if(g[ligne+i][colonne+i] == pion)
                {
                    compte++;
                }else{
                    erreurDiago_1++;
                }
                
            }
            if((ligne - i >= ZERO && colonne - i >= ZERO)&& erreurDiago_2 != 1 && compte != PUISSANCE_4)
            {
                if(g[ligne-i][colonne-i] == pion)
                {
                    compte++;
                }else{
                    erreurDiago_2++;
                }
            }
            
            
        }  
        if (erreurDiago_1 + erreurDiago_2 == 2)
        {
            compte = ZERO;
        }else if(compte == PUISSANCE_4){
            gagner = true;
        }   

    }
    
    
    return gagner;
    
}

/**
 * \fn void saisiNom(char joueur_1[50], char joueur_2[50])
 * \brief Procédure permettant aux joueurs de saisir leurs noms
 * \param joueur_1 : paramètre d'entrée qui représente une chaine qui est le nom du joueur n°1
 * \param joueur_2 : paramètre d'entrée qui représente une chaine qui est le nom du joueur n°2
*/
void saisiNom(char joueur_1[50], char joueur_2[50]){
    printf("Saisissez le nom de "); 
    printf(BLEU "%s\n" NOIR,J1);
    scanf("%s",joueur_1);
    printf("Saisissez le nom de ");
    printf(VERT "%s\n" NOIR,J2); 
    scanf("%s",joueur_2);
}

/**
 * \fn char commenceAJouer(char pionA, char pionB)
 * \brief Fonction qui permet de savoir lequel des deux joueurs commencera la partie
 * \param pionA : paramètre d'entrée qui représente un caractère qui est le pion du joueur 1
 * \param pionB : paramètre d'entrée qui représente un caractère qui est le pion du joueur 2
 * \return un caractère : qui représente le pion du joueur qui va commencer
*/
char commenceAJouer(char pionA, char pionB){
    char premierJoueur, absorption;
    do
    {
        printf("Quel joueur veut commencer ? ('%c' ou '%c')\n",PION_A,PION_B);
        scanf("%c%c",&absorption,&premierJoueur);
    } while((premierJoueur!= pionA && premierJoueur!= pionB));
    return premierJoueur;
    
}


/**
 * \fn void recommencerPartie(bool *continuer)
 * \brief Procédure permettant de recommencer la partie
 * \param continuer : paramètre de sortie qui représente un booléen pour savoir si le joueur veut continuer ou si il veut arrêter la partie 
 * 
*/
void recommencerPartie(bool *continuer){

    char choix[10];
    bool ok;
    do
    {
        printf("Taper '%s' pour recommencer la partie ou taper sur '%s' pour arreter\n",ENTRER, ARRET);
        scanf("%s",choix);
    } while(strcmp(choix, ARRET)!=ZERO && strcmp(choix, ENTRER)!=ZERO);
    if(strcmp(choix, ENTRER) == ZERO){
        ok = true;
    }
    else{
        ok = false;
    }
    *continuer = ok;
}

/**
 * \fn int choisirColonne(Grille g, char pion, int colonne)
 * \brief Fonction permettant au joueur de choisir où est ce qu'il va placer son pion
 * \param g : paramètre d'entrée qui représente la grille de jeu (tableau) à parcourir
 * \param pion : paramètre d'entrée qui représente un caractère qui est le pion du joueur qui doit jouer
 * \param colonne : paramètre d'entrée qui représente un entier qui est la position du pion qui se situe au dessus de la grille pour séléctionner une colonne
 * \return un entier : le choix de la colonne où le joueur veut jouer
*/
int choisirColonne(Grille g, char pion, int colonne){
    
    int colChoix;
    char decisionJoueur;

    colChoix = colonne;
    printf("-Appuyer sur '%c' pour deplacer le pion vers la gauche\n",GAUCHE);
    printf("-Appuyer sur '%c' pour deplacer vers la droite\n",DROITE);
    printf("-Appuyer sur 'ESPACE' pour lancer le pion\n");
    
    decisionJoueur = getch();
    while(decisionJoueur != LANCER_PION)
    {
        if(decisionJoueur == GAUCHE)
        {
            if (colChoix > MIN )
            {
                colChoix --;
                afficher(g, pion, colChoix);
            }else{
                afficher(g, pion, colChoix);
            }
            
        }else if(decisionJoueur == DROITE){
            if (colChoix < MAX)
            {
                colChoix++;
                afficher(g, pion, colChoix);
            }else{
                afficher(g, pion, colChoix);
            }
            
        }

        printf("-Appuyer sur '%c' pour deplacer le pion vers la gauche\n",GAUCHE);
        printf("-Appuyer sur '%c' pour deplacer vers la droite\n",DROITE);
        printf("-Appuyer sur 'ESPACE' pour lancer le pion\n");
        
        
        decisionJoueur = getch();
    }
    return colChoix;
     
}


/**
 * \fn void jouer(Grille g, char pion, int *ligne, int *colonne, char joueur_1[50], char joueur_2[50])
 * \brief Procédure permettant aux joueurs de jouer la partie
 * \param g : paramètre d'entrée/sortie qui représente la grille de jeu (tableau) où on va ajouter un pion à l'intérieur
 * \param pion : paramètre d'entrée qui représente un caractère qui est le pion du joueur
 * \param ligne : paramètre de sortie qui représente un entier permettant d'assigner la ligne où le joueur a placé son pion
 * \param colonne : paramètre de sortie qui représente un entier permettant d'assigner la colonne où le joueur a placé son pion
 * \param joueur_1 : paramètre d'entrée qui représente une chaine qui est le nom du joueur n°1
 * \param joueur_2 : paramètre d'entrée qui représente une chaine qui est le nom du joueur n°2
 * 
*/
void jouer(Grille g, char pion, int *ligne, int *colonne, char joueur_1[50], char joueur_2[50]){
    
    int i;
    bool pionMis;
    char joueurSelectionne[50], numeroJoueur[10], couleurSelect[15];
    pionMis = false;

    //On assigne les couleurs aux pions
    if(pion == PION_A){
        strcpy(joueurSelectionne, joueur_1);
        strcpy(numeroJoueur,J1);
        strcpy(couleurSelect, BLEU);
    }else if(pion == PION_B){
        strcpy(joueurSelectionne,joueur_2);
        strcpy(numeroJoueur,J2);
        strcpy(couleurSelect, VERT);
        
    }

    printf("%s %s(%s)" NOIR, couleurSelect,joueurSelectionne, numeroJoueur);
    printf(" c'est votre tour, choisissez une colonne : \n"); 
    *colonne = choisirColonne(g, pion,COLONNE_DEBUT);  
    while (trouverLigne(g, *colonne) == REFAIRE_JOUER)
    {
        afficher(g, pion, COLONNE_DEBUT);
        printf("%s %s(%s)" NOIR, couleurSelect,joueurSelectionne, numeroJoueur);
        printf(" la colonne choisie est pleine, veuillez recommencer !\n"); 
        *colonne = choisirColonne(g, pion, COLONNE_DEBUT);
    }
    printf("%s %s(%s)" NOIR, couleurSelect,joueurSelectionne, numeroJoueur);
    printf(" a choisi la colonne %d\n",*colonne+1); 

    //On ajoute le pion à la grille
    i = NBLIG;
    while(i >= ZERO && pionMis == false)
    {
        if(g[i][*colonne] == VIDE)
        {
            g[i][*colonne] = pion;
            *ligne = i;
            pionMis = true;
        }
        i--;
        
    }
    
}



