#include<SDL.h>
#include<iostream>
#include<limits>
#include<time.h>
#include<string>
using namespace std;
const int srn_width=910;
const int srn_height=700;
const int arrSize=140;
const int rectSize=7;

int arr[arrSize];
int Barr[arrSize];

SDL_Window* window=NULL;
SDL_Renderer* renderer=NULL;

bool complete=false;
bool init()
{
    bool success=true;
    if(SDL_Init(SDL_INIT_VIDEO)<0)
    {
        cout<<"Couldn't initialize SDL. SDL_Error: "<<SDL_GetError();
        success=false;
    }
    else{
        if(!(SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"1")))
        {
            COUT<<"Warining: Linear Texture Filtering not enabled.\n";
        }
        window=SDL_CreateWindow("Sort-o-Matic",SDL_WINDOWPOS_UNDEFINED,DLE_WINDOWPOS_UNDEFINED,srn_width,srn_height,SDL_WINDOW_SHOW);
        if(window==NULL)
        {
            cout<<"Couldn't create window. SDL_Erroe: "<<SDL_GetError();
            success=false;
        }
        else{
            renderer=SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED);
            if(renderer==NULL)
            {
                cout<<"Couldn't create renderer. SDL_Error:"<<SDL_GetError();
                sucsess=false;
            }
        }
    }
    return success;
}
void close()
{
    SDL_DestroyRenderer(renderer);
    renderer=NULL;
    SDL_DestroyWindow(window);
    window=NULL;
    SDL_Quit();
}

