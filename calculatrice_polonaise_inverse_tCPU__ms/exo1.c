#include<stdio.h>
#include<stdlib.h>
#define N 100


int convertir(char c){
  //convertit un chiffre dedans les '' en l'entier correspondant
  //(int)c donne le code ASCII de ce qu'il y a dedans le c (entre ''_2-<<<)
  //en assembleur(~++): 1 caractere sur 8 bits (code ascii --___<->)
  //c'est pour cela declarer un '?' se fait par db '?',10,0
  //donc un char en entier ((int) c par exemple) donnera le code ascii de
  //ce charactere.
  int code1=(int)c;//'0' correspond a 48
  return code1 -48;}

void print_tab(int tab[], int len){
  int n=0;
  while(n<len){printf("%d\t",tab[n]);n++;}
  printf("\n");}
  
int execute(char* s, int a, int b){
  int tab[N];//tableau (pile apres) de 100 elements
  //!!!INITIALISER LE TABLEAU sinon valeurs aleatoires donc probleme apres..
  for(int h=0;h<100;h++){
    tab[h]=0;}
  int j=0;
  do{//car s pas vide.
    switch(*s){
    case 'a':
      tab[j++]=a;
      break;
    case'b':
      tab[j++]=b;
      break;
    case '+':
      tab[j-2]+=tab[j-1];tab[j-1]=0;j--;
      break;
    case '*':
      tab[j-2]*=tab[j-1];tab[j-1]=0;j--;
      break;
    case '-':
      tab[j-2]-=tab[j-1];tab[j-1]=0;j--;
      break;
    default:
      tab[j++]=convertir(*s);
      break;}
  }while(*(++s));//refaire tant que s[index_prec++] n'est pas le charactere
  //d'echappement '\0' qui est interprete en un booleen False.
  //++ avant pour avoir une manip. de *(s_prec+1) au prochain switch.
  //print_tab(tab,100);
  return tab[0];
}

int compter(char *ss){
  int n=0;char *s=ss;
  while(*s && *s!='+' && *s!='b' && *s!='a' && *s!='-' && *s!='*'){
    n++;s++;}
  return n;
}

int power_10(int puissance){
  int a=1;
  for(int i=0;i<puissance;i++){
    a*=10;}
  return a;}

int recuperer(int nbr, char* ss){
  int b=0;char* s=ss;
  for(int l=0;l<nbr;l++){
    b+=power_10(nbr-l-1)*(convertir(*s));s++;}
  return b;}

char* avancer_plus(int n,char* s){
  for(int p=0;p<n;p++){
    s++;}
  return s;}
  
int execute_avancee(char* s, int a, int b){//*s,a,b peuvent etre des entiers
  int tab[N];//tableau (pile apres) de 100 elements
  //!!!INITIALISER LE TABLEAU sinon valeurs aleatoires donc probleme apres..
  for(int h=0;h<100;h++){
    tab[h]=0;}
  int j=0;int m;
  do{
    //car s pas vide.
    switch(*s){
    case 'a':
      tab[j++]=a;
      break;
    case'b':
      tab[j++]=b;
      break;
    case '+':
      tab[j-2]+=tab[j-1];tab[j-1]=0;j--;
      break;
    case '*':
      tab[j-2]*=tab[j-1];tab[j-1]=0;j--;
      break;
    case '-':
      tab[j-2]-=tab[j-1];tab[j-1]=0;j--;
      break;
    default:
      tab[j++]=recuperer(compter(s),s);s=avancer_plus(compter(s)-1,s);
      //printf("%d %d\n",compter(s),tab[j-1]);
      break;}
    }while(*(++s));
   //refaire tant que s[index_prec++] n'est pas le charactere
  //d'echappement '\0' qui est interprete en un booleen False.
  //++ avant pour avoir une manip. de *(s_prec+1) au prochain switch.
  //print_tab(tab,100);
  return tab[0];
}

int main(int argc, char* argv[]){
  char s[]="4a+b*";
  printf("%d\n",execute(s,3,5));
  char ss[]="40a+b*";
  printf("%d\n",execute_avancee(s,30,50));
  //  printf("%d\n",execute_avancee(s,30,50));//verification
  int a=4;int b=6;
  for(int m=2;m<100000;m++){//100 milles executions(100 millions bcp)
    //impliquant des a,b differents donc 100 milles executions pour
    //100 milles valeurs differentes de a,b.(sans le printf ca serait mieux hhh)
    a++;b++;
    if(a==30) a++;
    if(b==50) b++;
    execute_avancee(ss,a,b);}
  //printf("%d\n",convertir('4'));
  return 0;}
      

