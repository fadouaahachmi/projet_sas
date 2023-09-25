#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct
{
    int jour;
    int mois;
    int annee;

} deadline;

typedef struct
{
    char titre[50], description[50], statut[50];
    deadline date;
    int ID;
} tach;

tach temp;
tach taches[50];
int ID_supprimer;
int indx = 0;
int jour_actuelle, mois_actuelle, annee_actuelle;
int delai;

void calcule_jour(int i)
{
    // Get Current DAte in Days:
    time_t date_actuelle = time(NULL);
    struct tm currDate = *localtime(&date_actuelle);
    int currDays = currDate.tm_mday;
    int currMonth = currDate.tm_mon + 1;
    int currYear = currDate.tm_year + 1900;
    int currDateJours = (currDays) + (currMonth * 30) + (currYear * 360);

    //
    int tache_jours = (taches[i].date.jour) + (taches[i].date.mois * 30) + taches[i].date.annee * 360;
    delai = tache_jours - currDateJours;
}

void affiche()
{
    int choix;
    printf("voulez-vous trier les taches par ordre : \n [1] alphabetique.\n [2] deadline. \n [3] deadline est dans 3 jours ou moins.\n");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
    {
        for (int i = 0; i < indx; i++)
        {
            for (int j = i + 1; j < indx; j++)
            {
                if (strcmp(taches[i].titre, taches[j].titre) > 0)
                {
                    temp = taches[i];
                    taches[i] = taches[j];
                    taches[j] = temp;
                }
            }
        }
        for (int i = 0; i < indx; i++)
        {
            printf("_______LA TACH N%d______\n", taches[i].ID);
            printf("_Le titre de la tache c'est :%s \n", taches[i].titre);
            printf("_La description : %s \n", taches[i].description);
            printf("_Deadline : %d-%d-%d \n", taches[i].date.jour, taches[i].date.mois, taches[i].date.annee);
            printf("_Le statut :%s\n\n", taches[i].statut);
        }
        break;
    }
    case 2:
    {
        for (int i = 0; i < indx; i++)
        {
            for (int j = i + 1; j < indx; j++)
            {
                int tach_jour1 = (taches[j].date.jour + taches[j].date.mois * 30 + taches[j].date.annee * 365);
                int tach_jour2 = (taches[i].date.jour + taches[i].date.mois * 30 + taches[i].date.annee * 365);

                if (tach_jour2 > tach_jour1)
                {
                    temp = taches[i];
                    taches[i] = taches[j];
                    taches[j] = temp;
                }
            }
        }
        for (int i = 0; i < indx; i++)
        {
            printf("_______LA TACH N%d______\n", taches[i].ID);
            printf("_Le titre de la tache c'est :%s \n", taches[i].titre);
            printf("_La description : %s \n", taches[i].description);
            printf("_Deadline : %d-%d-%d \n", taches[i].date.jour, taches[i].date.mois, taches[i].date.annee);
            printf("_Le statut :%s\n\n", taches[i].statut);
        }
        break;
    }
    case 3:
    {
        for (int i = 0; i < indx; i++)
        {
            calcule_jour(i);
            if (delai <= 3 && delai > 0)
            {
                printf("_______LA TACH N%d______\n", taches[i].ID);
                printf("_Le titre de la tache c'est :%s \n", taches[i].titre);
                printf("_La description : %s \n", taches[i].description);
                printf("_Deadline : %d-%d-%d \n", taches[i].date.jour, taches[i].date.mois, taches[i].date.annee);
                printf("_Le statut :%s\n\n", taches[i].statut);
            }
        }
    }
    break;

    default:
        printf("_SVP enterez 1,2 ou 3.\n");
        break;
    }
}

void ajoute()
{
    char choix_statut;
    taches[indx].ID = indx + 1;
    printf("_Ecrit le titre de la tache :");
    scanf(" %[^\n]s", taches[indx].titre);
    printf("_La description de la tache :");
    scanf(" %[^\n]s", taches[indx].description);
    printf("_Deadline de la tache (jour-mois-annee) :");
    scanf("%d-%d-%d", &taches[indx].date.jour, &taches[indx].date.mois, &taches[indx].date.annee);
    printf("_Le statut de la tache:\n");
    printf("CHOISEZ :\n");
    printf("[1] realiser.\n[2] encours...\n[3] finalisee.\n");
    scanf("%d", &choix_statut);
    switch (choix_statut)
    {
    case 1:
        strcpy(taches[indx].statut, "a realiser");
        break;
    case 2:
        strcpy(taches[indx].statut, "encours");
        break;
    case 3:
        strcpy(taches[indx].statut, "finalisee");
        break;
    default:
        printf("choisir 1,2 ou 3");
        break;
    }
    indx++;
}

void mod_Description()
{
    int exist = 0;
    int ID_mod;
    printf("entrez l'ID de la tache que vous voulez modifier sa description :");
    scanf("%d", &ID_mod);
    for (int i = 0; i < indx; i++)
    {
        if (taches[i].ID == ID_mod)
        {
            printf("entrez la nouvelle description :");
            scanf(" %[^\n]s", taches[i].description);
            exist++;
        }
    }
    if (exist == 0)
        printf("l'id est introuvable.");
}

void mod_Statut()
{
    int exist = 0;
    int choix_statut;
    int ID_mod;
    printf("entrez l'ID de la tache que vous voulez modifier son statut :");
    scanf("%d", &ID_mod);
    for (int i = 0; i < indx; i++)
    {
        if (taches[i].ID == ID_mod)
        {
            printf("choisez le nouveau statut:\n");
            printf("[1] realiser.\n[2] encours...\n[3] finalisee.\n");
            scanf("%d", &choix_statut);
            switch (choix_statut)
            {
            case 1:
                strcpy(taches[i].statut, "realiser");
                break;
            case 2:
                strcpy(taches[i].statut, "encours");
                break;
            case 3:
                strcpy(taches[i].statut, "finalisee");
                break;
            default:
                printf("choisir 1,2 ou 3\n");
                break;
            }
            exist++;
        }
    }
    if (exist == 0)
        printf("l'id est introuvable.");
}

void mod_Deadline()
{
    int ID_mod;
    int exist = 0;
    printf("entrez l'ID de la tache que vous voulez modifier son deadline :");
    scanf("%d", &ID_mod);
    for (int i = 0; i < indx; i++)
    {
        if (taches[i].ID == ID_mod)
        {
            printf("entrez le nouveau deadline :");
            scanf(" %d-%d-%d", &taches[i].date.jour, &taches[i].date.mois, &taches[i].date.annee);
            exist++;
            break;
        }
    }
    if (exist == 0)
        printf("l'id est introuvable.");
}

void menu()
{
    int choix;
    char oui_non[4];
    do
    {
        printf("________________________________| MENU |______________________________\n\n");
        printf(" [1] Ajouter une nouvelle tache.\n [2] Ajouter plusieurs nouvelles taches.\n [3] Afficher la liste de toutes les taches. \n [4] Modifier une tache. \n [5] Supprimer une tache par identifiant.\n [6] Rechercher les Taches.\n [7] Statistiques. \n\n");
        printf("_______________________________________________________________________\n\n");
        printf("  Tapez votre choix : ");
        scanf("%d", &choix);
        // system("cls");
        switch (choix)
        {
        case 1:
            ajoute();
            // system("cls");
            break;
        case 2:
            ajoute();
            for (int i = 0; i <= 50; i++)
            {
                printf("Voulez-vous ajouter une autre tache?\n _oui/non: \n");
                scanf("%s", oui_non);
                if (strcmp(oui_non, "oui") == 0)
                {
                    ajoute();
                    // system("cls");
                }
                else
                    break;
            }
            // system("cls");
            break;
        case 3:
            affiche();
            break;
        case 4:
        {
            int choix_mdf;
            printf("que vous voulez modifier ?\n ");
            printf("[1] description.\n [2] statut.\n [3] deadline.");
            scanf("%d", &choix_mdf);
            switch (choix_mdf)
            {
            case 1:
                mod_Description();
                break;
            case 2:
                mod_Statut();
                break;
            case 3:
                mod_Deadline();
                break;
            }
        }
        break;
        case 5:
        {
            int ID_spr;
            printf("entrez l'ID de la taches que vous souhaitez supprimer :");
            scanf("%d", &ID_spr);
            for (int i = 0; i < indx; i++)
            {
                if (taches[i].ID == ID_spr)
                {
                    for (int j = i; j < indx; j++)
                    {
                        taches[j] = taches[j + 1];
                    }
                    indx--;
                }
            }
            break;
        }

        case 6:
        {
            int exist = 0;
            int choix_recherche, ID_recherche;
            char titre_recherche[30];
            printf("voulez vous rechercher une tache par :\n [1] Identifiant.\n [2] Titre.\n\nTaper :");
            scanf("%d", &choix_recherche);
            switch (choix_recherche)
            {
            case 1:
                printf("entrez l'ID de la tache souhaitee :");
                scanf("%d", &ID_recherche);
                for (int i = 0; i < indx; i++)
                {
                    if (ID_recherche == taches[i].ID)
                    {
                        printf("le Titre : %s\n", taches[i].titre);
                        printf("la description : %s \n", taches[i].description);
                        printf(" deadline : %d-%d-%d \n", taches[i].date.jour, taches[i].date.mois, taches[i].date.annee);
                        printf("le statut de la tache :%s\n\n", taches[i].statut);
                        exist++;
                    }
                }
                if (exist == 0)
                    printf("aucun donnee\n");
                break;
            case 2:
                printf("entrez le Titre de la tache souhaitee :");
                scanf(" %[^\n]s", titre_recherche);
                for (int i = 0; i < indx; i++)
                {
                    if (strcmp(titre_recherche, taches[i].titre) == 0)
                    {
                        printf("le Titre : %s\n", taches[i].titre);
                        printf("la description : %s \n", taches[i].description);
                        printf(" deadline : %d-%d-%d \n", taches[i].date.jour, taches[i].date.mois, taches[i].date.annee);
                        printf("le statut de la tache :%s\n\n", taches[i].statut);
                        exist++;
                    }
                }
                if (exist == 0)
                    printf("aucun donnee\n");
                break;
            default:
                printf("svp entrer 1 ou 2");
            }
        }
        break;
        case 7:
        {
            int choix_stq;
            printf("que vous voulez ?\n[1] Afficher le nombre total des taches.\n[2] Afficher le nombre de taches completes et incompletes.\n[3] Afficher le nombre de jours restants jusqu'au delai de chaque tache.\n");
            printf("__Tapez votre choix:");
            scanf("%d", &choix_stq);
            switch (choix_stq)
            {
            case 1:
                printf("_Le nombre du tches que vous avez ajoute c'est : %d\n\n", indx);
                break;
            case 2:
            {
                int fin = 0;

                for (int i = 0; i < indx; i++)
                {
                    if (strcmp(taches[i].statut, "finalisee") == 0)
                    {
                        fin++;
                    }
                }
                int count = indx - fin;
                printf("_Vous avez terminee %d taches.\n", fin);
                printf("_Vous n'avez pas encours terminee %d taches.\n", count);
                break;
            }
            case 3:
            {
                for (int i = 0; i < indx; i++)
                {
                    calcule_jour(i);
                    printf("Delai de la tache N%d est :%d.\n", i + 1, delai);
                }
            }
            }
        }
        break;
        }

    } while (1);
}

int main()
{
    menu();

    return 0;
}
