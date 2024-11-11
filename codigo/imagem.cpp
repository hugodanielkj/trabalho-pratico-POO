#include <iostream>
#include "imagem.h"

Imagem::Imagem(int dimensao){
  _dimensao = dimensao;
  _matriz = new int*[_dimensao];
  for(int i=0;i<_dimensao;i++)
    _matriz[i] = new int[_dimensao];
}

Imagem::~Imagem(){
  for(int i=0;i<_dimensao;i++)
    delete[] _matriz[i];
  delete[] _matriz;
}

void Imagem::leImagem(){
  for(int i=0;i<_dimensao;i++)
    for(int j=0;j<_dimensao;j++)
      std::cin >> _matriz[i][j];
}

void Imagem::soma(Imagem &img2, Imagem &imgResultante){
  if(_dimensao != img2._dimensao){
    std::cerr << "Nao e possivel somar, dimensoes diferentes.";
    exit(1);
  }
  for(int i=0;i<_dimensao;i++)
    for(int j=0;j<_dimensao;j++){
      if(_matriz[i][j] + img2._matriz[i][j] <= 255)
        imgResultante._matriz[i][j] = _matriz[i][j] + img2._matriz[i][j];
      else
        imgResultante._matriz[i][j] = 255;
    }
}

void Imagem::subtrai(Imagem &img2, Imagem &imgResultante){
  if(_dimensao != img2._dimensao){
    std::cerr << "Nao e possivel subtrair, dimensoes diferentes.";
    exit(1);
  }
  for(int i=0;i<_dimensao;i++)
    for(int j=0;j<_dimensao;j++)
      if(_matriz[i][j] - img2._matriz[i][j] >= 0)
        imgResultante._matriz[i][j] = _matriz[i][j] - img2._matriz[i][j];
      else
        imgResultante._matriz[i][j] = 0;
}

void Imagem::inverteImagem(Imagem &imgResultante){
  for(int i=0;i<_dimensao;i++)
    for(int j=0;j<_dimensao;j++){
      int pixel_invertido = 255 - _matriz[i][j];
      imgResultante._matriz[i][j] = pixel_invertido;
    }    
}

bool Imagem::compara(Imagem &img2){
  for(int i=0;i<_dimensao;i++)
    for(int j=0;j<_dimensao;j++)
      if( _matriz[i][j] != img2._matriz[i][j] )
        return false;
  return true;
}

void Imagem::imprimeImagem(){
  for(int i=0;i<_dimensao;i++){
    for(int j=0;j<_dimensao;j++)
      std::cout << _matriz[i][j] << " ";
    std::cout << std::endl;
  }
}

void Imagem::adicionaBorda(){
  if(existeBordaBranca()){   //Verifica se a borda e branca
    alocaNovaMatrizComBorda(1);
    adicionaUmPixelDeBorda(0,0);
  }
  else{   //Implementacao em imagens sem borda branca
    alocaNovaMatrizComBorda(2);
    adicionaUmPixelDeBorda(1,255);
    adicionaUmPixelDeBorda(0,0);
  }
}

void Imagem::criaImagemPreta(){
  for(int i=0;i<_dimensao;i++){
    for(int j=0;j<_dimensao;j++)
      _matriz[i][j] = 0;
  }
}

void Imagem::alocaNovaMatrizComBorda(int tamanho_borda){
  int** novaMatriz = new int*[_dimensao+(tamanho_borda*2)];
  for(int i=0;i<_dimensao+(tamanho_borda*2);i++)
    novaMatriz[i] = new int[_dimensao+(tamanho_borda*2)];

  for(int i=tamanho_borda;i<_dimensao+tamanho_borda;i++)
    for(int j=tamanho_borda;j<_dimensao+tamanho_borda;j++)
      novaMatriz[i][j] = _matriz[i-tamanho_borda][j-tamanho_borda];

  this->~Imagem();

  _matriz = novaMatriz;
  _dimensao += tamanho_borda*2;
}

void Imagem::adicionaUmPixelDeBorda(int index_borda, int cor){
for(int i=index_borda;i<_dimensao-index_borda;i++){
  for(int j=index_borda;j<_dimensao-index_borda;j++){
    if(i==index_borda || i==_dimensao-1-index_borda)
      _matriz[i][j] = cor;
    else{
      _matriz[i][index_borda] = cor;
      _matriz[i][_dimensao-1-index_borda] = cor;
    }
  }
  }
}

bool Imagem::existeBordaBranca(){
  for(int i=0;i<_dimensao;i++)
    for(int j=0;j<_dimensao;j++)
      if(i==0 || i==_dimensao-1){
        if(_matriz[i][j]!=255)
          return false;
      } else {
        if(_matriz[i][0]!=255 || _matriz[i][_dimensao-1]!=255)
          return false;
      }
  return true;
}