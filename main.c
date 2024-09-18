#include <raylib.h>
#include <stdio.h>
#include<time.h>
int main()
{
    //criar variaveis para criar celulas com endereços na tela
    int contx= 0;
    int conty=0;
    //matriz que recebarar uma pozição x e y para todos as 1200 celulas da tela
    int mortos[1200][2];
    //matriz booleana para determinar quem estará vivo ou morto na proxima rodada
    bool estado[1200][1];
    //matriz onde será guardada os vivos e mortos da proxima rodada e em seguida a matriz estado recebera a rodada
    bool rodada[1200][1];

    //contador de vivos
    int v_cont= 0;

    //gerar endereço para todos os quadrados
    for (int i = 0;i<1200;i++)
    {
        mortos[i][0] = contx; 
        mortos[i][1] = conty;
        estado[i][0] = false;
        rodada[i][0] = estado[i][0]; 
        contx += 20;
        if (contx == 800)
        {
            contx = 0;
            conty += 20;
        }
    }
  
    //iniciar janela
    InitWindow(800,600,"LIFE GAME");
    SetTargetFPS(9);
    //definir fps para 10
    while (WindowShouldClose() == false)
    {
        //-------------------------UPDATE---------------------------------//
        //se apertar a tecla enter, as regras da celula serao aplicadas
        if (IsKeyUp(KEY_ENTER))
        {
            for (int i=0;i<1200;i++)
            {
            estado[i][0] = rodada[i][0];
            }
        //aqui será verificada cada celula da tela
        for (int i=0;i<1200;i++)
        {

            //se estiver vivo, verificar se tme vivos ao redor
            if (estado[i][0] == true)
            {
                //ifs para verificar se o vizinho esta vivo e incrementar em um contador
                if (estado[i+1][0] == true)
                {
                    v_cont++;
                }
                if (estado[i-1][0] == true)
                {
                    v_cont++;
                }
                if (estado[i+40][0] == true)
                {
                    v_cont++;
                }
                if (estado[i-40][0]== true)
                {
                    v_cont++;
                }
                if (estado[i+41][0]== true)
                {
                    v_cont++;
                }
                if (estado[i-41][0]== true)
                {
                    v_cont++;
                }
                if (estado[i+39][0]== true)
                {
                    v_cont++;
                }
                if (estado[i-39][0]== true)
                {
                    v_cont++;
                }


                //verificar se o contador for menor que 3, se sim morre
                if (v_cont<2)
                {
                    rodada[i][0] = false ;
                } 
                //verificar se o contador for maior que 3, se sim morre
                if (v_cont>3)
                {
                    rodada[i][0]= false;
                }
                //resetar contador
                v_cont = 0;
            }
            //caso a celula verifiada for uma morta
            else if (estado[i][0] == false)
            {
                //verificar vizinhos e incrementar no contador
                if (estado[i+1][0] == true)
                {
                    v_cont++;
                }
                if (estado[i-1][0] == true)
                {
                    v_cont++;
                }
                if (estado[i+40][0] == true)
                {
                    v_cont++;
                }
                if (estado[i-40][0]== true)
                {
                    v_cont++;
                }
                if (estado[i+41][0]== true)
                {
                    v_cont++;
                }
                if (estado[i-41][0]== true)
                {
                    v_cont++;
                }
                if (estado[i+39][0]== true)
                {
                    v_cont++;
                }
                if (estado[i-39][0]== true)
                {
                    v_cont++;
                }
                //se tiver 3 vizinhos vivos entao celula vai receber estado vivo
                if (v_cont>=3 && v_cont<4)
                {
                    rodada[i][0] = true;
                }
                v_cont = 0;
            }

        }
        }
        if (IsKeyDown(KEY_R))
        {
            for (int i=0;i<1200;i++)
            {
              estado[i][0] = false;
              rodada[i][0] = estado[i][0];   
            }
        }
        //criar um padrão do tipo glider
        if (IsKeyDown(KEY_A))
            {
           
            rodada[131][0] = true;
            rodada[211][0] = true;
            rodada[211][0] = true;
            rodada[210][0] = true;
            rodada[212][0] = true;
            rodada[172][0] = true;
            
            }
        //usuario clicar no padrao que deseja criar
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON) && IsKeyDown(KEY_ENTER))
        {
            Vector2 mousep= GetMousePosition();

            for (int i=0;i<1200;i++)
            {
              Rectangle celula;
              celula.x = mortos[i][0];
              celula.y = mortos[i][1];
              celula.height = 20;
              celula.width = 20;
            if (CheckCollisionPointRec(mousep,celula))
            {
                estado[i][0] = true;
                rodada[i][0] = true;
            }




               
            }
        }
        //----------------------DRAW--------------------------------------//
        BeginDrawing();
        ClearBackground(GRAY); 


        
        //desenhar celulas
        for (int qua=0;qua<1200;qua++)
        {
            //se estiver morto vai desenhar preto
            if (estado[qua][0] == false)
            {
                DrawRectangle(mortos[qua][0],mortos[qua][1],20,20,BLACK);
            }
            //se estiver vivo vai desenhar amarelo
            else{
                DrawRectangle(mortos[qua][0],mortos[qua][1],20,20,YELLOW);    
            }  
        }
        //desenhar grid
        for (int i =0;i<620;i = i+20)
        {
           DrawLine(1,i,800,i,GRAY);
        }
        for (int i =0;i<820;i = i+20)
        {
           DrawLine(i,1,i,600,GRAY);
        }
        EndDrawing();
    }
    CloseWindow();
}