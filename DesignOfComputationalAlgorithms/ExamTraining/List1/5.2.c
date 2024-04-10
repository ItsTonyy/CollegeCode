#include <stdio.h>

int horasMinutos(int horas, int minutos) {
  int qtdMinutos = minutos;
  int horasPraMinutos = horas * 60;
  qtdMinutos += horasPraMinutos;

  return qtdMinutos;
}

int horarioVoo(int horaPrevista, int minutoPrevisto, int horaEfetiva, int minutoEfetivo) {
  int minutosPrevistosConvertidos = horasMinutos(horaPrevista, minutoPrevisto);
  int minutosEfetivosConvertidos = horasMinutos(horaEfetiva, minutoEfetivo);

  return minutosEfetivosConvertidos - minutosPrevistosConvertidos;
}

int main() {
  int horaPrevista, minutoPrevisto, horaEfetiva, minutoEfetivo;

  printf("Insira a hora prevista de chegada: ");
  scanf("%d", &horaPrevista);

  printf("Insira o minuto previsto de chegada: ");
  scanf("%d", &minutoPrevisto);

  printf("Insira a hora efetiva de chegada: ");
  scanf("%d", &horaEfetiva);

  printf("Insira o minuto efetivo de chegada: ");
  scanf("%d", &minutoEfetivo);

  printf("A diferenca, em minutos, do tempo previsto pro tempo efetivo de chegada foi de %d minutos.", horarioVoo(horaPrevista, minutoPrevisto, horaEfetiva, minutoEfetivo));
  
  return 0;
}