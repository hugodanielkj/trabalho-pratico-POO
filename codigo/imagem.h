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
    void soma();
    void subtrai();
    void inverteImagem();
    bool compara();
    void imprimeImagem();
    void adicionaBorda();
};