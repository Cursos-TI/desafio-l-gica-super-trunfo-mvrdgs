#include <stdio.h>

typedef struct {
    char state[2];
    char cardID[3];
    char city[30];
    int population;
    int touristAttractionNumber;
    float area;
    float pib;
    float populationalDensity;
    float pibPerCapita;
    float superPower;
} Card;

Card createCard(int cardNumber) {
    Card card;

    printf("\nDigite as informações da %dª carta", cardNumber);

    printf("\nDigite a letra do Estado: ");
    scanf("%s", card.state);

    printf("Digite o Código da Carta: ");
    scanf("%s", card.cardID);

    printf("Digite o Nome da Cidade: ");
    scanf("%s", card.city);

    printf("Digite a Área: ");
    scanf("%f", &card.area);

    printf("Digite a População: ");
    scanf("%d", &card.population);

    printf("Digite o PIB: ");
    scanf("%f", &card.pib);

    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &card.touristAttractionNumber);

    getchar();

    card.populationalDensity = card.population / card.area;
    card.pibPerCapita = card.pib / card.population;
    card.superPower = card.area + card.population + card.pib + card.touristAttractionNumber;

    return card;
};

void printCard(Card card) {
    printf("\nEstado: %s\n", card.state);
    printf("Código da Carta: %s\n", card.cardID);
    printf("Nome da Cidade: %s\n", card.city);
    printf("População: %d\n", card.population);
    printf("Área: %.2f km²\n", card.area);
    printf("PIB: %.2f bilhões de reais\n", card.pib);
    printf("Número de Pontos Turísticos: %d\n", card.touristAttractionNumber);
    printf("Densidade populacional: %f\n", card.populationalDensity);
    printf("PIB per Capita: %f\n", card.pibPerCapita);
    printf("Super Poder: %f\n", card.superPower);
}

void compareCards(Card card1, Card card2) {
    Card winner;

    winner = (card1.population > card2.population) ? card1 : card2;
    printf("\nEstado: %s, Código da Carta: %s, Nome da Cidade: %s, População: %d habitantes", card1.state, card1.cardID, card1.city, card1.population);
    printf("\nEstado: %s, Código da Carta: %s, Nome da Cidade: %s, População: %d habitantes", card2.state, card2.cardID, card2.city, card2.population);
    printf("\nA população da cidade %s é maior: %d habitantes\n", winner.city, winner.population);
    
    winner = (card1.area > card2.area) ? card1 : card2;
    printf("\nEstado: %s, Código da Carta: %s, Nome da Cidade: %s, Área: %fkm²", card1.state, card1.cardID, card1.city, card1.area);
    printf("\nEstado: %s, Código da Carta: %s, Nome da Cidade: %s, Área: %fkm²", card2.state, card2.cardID, card2.city, card2.area);
    printf("\nA área da cidade %s é maior: %f km²\n", winner.city, winner.area);
    
    winner = (card1.pib > card2.pib) ? card1 : card2;
    printf("\nEstado: %s, Código da Carta: %s, Nome da Cidade: %s, PIB: %f", card1.state, card1.cardID, card1.city, card1.pib);
    printf("\nEstado: %s, Código da Carta: %s, Nome da Cidade: %s, PIB: %f", card2.state, card2.cardID, card2.city, card2.pib);
    printf("\nO PIB da cidade %s é maior: %f\n", winner.city, winner.pib);
    
    winner = (card1.touristAttractionNumber > card2.touristAttractionNumber) ? card1 : card2;
    printf("\nEstado: %s, Código da Carta: %s, Nome da Cidade: %s, Atrações turísticas: %d", card1.state, card1.cardID, card1.city, card1.touristAttractionNumber);
    printf("\nEstado: %s, Código da Carta: %s, Nome da Cidade: %s, Atrações turísticas: %d", card2.state, card2.cardID, card2.city, card2.touristAttractionNumber);
    printf("\nO número de atrações turísticas da cidade %s é maior: %d\n", winner.city, winner.touristAttractionNumber);
    
    winner = (card1.populationalDensity < card2.populationalDensity) ? card1 : card2;
    printf("\nEstado: %s, Código da Carta: %s, Nome da Cidade: %s, Densidade populacional: %f", card1.state, card1.cardID, card1.city, card1.populationalDensity);
    printf("\nEstado: %s, Código da Carta: %s, Nome da Cidade: %s, Densidade populacional: %f", card2.state, card2.cardID, card2.city, card2.populationalDensity);
    printf("\nA densidade populacional da cidade %s é menor: %f\n", winner.city, winner.populationalDensity);
    
    winner = (card1.pibPerCapita > card2.pibPerCapita) ? card1 : card2;
    printf("\nEstado: %s, Código da Carta: %s, Nome da Cidade: %s, PIB per capita: %f", card1.state, card1.cardID, card1.city, card1.pibPerCapita);
    printf("\nEstado: %s, Código da Carta: %s, Nome da Cidade: %s, PIB per capita: %f", card2.state, card2.cardID, card2.city, card2.pibPerCapita);
    printf("\nO PIB per capita da cidade %s é maior: %f\n", winner.city, winner.pibPerCapita);
    
    winner = (card1.superPower > card2.superPower) ? card1 : card2;
    printf("\nEstado: %s, Código da Carta: %s, Nome da Cidade: %s, Super Poder: %f", card1.state, card1.cardID, card1.city, card1.superPower);
    printf("\nEstado: %s, Código da Carta: %s, Nome da Cidade: %s, Super Poder: %f", card2.state, card2.cardID, card2.city, card2.superPower);
    printf("\nO Super Poder da cidade %s é maior: %f\n", winner.city, winner.superPower);
}

int main() {
    Card card1 = createCard(1);
    printCard(card1);

    Card card2 = createCard(2);
    printCard(card2);

    compareCards(card1, card2);
    
    return 0;
}
