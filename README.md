Trabalho da materia Metodos de Programacao - 1/2017
Implementar conversao de um numero romano para algarismos arabicos, utilizando a abordagem TDD.

A pasta docs vai conter os arquivos html gerados pelo doxygen.
GitHub: https://github.com/IceVct/LaboratorioMP_NumerosRomanos

Para executar esse programa:
  1. Va na pasta principal e abra o terminal;
  2. Digite make, isso ira compilar todos os programas, executar e rodar o gcov;
  3. Depois, para verificar o cppcheck, basta ir na pasta src/ com o terminal e usar em todos os .cpp,
  menos o teste_num_romanos_main;
  4. Apesar de ja ter os arquivos do doxygen, para gera-los de novo, basta digitar no terminal doxygen Doxifile;
  5. OBS: Ignorar os warnings do Catch, e ignorar os warnings que deram na funcao teste_num_romanos.cpp em relacao ao
  uso de comparacao de valores verdadeiros ou falso sem ser com 0 ou 1, e sim com -1.

