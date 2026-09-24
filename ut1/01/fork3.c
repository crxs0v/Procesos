Analiza este programa fork3.c antes de ejecutarlo:
printf("Inicio\n");
pid_t pid = fork();
printf("Después del fork\n");
if (pid == 0) {
 printf("Soy el hijo\n");
} else {
 printf("Soy el padre\n");
}
printf("Fin\n");
a) ¿Cuántos procesos existen? 2
b) ¿ qué instrucciones ejecuta cada uno? El proceso padre ejecuta 
printf("Inicio\n");
pid_t pid = fork();
printf("Después del fork\n");
y entra en el else, de ahí ejecuta 
printf("Soy el padre\n");
printf("Fin\n");
El poceso hijo ejecuta 
printf("Después del fork\n");
y entra en el if, de ahí ejecuta
printf("Soy el hijo\n");
printf("Fin\n");
c) ¿cuántas veces aparece cada mensaje y qué partes de la salida pueden aparecer en distinto
orden?
  El principio antes del fork y el printf dentro del if o else solo aparece 1 vez, lo demás aparece 2 veces.
