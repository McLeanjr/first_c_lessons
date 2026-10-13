#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// Função que verifica se a embarcação cabe na matriz de seleção
int selection(int x, int y, int direction, int size, int ordem){
    int op_cl = 0;

    while (op_cl==0){

        // 0 = CIMA
        if(direction==0){
            if(size <= y){
                return 1;
            }else{
                return 0;
            }
        // 1 = DIREITA
        }else if(direction==1){
            if(size <= ordem - x + 1){
                return 1;
            }else{
                return 0;
            }
        // 2 = PARA BAIXO
        }else if(direction==2){
            if(size <= ordem - y + 1){
                return 1;
            }else{
                return 0;
            }
        // 3 = ESQUERDA
        }else if(direction==3){
            if(size <= x){
                return 1;
            }else{
                return 0;
            }
        }
    }
}

// FUNÇÃO PARA TÍTULOS
void title(char name[], int size){
    int tamanho = 0;
    while (name[tamanho] != '\0') {
        tamanho++;
    }
    for (int i=0; i<size; i++){
        printf("=");
    }
    printf("\n");
    for (int i=0; i<(size/2)-(tamanho/2); i++){
        printf(" ");
    }
    printf(name);
    printf("\n");
    for (int i=0; i<size; i++){
        printf("=");
    }    
    printf("\n");
}

int main(){

    srand(time(NULL)); 

    int op_cl = 0;
    
    int x;
    int y;
    int direction;
    int size;

    int menu;
    int verificator;
    int n_ships = 0;
    int n_m_ships;
    int sort = 0;

    //LOOP JOGO PRINCIPAL
    while (op_cl == 0){ 

        //MENU DO BATTLESHIP
        int ordem;

        title("BATTLESHIP!!", 41);
        printf("Olá Jogador\nDeseja começar/reiniciar o jogo?\n(0)SIM\n(1)NÃO\n");
        printf("-->> ");
        scanf("%d", &op_cl);

        while (op_cl == 0){
            printf("Selecione o Modo de jogo:\n(0)Fácil: Mapa de Ordem [5]\n(1)Médio: Mapa de Ordem [10]\n(2)Difícil: Mapa de Ordem [15]\n");
            printf("-->> ");
            scanf("%d", &menu);
            if (menu == 0){
                ordem = 7;
                n_ships = 2;
                n_m_ships = n_ships;
                break;
            }else if(menu == 1){
                ordem = 12;
                n_ships = 3;
                n_m_ships = n_ships;
                break;
            }else if(menu == 2){
                ordem = 17;
                n_ships = 5;
                n_m_ships = n_ships;
                break;
            }else{
                printf("Digite um valor válido!!");
            }
        }
        
        int player_matrix[ordem][ordem];
        int opp_matrix[ordem][ordem];

        //CRIA MATRIZ DE SELEÇÃO DO PLAYER E DO OPONENTE
        for (int l=0; l<ordem; l++){
            for (int c=0; c<ordem; c++){
                if (l==0 && c!= 0 && c!= 1){
                    player_matrix[l][c] = c-1;
                    opp_matrix[l][c] = c-1;
                } 
                else if (l==1 && c!=0 && c!=1){
                    player_matrix[l][c] = -1;
                    opp_matrix[l][c] = -1;
                }
                else if (c==0 && l!=0 && l!=1){
                    player_matrix[l][c] = l-1;
                    opp_matrix[l][c] = l-1;
                }
                else if (c==1 && l!=0 && l!=1){
                    player_matrix[l][c] = -1;
                    opp_matrix[l][c] = -1;
                }
                else if (c<2 && l<2){
                    player_matrix[l][c] = -1;
                    opp_matrix[l][c] = -1;
                }
                else{
                    player_matrix[l][c] = 0;
                    opp_matrix[l][c] = 0;
                }
            }
        }

        //LOOP PARA SELEÇÃO DAS EMBARCAÇÕES PELO JOGADOR
        while (n_ships != 0){

            //TRANFORMA OS ELEMENTOS INTEIROS -1 DA MATRIZ PARA MELHOR VISUALIZAÇÃO DO JOGADOR
            title("PAINEL DE POSIÇÃO", 41);
            for (int l=0; l<ordem; l++){
                for (int c=0; c<ordem; c++){
                    if (player_matrix[l][c] == -1){
                        printf("   ");
                    }else if (player_matrix[l][c] == 0){
                        printf("~   ");
                    }else if (player_matrix[l][c] == -2){
                        printf("■   ");
                    }else{    
                        printf("%02d  ", player_matrix[l][c]);
                    }
                }
            printf("\n");
            }

            //PREENCHIMENTO DAS VARIÁVEIS DE SELEÇÃO DAS EMBARCAÇÕES
            printf("Selecione a coordenada x, y que deseja selecionar: ");
            scanf(" %d %d", &x, &y);
            printf("Qual a direção que deseja selecionar\n(0)cima (1)direita (2)baixo (3)esquerda\n");
            scanf("%d", &direction);
            printf("Qual o tamanho da embarcação: ");
            scanf("%d", &size);

            int x_r = x+1; 
            int y_r = y+1;

            //SE A FUNÇÃO SELECTION RETORNAR 1, A EMBARCAÇÃO CABE NA MATRIZ, CASO CONTRÁRIO NÃO CABE
            if (selection(x, y, direction, size, ordem) == 1){

                // 0 = CIMA
                if (direction == 0){
                    for (int i=0; i<size; i++){
                        if(player_matrix[y_r-i][x_r] == -2){
                            printf("\nColisão de Embarcações\nDigite novamente!!\n");
                            verificator = 1;
                        }
                    }
                    if (verificator != 1){
                        for (int i=0; i<size; i++){
                            player_matrix[y_r-i][x_r] = -2;
                        }
                        n_ships -= 1;                       
                    }
                    verificator = 0;

                // 1 = DIREITA
                }else if (direction == 1){
                    for (int i=0; i<size; i++){
                        if(player_matrix[y_r][x_r+i] == -2){
                            printf("\nColisão de Embarcações\nDigite novamente!!\n");
                            verificator = 1;
                        }
                    }
                    if (verificator != 1){
                        for (int i=0; i<size; i++){
                            player_matrix[y_r][x_r+i] = -2;
                        }
                        n_ships -= 1;
                    }
                    verificator = 0;

                // 2 = PARA BAIXO
                }else if (direction == 2){
                    for (int i=0; i<size; i++){
                        if(player_matrix[y_r-i][x_r] == -2){
                            printf("\nColisão de Embarcações\nDigite novamente!!\n");
                            verificator = 1;
                        }
                    }
                    if (verificator != 1){
                        for (int i=0; i<size; i++){
                            player_matrix[y_r+i][x_r] = -2;
                        }
                        n_ships -= 1;
                    }
                    verificator = 0;

                // 3 = ESQUERDA
                }else if (direction == 3){
                    for (int i=0; i<size; i++){
                        if(player_matrix[y_r][x_r-i] == -2){
                            printf("\nColisão de Embarcações\nDigite novamente!!\n");
                            verificator = 1;
                        }
                    }
                    if (verificator != 1){
                        for (int i=0; i<size; i++){
                            player_matrix[y_r][x_r-i] = -2;
                        }
                        n_ships -= 1;
                    }
                    verificator = 0;

                }
            }else{
                printf("\nEmbarcação além do tamanho permitido!!\nDigite novamente!!\n");
            }  
        }

        //RETOMA PARA O NUMERO DE EMBARCAÇÕES
        n_ships = n_m_ships;

        //LOOP PARA SELEÇÃO DAS EMBARCAÇÕES PELO OPONENTE
        while (n_ships != 0){

            //PREENCHIMENTO DAS VARIÁVEIS DE SELEÇÃO DAS EMBARCAÇÕES
            x = (rand() % (ordem - 2)) + 1;
            y = (rand() % (ordem - 2)) + 1;
            direction = (rand() % 4);
            size = (rand() % (ordem - 2)) + 2;

            int x_r = x+1; 
            int y_r = y+1;

            //SE A FUNÇÃO SELECTION RETORNAR 1, A EMBARCAÇÃO CABE NA MATRIZ, CASO CONTRÁRIO NÃO CABE
            if (selection(x, y, direction, size, ordem) == 1){

                // 0 = CIMA
                if (direction == 0){
                    for (int i=0; i<size; i++){
                        if(opp_matrix[y_r-i][x_r] == -2){
                            verificator = 1;
                        }
                    }
                    if (verificator != 1){
                        for (int i=0; i<size; i++){
                            opp_matrix[y_r-i][x_r] = -2;
                        }
                        n_ships -= 1;
//                        usleep(1000000);                       
                    }
                    verificator = 0;

                // 1 = DIREITA
                }else if (direction == 1){
                    for (int i=0; i<size; i++){
                        if(opp_matrix[y_r][x_r+i] == -2){
                            verificator = 1;
                        }
                    }
                    if (verificator != 1){
                        for (int i=0; i<size; i++){
                            opp_matrix[y_r][x_r+i] = -2;
                        }
                        n_ships -= 1;
//                        usleep(1000000);
                    }
                    verificator = 0;

                // 2 = PARA BAIXO
                }else if (direction == 2){
                    for (int i=0; i<size; i++){
                        if(opp_matrix[y_r+i][x_r] == -2){
                            verificator = 1;
                        }
                    }
                    if (verificator != 1){
                        for (int i=0; i<size; i++){
                            opp_matrix[y_r+i][x_r] = -2;
                        }
                        n_ships -= 1;
//                        usleep(1000000);
                    }
                    verificator = 0;

                // 3 = ESQUERDA
                }else if (direction == 3){
                    for (int i=0; i<size; i++){
                        if(opp_matrix[y_r][x_r-i] == -2){
                            verificator = 1;
                        }
                    }
                    if (verificator != 1){
                        for (int i=0; i<size; i++){
                            opp_matrix[y_r][x_r-i] = -2;
                        }
                        n_ships -= 1;
//                        usleep(1000000);
                    }
                    verificator = 0;

                }
            } 
        }
        
        //DEBUG: PRINTA MATRIZ DO OPONENTE
//        printf("\nMatriz do oponente!!\n");
//        for (int l=0; l<ordem; l++){
//            for (int c=0; c<ordem; c++){
//                printf("%d ", opp_matrix[l][c]);
//            }
//        printf("\n");
//        }

        //LOOP PARA ATIRAR NOS NAVIOS INIMIGOS 
        while (op_cl == 0){
            int cont1 = 0;
            int cont2 = 0;
            int x_player;
            int y_player;
            int x_opp;
            int y_opp;


            //VERIFICAÇÃO SE O JOGO TERMINOU, SE O JOGADOR OU O OPONENTE PERDEU
            for (int l=0; l<ordem; l++){
                for (int c=0; c<ordem; c++){
                    if (opp_matrix[l][c] == -2){
                        cont1 += 1;
                    }
                    if (player_matrix[l][c] == -2){
                        cont2 += 1;
                    }
                }
            }

            // SUBSTITUE NÚMEROS NOTÁVEIS PARA MELHOR VISUALIZAÇÃO DO JOGADOR
            // 0 == ALTO MAR (ESPAÇOS VAZIOS)
            //-1 == CAMPOS DA BORDA DO MAPA/MATRIZ (SERVE APENAS PARA GARANTIR MELHOR VISUALIZAÇÃO DAS COORDENADAS)
            //-2 == POSIÇÃO DA EMBARCAÇÃO DO JOGADOR/OPONENTE
            //-3 == O JOGADOR/OPONENTE ACERTOU O TIRO
            //-4 == O JOGADOR/OPONENTE ERROU O TIRO
            if (cont1 != 0 && cont2 != 0){
                title("PAINEL DE ARMAMENTO", 41);
                printf("Menu Player\n");
                for (int l=0; l<ordem; l++){
                    for (int c=0; c<ordem; c++){
                        if (player_matrix[l][c] == -1){
                            printf("   ");
                        }else if (player_matrix[l][c] == 0){
                            printf("~   ");
                        }else if (player_matrix[l][c] == -2){
                            printf("■   ");
                        }else if (player_matrix[l][c] == -3){
                            printf("X   ");
                        }else if (player_matrix[l][c] == -4){
                            printf("O   ");
                        }else{    
                            printf("%02d  ", player_matrix[l][c]);
                        }
                    }
                printf("\n");
                }
                printf("\nMenu Oponente\n");
                for (int l=0; l<ordem; l++){
                    for (int c=0; c<ordem; c++){
                        if (opp_matrix[l][c] == -1){
                            printf("   ");
                        }else if (opp_matrix[l][c] == 0){
                            printf("~   ");
                        }else if (opp_matrix[l][c] == -2){
                            printf("~   ");
                        }else if (opp_matrix[l][c] == -3){
                            printf("X   ");
                        }else if (opp_matrix[l][c] == -4){
                            printf("O   ");
                        }else{    
                            printf("%02d  ", opp_matrix[l][c]);
                        }
                    }
                printf("\n");
                }

                //SELEÇÃO PLAYER
                printf("Selecione a coordenada x, y que deseja atacar: ");
                scanf(" %d %d", &x_player, &y_player);
                if (opp_matrix[y_player+1][x_player+1] == -2){
                    printf("\nVocê acertou!!\n");
                    opp_matrix[y_player+1][x_player+1] = -3;
                }else{
                    printf("\nVocê errou!!\n");
                    opp_matrix[y_player+1][x_player+1] = -4;
                }

                //SELEÇÃO OPONENTE
                while (sort==0){
                    x_opp = (rand() % (ordem-2)) + 1;
                    y_opp = (rand() % (ordem-2)) + 1;
                    if (player_matrix[y_opp+1][x_opp+1] == 0 || player_matrix[y_opp+1][x_opp+1] == -2){
                        sort = 1;
                    }
                }

                sort = 0;

                 if (player_matrix[y_opp+1][x_opp+1] == -2){
                    printf("\nO oponente acertou você em (%d, %d)\n", x_opp, y_opp);
                    player_matrix[y_opp+1][x_opp+1] = -3;
                }else{
                    printf("\nO oponente atirou em (%d, %d)\n", x_opp, y_opp);
                    player_matrix[y_opp+1][x_opp+1] = -4;
                }
            }

            if (cont1 == 0){
                printf("\nParabéns, você venceu!!\n");
                op_cl = 1;
            }else if(cont2 == 0){
                printf("\nParabéns, você perdeu!!\n");
                op_cl = 1;
            }else if(cont1 == 0 && cont2 == 0){
                printf("\nO jogo empatou!!\n");
                op_cl = 1;
            }
        }
    }  
    return 0;
}