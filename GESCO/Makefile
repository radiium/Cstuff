
# Tester et exécuté sur :
# =======================
# Compilateur : gcc
# Version     : 4.8.4 (Ubuntu 4.8.4-2ubuntu1~14.04)
# Date        : 27/01/2016(dernière mise à jour)



# Flag de compilation -g pour debuggage avec gdb
CFLAGS = -g -W -Wall -Wextra

# Chemin d'accès des fichiers sources
SRC = src/

# L'exécutable final
EXEC = GESCO



# Toutes le taches (compilation et nettoyage)
all: $(EXEC) clean

# cible principale
GESCO:  $(SRC)main.c $(SRC)demo.o $(SRC)menu.o $(SRC)ecole.o $(SRC)classe.o $(SRC)eleve.o $(SRC)InOut.o $(SRC)coord.o $(SRC)fratrie.o $(SRC)contact.o $(SRC)annexe.o $(SRC)date.o
	gcc $(SRC)main.c $(SRC)demo.o $(SRC)menu.o $(SRC)ecole.o $(SRC)classe.o $(SRC)eleve.o $(SRC)InOut.o $(SRC)coord.o $(SRC)fratrie.o $(SRC)contact.o $(SRC)annexe.o $(SRC)date.o -o $(EXEC)


# cibles secondaires
demo.o:    $(SRC)demo.c $(SRC)menu.o $(SRC)demo.h
	gcc -c $(SRC)demo.c  $(CFLAGS)

menu.o:    $(SRC)menu.c $(SRC)ecole.o $(SRC)annexe.o $(SRC)date.o $(SRC)menu.h
	gcc -c $(SRC)menu.c  $(CFLAGS)

ecole.o:   $(SRC)ecole.c $(SRC)classe.o $(SRC)annexe.o $(SRC)date.o $(SRC)ecole.h
	gcc -c $(SRC)ecole.c  $(CFLAGS)

classe.o:  $(SRC)classe.c $(SRC)eleve.o $(SRC)annexe.o $(SRC)date.o $(SRC)classe.h
	gcc -c $(SRC)classe.c $(CFLAGS)

eleve.o:   $(SRC)eleve.c $(SRC)coord.o $(SRC)fratrie.o $(SRC)contact.o $(SRC)annexe.o $(SRC)date.o $(SRC)eleve.h
	gcc -c $(SRC)eleve.c $(CFLAGS)

InOut.o:   $(SRC)InOut.c $(SRC)ecole.o $(SRC)annexe.o $(SRC)date.o $(SRC)InOut.h
	gcc -c $(SRC)InOut.c $(CFLAGS)


# cibles sans dépendances
coord.o:   $(SRC)coord.c $(SRC)annexe.o $(SRC)coord.h
	gcc -c $(SRC)coord.c $(CFLAGS)

fratrie.o: $(SRC)fratrie.c $(SRC)annexe.o $(SRC)fratrie.h
	gcc -c $(SRC)fratrie.c $(CFLAGS)

contact.o: $(SRC)contact.c $(SRC)annexe.o $(SRC)contact.h
	gcc -c $(SRC)contact.c $(CFLAGS)

date.o:    $(SRC)date.c $(SRC)annexe.o $(SRC)date.h
	gcc -c $(SRC)date.c $(CFLAGS)

annexe.o:    $(SRC)annexe.c $(SRC)annexe.h
	gcc -c $(SRC)annexe.c $(CFLAGS)


clean:
	@echo "	Suppression des fichiers objets"
	rm -f $(SRC)*.o

