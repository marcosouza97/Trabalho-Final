#include <iostream>
#include <locale.h>
#include <fstream>

using namespace std;

struct tTriangulo{
  float lado1=0.0;
  float lado2=0.0;
  float lado3=0.0;
  float aux;
};

// estrutura para lista
struct tNo{
  int info;
  tNo* proximo; 

};

// coloca a informação na lista e a ponta para o proximo nó
tNo* criaNo(int item){
  tNo* no = new tNo;

  no->info = item;
  no->proximo=NULL;

  return no;
}

//******************************************

// Grerenciador
struct tLista{
  tNo* primeiro;
  tNo* ultimo;
  tNo* marcador;
  int tamanho;
};

void inicializaLista(tLista *pLista){
  pLista -> primeiro = NULL;
  pLista -> ultimo = NULL;
  pLista -> marcador = NULL;
  pLista -> tamanho = 0;

}

int obterTamanho(tLista* pLista){
  return pLista -> tamanho;
}

bool listaVazia (tLista* pLista){
  return(pLista -> tamanho == 0);
}

bool finalLista(tLista* pLista){
  return (pLista->marcador == NULL);
}

void incluirNoFim(tLista* pLista, int info){
  tNo* no;
  no = criaNo(info);

  if(listaVazia(pLista)){
    pLista -> primeiro = no;
  }
  
  else{
  pLista -> ultimo ->proximo=no;
  }
  pLista ->ultimo=no;
  pLista ->marcador=no;
  pLista -> tamanho ++;


}

void imprimirLista(tLista* pLista){
  pLista->marcador = pLista->primeiro;
  

  while(!finalLista(pLista)){
  int informacao = pLista->marcador->info;
  cout << "A informacao eh:" << informacao<<endl;

  
  pLista ->marcador = pLista->marcador->proximo;
  }
}

void varrerLista(tLista* pLista){
  
  pLista->marcador = pLista->primeiro;
  
  ofstream gravar;
  gravar.open("valores.txt",ios::out);

  while(!finalLista(pLista)){
  int informacao = pLista->marcador->info;

  gravar << informacao <<endl;

  pLista ->marcador = pLista->marcador->proximo;

  }
  gravar.close();
}


int main() {
tLista* lados = new tLista;
int aux1=0, aux2=0, aux3=0;
tTriangulo base, altura, hipotenusa;

inicializaLista (lados);

cout << "Digite uma opção:" << endl;
cout << "1 - para ler" << endl;
cout << "2 - para escrever" << endl;
cin >> aux1;

// entrada de dados
while(aux1!=){
  
  if(aux1 == 1){

  }
  else{
    if (aux1 == 2){
      cout << "Digite quantos triangulos deseja gravar" << endl;
      cin >> aux2;


      for(int i=0;i<aux2;i++){
        
        cout << "Digite o" << i+1 <<"° lado" << endl;
        cin >> base.lado1;
        incluirNoFim(lados, base.lado1);


        cout << "Digite o " << i+1 <<"° lado" <<endl;
        cin >> altura.lado2;
        incluirNoFim(lados, altura.lado2);


        cout << "Digite o " << i+2 << "° lado" << endl;
        cin >> hipotenusa.lado3;
        incluirNoFim(lados, hipotenusa.lado3);


      }

      imprimirLista(lados);
      varrerLista (lados);
    }
  }
  cout << "O que deseja fazer" <<endl;
  cout << "1 - para ler" << endl;
  cout << "2 - para escrever" << endl;
  cin >> aux1;
}



}