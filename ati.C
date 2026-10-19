#include <stdio.h>
int main() {
    int pais;
    float preco, imposto, frete, preco_final, seguro;
    printf("Digite o preço unitário do produto (ou um valor menor ou igual a zero para finalizar): ");
    scanf("%f", &preco);
    char transporte;
   
  // Loop para processar múltiplos produtos
    while (preco > 0) {
        printf("Digite o país de origem (1 - Estados Unidos; 2 - México; 3 - Outros): ");
        scanf("%d", &pais);
        printf("Digite o meio de transporte (T - terrestre; F - fluvial; A - aéreo): ");
        scanf(" %c", &transporte);
        char carga_perigosa;
        printf("O produto é carga perigosa? (S - sim; N - não): ");
        scanf(" %c", &carga_perigosa);

        // Cálculo do imposto
        if (preco <= 100) {
            imposto = preco * 0.5; // 5% para produtos com preço unitário até 100
        } else if (preco > 100) {
            imposto = preco * 0.10; // 10% para produtos com preço unitário acima de 100
        } 
       
        // Cálculo do frete
        if ( pais == 1 && carga_perigosa == 'S') {
            frete = 50; 
        } else if (pais == 2 && carga_perigosa == 'S') {
            frete = 21; 
        } else if (pais == 3 && carga_perigosa == 'S') {
            frete = 24; 
        } else if (pais == 1 && carga_perigosa == 'N') {
            frete = 12; 
        } else if (pais == 2 && carga_perigosa == 'N') {
            frete = 21; 
        } else if (pais == 3 && carga_perigosa == 'N') {
            frete = 60;
        } else {
            frete = 0;
        }
        
        // Cálculo do seguro
        if (pais == 2 || transporte == 'A') {
                seguro = preco * 0.5; // metade do preço unitário para produtos do México ou com transporte aéreo
            } else if (transporte == 'A') {
                seguro = preco * 0.5; // metade do preço unitário para produtos com transporte aéreo
            } 
        preco_final = preco + imposto + frete + seguro;
            // Exibição dos resultados
        printf("Preço unitário: %.2f\n", preco);
        printf("Imposto: %.2f\n", imposto);
        printf("Frete: %.2f\n", frete);
        printf("Seguro: %.2f\n", seguro);
        printf("Preço final: %.2f\n", preco_final);

        printf("\nDigite o preço unitário do próximo produto (ou um valor menor ou igual a zero para finalizar): ");
        scanf("%f", &preco);
    }
return 0;
}