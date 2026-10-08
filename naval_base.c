#include <stdio.h>

int selection(int x, int y, int direction, int size){
    int x_r = x+1;
    int y_r = y+1;
    int op_cl = 0;
    int ordem = 5;

    while (op_cl==0){
        // 0 = CIMA
        if(direction==0){
            if(y_r-size <= ordem){
                return 1;
            }else{
                return 0;
            }

        // 1 = DIREITA
        }else if(direction==1){
            if(x_r-size <= ordem){
                return 1;
            }else{
                return 0;
            }

        // 2 = PARA BAIXO
        }else if(direction==2){
            if(y_r+size <= ordem){
                return 1;
            }else{
                return 0;
            }

        // 3 = ESQUERDA
        }else if(direction==3){
            if(x_r+size <= ordem){
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
        while (op_cl == 0){
            printf("Selecione a coordenada x, y que deseja selecionar: ");
            scanf(" %d %d", &x, &y);
            printf("Qual a direção que deseja selecionar\n (0)cima (1)direita (2)baixo (3)esquerda\n");
            scanf("%d", &direction);
            printf("Qual o tamanho da embarcação: ");
            scanf("%d", &size);

            int x_r = x+1; 
            int y_r = y+1;
            if (selection(x, y, direction, size) == 1){
                for (int l=0; l<ordem; l++){
                    for (int c=0; c<ordem; c++){
                        if (l == x_r && c == y_r){

                            if (direction == 0){
                                for (int i=0; i<size; i++){
                                    player_matrix[l+i][c] = 8;
                                }
                            }else if (direction == 1){
                                for (int i=0; i<size; i++){
                                    player_matrix[l][c-i] = 8;
                                }
                            }else if (direction == 2){
                                for (int i=0; i<size; i++){
                                    player_matrix[l-i][c] = 8;
                                }
                            }else if (direction == 3){
                                for (int i=0; i<size; i++){
                                    player_matrix[l][c+i] = 8;
                                }
                            }
                        }
                    }
                }
            }else{
                printf("\nBobao, por ai nao cabe\n");
            }
        printf("\n");
        break;
        }
    }    
}