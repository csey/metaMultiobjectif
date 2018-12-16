#include <stdio.h>
int main(void)
{

  FILE * f;
  // Ouverture du shell et lancement de gnuplot
  f = popen("gnuplot", "w");

  // exécution de la commande gnuplot
  //fprintf(f, " set term dumb \n");
  fprintf(f, " set xrange [-10 : 10] \n");
  fprintf(f, " set yrange [-10 : 10] \n");
  fprintf(f, " set title \"MOP 1: Kim\" \n");
  fprintf(f, " set xlabel \" z1 \" \n");
  fprintf(f, " set ylabel \" z2 \" \n");
  fprintf(f, " plot \"kim.dat\" using 4:5 notitle with points lt -1 linewidth 2\n");
  fprintf(f, " replot \"kimYN.dat\" using 4:5 notitle with dots lt rgb \"green\" \n");
  fprintf(f, " replot \"kimyns.dat\" using 4:5 notitle with dots lt rgb \"red\" \n");
  fflush(f);
  // terminer l'envoi de commandes et fermer gnuplot
  sleep(60);
  pclose(f);
}
