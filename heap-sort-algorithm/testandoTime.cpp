#include <stdio.h>
#include <time.h>

void take_enter() {
   printf("Press enter to stop the counter\n");
   while (getchar() != '\n') {
      // Aguarda até que o Enter seja pressionado
   }
}

int main() {
   struct timespec start, end;

   // Captura o tempo de início
   clock_gettime(CLOCK_MONOTONIC, &start);

   printf("Timer starts\n");
   take_enter();
   printf("Timer ends\n");

   // Captura o tempo de término
   clock_gettime(CLOCK_MONOTONIC, &end);

   // Calcula o tempo em milissegundos
   long seconds = end.tv_sec - start.tv_sec;
   long nanoseconds = end.tv_nsec - start.tv_nsec;
   double elapsed_ms = (seconds * 1000.0) + (nanoseconds / 1000000.0);

   printf("The program took %.0f ms to execute\n", elapsed_ms);

   return 0;
}
