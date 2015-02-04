#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dummyMath.h"
#include "classe.h"

struct classe * allocaRecord(int n);
void memorizzaClassi(struct classe *classi, int i, char nome[], int alunni); 
struct classe * ingrandisciRecord(struct classe *classi, int size, int nuovaSize);
void stampaRovescio(struct classe *classi, int i);

int main(int argc, char** argv) {
    float f;
    char scelta = 's';
    char nome[NOME_MAXLEN+1];
    int alunni, i = 0 , size = 2;
    struct classe *class = allocaRecord(size);
    
    // SEZIONE 1 ------------------------------------------
    // ----------------------------------------------------
    printf("Inserisci un valore decimale da raddoppiare: ");
    scanf("%f", &f);
    // TODO Correggi l'implementazione della procedura raddoppia
    raddoppia(&f);
    printf("Il valore raddoppiato è: %f\n", f);
    
    // SEZIONE 2 ------------------------------------------
    // ----------------------------------------------------
    // Inserimento dei dati
    
    while(scelta == 's') {
        printf("\nInserisci il nome della classe (max %d caratteri): ", NOME_MAXLEN);
        scanf("%s", nome);
        printf("Inserisci il numero degli alunni: ");
        scanf("%d", &alunni);
        memorizzaClassi(class, i, nome, alunni); 
        printf("Vuoi aggiungere un'altra classe? (s/n) ");
        getchar();  // Non modificare (buffered read)
        scelta = getchar();
        i++;
        if(scelta == 's' && size == i)
        {
            class = ingrandisciRecord(class, size, size*2);
            size*=2; 
        }
    }  
    // Stampa delle informazioni, in ordine _INVERSO_ rispetto a quello di inserimento
    // TODO Modifica il codice seguente per eseguire quanto richiesto.
    // TODO Aggiungi eventuali funzioni a tuo piacimento
    printf("\nStampa degli elementi in ordine inverso rispetto all'inserimento\n");
    stampaRovescio(class, i);
    free(class);
    return (EXIT_SUCCESS);
}

struct classe * allocaRecord(int n)
{
    struct classe *class = (struct classe*)malloc(n*sizeof(struct classe));
    return class;
}

void memorizzaClassi(struct classe *class, int i, char nome[], int alunni)
{
    strcpy(class[i].nome, nome);
    class[i].alunni = alunni;
    return;
}

struct classe * ingrandisciRecord(struct classe *class, int size, int nuovaSize) 
{
    int i;
    struct classe *newClass = (struct classe*)malloc(nuovaSize*sizeof(struct classe));
    for(i=0; i<size; i++)
    {
        strcpy(newClass[i].nome, class[i].nome);
        newClass[i].alunni = class[i].alunni;
    }
    free(class);
    return newClass;
}

void stampaRovescio(struct classe *class, int i)
{
    int c;
    for(c=i-1; c>=0; c--)
    {
        printf("%s ", class[c].nome);
        printf("%d\n", class[c].alunni);
    }
    return;
}