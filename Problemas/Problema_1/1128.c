#include<stdio.h>
#include <stdbool.h>


bool graph[2001][2001];
bool visitados[2001];
int N, P;
 
void profundidade( int ponto ){
 if( visitados[ ponto ] == true ){
    return;
 }else{
    visitados[ ponto ] = true;
    for( int i = 1; i <= N; i++ )
    if( graph[ ponto ][ i ] && !visitados[ i ] ) profundidade( i );
 }
}
 
int main(){
 
    scanf(" %d", &N);
    while( N != 0 ){
        scanf(" %d", &P);
        for( int i = 1; i <= N; i++ ){
            visitados[ i ] = false;
                for( int j = 1; j <= N; j++ ){
                    graph[ i ][ j ] = false;
                }
        }
 
        for( int i = 1; i <= P; i++ ){
            int c, d, sel;
            scanf(" %d %d %d", &c, &d, &sel);
            if( sel == 1 ){
                graph[ c ][ d ] = true; 
            }
            else{
                graph[ c ][ d ] = true;
                graph[ d ][ c ] = true;
                }
        }
 
        profundidade( 1 );
 
        bool solucao = true;
        for( int i = 1; i <= N; i++ ){
            if( !visitados[ i ] ){
                solucao = false;
            }
        }
 
        if( solucao == true ){
            for( int i = 1; i <= N; i++ ){
                visitados[ i ] = false;
                for( int j = i+1; j <= N; j++ ){
                    if( graph[ i ][ j ] && graph[ j ][ i ] ) continue;
                    else if( graph[ i ][ j ] ){
                        graph[ j ][ i ] = true; graph[ i ][ j ] = false;
                    }else if( graph[ j ][ i ] ){
                        graph[ i ][ j ] = true; graph[ j ][ i ] = false;
                    }
                }
             }
 
            profundidade( 1 );
        }
        
        for( int i = 1; i <= N; i++ ){
            if( !visitados[ i ] ){
                solucao = false;
            }
        }
 
        if( solucao ){
           printf("1\n"); 
        } 
        else {
            printf("0\n");
        }
        scanf(" %d", &N);
    }
 
    return 0;
}
