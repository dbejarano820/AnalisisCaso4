# Caso 4
## Patrones visuales de pintado

### Explicación de Algoritmo

El objetivo del algoritmo es crear círculos concéntricos basándose en el radio inicial. Por cada iteración donde se crea un circulo nuevo, el radio disminuye por 1 y así crear el patrón del efecto visual. Se utiliza el algoritmo de Bersenham para crear los círculos, de esta manera se aprovecha la simetría y el hecho de que un circulo tiene 8 octantes de 45 grados. Se calculan las coordenadas de los pixeles de un solo octante y con eso se puede ubicar pixeles en el resto de los octantes. La exactitud de los pixeles de los círculos concéntricos crea de manera colateral espacios donde no se ubican pixeles, formando los patrones observados.

### Análisis del Core del Algoritmo

- C = cantidad de círculos por dibujar
- P = cantidad de pixeles en el primer octante del circulo
- N = cantidad de círculos por dibujar (radio del circulo más grande) * la cantidad de pixeles en el primer octante del circulo
- N = C * P

- f(n) = 29N + 9
- O(n)

### Información adicional de como correr el programa para poder pintar el patrón en processing

- En la linea 15 se debe de poner el path propio de donde se guarda el archivo puntos.txt que sea crea durante la ejecución del algoritmo. Ese archivo contiene todas las coordenadas de los pixeles para pintar el patrón.
- En consola se piden los parametros para el alto y ancho de cada canvas. Despues de ejecutar la primera prueba y antes de insertar los parametros de la segunda prueba, se debe de ir y cambiar el nombre del puntos.txt creado (le puede agregar un 1) ya que cuando corre la segunda prueba si tiene el archivo sigue con el nombre puntos.txt, lo va a sobreescribir.
- Por lo tanto cuando pega el código del output a processing para la primera prueba, tiene que modificar el path para que concuerde con el nombre del archivo que le pone.

