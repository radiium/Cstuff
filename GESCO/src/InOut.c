/*******************************************************
    Nom        : InOut.c

    Desription : Définition des structures et des fonctions associées  à
                 la gestion d'une classe.

    Auteur     : T.C
                 C.H.L

********************************************************/

#include "InOut.h"

///-----------------------------------------------------------------------------
/// Fonction : Impression informations eleve
/// paramètre en lecture : ecole
void ft_imprimerEleve(eleve_t el,char n_f[MAX_CHAR])
{
	FILE *ptr_f;
	int i;
	char date[11];
	
// ouverture fichier
	ptr_f=fopen(n_f,"w");
	
	if (!ptr_f)
		perror("impossible d'ouvrir le fichier");
 
// enregistrement dans le fichier n_f de toutes les informations de l'élève 
	fprintf(ptr_f,"%s\n %s\n %c\n %c\n %c\n %d\n",el.nom, el.prenom, el.redoublement, el.restauration, el.genre, el.nb_fratrie);
	
	// enregistrement de la date de naissance
    strftime(date,11,"%d/%m/%Y", localtime(&el.date_naissance));
	fprintf(ptr_f,"%s\n",date);
	
	// enregistrement des coordonnées
	fprintf(ptr_f,"%s\n %s\n %s\n %s\n %s\n",el.adresse.num, el.adresse.rue, el.adresse.postal, el.adresse.ville, el.adresse.tel);
	
	// enregistrement de la fratrie
	for (i=0;i<el.nb_fratrie;i++)
	{
		strftime(date,11,"%d/%m/%Y", localtime(&el.tab_fratrie[i].date_nais));
		fprintf(ptr_f,"%s\n %s\n %s\n %c\n",el.tab_fratrie[i].nom,el.tab_fratrie[i].prenom,date,el.tab_fratrie[i].scolarise_ec);
	}
	
	// enregistrement des contacts
	for (i=0;i<2;i++)
	{
		fprintf(ptr_f,"%s\n %s\n %s\n",el.tab_contact[i].nom,el.tab_contact[i].prenom,el.tab_contact[i].tel);
	}
	
	
// fermeture du fichier
	fclose(ptr_f);

	if (!ptr_f)
		perror("impossible de fermer le fichier");
}

///-----------------------------------------------------------------------------
/// Fonction : Impression informations classe
/// paramètre en lecture : classe
void ft_imprimerClasse(classe_t cl,char n_f[MAX_CHAR])
{
	FILE *ptr_f;
	int i;
	char date[11];

	
// ouverture fichier
	ptr_f=fopen(n_f,"w");
	
	if (!ptr_f)
		perror("impossible d'ouvrir le fichier");
		
		
// enregistrement dans le fichier n_f de toutes les informations de la classe
	fprintf(ptr_f,"%s\n %s\n %d\n",cl.nom,cl.prof,cl.nbeleve);
	
	// enregistrement des élèves de la classe
	for (i=0;i<cl.nbeleve;i++)
	{
		strftime(date,11,"%d/%m/%Y", localtime(&cl.ptr_eleve[i].date_naissance));
		fprintf(ptr_f,"%s\n %s\n %s\n",cl.ptr_eleve[i].nom,cl.ptr_eleve[i].prenom,date);
	}

	
// fermeture du fichier
	fclose(ptr_f);

	if (!ptr_f)
		perror("impossible de fermer le fichier");
}


///-----------------------------------------------------------------------------
/// Fonction : Impression informations ecole
/// paramètre en lecture : ecole
void ft_imprimerEcole(ecole_t ec,char n_f[MAX_CHAR])
{
	FILE *ptr_f;
	int i=0;
	char date[11];
	
// ouverture fichier
	ptr_f=fopen(n_f,"w");
	
	if (!ptr_f)
		perror("impossible d'ouvrir le fichier");
		

// enregistrement dans le fichier n_f de toutes les informations de l'école

	// enregistrement du nom et directeur de l'école
	fprintf(ptr_f,"%s\n %s\n",ec.nom,ec.directeur);
	
	// enregistrement de l'année scolaire concernée
	strftime(date,11,"%d/%m/%Y", localtime(&ec.date));
	fprintf(ptr_f,"%s\n",date);
	
	// enregistrement des coordonnées de l'école
	fprintf(ptr_f,"%s\n %s\n %c\n %s\n %s\n",ec.adresse.num,ec.adresse.rue,ec.adresse.postal,ec.adresse.ville,ec.adresse.tel);
	
	// enregistrement du nombre de classes
	fprintf(ptr_f,"%d\n",ec.nombreClasse);
	
	// enregistrement par niveau du nom, professeur et nombre d'élèves de chaque classe ouverte dans l'école
	while (ec.tab_cp[i] != NULL)
	{
		fprintf(ptr_f,"%s\n %s\n %d\n",ec.tab_cp[i]->nom,ec.tab_cp[i]->prof,ec.tab_cp[i]->nbeleve);
	}
	
	i=0;
	while (ec.tab_ce1[i] != NULL)
	{
		fprintf(ptr_f,"%s\n %s\n %d\n",ec.tab_cp[i]->nom,ec.tab_cp[i]->prof,ec.tab_cp[i]->nbeleve);
	}
	
	i=0;
	while (ec.tab_ce2[i] != NULL)
	{
		fprintf(ptr_f,"%s\n %s\n %d\n",ec.tab_cp[i]->nom,ec.tab_cp[i]->prof,ec.tab_cp[i]->nbeleve);
	}
	
	i=0;
	while (ec.tab_cm1[i] != NULL)
	{
		fprintf(ptr_f,"%s\n %s\n %d\n",ec.tab_cp[i]->nom,ec.tab_cp[i]->prof,ec.tab_cp[i]->nbeleve);
	}
	
	i=0;
	while (ec.tab_cm2[i] != NULL)
	{
		fprintf(ptr_f,"%s\n %s\n %d\n",ec.tab_cp[i]->nom, ec.tab_cp[i]->prof, ec.tab_cp[i]->nbeleve);
	}
		

// fermeture du fichier
	fclose(ptr_f);

	if (!ptr_f)
		perror("impossible de fermer le fichier");
}


///-----------------------------------------------------------------------------
/// Fonction : Exportation informations ecole
/// paramètre en lecture : ecole
void ft_exporterEcole(ecole_t ec,char n_f[MAX_CHAR])
{
	FILE * ptr_f;
	
// ouverture fichier n_f
	ptr_f=fopen(n_f,"wb");
	
	if (!ptr_f)
		perror("impossible d'ouvrir le fichier");
		
// enregistrement des informations de l'école dans le fichier n_f
	fwrite(&ec,sizeof(ecole_t),1,ptr_f);
	
	
// fermeture du fichier n_f
	fclose(ptr_f);

	if (!ptr_f)
		perror("impossible de fermer le fichier");
}

///-----------------------------------------------------------------------------
/// Fonction : Importation informations ecole
/// paramètre en mise à jour : ecole
void ft_importerEcole(ecole_t ec,char n_f[MAX_CHAR])
{
	FILE * ptr_f;
	
// ouverture fichier n_f
	ptr_f=fopen(n_f,"wb");
	
	if (!ptr_f)
		perror("impossible d'ouvrir le fichier");
		
// lecture des informations de l'école contenues dans le fichier n_f
	fread(&ec,sizeof(ecole_t),1,ptr_f);
	
// fermeture du fichier n_f
	fclose(ptr_f);

	if (!ptr_f)
		perror("impossible de fermer le fichier");
}

