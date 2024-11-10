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
      imgResultante._matriz[i][j] = _matriz[i][j] + img2._matriz[i][j];
    }
}

void Imagem::subtrai(Imagem &img2, Imagem &imgResultante){
  if(_dimensao != img2._dimensao){
    std::cerr << "Nao e possivel subtrair, dimensoes diferentes.";
    exit(1);
  }
  for(int i=0;i<_dimensao;i++)
    for(int j=0;j<_dimensao;j++)
      imgResultante._matriz[i][j] = _matriz[i][j] - img2._matriz[i][j];
}

void Imagem::inverteImagem(){
  for(int i=0;i<_dimensao;i++)
    for(int j=0;j<_dimensao;j++){
      int pixel_invertido = 255 - _matriz[i][j];
      _matriz[i][j] = pixel_invertido;
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
  
}

void Imagem::criaImagemPreta(){
  for(int i=0;i<_dimensao;i++){
    for(int j=0;j<_dimensao;j++)
      _matriz[i][j] = 0;
  }
}