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

typedef struct {
    float attributeCard1;
    float attributeCard2;
} ComparisonResult;

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

    printf("\n");

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

ComparisonResult comparePopulation(Card card1, Card card2) {
    printf("\nEstado: %s, Código da Carta: %s, Nome da Cidade: %s, População: %d habitantes", card1.state, card1.cardID, card1.city, card1.population);
    printf("\nEstado: %s, Código da Carta: %s, Nome da Cidade: %s, População: %d habitantes", card2.state, card2.cardID, card2.city, card2.population);

    if (card1.population == card2.population) {
        printf("Empate!\n");
    } else {
        Card winner = (card1.population > card2.population) ? card1 : card2;
        printf("\nA população da cidade %s é maior: %d habitantes\n", winner.city, winner.population);
    }

    return (ComparisonResult) { 
        attributeCard1: card1.population, 
        attributeCard2: card2.population 
    };
}

ComparisonResult compareArea(Card card1, Card card2) {
    printf("\nEstado: %s, Código da Carta: %s, Nome da Cidade: %s, Área: %fkm²", card1.state, card1.cardID, card1.city, card1.area);
    printf("\nEstado: %s, Código da Carta: %s, Nome da Cidade: %s, Área: %fkm²", card2.state, card2.cardID, card2.city, card2.area);

    if (card1.area == card2.area) {
        printf("Empate!\n");
    } else {
        Card winner = (card1.area > card2.area) ? card1 : card2;
        printf("\nA área da cidade %s é maior: %f km²\n", winner.city, winner.area);
    }

    return (ComparisonResult) { 
        attributeCard1: card1.area, 
        attributeCard2: card2.area 
    };
}

ComparisonResult comparePib(Card card1, Card card2) {
    printf("\nEstado: %s, Código da Carta: %s, Nome da Cidade: %s, PIB: %f bilhões de reais", card1.state, card1.cardID, card1.city, card1.pib);
    printf("\nEstado: %s, Código da Carta: %s, Nome da Cidade: %s, PIB: %f bilhões de reais", card2.state, card2.cardID, card2.city, card2.pib);

    if (card1.pib == card2.pib) {
        printf("Empate!\n");
    } else {
        Card winner = (card1.pib > card2.pib) ? card1 : card2;
        printf("\nO PIB da cidade %s é maior: %f bilhões de reais\n", winner.city, winner.pib);
    }

    return (ComparisonResult) { 
        attributeCard1: card1.pib, 
        attributeCard2: card2.pib 
    };
}

ComparisonResult compareTouristAttraction(Card card1, Card card2) {
    printf("\nEstado: %s, Código da Carta: %s, Nome da Cidade: %s, Atrações turísticas: %d", card1.state, card1.cardID, card1.city, card1.touristAttractionNumber);
    printf("\nEstado: %s, Código da Carta: %s, Nome da Cidade: %s, Atrações turísticas: %d", card2.state, card2.cardID, card2.city, card2.touristAttractionNumber);

    if (card1.touristAttractionNumber == card2.touristAttractionNumber) {
        printf("Empate!\n");
    } else {
        Card winner = (card1.touristAttractionNumber > card2.touristAttractionNumber) ? card1 : card2;
        printf("\nO número de atrações turísticas da cidade %s é maior: %d\n", winner.city, winner.touristAttractionNumber);
    }

    return (ComparisonResult) { 
        attributeCard1: card1.touristAttractionNumber, 
        attributeCard2: card2.touristAttractionNumber 
    };
}

ComparisonResult comparePopulationalDensity(Card card1, Card card2) {
    printf("\nEstado: %s, Código da Carta: %s, Nome da Cidade: %s, Densidade populacional: %f", card1.state, card1.cardID, card1.city, card1.populationalDensity);
    printf("\nEstado: %s, Código da Carta: %s, Nome da Cidade: %s, Densidade populacional: %f", card2.state, card2.cardID, card2.city, card2.populationalDensity);

    if (card1.populationalDensity == card2.populationalDensity) {
        printf("Empate!\n");
    } else {
        Card winner = (card1.populationalDensity < card2.populationalDensity) ? card1 : card2;
        printf("\nA densidade populacional da cidade %s é maior: %f\n", winner.city, winner.populationalDensity);
    }

    return (ComparisonResult) { 
        attributeCard1: card1.populationalDensity, 
        attributeCard2: card2.populationalDensity 
    };
}

ComparisonResult comparePibPerCapita(Card card1, Card card2) {
    printf("\nEstado: %s, Código da Carta: %s, Nome da Cidade: %s, PIB per capita: %f", card1.state, card1.cardID, card1.city, card1.pibPerCapita);
    printf("\nEstado: %s, Código da Carta: %s, Nome da Cidade: %s, PIB per capita: %f", card2.state, card2.cardID, card2.city, card2.pibPerCapita);

    if (card1.pibPerCapita == card2.pibPerCapita) {
        printf("Empate!\n");
    } else {
        Card winner = (card1.pibPerCapita > card2.pibPerCapita) ? card1 : card2;
        printf("\nO PIB per capita da cidade %s é maior: %f\n", winner.city, winner.pibPerCapita);
    }

    return (ComparisonResult) { 
        attributeCard1: card1.pibPerCapita, 
        attributeCard2: card2.pibPerCapita 
    };
}

ComparisonResult compareSuperPower(Card card1, Card card2) {
    printf("\nEstado: %s, Código da Carta: %s, Nome da Cidade: %s, Super Poder: %f", card1.state, card1.cardID, card1.city, card1.superPower);
    printf("\nEstado: %s, Código da Carta: %s, Nome da Cidade: %s, Super Poder: %f", card2.state, card2.cardID, card2.city, card2.superPower);

    if (card1.superPower == card2.superPower) {
        printf("Empate!\n");
    } else {
        Card winner = (card1.superPower > card2.superPower) ? card1 : card2;
        printf("\nO Super Poder da cidade %s é maior: %f\n", winner.city, winner.superPower);
    }

    return (ComparisonResult) { 
        attributeCard1: card1.superPower, 
        attributeCard2: card2.superPower 
    };
}

void compareTwoAttributes(Card card1, Card card2, ComparisonResult* comparisonResult) {
    printf("\nComparando soma dos dois atributos:\n");

    float card1Sum = comparisonResult[0].attributeCard1 + comparisonResult[1].attributeCard1;
    float card2Sum = comparisonResult[0].attributeCard2 + comparisonResult[1].attributeCard2;
    if (card1Sum == card2Sum) {
        printf("Empate!\n");
    } else {
        Card winner = (card1Sum > card2Sum) ? card1 : card2;
        printf("\nA soma dos atributos da cidade %s é maior: %f\n", winner.city, (card1Sum > card2Sum) ? card1Sum : card2Sum);
    }
}

int* chooseOption(int numberOfInteractions) {
    int* result = (int*)malloc(numberOfInteractions * sizeof(int));

    for (int i = 0; i < numberOfInteractions; i++) {
        int option;

        printf("Insira o resultado da interação %d: ", i + 1);
        printf("\nEscolha a característica para comparar:\n");
        printf("1 - População\n");
        printf("2 - Área\n");
        printf("3 - PIB\n");
        printf("4 - Número de Pontos Turísticos\n");
        printf("5 - Densidade populacional\n");
        printf("6 - PIB per Capita\n");
        printf("7 - Super Poder\n");
        scanf("%d", &option);

        for (int j = 0; j < i; j++) {
            if (result[j] == option) {
                printf("\nOpção já inserida, por favor insira outra opção.\n\n");
                i--;
                break;
            }
        }

        result[i] = option;
    }

    return result;
}

ComparisonResult compareCards(Card card1, Card card2, int option) {
    if (card1.superPower == 0 || card2.superPower == 0) {
        printf("Uma ou ambas as cartas não foram cadastradas!\n");
        return;
    }

    switch(option) {
        case 1:
            return comparePopulation(card1, card2);
        case 2:
            return compareArea(card1, card2);
        case 3:
            return comparePib(card1, card2);
        case 4:
            return compareTouristAttraction(card1, card2);
        case 5:
            return comparePopulationalDensity(card1, card2);
        case 6:
            return comparePibPerCapita(card1, card2);
        case 7:
            return compareSuperPower(card1, card2);
        default:
            printf("Opção inválida");
            return (ComparisonResult) { 
                attributeCard1: 0, 
                attributeCard2: 0 
            };
    }
}

void runGame(Card card1, Card card2, int interactionNumber) {
    int* options;
    options = chooseOption(interactionNumber);
    ComparisonResult comparisonResult[interactionNumber];

    if (card1.superPower == 0 || card2.superPower == 0) {
        printf("Uma ou ambas as cartas não foram cadastradas!\n");
        return;
    }

    if (interactionNumber <= 0) {
        printf("Número de interações inválido.\n");
        return;
    }

    for (int i = 0; i < interactionNumber; i++) {
        comparisonResult[i] = compareCards(card1, card2, options[i]);
    }

    if (interactionNumber == 1) {
        return;
    }

    compareTwoAttributes(card1, card2, comparisonResult);
}

int insertOption() {
    int option;

    printf("Digite a opção desejada:\n");
    printf("1 - Cadastrar carta 1\n");
    printf("2 - Cadastrar carta 2\n");
    printf("3 - Comparar cartas\n");
    printf("4 - Comparar dois atributos cartas\n");
    printf("5 - Sair\n");
    scanf("%d", &option);

    return option;
}

int main() {
    int option;
    Card card1;
    Card card2;

    while (1) {
        option = insertOption();

        switch (option) {
            case 1:
                card1 = createCard(1);
                break;
            case 2:
                card2 = createCard(2);
                break;
            case 3:
                runGame(card1, card2, 1);
                break;
            case 4:
                runGame(card1, card2, 2);
                break;
            case 5:
                printf("Saindo do programa...\n");
                return 0;
            default:
                printf("Opção inválida!\n");
        }
    }
    
    return 0;
}
