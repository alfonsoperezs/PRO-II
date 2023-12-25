/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Miguel García González
 * AUTHOR 2: Alfonso Pérez Sánchez
 * DATE: 16/03/2023
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "types.h"

#define MAX_BUFFER 255

#ifdef DYNAMIC_LIST
#include "dynamic_list.h"
#endif
#ifdef STATIC_LIST
#include "static_list.h"
#endif


void createItem(tParticipantName pName, tNumVotes nVotes, char euN[MAX_BUFFER], tItemL *item){
    //Función que crea una variable de tipo tItemL y le asigna valores.
    strcpy(item->participantName,pName);
    item->numVotes = nVotes;
    if(strcmp(euN,"eu")==0){
        item->EUParticipant = true;
    } else item->EUParticipant = false;
}
void testInsert(bool result, char participant[MAX_BUFFER], char location[MAX_BUFFER]){
    //Comprueba si el participante ha sido añadido o no. Además, imprime el mensaje correspondiente.
    if(result==true){
        printf("* New: participant %s location %s\n", participant, location);
    } else{
        puts("+ Error: New not possible");
    }
}
void euBoolChar(tItemL item, char *location){
    //Función que transforma una variable de tipo tEUParticipant en una variable de tipo char
    if(item.EUParticipant==true)
        strcpy(location,"eu");
    else
        strcpy(location,"non-eu");

}

void newParticipant( tList *Lpart, char *param1,char *param2, char *commandNumber, char command){
   //Función que añade un participante nuevo a la lista colocándolo en la ultima posición y inicializa a 0 su numero de votos.

    tItemL item;

    puts("********************");
    printf("%s %c: participant %s location %s\n" ,commandNumber,command,param1,param2);
    createItem(param1, 0, param2, &item);
    /*
     * A continuación si el item que queremos introducir esta ya previamente en la lista sacamos por texto un mensaje de
     * error. Si el dato no está previamente en la lista lo insertamos en la ultima posición en caso de haber mas elementos en la lista
     * o de primero en caso de que la lista esté vacía.
     */
    if(findItem(param1,*Lpart)!=LNULL){
        puts("+ Error: New not possible");
    }else{
        if(isEmptyList(*Lpart)){
            testInsert(insertItem(item, first(*Lpart), Lpart),param1,param2);
        }
        else{
            testInsert(insertItem(item, next(last(*Lpart),*Lpart),Lpart),param1,param2);
        }
    }
}
void voteParticipant(tList *Lpart,char *param1, char *location, char *commandNumber, char command, tNumVotes *nullVotes, float *totalvotes){
    //Función que vota a favor de un participante. El participante debe existir.
    tItemL item;

    puts("********************");
    printf("%s %c: participant %s\n" ,commandNumber,command,param1);
/*
 * A continuación en caso de que la lista no esté vacia y ademas el pais esté en la lista , se modifica la lista sumandole
 * un voto al país indicado. Además se suma uno a la variable que mide el numero de votos totales sin ser nulos. En caso
 * contrario sale por pantalla un mensaje de error.
 */

    if((findItem(param1,*Lpart)!=LNULL) && (isEmptyList(*Lpart)==false)){
        item = getItem(findItem(param1,*Lpart),*Lpart);
        euBoolChar(item,location);
        ++item.numVotes;
        updateItem(item, findItem(param1,*Lpart), Lpart);
        ++*totalvotes;
        printf("* Vote: participant %s location %s numvotes %d\n",param1,location,item.numVotes);
    } else{
        ++*nullVotes;

        printf("+ Error: Vote not possible. Participant %s not found. NULLVOTE\n", param1);
    }
}
void disqualifyParticipant(tList *Lpart,char *param1, char *location, char *commandNumber, char command, tNumVotes *nullVotes, float *totalvotes){
    //Función que elimina al participante indicado de la lista, pasando a considerar nulos sus votos previos.
    tItemL item;
    puts("********************");
    printf("%s %c: participant %s \n" ,commandNumber,command,param1);

    /*
     * A continuación en caso de que el participante indicado este en la lista y que la lista no está vacía, se eliminan
     * todos los datos de dicho participante. Previamente a borrar los datos, el valor de los votos se declaran como nulos
     * y se suman a el numero de votos nulos totales. En caso contrario a la condicion inicial se indica por pantalla un
     * mensaje de error.
     */

    if((findItem(param1,*Lpart)==LNULL) || (isEmptyList( *Lpart)) == true){
        puts("+ Error: Disqualify not possible");
    }else{
        item = getItem(findItem(param1,*Lpart),*Lpart);
        *nullVotes = *nullVotes + item.numVotes;
        if (*totalvotes > 0) *totalvotes = *totalvotes - (float)item.numVotes;
        euBoolChar(item,location);
        printf("* Disqualify: participant %s location %s \n", param1, location);
        deleteAtPosition(findItem (param1, *Lpart), Lpart);
    }



}
void statsParticipant(tList *Lpart,char *param1, char *location, char *commandNumber, char command, const tNumVotes *nullVotes, const float *totalvotes){
    //Funcion que muestra las estadísticas de cada participante, la cantidad de votos nulos totales y la participación total.
    tItemL item;
    float percent;
    double votescommand;

    puts("********************");
    printf("%s %c: totalvoters %s\n" ,commandNumber,command,param1);

    /*
     *A continuación si la lista está vacía se indica por pantalla un mensaje de error. En caso contrario mediante un
     * bucle se representaran por pantalla las estadisticas de los participantes. Además tambien saldrá por pantalla el
     * numero de votos nulos totales y los datos de participación.
     */

    if (isEmptyList(*Lpart)== true){
        printf("+ Error: Stats not possible\n");
    }
    else{
        for (tPosL p = first(*Lpart); p != LNULL; p = next(p,*Lpart)) {
            item = getItem(p,*Lpart);
            euBoolChar(item,location);
            if(*totalvotes==0) percent= 0;
            else percent = ((float)item.numVotes/(*totalvotes))*100; //Necesitamos modificar el tipo de variable para poder hacer el cálculo

            printf("Participant %s location %s numvotes %d (%.2f%%)\n",item.participantName,location,item.numVotes,percent);
        }
        printf("Null votes %d \n", *nullVotes);
        votescommand = atof(param1); //Convierte param 1 (tipo char) a una variable tipo float.
        if(votescommand == 0) percent = 0;
        else percent = (((float)*nullVotes + *totalvotes)/(float)votescommand)*100;
        printf("Participation: %.f votes from %s voters (%.2f %%)\n",(float)*nullVotes+*totalvotes,param1,percent);
    }
}

void processCommand(char *commandNumber, char command, char *param1, char *param2,tList *Lpart,tNumVotes *nullVotes,float *totalvotes) {
    char location[MAX_BUFFER];

    switch (command) {
        case 'N':
            //Opción NEW
            newParticipant( Lpart, param1, param2, commandNumber, command);
            break;
        case 'V':
            //Opción VOTE
            voteParticipant(Lpart,param1,location,commandNumber,command,nullVotes,totalvotes);
            break;
        case 'D':
            //Opción DISQUALIFY
            disqualifyParticipant(Lpart,param1, location, commandNumber, command, nullVotes, totalvotes);
            break;
        case 'S':
            //Opción STATS
            statsParticipant(Lpart,param1,location,commandNumber,command,nullVotes, totalvotes);
            break;
        default:
            break;
    }
}

void readTasks(char *filename) {
    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];
    tList Lpart;
    createEmptyList(&Lpart);
    tNumVotes nullVotes = 0;
    float totalvotes=0;

    f = fopen(filename, "r");

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);

            processCommand(commandNumber, command[0], param1, param2,&Lpart,&nullVotes,&totalvotes);
        }

        fclose(f);

    } else {
        printf("Cannot open file %s.\n", filename);
    }
}


int main(int nargs, char **args) {
    char *file_name = "new.txt";

    if (nargs > 1) {
        file_name = args[1];
    } else {
        #ifdef INPUT_FILE
        file_name = INPUT_FILE;
        #endif
    }

    readTasks(file_name);

    return 0;
}






