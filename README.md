# Caso 4
## Patrones visuales de pintado

### Explicación de Algoritmo

El objetivo del algoritmo es crear círculos concéntricos basándose en el radio inicial. Por cada iteración donde se crea un circulo nuevo, el radio disminuye por 1 y así crear el patrón del efecto visual. Se utiliza el algoritmo de Bersenham para crear los círculos, de esta manera se aprovecha la simetría y el hecho de que un circulo tiene 8 octantes de 45 grados. Se calculan las coordenadas de los pixeles de un solo octante y con eso se puede ubicar pixeles en el resto de los octantes. La exactitud de los pixeles de los círculos concéntricos crea de manera colateral espacios donde no se ubican pixeles, formando los patrones observados.
