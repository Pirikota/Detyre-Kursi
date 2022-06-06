#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define GJATESIA_EMER 50///gjatesia max emrit (mund te ndryshohet)
#define GJATESIA_MBIEMER 50///gjatesia max mbiemrit (mund te ndryshohet)
#define NUMRI_NOTAVE 12///psh 12 nota ne nje vit (mund te ndryshohet)

void funksioneMenu(void);
void perzgjidhFunksione(void);
void shtoStudent(void);///funksion per te shtuar student te ri me id unike
void shtoPedagog(void);///funksion per te shtuar pedagog te ri me id unike
void shtoGrup(void);///fuksion per te shtuar grup te ri
void kerkoStudent(int);///funksion qe kerkon nje student dhe nese e gjen printon te dhenat
bool modifikoStudent(int);///funksion qe kerkon nje student pasi e gjen rishkruan te dhenat e tjera pervec id
void printoTeDhenatEStdMesatareMeTeLarte(void);///printon te dhenat e std me mesatare me te larte
void printoInfoPerPedagoget(void);///shfaq te dhenat e pedagogve
void printoGrupetNeRendZbrites(void);///printon grupet e renditur e rend zbrites sipas vitit
bool fshiStudent(int);///fshi student me nje id te dhene
void kopjoSkedarinPedagog(void);///kopjo te dhenat e file pedagog.txt tek file copyPedagog.txt
bool fshiStudentetMe3NotaJoKaluese(void);///fshi student me  3 ose me shume nota jo kaluese
void printoTeDhenatEStudentitGrupinDhePedagogun(int);///printon te dhenat e detajuara te nje studenti te dhene

///funksione ndihmes
void printoNotat(int[]);///kur dua te printoj nje vektor me nota perdor kte funksionin, perdoret tek funksioni kerkoStudent
float gjejMesataren(int[]);///kur dua te gjej mesataren e nje vektori notash perdor kte funksion, perdoret tek funksioni printoTeDhenatEStdMesatareMeTeLarte
int gjejNumrinENotaveAktual(int[]);///gjen numrin aktual te notave, perdoret tek modifiko student kur do te modifikosh notat
int numriNotaveJoKaluese(int[]);///kur dua te gjej numrin e notave jo kaluese te nje studenti, perdoret tek funksioni fshiStudentetMe3NotaJoKaluese

///perdoren tek funksioni fundit qe printon grupin dhe pedagogun per nje student ( printoTeDhenatEStudentitGrupinDhePedagogun )
void printoPedagogGrupi(int);///kur dua te printoj te dhenat e nje pedagogu qe i perket nje x grupi me id te dhene
void printoGrupMeId(int);///kur dua te printoj te dhent e nje grupi me nje id te caktuar

struct student {
    int id_student;
    char emer[GJATESIA_EMER];
    char mbiemer[GJATESIA_MBIEMER];
    int mosha;
    int notat[NUMRI_NOTAVE];
    int id_grupi;
}student[1000];///shembull 1000 student

struct pedagog{
    int id_pedagog;
    char emer[GJATESIA_EMER];
    char mbiemer[GJATESIA_MBIEMER];
    char departamenti[20];
    int id_grupi;
}pedagog[50];///shembull 50 pedagog

struct grupi{
    int id_grupi;///inkrementohet nga 0 per cdo grup te ri qe shtojme, sipas kerkeses meqe duhet unik
    char emer[50];
    int viti;

}grupi[40];///shembull 40 grupe

int numerim;///varibe global per numerim qe e perodrim kur lexojme ne file

int main (void){

    funksioneMenu();
    return 0;
}

void funksioneMenu(){

    printf("\n----------------------------------------------------");
    printf("\nJu lutem zgjidhni nje nga funksionet e meposhtme:\n");
    printf("a.Shto student\n"
           "b.Shto pedagog\n"
           "c.Shto grup\n"
           "d.Kerko student\n"
           "e.Modifiko student\n"
           "f.Shfaq te dhenat e studentit me mesatare me te larte\n"
           "g.Shfaq te dhenat e pedagogeve\n"
           "h.Shfaq ne rend zbrites grupe\n"
           "i.Fshi student\n"
           "j.Kopjo te dhenat e pedagogeve\n"
           "k.Fshi studentet > 3 nota jo kaluese\n"
           "l.Shfaq te dhenat e studentit me grupin dhe pedagogun perkates\n"
           "Shtyp 0 per te perfunduar programin\n");
    printf("\nZgjedhja juaj : ");

    perzgjidhFunksione();

    return;
}

void perzgjidhFunksione(void){


    char funksioniZgjedhur;
    scanf(" %c", &funksioniZgjedhur);
    bool eshteESakteZgjedhja;

    do{
        eshteESakteZgjedhja = true;
        switch(funksioniZgjedhur){
        case 'a':
            shtoStudent();
            break;
        case 'b':
            shtoPedagog();
            break;
        case 'c':
            shtoGrup();
            break;
        case 'd':
            printf("\nVendosni id e studentit : ");
            int id;
            scanf(" %d", &id);
            kerkoStudent(id);
            break;
        case 'e':
            printf("\nVendosni id e studentit : ");
            scanf(" %d", &id);
            if(modifikoStudent(id)){
                printf("Modifikimi i studentit u realizua me sukses.\n");
            }
            break;
        case 'f':
            printoTeDhenatEStdMesatareMeTeLarte();
            break;
        case 'g':
            printoInfoPerPedagoget();
            break;
        case 'h':
            printoGrupetNeRendZbrites();
            break;
        case 'i':
            printf("\nVendosni id e studentit : ");
            scanf(" %d", &id);
            if(fshiStudent(id)){
                printf("\nFshirja studentit u realizua me sukses.");
            }
            break;
        case 'j':
            kopjoSkedarinPedagog();
            break;
        case 'k':
            if(fshiStudentetMe3NotaJoKaluese()){
                printf("Fshirja studenteve u realizua me sukses.");
            }
            break;
        case 'l':
            printf("Vendosni id e studentit : ");
            scanf("%d", &id);
            printoTeDhenatEStudentitGrupinDhePedagogun(id);
            break;
        case 0:
            return;
        default :
            printf("\nGABIM!\nJu lutem vendosni njerin nga karakteret e percaktuar ne funksionetMenu: ");
            eshteESakteZgjedhja = false;
            scanf(" %c", &funksioniZgjedhur);
        }
    }while(!eshteESakteZgjedhja);

    funksioneMenu();

}

void shtoStudent(){

    int id_student;
    char emer[GJATESIA_EMER];
    char mbiemer[GJATESIA_MBIEMER];
    int mosha;
    int notat[NUMRI_NOTAVE];
    int id_grupi;

    FILE *stdPtr;
    stdPtr = fopen("student.txt","rb");
    if (stdPtr==NULL){
        printf("\nGabim ne hapjen e file\n");
        return;
    }
    numerim=0;

    while (fread(&student[numerim], sizeof(struct student), 1, stdPtr)){//lexim file
        numerim++;
    }

    printf("\nVendosni te dhenat e studentit:");
    printf("\nEmri : ");
    fflush(stdin);
    gets(emer);
    printf("\nMbiemri : ");
    fflush(stdin);
    gets(mbiemer);
    printf("\nId : ");
    scanf("%d", &id_student);
    printf("\nMosha : ");
    scanf("%d", &mosha);
    int nrNotave;
    printf("Vendos numrin e notave : ");
    scanf("%d", &nrNotave);
    int i;
    for(i = 0; i < nrNotave; i++){///lexojme notat me cikel meqense mund te kemi disa nota
        printf("Nota %d : ", i+1);
        scanf(" %d", &notat[i]);
    }

    FILE *grpPtr;
    grpPtr = fopen("grupet.txt","rb");
    if (grpPtr==NULL){
        printf("\nGabim ne hapjen e file\n");
        return;
    }
    int nrGrupeve=0;

    while (fread(&grupi[nrGrupeve],sizeof(struct grupi),1,grpPtr))
    {
        nrGrupeve++;
    }

    if(nrGrupeve == 0){
        printf("Ju lutem vendosni te dhenat e grupeve si fillim qe me pas te shtoni student per id e grupeve.\n");
        return;
    }

    bool eshteESakteId = false;
    do{//zgjidh grupin ku do rregjistrohet nje student

        printf("Zgjidh id e grupit per studentin\n");
        int i;
        for(i = 0; i < nrGrupeve; i++ ){
            printf("Grupi %d\n", i+1);
            printf("Id : %d\n", grupi[i].id_grupi);
            printf("Emer : %s\n", grupi[i].emer);
            printf("Viti : %d\n", grupi[i].viti);
        }

        scanf("%d", &id_grupi);


        for(i = 0; i < nrGrupeve; i++){
            if(grupi[i].id_grupi == id_grupi){
                eshteESakteId = true;
            }
        }
    }while(!eshteESakteId);


    for (i = 0; i < numerim; i++){
        ///nuk mund te rregjistrojme dy student me te njejten ID
        if (student[i].id_student == id_student){
            printf("\nRegjistrimi nuk mund te vazhdoje sepse ekziston nje student me kete ID.\n\n");
            return;
         }
    }
    fclose(stdPtr);
    stdPtr=fopen("student.txt","wb");///hapim file per te shkruar te dhenat e reja qe morem
    if (stdPtr==NULL){
        printf("\nGabim ne hapjen e file\n");
        return;
    }

    ///vendosim te dhenat e reja ne strukture qe ti shkruuajme tek file
    strcpy(student[numerim].emer, emer);
    strcpy(student[numerim].mbiemer, mbiemer);
    student[numerim].id_student = id_student;
    student[numerim].id_grupi = id_grupi;
    student[numerim].mosha = mosha;

    for(i = 0; i < nrNotave; i++){
      student[numerim].notat[i] = notat[i];
    }

    for(i = 0; i<=numerim; i++){///shkruajme te dhenat ne file
        fwrite(&student[i],sizeof(struct student),1,stdPtr);
    }
    printf("\nRregjistrimi i studentit u realizua me sukses.\n\n");
    fclose(stdPtr);
    return;
}

void shtoPedagog(void){

    int id_pedagog;
    char emer[GJATESIA_EMER];
    char mbiemer[GJATESIA_MBIEMER];
    char departamenti[20];
    int id_grupi;

    FILE *pdgPtr;
    pdgPtr = fopen("pedagog.txt","rb");
    if (pdgPtr==NULL){
        printf("\nGabim ne hapjen e file\n");
        return;
    }
    numerim=0;

    while (fread(&pedagog[numerim],sizeof(struct pedagog),1,pdgPtr))//lexim file
    {
        numerim++;
    }
    fclose(pdgPtr);
    printf("\nVendosni te dhenat e pedagogut:");
    printf("\nEmri : ");
    fflush(stdin);
    gets(emer);
    printf("\nMbiemri : ");
    fflush(stdin);
    gets(mbiemer);
    printf("\nId : ");
    scanf("%d", &id_pedagog);
    printf("\nDepartamenti : ");
    fflush(stdin);
    gets(departamenti);


    FILE *grpPtr;
    grpPtr = fopen("grupet.txt","rb");
    if (grpPtr==NULL){
        printf("\nGabim ne hapjen e file\n");
        return;
    }
    int nrGrupeve=0;

    while (fread(&grupi[nrGrupeve],sizeof(struct grupi),1,grpPtr))
    {
        nrGrupeve++;
    }
    fclose(grpPtr);
    if(nrGrupeve == 0){
        printf("Ju lutem vendosni te dhenat e grupeve si fillim qe me pas te shtoni pedagog per id e grupeve.\n");
        return;
    }

    bool eshteESakteId = false;
    int i;
    do{//zgjidh grupin perkates per pedagogun

        printf("Zgjidh id e grupit per pedagogun\n");

        for(i = 0; i < nrGrupeve; i++ ){
            printf("Grupi %d\n", i+1);
            printf("Id : %d\n", grupi[i].id_grupi);
            printf("Emer : %s\n", grupi[i].emer);
            printf("Viti : %d\n", grupi[i].viti);
        }

        scanf(" %d", &id_grupi);
        for(i = 0; i < nrGrupeve; i++){
            if(grupi[i].id_grupi == id_grupi){
                eshteESakteId = true;
            }
        }
    }while(!eshteESakteId);

    for (i = 0; i < numerim; i++){
        ///nuk mund te rregjistrojme dy pedagog me te njejten ID
        if (pedagog[i].id_pedagog == id_pedagog){
            printf("\nRegjistrimi nuk mund te vazhdoje sepse ekziston nje pedagog me kete ID.\n\n");
            return;
         }
    }

    pdgPtr=fopen("pedagog.txt","wb");///hapim file per te shkruar te dhenat e reja qe morem
    if (pdgPtr==NULL){
        printf("\nGabim ne hapjen e file\n");
        return;
    }

    ///vendosim te dhenat e reja ne strukture qe ti shkruuajme tek file
    strcpy(pedagog[numerim].emer, emer);
    strcpy(pedagog[numerim].mbiemer, mbiemer);
    strcpy(pedagog[numerim].departamenti, departamenti);
    pedagog[numerim].id_pedagog = id_pedagog;
    pedagog[numerim].id_grupi = id_grupi;

    for(i = 0; i<=numerim; i++){///shkrim ne file
        fwrite(&pedagog[i], sizeof(struct pedagog), 1, pdgPtr);
    }
    printf("\nRregjistrimi i pedagogut u realizua me sukses.\n\n");
    fclose(pdgPtr);
    return;

}

void shtoGrup(void){


    char emerGrupi[50];
    int viti;


    FILE *grpPtr;
    grpPtr = fopen("grupet.txt","rb");
    if (grpPtr==NULL){
        printf("\nGabim ne hapjen e file\n");
        return;
    }
    numerim=0;

    while (fread(&grupi[numerim],sizeof(struct grupi),1,grpPtr))
    {
        numerim++;
    }

    printf("\nVendosni te dhenat e grupit : ");
    printf("\nVendosni emrin ne formatin (Elektronike A) : ");
    fflush(stdin);
    gets(emerGrupi);
    printf("Vendosni vitin e studimeve (1, 2, 3, 4, 5) : ");
    scanf("%d", &viti);

    ///Kontrollo nese emri dhe vit i grupit te dhene jane te njejte me nje grup ekzistues ateher nuk e shtojme
    int i;
    for(i = 0; i< numerim; i++){
        if (strcmp(grupi[i].emer, emerGrupi) == 0 && grupi[i].viti == viti ){
            printf("Grupi nuk mund te shtohet ne file sepse ekziston.\n\n");
            return;
        }
    }

    fclose(grpPtr);
    grpPtr=fopen("grupet.txt","wb");///hapim file per te shkruar te dhenat e reja qe morem
    if (grpPtr==NULL){
        printf("\nGabim ne hapjen e file\n");
        return;
    }

    ///vendosim te dhenat e reja ne strukture qe ti shkruuajme tek file
    strcpy(grupi[numerim].emer, emerGrupi);
    grupi[numerim].viti = viti;
    grupi[numerim].id_grupi = numerim;

    for(i = 0; i<=numerim; i++){
        fwrite(&grupi[i],sizeof(struct grupi),1,grpPtr);
    }
    printf("\nRregjistrimi i grupit u realizua me sukses.\n\n");
    fclose(grpPtr);
    return;
}


void kerkoStudent(int id){

    FILE *stdPtr;
    stdPtr = fopen("student.txt","rb");
    if (stdPtr==NULL){
        printf("\nGabim ne hapjen e file\n");
        return;
    }
    numerim=0;

    while (fread(&student[numerim], sizeof(struct student), 1, stdPtr))
    {
        numerim++;
    }

    fclose(stdPtr);
    int i;
    for (i = 0; i < numerim; i++){
        if(student[i].id_student == id){
            printf("\nTe dhenat e studentit : \n");
            printf("Emri : %s\n", student[i].emer);
            printf("Mbiemer : %s\n", student[i].mbiemer);
            printf("Mosha : %d\n", student[i].mosha);
            printf("Notat : ");
            printoNotat(student[i].notat);
            printf("ID grupi : %d\n", student[i].id_grupi);
            return;
        }
    }
    printf("Studenti me id e kerkuar nuk ekziston. \n");
    return;
}

bool modifikoStudent(int id){

    FILE *stdPtr;
    stdPtr = fopen("student.txt","rb");
    if (stdPtr==NULL){
        printf("\nGabim ne hapjen e file\n");
        return false;
    }
    numerim=0;

    while (fread(&student[numerim], sizeof(struct student), 1, stdPtr)){
        numerim++;
    }

    fclose(stdPtr);
    int i;
    for (i = 0; i < numerim; i++){
        if(student[i].id_student == id){
            printf("\nVendosni te dhenat e reja te studentit : ");

            printf("\nEmri : ");
            fflush(stdin);
            gets(student[i].emer);
            printf("\nMbiemri : ");
            fflush(stdin);
            gets(student[i].mbiemer);
            printf("\nMosha : ");
            scanf(" %d", &student[i].mosha);
            int nrNotaveAktuale = gjejNumrinENotaveAktual(student[i].notat);

            int nrNotave;
            printf("Vendos numrin e notave : ");
            scanf(" %d", &nrNotave);
            int j;
            for(j = 0; j < nrNotave; j++){
                printf("Nota %d : ", j+1);
                scanf(" %d", &student[i].notat[j]);
            }
            ///nese numri notave eshte me i vogel se ai qe ishte pjesen e mbetur
            ///te notave i vendosim = '\0'
            for(j=nrNotave; j < nrNotaveAktuale; j++){
                student[i].notat[j] = '\0';
            }

            FILE *grpPtr;
            grpPtr = fopen("grupet.txt","rb");
            if (grpPtr==NULL){
                printf("\nGabim ne hapjen e file\n");
                return false;
            }
            int nrGrupeve=0;

            while (fread(&grupi[nrGrupeve],sizeof(struct grupi),1,grpPtr)){
                nrGrupeve++;
            }
            fclose(stdPtr);

            bool eshteESakteId = false;
            do{

                printf("Zgjidh id e grupit per studentin\n");
                for(j = 0; j < nrGrupeve; j++ ){
                    printf("Grupi %d\n", j+1);
                    printf("Id : %d\n", grupi[j].id_grupi);
                    printf("Emer : %s\n", grupi[j].emer);
                    printf("Viti : %d\n", grupi[j].viti);
                }

                scanf("%d", &student[i].id_grupi);

                for(j = 0; j < nrGrupeve; j++){
                    if(student[i].id_grupi == grupi[j].id_grupi){
                        eshteESakteId = true;
                    }
                }
            }while(!eshteESakteId);
            stdPtr=fopen("student.txt","wb");///hapim file per te shkruar te dhenat e reja qe morem
            if (stdPtr==NULL){
                printf("\nGabim ne hapjen e file\n");
                return false;
            }
            for(j = 0; j<=numerim; j++){
                fwrite(&student[j],sizeof(struct student),1,stdPtr);
            }
            fclose(stdPtr);
            return true;
        }
    }
    printf("Studenti me id e kerkuar nuk ekziston. \n");
    return false;
}

void printoTeDhenatEStdMesatareMeTeLarte(){
    FILE *stdPtr;
    stdPtr = fopen("student.txt","rb");
    if (stdPtr==NULL){
        printf("\nGabim ne hapjen e file\n");
        return;
    }
    numerim=0;

    while (fread(&student[numerim], sizeof(struct student), 1, stdPtr)){
        numerim++;
    }

    fclose(stdPtr);

    if(numerim == 0){
        printf("Nuk ka student te regjistruar!\n");
        return;
    }

    float mesMax = 0;
    int index = -1;
    int i;
    for(i = 0; i < numerim; i++){
        float tempMes = gjejMesataren(student[i].notat);
        if(tempMes > mesMax){
            mesMax = tempMes;
            index = i;
        }
    }

    printf("Te dhenat e studentit me mesatare me te larte %.2f \n", mesMax);
    printf("Emri : %s\n", student[index].emer);
    printf("Mbiemer : %s\n", student[index].mbiemer);
    printf("Mosha : %d\n", student[index].mosha);
    printf("Notat : ");
    printoNotat(student[index].notat);
    printf("ID grupi : %d\n", student[index].id_grupi);
    return;
}

void printoInfoPerPedagoget(){

    FILE *pdgPtr;
    pdgPtr = fopen("pedagog.txt","rb");
    if (pdgPtr==NULL){
        printf("\nGabim ne hapjen e file\n");
        return;
    }
    numerim=0;

    while (fread(&pedagog[numerim],sizeof(struct pedagog),1,pdgPtr)){
        numerim++;
    }
    fclose(pdgPtr);
    int i;
    for(i = 0; i < numerim; i++){
        printf("\nPedagog nr. %d\n", i+1);
        printf("Id : %d\n", pedagog[i].id_pedagog);
        printf("Emri : %s\n", pedagog[i].emer);
        printf("Mbiemri : %s\n", pedagog[i].mbiemer);
        printf("Departamenti : %s\n", pedagog[i].departamenti);
        printf("Id grupi : %d\n", pedagog[i].id_grupi);
    }
    return;
}

void printoGrupetNeRendZbrites(){

    FILE *grpPtr;
    grpPtr = fopen("grupet.txt","rb");
    if (grpPtr==NULL){
        printf("\nGabim ne hapjen e file\n");
        return;
    }
    int nrGrupeve=0;

    while (fread(&grupi[nrGrupeve],sizeof(struct grupi),1,grpPtr)){
        nrGrupeve++;
    }
    fclose(grpPtr);

    ///ndarja e viteve eshte 1, 2, 3 per bachelor
    ///dhe 4, 5 per master
    int viti = 5;
    while(viti > 0){///printojme te dhenat duke nisur me grupet viti 5 deri tek viti 1
        int j;
        for(j = 0; j < nrGrupeve; j++){
            if(grupi[j].viti == viti ){
                printf("\nId grupi : %d\n", grupi[j].id_grupi);
                printf("Emri : %s\n", grupi[j].emer);
                printf("Viti : %d\n", grupi[j].viti);
            }
        }
        viti--;
    }
    return;
}

bool fshiStudent(int id){

    FILE *stdPtr;
    stdPtr = fopen("student.txt","rb");
    if (stdPtr==NULL){
        printf("\nGabim ne hapjen e file\n");
        return false;
    }

    numerim = 0;

    while (fread(&student[numerim], sizeof(struct student), 1, stdPtr)){
        numerim++;
    }
    fclose(stdPtr);

    int i = 0;
    for(i = 0; i < numerim; i++){
        if(student[i].id_student == id){
            break;
        }
    }

    if(i >= numerim){
        printf("\nStudenti kerkuar nuk u gjend.\n\n");
        return false;
    }

    for( ; i < numerim-1; i++){
        student[i] = student[i+1];
    }


    stdPtr=fopen("student.txt","wb");///hapim file per te shkruar te dhenat e reja pasi fshirjes se studentit nga struktura
    if (stdPtr==NULL){
        printf("\nGabim ne hapjen e file\n");
        return false;
    }

    for(i=0; i< numerim-1; i++)
    {
        fwrite(&student[i], sizeof(struct student), 1, stdPtr);
    }
    fclose(stdPtr);
    return true;//studenti eshte fshire me sukses
}

void kopjoSkedarinPedagog(){

    FILE *pdgPtr;
    pdgPtr = fopen("pedagog.txt","rb");
    if (pdgPtr==NULL){
        printf("\nGabim ne hapjen e file\n");
        return;
    }
    numerim=0;

    while (fread(&pedagog[numerim],sizeof(struct pedagog),1,pdgPtr)){
        numerim++;
    }
    fclose(pdgPtr);

    pdgPtr=fopen("copyPedagog.txt","wb");///hapim file copy per te shkruar
    if (pdgPtr==NULL){
        printf("\nGabim ne hapjen e file\n");
        return;
    }
    int i;
    for(i = 0; i < numerim; i++)
    {
        fwrite(&pedagog[i], sizeof(struct pedagog), 1, pdgPtr);
    }
    printf("\nKopjimi i file te pedagogve u realizua me sukses kontrrollo direktorine per te pare file copy\n\n");
    fclose(pdgPtr);
    return;
}

bool fshiStudentetMe3NotaJoKaluese(){

    FILE *stdPtr;
    stdPtr = fopen("student.txt","rb");
    if (stdPtr==NULL){
        printf("\nGabim ne hapjen e file\n");
        return false;
    }

    numerim = 0;

    while (fread(&student[numerim], sizeof(struct student), 1, stdPtr))
    {
        numerim++;
    }
    fclose(stdPtr);

    int i = 0;
    int j;
    for(i = 0; i < numerim; i++){
        if(numriNotaveJoKaluese(student[i].notat) >= 3){

            for(j = i ; j < numerim-1; j++){
                student[j] = student[j+1];
            }
            numerim--;
        }
    }

    stdPtr=fopen("student.txt","wb");///hapim file per te shkruar te dhenat e reja pasi fshirjes se studentit nga struktura
    if (stdPtr==NULL){
        printf("\nGabim ne hapjen e file\n");
        return false;
    }

    for(i=0; i < numerim; i++)
    {
        fwrite(&student[i], sizeof(struct student), 1, stdPtr);
    }
    fclose(stdPtr);
    return true;

}
void printoTeDhenatEStudentitGrupinDhePedagogun(int id){

    FILE *stdPtr;
    stdPtr = fopen("student.txt","rb");
    if (stdPtr==NULL){
        printf("\nGabim ne hapjen e file\n");
        return;
    }
    numerim=0;

    while (fread(&student[numerim], sizeof(struct student), 1, stdPtr)){
        numerim++;
    }

    fclose(stdPtr);
    int i;
    for (i = 0; i < numerim; i++){
        if(student[i].id_student == id){
            printf("\nTe dhenat e studentit : \n");
            printf("Emri : %s\n", student[i].emer);
            printf("Mbiemer : %s\n", student[i].mbiemer);
            printf("Mosha : %d\n", student[i].mosha);
            printf("Notat : ");
            printoNotat(student[i].notat);

            printoGrupMeId(student[i].id_grupi);

            printoPedagogGrupi(student[i].id_grupi);

            return;
        }
    }
    printf("Studenti me id e kerkuar nuk ekziston. \n");
    return;
}
///funksion ndihmes per te printuar nje vektor notash
void printoNotat(int notat[]){

    int i;
    for(i = 0; notat[i] != '\0'; i++){
        printf("%d\t", notat[i]);
    }
    printf("\n");
    return;
}
///funksion ndihmes qe printon te dhenat e nje grupi
void printoGrupMeId(int idGrupi){
    FILE *grpPtr;
    grpPtr = fopen("grupet.txt","rb");
    if (grpPtr==NULL){
        printf("\nGabim ne hapjen e file\n");
        return;
    }
    numerim = 0;

    while (fread(&grupi[numerim],sizeof(struct grupi),1,grpPtr)){
        numerim++;
    }
    fclose(grpPtr);
    int i;
    for(i = 0; i < numerim; i++ ){
        if(grupi[i].id_grupi == idGrupi){
            printf("Grupi \n");
            printf("Id : %d\n", grupi[i].id_grupi);
            printf("Emer : %s\n", grupi[i].emer);
            printf("Viti : %d\n", grupi[i].viti);
        }

    }
    return;
}

///funksion ndihmes qe gjen mesataren e notave
float gjejMesataren(int notat[]){
    float shuma = 0;
    int count = 0;

    int i;
    for (i = 0; notat[i] != '\0'; i++){
        shuma += notat[i];
        count++;
    }
    return shuma / count;

}
///funksion ndihmes qe printon te dhenat e nje pedagogu sipas id se grupit qe i perket
void printoPedagogGrupi(int idGrupi){
    FILE *pdgPtr;
    pdgPtr = fopen("pedagog.txt","rb");
    if (pdgPtr==NULL){
        printf("\nGabim ne hapjen e file\n");
        return;
    }
    numerim=0;

    while (fread(&pedagog[numerim],sizeof(struct pedagog),1,pdgPtr)){
        numerim++;
    }
    fclose(pdgPtr);

    int i;
    for(i = 0; i < numerim; i++){
        if(pedagog[i].id_grupi == idGrupi){
            printf("\nPedagog \n", i+1);
            printf("Id : %d\n", pedagog[i].id_pedagog);
            printf("Emri : %s\n", pedagog[i].emer);
            printf("Mbiemri : %s\n", pedagog[i].mbiemer);
            printf("Departamenti : %s\n", pedagog[i].departamenti);
        }
    }
    return;

}
///funksion ndihmes per te gjetur numrin aktual te notave
int gjejNumrinENotaveAktual(int notat []){
    int count = 0;
    int i;
    for(i = 0; notat[i] != '\0'; i++){
        count++;
    }
    return count;

}

///funksion ndimes qe gjen numrin e notave jo kaluese
int numriNotaveJoKaluese(int notat []){

    int count = 0;
    int i;
    for(i = 0; notat[i] != '\0'; i++){
        if(notat[i] == 4){
            count ++;
        }

    }
    return count;
}
