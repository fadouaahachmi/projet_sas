#include <stdio.h>
#include <string.h>
#include <time.h>
  typedef struct {
        char titre[50],description[50],statut[50],tach[50];
        char deadline[50];


  }tach;
   tach taches[50];
void menu(int index,char oui_non[4],int tri,int i,char temp){
    int choix;


  do{
    printf("________________________________| MENU |______________________________\n\n");
    printf(" [1] Ajouter une nouvelle tache.\n [2] Ajouter plusieurs nouvelles taches.\n [3] Afficher la liste de toutes les taches. \n [4] Modifier une tache. \n [5] Supprimer une tache par identifiant.\n [6] Rechercher les Taches.\n [7] Statistiques. \n\n");
    printf("_______________________________________________________________________\n\n");
    printf("  Tapez votre choix : ");
    scanf("%d",&choix);
   switch(choix){
       system("cls");
     case 1:
      ajoute(index);
      break;
     case 2 :
      ajoute(index);
      for(int i=0;i<=50;i++){
       printf("Voulez-vous ajouter une autre tache?\n _oui/non: \n");
       scanf("%s",oui_non);
       if(strcmp(oui_non,"oui")==0)
       ajoute(index);
       else{
        break;
        }
        }
       break;
     case 3 :
            affiche(tri,index,i,temp);
        break;
     case 4 :{
         int choix_modification;
            printf("que vous voulez modifier ?\n ");
            printf("[1] description.\n [2] statut.\n [3] deadline.");
            scanf("%d",&choix_modification);
            switch(choix_modification){
                 case 1:
                    modifierDescription(index);
                    break;
                 case 2 :
                    modifierStatut(index);
                    break;
                 case 3:
                    modifierDeadline(index);
                    break;
               }
            }
        break;
     case 5 :
        break;
     case 6 :{
        int i=0;
         int choix_recherche,ID_recherche;
         char titre_recherche;
         printf("voulez vous rechercher une tache par :\n [1] Identifiant.\n [2] Titre.\n\nTaper :");
         scanf("%d",&choix_recherche);
          switch(choix_recherche){
             case 1:
            printf("entrez l'ID de la tache souhaitee :");
            scanf("%d",&ID_recherche);
            while(i<50){
            if(strcmp(ID_recherche,index==0)){
              printf("le Titre : %s\n",taches[i].titre);
                        printf("la description : %s \n",taches[i].description);
                        printf(" deadline : %s \n",taches[i].deadline);
                        printf("le statut de la tache :%s\n\n",taches[i].statut);
                    }
            }
            i++;
            if(strcmp(ID_recherche,index!=0))
                printf("aucun donnee\n");
          break;
             case 2 :
                printf("entrez le Titre de la tache souhaitee :");
                scanf(" %[^\n]s",titre_recherche);
                while(i<50){
                    if(strcmp(titre_recherche,taches[i].titre)== 0){
                        printf("le Titre : %s\n",taches[i].titre);
                        printf("la description : %s \n",taches[i].description);
                        printf(" deadline : %s \n",taches[i].deadline);
                        printf("le statut de la tache :%s\n\n",taches[i].statut);
                    }
                }
                i++;
                if(strcmp(titre_recherche,taches[i].titre)!=0)
                    printf("aucun donnee\n");
                break;
             default :
                printf("svp entrer 1 ou 2");
          }
     }
        break;
     case 7 :
        break;

    }


  }while (1);
}


int main(){
int index=0,i;
char oui_non[4];
int tri;
char temp;
   menu(index,oui_non,tri,i,temp);

   return 0;
  }


  void affiche(int i,int index,int tri,char temp){

      printf("titre :%s\n,description:%s\n,statut:%s\n,deadline:%s\n",taches[0].titre,taches[0].description,taches[0].statut,taches[0].deadline);

        printf("voulez-vous trier les taches par ordre : \n [1] alphabetique.\n [2] deadline. \n");
        scanf("%d",&tri);
        switch(tri){
            case 1:{

                char temp[50];
                for(int i=0;i<=index-1;i++){
                for(int j=0;j<=index-1-i;j++){
                if(strcmp(taches[j].titre,taches[j+1].titre)>0){
                  strcpy(temp,taches[j].titre);
                  strcpy(taches[j].titre,taches[j+1].titre);
                  strcpy(taches[j+1].titre,temp);
                }
                }
                }
           for(int i=0;i<index;i++){
                  printf("le titre de la tache c'est :%s \n",taches[i].titre);
                  printf("la description : %s \n",taches[i].description);
                  printf(" deadline : %s \n",taches[i].deadline);
                  printf("le statut de la tache :%s\n\n",taches[i].statut);
              }
            }
            break;
            default:
            printf("SVP enterez 1,2ou 3.\n");
    }

 }



    void ajoute(int index){
         char choix_statut;
      printf("ecrit le titre de la tache :");
      scanf(" %[^\n]s",taches[index].titre);
      printf("la description de la tache :");
      scanf(" %[^\n]s",taches[index].description);
      printf("deadline de la tache (jour-mois-annee) :");
      scanf(" %[^\n]s",&taches[index].deadline);
       printf("le statut de la tache:\n");
      printf("CHOISEZ :\n");
      printf("[1] realiser.\n[2] encours...\n[3] finalisee.\n");
      scanf("%d",&choix_statut);
      switch(choix_statut){
        case 1:
           strcpy( taches[index].statut,"realiser");
            break;
        case 2:
            strcpy(taches[index].statut ,"encours");
            break;
        case 3:
          strcpy(taches[index].statut ,"finalisee");
            break;
        default :
          printf("choisir 1,2 ou 3");
          break;
      }
      index++;

      }


      void modifierDescription(){
      int index;
         printf("entrez l'ID de la tache que vous voulez modifier sa description :");
         scanf("%d",&index);
            if(taches[index].description,index == index){
                printf("entrez la nouvelle description :");
                scanf(" %[^\n]s",taches[index].description);
            }
            else
                printf("l'id est introuvable.");
         }



      void modifierStatut(){
          int index;
          int choix_statut;
               printf("entrez l'ID de la tache que vous voulez modifier son statut :");
               scanf("%d",&index);
          for(int i=0;i<50;i++){
                if(taches[index].statut,index == index){
                printf("choisez le nouveau statut:\n");
                printf("[1] realiser.\n[2] encours...\n[3] finalisee.\n");
                scanf("%d",&choix_statut);
            switch(choix_statut){
                  case 1:
                     strcpy( taches[index].statut,"realiser");
                     break;
                  case 2:
                     strcpy(taches[index].statut ,"encours");
                     break;
                  case 3:
                     strcpy(taches[index].statut ,"finalisee");
                     break;
                  default :
                     printf("choisir 1,2 ou 3");
                     break;
            }
            }
            else{
                printf("l'id est introuvable.");
                }


         }
      }


 void modifierDeadline(){
    int index;
    printf("entrez l'ID de la tache que vous voulez modifier son deadline :");
    scanf("%d",&index);
    for(int i=0;i<50;i++){
        if(taches[index].deadline,index == index){
            printf("entrez le nouveau deadline :");
            scanf(" %[^\n]s",taches[index].deadline);
        }
        else
                printf("l'id est introuvable.");
         }
 }









