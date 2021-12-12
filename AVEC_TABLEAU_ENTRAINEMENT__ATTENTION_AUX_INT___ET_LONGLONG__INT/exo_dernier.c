#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

void (*calcule)(long long int*,long long int*);

void* load(){
  void* lib=dlopen("./calcule.so",RTLD_LAZY);
  calcule=dlsym(lib,"evalExpr");
  return lib;
}

void unload(void* lib){
  dlclose(lib);
}

long long int convertisseur(char c){
  return ((long long int)c)-48;}

//evalExpr est de type void (*calcule)(int*, int*).
void compile(char* s){
  //l'appel a cette fonction va creer le fichier assembleur
  //qui traitera la fonction evalExpr classiquement parlons--.
  FILE *f = fopen("calcule.s","w");//si existe creation apres ecrasement
  //version ancienne AU CAS OU..
 
  fprintf(f,"\t section .text\n \t global evalExpr\n evalExpr:\n\t mov r10,0 \n  boucle:\n");
  //"w" pas "r" car format constant et "rw" possible -> char[] l'emporte..
  int p=0;
  do{
    switch(*s){
       case '*':
	 fprintf(f,"\t pop r8\n \t pop r9\n \t imul r8,r9\n \t push r8\n");
	 break;
       case '+':
	 fprintf(f,"\t pop r8\n \t pop r9\n \t add r8,r9\n \t push r8\n");
	 break;
       case '-':
	 fprintf(f,"\t pop r8\n \t pop r9\n \t sub r8,r9\n \t push r8\n");
	 break;
       case 'a':
	 fprintf(f,"\t mov r11,[rdi+r10*8]\n \t push r11 \n");
	 break;
      case 'b':
         fprintf(f,"\t mov r12,[rsi+r10*8]\n \t push r12 \n");
	 break;
    default:
      fprintf(f,"\t push %lld\n",convertisseur(*s));
      break;}
    p++;
  }while(*(++s));
  for(int y=0;y<p;y++) s--;
  fprintf(f,"\t pop r13 \n \t lea r15,[rdi+r10*8] \n \t mov [r15],r13\n");
  fprintf(f,"\t inc r10 \n");
  fprintf(f,"\t mov r14,0 \n \t cmp [rsi+r10*8],r14 \n \t jne boucle\n");
  fprintf(f,"fin:\n \t ret");
  fclose(f);
  system("yasm -felf64 calcule.s");
  system("gcc -shared -o calcule.so calcule.o");
}

void initialiser(long long int* tab, int len){
  for(int i=0;i<len;i++){
    *(tab+i)=0;}}

void print_tab(int* e, int len){
  for(int u=0;u<len;u++){
    printf("%d\t",*(e+u));}
  printf("\n");}

int main(int argc, char* argv[]){
  char* s=argv[1];
  compile(s);
  long long int a[100];long long int b[100];
  initialiser(a,100);initialiser(b,100);
  //print_tab(a,100);print_tab(b,100);
  *a=4;*b=7;
  *(a+1)=3;*(b+1)=1;
   *(a+2)=38;*(b+2)=3;
  void* lib=load();
  calcule(a,b);
  printf("%lld %lld\n%lld %lld\n%lld %lld\n",*a,*b,*(a+1),*(b+1),*(a+2),*(b+2));
  unload(lib);
  return 0;}
//on pourrait amelioerer en faisant des scanfs puis remplir des tableaux
//dynamiques pour que ca soit plus generale mais vu qu'on dispose de la bonne
//fonction generale associée, donc cela suffit pour valider++ la moitie +des
//potentielles tests a faire en cas.///
  
