#include <iostream>

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


int main() {
tLista* lados = new tLista;

inicializaLista (lados);



}