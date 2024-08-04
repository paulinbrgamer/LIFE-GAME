#include <raylib.h>
#include <stdio.h>
#include<time.h>
int main()
{
    //criar celulas com endereços na tela
    int contx= 0;
    int conty=0;
    int mortos[600][2];
    bool estado[600][1];
    bool rodada[600][1];

    //contador de vivos
    int v_cont= 0;
    for (int i = 0;i<600;i++)
    {
        mortos[i][0] = contx; 
        mortos[i][1] = conty;
        estado[i][0] = false;
        rodada[i][0] = estado[i][0]; 
        contx += 20;
        if (contx == 600)
        {
            contx = 0;
            conty += 20;
        }
    }
  

    InitWindow(600,400,"LIFE GAME");
    SetTargetFPS(10);
    while (WindowShouldClose() == false)
    {
        //-------------------------UPDATE---------------------------------//
        
        if (IsKeyDown(KEY_ENTER))
        {
            for (int i=0;i<600;i++)
            {
            estado[i][0] = rodada[i][0];
            }
        
        for (int i=0;i<600;i++)
        {
            
            
            //se estiver vivo, verificar se tme vivos ao redor
            if (estado[i][0] == true)
            {
                
                if (estado[i+1][0] == true)
                {
                    v_cont++;
                }
                if (estado[i-1][0] == true)
                {
                    v_cont++;
                }
                if (estado[i+30][0] == true)
                {
                    v_cont++;
                }
                if (estado[i-30][0]== true)
                {
                    v_cont++;
                }
                if (estado[i+31][0]== true)
                {
                    v_cont++;
                }
                if (estado[i-31][0]== true)
                {
                    v_cont++;
                }
                if (estado[i+29][0]== true)
                {
                    v_cont++;
                }
                if (estado[i-29][0]== true)
                {
                    v_cont++;
                }

                //verificar se for menor que 3 morre
                if (v_cont<2)
                {
                    rodada[i][0] = false ;
                } 
                //verufucar super popula~çao
                if (v_cont>3)
                {
                    rodada[i][0]= false;
                }
                //nascimento 
                v_cont = 0;
            }
            else if (estado[i][0] == false)
            {
                if (estado[i+1][0] == true)
                {
                    v_cont++;
                }
                if (estado[i-1][0] == true)
                {
                    v_cont++;
                }
                if (estado[i+30][0] == true)
                {
                    v_cont++;
                }
                if (estado[i-30][0]== true)
                {
                    v_cont++;
                }
                if (estado[i+31][0]== true)
                {
                    v_cont++;
                }
                if (estado[i-31][0]== true)
                {
                    v_cont++;
                }
                if (estado[i+29][0]== true)
                {
                    v_cont++;
                }
                if (estado[i-29][0]== true)
                {
                    v_cont++;
                }

                if (v_cont>=3 && v_cont<4)
                {
                    rodada[i][0] = true;
                }
                v_cont = 0;
            }
            
            
         
        }
        }
        
        if (IsKeyDown(KEY_A))
            {
           
            rodada[161][0] = true;
            
            rodada[222][0] = true;
            rodada[192][0] = true;
            rodada[220][0] = true;
            rodada[221][0] = true;
            
            
            }
         
        //----------------------DRAW--------------------------------------//
        BeginDrawing();
        ClearBackground(GRAY); 
        //desenhar celulas
        for (int qua=0;qua<600;qua++)
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
        for (int i =0;i<420;i = i+20)
        {
           DrawLine(1,i,600,i,GRAY);
        }
        for (int i =0;i<620;i = i+20)
        {
           DrawLine(i,1,i,400,GRAY);
        }
        




        EndDrawing();
    }
    CloseWindow();
}