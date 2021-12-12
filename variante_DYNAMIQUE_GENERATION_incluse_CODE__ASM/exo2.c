#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int (*calcule)(int, int);


int convertisseur(char c){
  return ((int)c)-48;}

void *load() {
void *lib= dlopen("./calcule.so",RTLD_LAZY);
calcule=dlsym(lib,"evalExpr");
return lib;
}
void unload(void *lib) {
dlclose(lib);
}

void compile(char* s){
  //l'appel a cette fonction va creer le fichier assembleur
  //qui traitera la fonction evalExpr classiquement parlons--.
  FILE *f = fopen("calcule.s","w");//si existe creation apres ecrasement
  //version ancienne AU CAS OU..
  fprintf(f,"\tsection .text\n \tglobal evalExpr\n evalExpr:\n");
  //"w" pas "r" car format constant et "rw" possible -> char[] l'emporte..
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
	 fprintf(f,"\t push rdi\n");
	 break;
      case 'b':
         fprintf(f,"\t push rsi\n");
	 break;
    default:
      fprintf(f,"\t push %d\n",convertisseur(*s));
      break;}
  }while(*(++s));
  fprintf(f,"fin:\n\t pop rax\n\t ret\n");
  fclose(f);
  system("yasm -felf64 calcule.s");
  system("gcc -shared -o calcule.so calcule.o");
}
  
    
int main(int argc, char* argv[]){
  char* s=argv[1];
  compile(s);
  void* lib=load();
  int a=atoi(argv[2]); int b=atoi(argv[3]);
  printf("%d\n",calcule(3,5));
  for(int m=1;m<100000;m++){
    a++;b++;calcule(a,b);}
  unload(lib);
  return 0;}
