/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Miguel García González
 * AUTHOR 2: Alfonso Pérez Sánchez
 * DATE: 13 / 04 / 2023
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "jury_list.h"

#define MAX_BUFFER 255

void createJury(tListJ *L,tJuryName name,char totalVoters[MAX_BUFFER]);
void newParticipant(tListJ *L, tJuryName juryName, tParticipantName participantName, char EUParticipant[MAX_BUFFER]);
void voteParticipant(tListJ *L, tJuryName jury, tParticipantName participant);
void disqualifyParticipant(tListJ *L, char participantName[MAX_BUFFER]);
void removeJury(tListJ *L);
void stats(tListJ *L);
void winners(tListJ *L);

void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3, tListJ *LIST) {

    switch (command) {
        case 'C':
            //[C]reate Jury
            puts("********************");
            printf("%s %c: jury %s totalvoters %s\n",commandNumber,command,param1,param2);
            createJury(LIST,param1,param2);
            break;
        case 'N':
            //[N]ew Participant
            puts("********************");
            printf("%s %c: jury %s participant %s location %s\n",commandNumber,command,param1,param2,param3);
            newParticipant(LIST,param1,param2,param3);
            break;
        case 'V':
            //[V]ote Participant
            puts("********************");
            printf("%s %c: jury %s participant %s\n", commandNumber,command,param1,param2);
            voteParticipant(LIST,param1,param2);
            break;
        case 'D':
            //[D]isqualify Jury
            puts("********************");
            printf("%s %c: participant %s\n",commandNumber,command,param1);
            disqualifyParticipant(LIST,param1);
            break;
        case 'S':
            //[S]tats
            puts("********************");
            printf("%s %c:\n",commandNumber,command);
            stats(LIST);
            break;
        case 'R':
            //[R]emove
            puts("********************");
            printf("%s %c:\n",commandNumber,command);
            removeJury(LIST);
            break;
        case 'W':
            //[W]inners
            puts("********************");
            printf("%s %c:\n",commandNumber,command);
            winners(LIST);
            break;
        default:
            break;
    }
}

void readTasks(char *filename) {
    tListJ LIST;
    createEmptyListJ(&LIST);

    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2, *param3;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];

    f = fopen(filename, "r");

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);
            param3 = strtok(NULL, delimiters);

            processCommand(commandNumber, command[0], param1, param2, param3, &LIST);
        }

        fclose(f);

    } else {
        printf("Cannot open file %s.\n", filename);
    }
}


int main(int nargs, char **args) {

    char *file_name = "create.txt";

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

//AUX
bool EUCharToBool(char EU[MAX_BUFFER]){
    /*
     * La función toma como entrada un arreglo de caracteres "EU" y lo compara con la cadena "eu". Si "EU" es igual
     * a "eu", la función devuelve "true"; de lo contrario, devuelve "false".
     */
    if(strcmp(EU,"eu")==0)
        return true;
    else
        return false;
}
void EUBoolToChar(tEUParticipant EUParticipant, char *EU){
    /*
     * La función convierte un valor booleano en una cadena de caracteres "eu" o "non-eu".
     */
    if(EUParticipant == true)
        strcpy(EU,"eu");
    else
        strcpy(EU,"non-eu");
}
void get_jury_winners(tListP participantList, tEUParticipant isEU, bool *empate, tItemP *winner, int *count) {
        int comparison;
        comparison = -1; //iniciamos la comparacion de votos en -1 para que los participantes con 0 votos también cuenten
        *count = 0;
        for (tPosP p = firstP(participantList); p != NULLP; p = nextP(p, participantList)) {
            //Recorremos la lista de participantes
            tItemP participant;
            participant = getItemP(p, participantList);

            if (participant.EUParticipant == isEU) { //seleccionamos que tipo de winner queremos obtener (eu o non-eu)
                *count = *count+1;
                if (participant.numVotes >= comparison) {
                    /*Comparamos para saber primero para saber si cumple la condicion de tener por lo menos  votos y
                     * despues para ver si el nuevo participante tiene mas votos que el anterior*/
                    if (participant.numVotes == comparison) {
                        /*Comparamos para obtener true en caso de empate. Al final del bucle si el valor de empate queda
                         * como true significa que hay empate.*/
                        *empate = true;
                    } else {
                        *empate = false;
                    }
                    *winner = participant;
                    comparison = participant.numVotes;
                }
            }
        }
}


void createJury(tListJ *L,tJuryName name,char totalVoters[MAX_BUFFER]){
    //[C]reate: Se incorpora el jurado juryName cuyo número total de miembros es totalVoters.
    tItemJ item;
    tListP P;

    createEmptyListP(&P);

    strcpy(item.juryName,name);
    item.totalVoters = atoi(totalVoters);
    item.validVotes = 0;
    item.nullVotes = 0;
    item.participantList = P;

    if (findItemJ(name,*L) != NULLJ) //caso ya existe dicho jurado
        puts("+ Error: Create not posible");
    else{ //caso crear jurado
        if(insertItemJ(item,L) == true)
            printf("* Create: jury %s totalvoters %d\n",item.juryName,item.totalVoters);
        else
            puts("+ Error: Create not posible");
    }
}
void newParticipant(tListJ *L, tJuryName juryName, tParticipantName participantName, char EUParticipant[MAX_BUFFER]){
    //[N]ew: Alta de un participante en un jurado y con 0 votos. EUParticipant puede tomar el valor eu o non-eu.
    tItemP item;
    tItemJ juryData;

    if (!isEmptyListJ(*L)) {
        if (findItemJ(juryName, *L) == NULLJ) //caso no existe dicho jurado
            puts("+ Error: New not possible");
        else {
            juryData = getItemJ(findItemJ(juryName, *L), *L);
            if (findItemP(participantName, juryData.participantList) != NULLP) //caso ya existe dicho participante
                puts("+ Error: New not possible");
            else {
                strcpy(item.participantName, participantName);
                item.numVotes = 0;
                item.EUParticipant = EUCharToBool(EUParticipant);
                insertItemP(item, &juryData.participantList);
                updateItemJ(juryData,findItemJ(juryName, *L),L); //creacion item y insertado en la lista
                printf("* New: jury %s participant %s location %s\n", juryName, participantName, EUParticipant);
            }
        }
    } else{ //caso lista jurados vacia
        puts("+ Error: New not possible");
    }
}
void voteParticipant(tListJ *L, tJuryName jury, tParticipantName participant){
    //[V]ote: Se emite un voto para un participante en un jurado.
    tPosJ PosJury;
    tItemJ itemJ;
    tPosP PosParticipant;
    tItemP itemP;
    char EU[MAX_BUFFER];
    PosJury=findItemJ(jury, *L);

    if (PosJury == NULLJ){
        //Caso en el que el jurado no existe
        printf("+ Error: Vote not possible\n");
    }
    else {
        itemJ = getItemJ(PosJury,*L);
        PosParticipant = findItemP(participant, itemJ.participantList);
        if (PosParticipant == NULL){
            //Caso en el que el participante no existe
            itemJ.nullVotes++; //Contamos el voto como nulo
            printf("+ Error: Vote not possible. Participant %s not found in jury %s. NULLVOTE\n", participant, jury);
        }
        else{
            itemP = getItemP(PosParticipant,itemJ.participantList);
            itemJ.validVotes++; //Sumamos el numero de votos validos del juez
            itemP.numVotes++; //Sumamos el numero de votos del participante
            EUBoolToChar(itemP.EUParticipant,EU);
            updateItemP(itemP,PosParticipant,&itemJ.participantList);
            //Actualizamos los nuevos valores de la lista participantes
            printf("* Vote: jury %s participant %s location %s numvotes %d \n", jury, participant, EU, itemP.numVotes);
        }
        updateItemJ(itemJ,PosJury,L); //Actualizamos los nuevos valores de la lista jurado
    }
}
void stats(tListJ *L){
    //[S]tats: Muestra estadísticas de participación y voto.
    tItemJ jury;
    tItemP participant;
    if(isEmptyListJ(*L)){
        //Caso en el que la lista de jurados esta vacia.
        printf("+ Error: Stats not possible\n");
    }
    else{
        for (tPosJ i = firstJ(*L); i != NULLJ; i= nextJ(i,*L)){
            //Recorremos la lista de jurados
            jury = getItemJ(i, *L);
            printf("Jury %s\n", jury.juryName);
            if (isEmptyListP(jury.participantList)) {
                //Caso en el que la lista de participantes esta vacia.
                printf("No participants\n");
                }
            else{
                //Caso en el que la lista de participantes no esta vacia
                for (tPosP p = firstP(jury.participantList); p != NULLP; p = nextP(p, jury.participantList)) {
                    //Recorremos la lista de partipantes
                    char EU[MAX_BUFFER];
                    participant=getItemP(p,jury.participantList);
                    EUBoolToChar(participant.EUParticipant,EU);
                    float participantAverage;
                    if(jury.validVotes==0)
                    //Caso en el que el jurado tiene 0 votos
                    {
                        participantAverage = 0;
                    }
                    else
                    {
                        participantAverage = ((float)participant.numVotes/(float)jury.validVotes)*100;
                    }
                    printf("Participant %s location %s numvotes %d (%.2f%%)\n", participant.participantName, EU,participant.numVotes, participantAverage);
                }
            }
            printf("Nullvotes %d\n",jury.nullVotes);
            float participationAverage;
            participationAverage = ((float)jury.validVotes+(float)jury.nullVotes)/((float)jury.totalVoters)*100;
            printf("Participation: %d votes from %d voters (%.2f%%)\n\n", jury.validVotes+jury.nullVotes, jury.totalVoters,participationAverage);
        }
    }
}
void disqualifyParticipant(tListJ *L, char participantName[MAX_BUFFER]){
    /*
     * [D]isqualify: Descalifica a un participante eliminándolo de todas las listas de jurados, y pasando a ser
     * votos nulos todos sus votos.
     */
    tPosJ juryPos;
    tPosP partPos;

    if (!isEmptyListJ(*L)) {
        for (juryPos = firstJ(*L); juryPos != NULLJ; juryPos = nextJ(juryPos, *L)) {
            //recorrido de la lista de jurados comprobando en cada jurado si está dicho participante
            tItemJ juryItem = getItemJ(juryPos, *L);

            partPos = findItemP(participantName, juryItem.participantList);

            if (partPos != NULLP) {
                printf("Jury %s\n", juryItem.juryName);
                printf("Participant %s disqualified\n", participantName);
                puts("");

                int partVotes = getItemP(partPos,juryItem.participantList).numVotes;

                juryItem.validVotes -= partVotes;
                juryItem.nullVotes += partVotes; //reajuste de los votos

                deleteAtPositionP(partPos, &juryItem.participantList);
                updateItemJ(juryItem, juryPos, L); //modificación de la lista
            } else{ //caso "x" jurado no tiene ese participante
                printf("No participant %s\n",participantName);
            }
        }
    } else { //caso no hay jurados en la lista
        printf("+ Error: Disqualify not possible\n");
    }
}
void removeJury(tListJ *L){
    //[R]emove: Elimina los jurados con 0 votos válidos.
    tPosJ juryPos, juryPosAux; //la variable auxiliar para indicar la posicion previa a la actual
    tItemJ juryItem;
    bool deleted = false; //indica si se ha borrado algun jurado a lo largo de toda la operacion

    if (!isEmptyListJ(*L)) { //caso lista no vacia
        juryPos = firstJ(*L);
        while (juryPos != NULLJ && !isEmptyListJ(*L)){
            juryItem = getItemJ(juryPos,*L);
            if(juryItem.validVotes == 0){ //caso eliminar jurado
                deleted = true;
                juryPosAux = previousJ(juryPos,*L);
                printf("* Remove: jury %s\n",juryItem.juryName);
                deleteAtPositionJ(juryPos,L);
                if(juryPosAux == NULLJ) //evitamos dejar jurados sin comprobar
                    juryPos = firstJ(*L); //se ha eliminado el primer jurado de la lista
                else{
                    juryPos = nextJ(juryPosAux,*L); //se ha eliminado un jurado de la lista
                }
            } else{ //caso no eliminar jurado
                juryPos = nextJ(juryPos,*L);
            }
        }
        if(!deleted) //caso no se ha eliminado ningún jurado
            puts("+ Error: Remove not possible");
    } else { //caso lista vacia
        puts("+ Error: Remove not possible");
    }
}
void winners(tListJ *L) {
    /*
     * [W]inners: Para cada jurado muestra el ganador entre los países que pertenecen
     * a la Unión Europea y entre los que no.
     */
    tItemJ jury;
    tItemP winner;
    bool empate;
    int count;
    if (isEmptyListJ(*L)) {
        //Caso en el que la lista de jurados esta vacia
        printf("+ Error: Winners not possible");
        printf("\n");
    }
    else {
        for (tPosJ i = firstJ(*L); i != NULLJ; i = nextJ(i, *L)) {
            jury = getItemJ(i, *L);
            printf("Jury %s\n", jury.juryName);
            empate = false;
            if (!isEmptyListP(jury.participantList)) {
                //Caso en el que la lista de participantes no está vacía
                get_jury_winners(jury.participantList, true, &empate, &winner,&count);
                if(empate == true || count == 0) {
                    //Analizamos si cumplen las condiciones de no empate y de que haya participantes con terminacion eu
                    printf("Location eu: No winner\n");
                }
                else{
                    printf("Location eu: Participant %s numvotes %d\n", winner.participantName, winner.numVotes);
                }
                get_jury_winners(jury.participantList, false, &empate, &winner, &count);
                if(empate == true || count == 0){
                    //Analizamos si cumplen las condiciones de no empate y de que haya participantes con terminacion non-eu

                    printf("Location non-eu: No winner\n");
                }
                else{
                    printf("Location non-eu: Participant %s numvotes %d\n", winner.participantName, winner.numVotes);
                }
                puts("");
            }
            else{
                //Caso en el que la lista de participantes está vacia
                printf("Location eu: No winner\n");
                printf("Location non-eu: No winner\n");
                puts("");
            }

        }
    }

}
