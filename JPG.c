#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>

int main(int argc, char* argv[]) {
    // SDL 초기화
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    // SDL 이미지 초기화 (PNG, JPG 포맷을 사용)
    if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) == 0) {
        printf("IMG_Init Error: %s\n", IMG_GetError());
        SDL_Quit();
        return 1;
    }

    // SDL 창 생성
    SDL_Window* window = SDL_CreateWindow("Image Viewer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    // SDL 렌더러 생성
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    // 이미지 파일 경로
    const char* image_path1 = "jcshim.png";  // 첫 번째 이미지
    const char* image_path2 = "jcshim.jpg";  // 두 번째 이미지

    // 첫 번째 이미지 로드
    SDL_Texture* texture1 = IMG_LoadTexture(renderer, image_path1);
    if (!texture1) {
        printf("IMG_LoadTexture Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    // 두 번째 이미지 로드
    SDL_Texture* texture2 = IMG_LoadTexture(renderer, image_path2);
    if (!texture2) {
        printf("IMG_LoadTexture Error: %s\n", IMG_GetError());
        SDL_DestroyTexture(texture1);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    // 렌더링 루프
    SDL_Event e;
    int quit = 0;
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
        }

        // 화면 지우기
        SDL_RenderClear(renderer);

        // 첫 번째 이미지 렌더링 (왼쪽 상단)
        SDL_Rect dstrect1 = { 100, 100, 400, 300 };  // (x, y, width, height)
        SDL_RenderCopy(renderer, texture1, NULL, &dstrect1);

        // 두 번째 이미지 렌더링 (오른쪽 하단)
        SDL_Rect dstrect2 = { 300, 200, 400, 300 };  // (x, y, width, height)
        SDL_RenderCopy(renderer, texture2, NULL, &dstrect2);

        // 화면에 렌더링
        SDL_RenderPresent(renderer);
    }

    // 리소스 해제
    SDL_DestroyTexture(texture1);
    SDL_DestroyTexture(texture2);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}
