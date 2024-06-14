// Variáveis
//--------------------------
#pragma region Variáveis
int ledVermelho = 2;  //Pino LED Vermelho
int ledAmarelo = 3;   //Pino LED Amarelo
int ledVerde = 4;     //Pino LED Verde
int ledAzul = 5;      //Pino LED Azul

int nivVermelho = 6;  //Pino Nível LED Vermelho
int nivAmarelo = 7;   //Pino Nível LED Amarelo
int nivVerde = 8;     //Pino Nível LED Verde
int nivAzul = 9;      //Pino Nível LED Azul

int botaoVermelho = 10;  //Pino Botão LED Vermelho
int botaoAmarelo = 11;   //Pino Botão LED Amarelo
int botaoVerde = 12;     //Pino Botão LED Verde
int botaoAzul = 13;      //Pino Botão LED Azul

bool verifVermelho = false;                       //Verificando se o obstáculo Vermelho está ativo
bool verifAmarelo = false;                        //Verificando se o obstáculo Amarelo está ativo
bool verifVerde = false;                          //Verificando se o obstáculo Verde está ativo
bool verifAzul = false;                           //Verificando se o obstáculo Azul está ativo
int verifLed;                                     //Armazena qual sequência de LEDS estará ativo naquele momento

int nivel = 0;                                    //Controla os níveis
int ponto = -1;                                   //Controla a quantidade de pontos
unsigned long tempBotao;                          //Usado como parâmetro para calcular o tempo de intervalo entre os obstáculos

int pontosPinos[6] = { A0, A1, A2, A3, A4, A5 };  //Criando uma lista com os seis pinos analógicos
int pontosValores[3][6] = {                       //Matriz para expor no display os números de 1 a 3
  { 1, 0, 0, 1, 1, 1 },                           //Desenha o número 1
  { 0, 0, 1, 0, 0, 0 },                           //Desenha o número 2
  { 0, 0, 0, 0, 1, 0 }                            //Desenha o número 3
};

#pragma endregion
//--------------------------

// Inicialização
//--------------------------
#pragma region Inicialização
void setup() {
  for (int x = 2; x <= 9; x++) {  //Definindo os pinos 2, 3, 4, 5, 6, 7, 8 e 9 como saída
    pinMode(x, OUTPUT);           //A cada iteração, atualiza o próximo pino
  }

  for (int x = 0; x <= 5; x++) {      //Definindo os pinos A0, A1, A2, A3, A4, A5 como saída
    pinMode(pontosPinos[x], OUTPUT);  //A cada iteração, atualiza o próximo pino
  }

  pinMode(botaoVermelho, INPUT_PULLUP);  //Definindo o pino 10 como entrada
  pinMode(botaoAmarelo, INPUT_PULLUP);   //Definindo o pino 11 como entrada
  pinMode(botaoVerde, INPUT_PULLUP);     //Definindo o pino 12 como entrada
  pinMode(botaoAzul, INPUT_PULLUP);      //Definindo o pino 13 como entrada

  digitalWrite(A0, HIGH);  //Pino A0 -> 1
  digitalWrite(A1, HIGH);  //Pino A1 -> 1
  digitalWrite(A2, HIGH);  //Pino A2 -> 1
  digitalWrite(A3, HIGH);  //Pino A3 -> 1
  digitalWrite(A4, HIGH);  //Pino A4 -> 1
  digitalWrite(A5, HIGH);  //Pino A5 -> 1
}
#pragma endregion
//--------------------------

// Execução
//--------------------------
#pragma region Execução
void loop() {
  if (!digitalRead(botaoVermelho)) {  //Bloco que verifica a colisão o obstáculo Vermelho
    tempBotao = millis();             //Captura o tempo atual de milisegundos (usado para calcular o tempo de intervalo entre cada obstáculo)
    verifLed = 1;                     //Define qual a sequência de LEDS que devem ser acesos
    verifVermelho = true;             //Avisa para o sistema que os LEDS Vermelhos estão ativos
  }

  else if (!digitalRead(botaoAmarelo)) {  //Bloco que verifica a colisão o obstáculo Amarelo
    tempBotao = millis();                 //Captura o tempo atual de milisegundos (usado para calcular o tempo de intervalo entre cada obstáculo)
    verifLed = 2;                         //Define qual a sequência de LEDS que devem ser acesos
    verifAmarelo = true;                  //Avisa para o sistema que os LEDS Amarelos estão ativos
  }

  else if (!digitalRead(botaoVerde)) {  //Bloco que verifica a colisão o obstáculo Verde
    tempBotao = millis();               //Captura o tempo atual de milisegundos (usado para calcular o tempo de intervalo entre cada obstáculo)
    verifLed = 3;                       //Define qual a sequência de LEDS que devem ser acesos
    verifVerde = true;                  //Avisa para o sistema que os LEDS Verdes estão ativos
  }

  else if (!digitalRead(botaoAzul)) {  //Bloco que verifica a colisão o obstáculo Azul
    tempBotao = millis();              //Captura o tempo atual de milisegundos (usado para calcular o tempo de intervalo entre cada obstáculo)
    verifLed = 4;                      //Define qual a sequência de LEDS que devem ser acesos
    verifAzul = true;                  //Avisa para o sistema que os LEDS Azuis estão ativos
  }


  switch (verifLed) {                   //Comanda qual LED deve ser aceso & Sequência de desligamento
    case 1:                             //Caso 1, acende os LEDS Vermelhos
      digitalWrite(ledVermelho, HIGH);  //Pino 2 -> 1
      break;                            //Saindo do switch case
    case 2:                             //Caso 2, acende os LEDS Amarelos
      digitalWrite(ledAmarelo, HIGH);   //Pino 3 -> 1
      break;                            //Saindo do switch case
    case 3:                             //Caso 3, acende os LEDS Verdes
      digitalWrite(ledVerde, HIGH);     // Pino 4 -> 1
      break;                            //Saindo do switch case
    case 4:                             //Caso 4, acende os LEDS Azuis
      digitalWrite(ledAzul, HIGH);      //Pino 5 -> 1
      break;                            //Saindo do switch case
    case 5:                             //Caso 5, sequência de desligamento
      digitalWrite(ledVermelho, LOW);   //Pino 2 -> 0
      digitalWrite(ledAmarelo, LOW);    //Pino 3 -> 0
      digitalWrite(ledVerde, LOW);      //Pino 4 -> 0
      digitalWrite(ledAzul, LOW);       //Pino 5 -> 0
      verifVermelho = false;            //Desativando o obstáculo Vermelho
      verifAmarelo = false;             //Desativando o obstáculo Amarelo
      verifVerde = false;               //Desativando o obstáculo Verde
      verifAzul = false;                //Desativando o obstáculo Azul
      break;                            //Saindo do switch case
    default:                            //Caso padrão
      break;                            //Saindo do switch case
  }


  if ((millis() - tempBotao) > 5000) {  //Verificando se passa do tempo de intervalo
    verifLed = 5;                       //Iniciando sequência de desligamento
  }


  if ((verifVermelho) && (verifAmarelo) && (verifVerde) && (verifAzul)) {  //Verificando se todos os LEDS estão ativos
    nivel += 1;                                                            //Passando de nível
    verifLed = 5;                                                          //Após a exibição do nível, chamando a sequência de desligamento

    delay(500);  //Esperando 0,5 segundo

    for (int x = 1; x <= 3; x++) {      //Animação para quando todos os LEDS estarem acesos
      digitalWrite(ledVermelho, LOW);   //Pino 2 -> 0
      digitalWrite(ledAmarelo, LOW);    //Pino 3 -> 0
      digitalWrite(ledVerde, LOW);      //Pino 4 -> 0
      digitalWrite(ledAzul, LOW);       //Pino 5 -> 0
      delay(250);                       //Esperando 0,25 segundos
      digitalWrite(ledVermelho, HIGH);  //Pino 2 -> 1
      digitalWrite(ledAmarelo, HIGH);   //Pino 3 -> 1
      digitalWrite(ledVerde, HIGH);     //Pino 4 -> 1
      digitalWrite(ledAzul, HIGH);      //Pino 5 -> 1
      delay(250);                       //Esperando 0,25 segundos
    }

    if (nivel <= 4) {                     //Limitando para o total de quatro níveis
      for (int x = 1; x <= nivel; x++) {  //A variável "nivel" define quantas vezes o ciclo deve acontecer (nivel = 1 -> Pino 6, nivel = 2 -> Pino 7, nivel = 3 -> Pino 8, nivel = 4 -> Pino 9)
        digitalWrite((5 + x), HIGH);      //Pino 6 -> 1, Pino 7 -> 1, Pino 8 -> 1, Pino 9 -> 1
      }
    }

    if (nivel >= 4) {                    //Chegando ao nível máximo (4),após uma animação, os LEDS dos níveis apagam
      for (int x = 0; x < nivel; x++) {  //A variável "nivel" define quantas vezes o ciclo deve acontecer (nivel = 1 -> Pino 6, nivel = 2 -> Pino 7, nivel = 3 -> Pino 8, nivel = 4 -> Pino 9)
        delay(500);                      //Esperando 0,5 segundo
        digitalWrite((6 + x), LOW);      //Pino 6 -> 0, Pino 7 -> 0, Pino 8 -> 0, Pino 9 -> 0
        delay(500);                      //Esperando 0,5 segundo
        digitalWrite((6 + x), HIGH);     //Pino 6 -> 1, Pino 7 -> 1, Pino 8 -> 1, Pino 9 -> 1
        delay(500);                      //Esperando 0,5 segundo
        digitalWrite((6 + x), LOW);      //Pino 6 -> 0, Pino 7 -> 0, Pino 8 -> 0, Pino 9 -> 0
      }

      nivel = 0;   //Reiniciam os níveis
      ponto += 1;  //Acrescenta um ponto

      for (int x = 0; x < 6; x++) {                             //Imprime no display a quantidade de pontos atual
        digitalWrite(pontosPinos[x], pontosValores[ponto][x]);  //Busca na matriz com base na quantidade de pontos (0 -> Linha 0(1), 1 -> Linha 1(2), 2 -> Linha 2(3))
      };

      if (ponto >= 2) {                     //Encerrando o jogo caso o jogador atinga os 3 pontos
        while (true) {                      //Entrando em um loop infinito, para recomeçar é preciso reiniciar o arduino
          digitalWrite(ledVermelho, HIGH);  //Pino 2 -> 1
          digitalWrite(nivVermelho, HIGH);  //Pino 6 -> 1
          digitalWrite(ledAmarelo, HIGH);   //Pino 3 -> 1
          digitalWrite(nivAmarelo, HIGH);   //Pino 7 -> 1
          digitalWrite(ledVerde, LOW);      //Pino 4 -> 0
          digitalWrite(nivVerde, LOW);      //Pino 8 -> 0
          digitalWrite(ledAzul, LOW);       //Pino 5 -> 0
          digitalWrite(nivAzul, LOW);       //Pino 9 -> 0
          delay(500);                       //Esperando 0,5 segundo
          digitalWrite(ledVermelho, LOW);   //Pino 2 -> 0
          digitalWrite(nivVermelho, LOW);   //Pino 6 -> 0
          digitalWrite(ledAmarelo, LOW);    //Pino 3 -> 0
          digitalWrite(nivAmarelo, LOW);    //Pino 7 -> 0
          digitalWrite(ledVerde, HIGH);     //Pino 4 -> 1
          digitalWrite(nivVerde, HIGH);     //Pino 8 -> 1
          digitalWrite(ledAzul, HIGH);      //Pino 5 -> 1
          digitalWrite(nivAzul, HIGH);      //Pino 9 -> 1
          delay(500);                       //Esperando 0,5 segundo
        }
      }
    }
  }
}
#pragma endregion
//--------------------------