#include <iostream>
#include "imagem.h"

int main ( ) {
  int dimensao;
  std::cout << "Qual a dimensao da imagem: "
  std::cin >> dimensao;

  Imagem img1 , img2 , imgSomada , imgSubtraida , imgInvertida , imgPreta , imgBranca ;

  // Inicializacao das imagens do programa
  Imagem img1 = Imagem(_dimensao);
  Imagem img2 = Imagem(_dimensao);
  Imagem imgSomada = Imagem(_dimensao);
  Imagem imgSubtraida = Imagem(_dimensao);
  Imagem imgInvertida = Imagem(_dimensao);
  Imagem imgPreta = Imagem(_dimensao);
  Imagem imgBranca = Imagem(_dimensao);

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
  criaImagemPreta (5 , imgPreta ) ; // Cria uma imagem preta de dimensao 5x5
  std :: cout << " Imagem Preta :" << std :: endl ;
  imprimeImagem ( imgPreta ) ; // Exibe a imagem preta
  adicionaBorda ( imgPreta ) ; // Adiciona borda na imagem preta ( novo tamanho = > 9x9)
  std :: cout << " Imagem Preta com Borda :" << std :: endl ;
  imprimeImagem ( imgPreta ) ; // Exibe a imagem preta com borda

  // Criando uma imagem branca
  criaImagemPreta (5 , imgBranca ) ; // Cria uma imagem preta de dimensao 5x5
  inverteImagem ( imgBranca ) ; // Inverte os pixels da imagem preta , tornando -os brancos
  std :: cout << " Imagem Branca :" << std :: endl ;
  imprimeImagem ( imgBranca ) ; // Exibe a imagem branca
  adicionaBorda ( imgBranca ) ; // Adiciona borda na imagem branca ( novo tamanho = > 7x7)
  std :: cout << " Imagem Branca com Borda :" << std :: endl ;
  imprimeImagem ( imgBranca ) ; // Exibe a imagem branca com borda

  return 0;
}