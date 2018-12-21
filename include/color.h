#ifndef color_h
#define color_h
#define QTD_CORES 6
/*Cores (caracteres) enumeradas*/
typedef enum {
    /*R = Red = Vermelho*/
    /*G = Green = Verde*/
    /*B = Blue = Azul*/
    /*Y = Yellow = Amarelo*/
    /*P = Purple = Roxo*/
    /*W = White = Branco*/
    R = 0, G, B, Y, P, W
} Cores;

/**
 * Recebe um valor enum do tipo Cores e retorna o caractere da cor correspondente
 * @param a Enum que recebe o número da cor
 * @return Caractere da cor
 */
char coresToChar(Cores a);

#endif
