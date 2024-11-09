#include <iostream>
#include "imagem.h"

int main ( ) {
  int dimensao;
  std::cout << "Qual a dimensao da imagem: ";
  std::cin >> dimensao;

  // Inicializacao das imagens do programa
  Imagem img1 = Imagem(dimensao);
  Imagem img2 = Imagem(dimensao);
  Imagem imgSomada = Imagem(dimensao);
  Imagem imgSubtraida = Imagem(dimensao);
  Imagem imgInvertida = Imagem(dimensao);

  // Leitura de imagens
  img1.leImagem(); // Le uma imagem quadrada em escala de cinza (uma matriz de inteiros nxn)
  img2.leImagem(); // Le uma segunda imagem

  // Somando duas imagens
  img1.soma (img2, imgSomada); // imgSomada = img1 + img2
  std::cout << "Imagem Somada :" << std::endl;
  imgSomada.imprimeImagem(); // Exibe a imagem resultante da soma

  // Subtraindo duas imagens
  img1.subtrai(img2, imgSubtraida); // imgSubtraida = img1 - img2
  std::cout << "Imagem Subtraida :" << std::endl;
  imgSubtraida.imprimeImagem(); // Exibe a imagem resultante da subtracao

  // Invertendo uma imagem
  img1.inverteImagem(); // Inverte os pixels da img1
  std::cout << "Imagem 1 invertida :" << std::endl;
  img1.imprimeImagem(); // Exibe a imagem invertida

  // Comparando duas imagens
  if(img1.compara(img2)){
    std::cout << "Imagens iguais." << std::endl;
  } else {
    std::cout << "Imagens diferentes." << std::endl;
  }

  // Criando uma imagem preta
  Imagem imgPreta = Imagem(5) ; // Cria uma imagem preta de dimensao 5x5
  std :: cout << " Imagem Preta :" << std :: endl ;
  imgPreta.imprimeImagem () ; // Exibe a imagem preta
  imgPreta.adicionaBorda () ; // Adiciona borda na imagem preta ( novo tamanho = > 9x9)
  std :: cout << " Imagem Preta com Borda :" << std :: endl ;
  imgPreta.imprimeImagem () ; // Exibe a imagem preta com borda

  // Criando uma imagem branca
  Imagem imgBranca = Imagem(5) ; // Cria uma imagem preta de dimensao 5x5
  imgBranca.inverteImagem () ; // Inverte os pixels da imagem preta , tornando -os brancos
  std :: cout << " Imagem Branca :" << std :: endl ;
  imgBranca.imprimeImagem () ; // Exibe a imagem branca
  imgBranca.adicionaBorda () ; // Adiciona borda na imagem branca ( novo tamanho = > 7x7)
  std :: cout << " Imagem Branca com Borda :" << std :: endl ;
  imgBranca.imprimeImagem () ; // Exibe a imagem branca com borda

  return 0;
}