class Imagem {
  private: 
    //Dados
    int _dimensao;
    int **_matriz;

  public:
    //Constructor
    Imagem(int dimensao);

    //Destructor
    ~Imagem();

    //Procedimentos
    void leImagem();
    void soma(Imagem &img2, Imagem &imgResultante);
    void subtrai(Imagem &img2, Imagem &imgResultante);
    void inverteImagem();
    bool compara(Imagem &img2);
    void imprimeImagem();
    void adicionaBorda();
    void criaImagemPreta();
};