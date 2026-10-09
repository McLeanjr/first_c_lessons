#include <stdio.h>
#include <stdlib.h>

// Função que verifica se a embarcação cabe na matriz de seleção
int selection(int x, int y, int direction, int size){
    int x_r = x;
    int y_r = y;
    int op_cl = 0;
    int ordem = 5;

    while (op_cl==0){

        // 0 = CIMA
        if(direction==0){
            if(size <= y_r){
                return 1;
            }else{
                return 0;
            }
        // 1 = DIREITA
        }else if(direction==1){
            if(size <= ordem - x_r){
                return 1;
            }else{
                return 0;
            }
        // 2 = PARA BAIXO
        }else if(direction==2){
            if(size <= ordem - y_r){
                return 1;
            }else{
                return 0;
            }
        // 3 = ESQUERDA
        }else if(direction==3){
            if(size <= x_r){
                return 1;
            }else{
                return 0;
            }
        }
    }
}


int main(){
    int ordem = 7;
    int player_matrix[ordem][ordem];
    int opp_matrix[ordem][ordem];
    int op_cl = 0;
    int x;
    int y;
    int direction;
    int size;
    int verificator;
    int n_ships = 3;

    //CRIA MATRIZ DE SELEÇÃO DO PLAYER E DO OPONENTE
    for (int l=0; l<ordem; l++){
        for (int c=0; c<ordem; c++){
            if (l==0 && c!= 0 && c!= 1){
                player_matrix[l][c] = c-1;
                opp_matrix[l][c] = c-1;
            } 
            else if (l==1 && c!=0 && c!=1){
                player_matrix[l][c] = 9;
                opp_matrix[l][c] = 9;
            }
            else if (c==0 && l!=0 && l!=1){
                player_matrix[l][c] = l-1;
                opp_matrix[l][c] = l-1;
            }
            else if (c==1 && l!=0 && l!=1){
                player_matrix[l][c] = 9;
                opp_matrix[l][c] = 9;
            }
            else if (c<2 && l<2){
                player_matrix[l][c] = 9;
                opp_matrix[l][c] = 9;
            }
            else{
                player_matrix[l][c] = 0;
                opp_matrix[l][c] = 0;
            }
        }
    }

    // TRANFORMA OS ELEMENTOS INTEIROS 9 DA MATRIZ PARA MELHOR VISUALIZAÇÃO DO JOGADOR
    while (op_cl == 0){
        printf("Seu jogo!!\n");
        for (int l=0; l<ordem; l++){
            for (int c=0; c<ordem; c++){
                if (player_matrix[l][c] == 9){
                    printf("  ");
                }else{    
                    printf("%d ", player_matrix[l][c]);
                }
            }
        printf("\n");
        }

        //LOOP PARA SELEÇÃO DAS EMBARCAÇÕES PELO JOGADOR
        for (int i = 0; i<n_ships; i++){
            printf("Selecione a coordenada x, y que deseja selecionar: ");
            scanf(" %d %d", &x, &y);
            printf("Qual a direção que deseja selecionar\n (0)cima (1)direita (2)baixo (3)esquerda\n");
            scanf("%d", &direction);
            printf("Qual o tamanho da embarcação: ");
            scanf("%d", &size);

            int x_r = x+1; 
            int y_r = y+1;

            //PLAYER!!
            //SE A FUNÇÃO SELECTION RETORNAR 1, A EMBARCAÇÃO CABE NA MATRIZ, CASO CONTRÁRIO NÃO CABE
            if (selection(x, y, direction, size) == 1){

                // 0 = CIMA
                if (direction == 0){
                    for (int i=0; i<size; i++){
                        if(player_matrix[x_r-i][y_r] == 8){
                            printf("\nBobao, por ai nao cabe 2\n");
                            verificator = 1;
                        }
                    }
                    if (verificator != 1){
                        for (int i=0; i<size; i++){
                            player_matrix[x_r-i][y_r] = 8;
                        }
                    }

                // 1 = DIREITA
                }else if (direction == 1){
                    for (int i=0; i<size; i++){
                        if(player_matrix[x_r][y_r+i] == 8){
                            printf("\nBobao, por ai nao cabe 2\n");
                            verificator = 1;
                        }
                    }
                    if (verificator != 1){
                        for (int i=0; i<size; i++){
                            player_matrix[x_r][y_r+i] = 8;
                        }
                    }

                // 2 = PARA BAIXO
                }else if (direction == 2){
                    for (int i=0; i<size; i++){
                        if(player_matrix[x_r+i][y_r] == 8){
                            printf("\nBobao, por ai nao cabe 2\n");
                            verificator = 1;
                        }
                    }
                    if (verificator != 1){
                        for (int i=0; i<size; i++){
                            player_matrix[x_r+i][y_r] = 8;
                        }
                    }

                // 3 = ESQUERDA
                }else if (direction == 3){
                    for (int i=0; i<size; i++){
                        if(player_matrix[x_r][y_r-i] == 8){
                            printf("\nBobao, por ai nao cabe 2\n");
                            verificator = 1;
                        }
                    }
                    if (verificator != 1){
                        for (int i=0; i<size; i++){
                            player_matrix[x_r][y_r-i] = 8;
                        }
                    }
                }
            }else{
                printf("\nBobao, por ai nao cabe 1\n");
            }
        printf("\n");
        break;
        }
    }    
}