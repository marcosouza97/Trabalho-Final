#include <iostream>
#include <locale.h>
#include <fstream>

using namespace std;
//Estrutura da prova 3
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

// vai inicializar lista.
void inicializaLista(tLista *pLista){
  pLista -> primeiro = NULL;
  pLista -> ultimo = NULL;
  pLista -> marcador = NULL;
  pLista -> tamanho = 0;

}

// volta o tamanho da lista 
int obterTamanho(tLista* pLista){
  return pLista -> tamanho;
}

bool listaVazia (tLista* pLista){
  return(pLista -> tamanho == 0);
}

bool finalLista(tLista* pLista){
  return (pLista->marcador == NULL);
}

//Função para inserior novos elementos no final
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

// Faz a impressão da lista na tela
void imprimirLista(tLista* pLista){
  pLista->marcador = pLista->primeiro;
  

  while(!finalLista(pLista)){
  int informacao = pLista->marcador->info;
  cout << "A informacao eh:" << informacao<<endl;

  
  pLista ->marcador = pLista->marcador->proximo;
  }
}

// Função responsalvel por navegar pelas informções da lista e inserir no aqruivo TXT
void navegacaoDaLista(tLista* pLista){
  
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
tLista* lados = new tLista;               //lista encadeada
tLista* amostragem = new tLista;         //lista encadeada
int aux1=0, aux2=0, aux3=0, opcao=0,n=0; //  varivaeis de auxiliio
tTriangulo base, altura, hipotenusa;     // 
ifstream baldo;                           
string nome=" ",mostrar=" ";

//funções para inicializar as listas 
inicializaLista (lados);
inicializaLista (amostragem);

//Solicitação da inforções para o usuario
cout << "Digite uma opção:" << endl;
cout << "1 - para ler" << endl;
cout << "2 - para escrever" << endl;
cin >> aux1;

// caso a opcao for escrever
while(aux1!=1){
    // quantidades de triangulos a ser calculados 
  if (aux1 == 2){
    cout << "Digite quantos triangulos deseja gravar" << endl;
    cin >> aux2;


    for(int i=0;i<aux2;i++){
        
      cout << "Digite o" << i+1 <<" ° lado" << endl;
      cin >> base.lado1;
      incluirNoFim(lados, base.lado1); //jogando as informações para uma lista encadeada


      cout << "Digite o " << i+2 <<"° lado" <<endl;
      cin >> altura.lado2;
      incluirNoFim(lados, altura.lado2); //jogando as informações para uma lista encadeada


        cout << "Digite o " << i+3 << "° lado" << endl;
        cin >> hipotenusa.lado3;
        incluirNoFim(lados, hipotenusa.lado3); //jogando as informações para uma lista encadeada


    }

    imprimirLista(lados);  // impri a lista encadeada
    navegacaoDaLista(lados); // chama a função para gravar a lista encadeada no arquivo TXT
  }

  // volta a opção para o usuario
  cout << "O que deseja fazer" <<endl;
  cout << "1 - para ler" << endl;
  cout << "2 - para escrever" << endl;
  cin >> aux1;
}

// caso a opção do usuario seja ler o arquivo
if(aux1 == 1 ){
   baldo.open("valores.txt", ios :: in); //funcao para realizar leitura

   while (!baldo.eof()){
    
    baldo >> mostrar;
    cout << mostrar << endl;
    n = stoi (mostrar);   // pegando o arquivo em string e transformando para int
    incluirNoFim(amostragem, n); //pegando as informções lidas e colocando em uma lista encadead 
  }

  baldo.close();
  // vai imprimir o modelo da lista encadeada
  imprimirLista(amostragem);
}

}

