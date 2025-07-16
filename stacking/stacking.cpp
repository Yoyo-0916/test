#include <iostream>
#include <stdlib.h>  // rand(), srand()
#include <time.h>    // time()

const int ROW_NUM = 13;
const int COL_NUM = 15;
const int LAYER_NUM = 6;
const int LAYER_TYPE_NUM = 3;

/* dummy data */
const int HORIZONTAL_LAYER[ROW_NUM][COL_NUM] =
{
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

const int VERTICAL_LAYER[ROW_NUM][COL_NUM] = 
{
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

const int DOT_LAYER[ROW_NUM][COL_NUM] =
{
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

const int GIVEN_PLACEMENT[ROW_NUM][COL_NUM] = 
{
    { 0, 0,  0,  0, 0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0,  0,  0, 0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 5, 6,  1, 10, 5, 11,  8, 9, 5, 0, 1, 8, 7, 8, 1},
    { 5, 6,  1, 10, 5, 11,  8, 9, 5, 0, 1, 8, 7, 8, 1},
    { 5, 6,  1, 10, 5, 11,  8, 9, 5, 0, 1, 8, 7, 8, 1},
    { 5, 6,  1, 10, 5, 11,  8, 9, 5, 0, 1, 8, 7, 8, 1},
    { 0, 6,  0, 10, 0, 11,  0, 9, 0, 0, 0, 8, 7, 8, 0},
    { 2, 6, 12, 10, 8, 11, 13, 9, 2, 0, 2, 8, 7, 8, 2},
    { 2, 6, 12, 10, 8, 11, 13, 9, 2, 0, 2, 8, 7, 8, 2},
    { 2, 6, 12, 10, 8, 11, 13, 9, 2, 0, 2, 8, 7, 8, 2},
    { 2, 6, 12, 10, 8, 11, 13, 9, 2, 0, 2, 8, 7, 8, 2},
    { 0, 0,  0,  0, 0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0,  0,  0, 0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int targetLayer[LAYER_NUM][ROW_NUM][COL_NUM];

/**
 * fillLayer() - Copy the contents of one 2D array into another
 * @targetLayer: 2D destination array to be filled
 * @LAYER: 2D predefined source array whose values will be copied
 */
void fillLayer(int targetLayer[ROW_NUM][COL_NUM], const int LAYER[ROW_NUM][COL_NUM]) 
{
    for (int i = 0; i < ROW_NUM; i++)
        for (int j = 0; j < COL_NUM; j++)
            targetLayer[i][j] = LAYER[i][j];
}


/**
 * randomStacking() - Randomly fill each layer with a predefined pattern
 * @targetLayer: 3D destination array to be filled
 */
void randomStacking(int targetLayer[LAYER_NUM][ROW_NUM][COL_NUM])
{
    srand(time(NULL));
    for (int i = 0; i < LAYER_NUM; i++) {
        int r = rand() % LAYER_TYPE_NUM;
        switch (r) {
        case 0: fillLayer(targetLayer[i], HORIZONTAL_LAYER); break;
        case 1: fillLayer(targetLayer[i], VERTICAL_LAYER);   break;
        case 2: fillLayer(targetLayer[i], DOT_LAYER);        break;
        }
    }
}

void display(const int LAYERS[LAYER_NUM][ROW_NUM][COL_NUM])
{
    for (int k = 0; k < LAYER_NUM; k++) {
        printf("Layer %d\n", k);
        for (int i = 0; i < ROW_NUM; i++) {
            for (int j = 0; j < COL_NUM; j++)
                printf("%2d ", LAYERS[k][i][j]);
            printf("\n");
        }
    }
}

/**
 * specifyLayer() - Randomly fill all layers, then overwrite a specified layer
 * @targetLayer: 3D destination array to be filled
 * @index: The index of the layer (0-based) to overwrite in targetLayer
 * @LAYER: 2D predefined source array whose values will be copied
 */
void specifyLayer(int targetLayer[LAYER_NUM][ROW_NUM][COL_NUM], int index, const int LAYER[ROW_NUM][COL_NUM])
{
    randomStacking(targetLayer);
    fillLayer(targetLayer[index], LAYER);
}

int main()
{
    /* Stacking strategy 1 */
    randomStacking(targetLayer);
    printf("Random result\n");
    display(targetLayer); // expected: show random result

    /* Stacking strategy 2 */
    specifyLayer(targetLayer, 3, GIVEN_PLACEMENT);
    printf("Specify result\n");
    display(targetLayer); // expected: layer 3 will be the given placement 
}