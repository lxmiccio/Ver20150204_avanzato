#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dummyMath.h"
#include "classe.h"

struct classe * allocaRecord(int n);
void memorizzaClassi(struct classe *classi, int i, char nome[], int alunni); 
struct classe * ingrandisciRecord(struct classe *classi, int size, int nuovaSize);
void stampaRovescio(struct classe *classi, int size);

int main(int argc, char** argv) {
    float f;
    char scelta = 's';
    char nome[NOME_MAXLEN+1];
    int alunni;
    int i = 0;
    int size = 2;
    struct classe *classi = allocaRecord(size);
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
        // TODO Inserisci qui codice e funzioni per l'aggiunta della classe
        memorizzaClassi(classi, i, nome, alunni); 
        printf("Vuoi aggiungere un'altra classe? (s/n) ");
        getchar();  // Non modificare (buffered read)
        scelta = getchar();
        i++;
    }
    
    // Stampa delle informazioni, in ordine _INVERSO_ rispetto a quello di inserimento
    // TODO Modifica il codice seguente per eseguire quanto richiesto.
    // TODO Aggiungi eventuali funzioni a tuo piacimento
    printf("\nStampa degli elementi in ordine inverso rispetto all'inserimento\n");
    stampaRovescio(classi, size);
    
    return (EXIT_SUCCESS);
}

struct classe * allocaRecord(int n)
{
    struct classe *classi = (struct classe*)malloc(n*sizeof(struct classe));
    return classi;
}

void memorizzaClassi(struct classe *classi, int i, char nome[], int alunni)
{
    strcpy(classi[i].nome, nome);
    classi[i].alunni = alunni;
    return;
}

struct classe * ingrandisciRecord(struct classe *classi, int size, int nuovaSize) 
{
    int i;
    struct classe *nuovoClassi = (struct classe*)malloc(nuovaSize*sizeof(struct classe));
    for(i=0; i<size; i++)
    {
        strcpy(nuovoClassi[i].nome, classi[i].nome);
        nuovoClassi[i].alunni = classi[i].alunni;
    }
    free(classi);
    return nuovoClassi;
}

void stampaRovescio(struct classe *classi, int size)
{
    int i;
    for(i=size-1; i>0; i--)
    {
        printf("%s", classi[i].nome);
        printf("%d", classi[i].alunni);
    }
    return;
}