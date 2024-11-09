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

void Imagem::soma(Imagem img2, Imagem imgResultante){
  for(int i=0;i<_dimensao;i++)
    for(int j=0;j<_dimensao;j++)
      imgResultante._matriz[i][j] = _matriz[i][j] + img2._matriz[i][j];
}

void Imagem::subtrai(Imagem img2, Imagem imgResultante){
  for(int i=0;i<_dimensao;i++)
    for(int j=0;j<_dimensao;j++)
      imgResultante._matriz[i][j] = _matriz[i][j] - img2._matriz[i][j];
}

void Imagem::inverteImagem(){
  for(int i=0;i<_dimensao;i++)
    for(int j=0;j<_dimensao;j++){
      int pixel_invertido = 255 - _matriz[i][j];
      _matriz[i][j] = 255 - pixel_invertido;
    }    
}

bool Imagem::compara(Imagem img2){
  for(int i=0;i<_dimensao;i++)
    for(int j=0;j<_dimensao;j++)
      if( _matriz[i][j] != img2._matriz[i][j] )
        return false;
  return true;
}

void Imagem::imprimeImagem(){
  
}

void Imagem::adicionaBorda(){
  
}