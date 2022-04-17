#include <stdio.h>
#define MAX 5000

typedef short boolean;
struct Build
{
    int x;
    int y;
    boolean start;
} building[MAX];

enum list
{
	FALSE = 0, TRUE 
};

//guardar alturas ativas
struct queue {
    int value;
}Queue[MAX];

void SkyLine()
{
	//guarda o maior valor da queue
    int previous_max_value = 0;

	
    int i = 0;
    for (i ; i < MAX; i++)
    {
        if (building[i].x == 0 && building[i].y == 0 && building[i].start == 0) break;
        if (building[i].start == TRUE)
        {
            Queue[building[i].y].value++;
        }
        else
        {
            Queue[building[i].y].value--;
        }

        //get bigger value from the queue
        int max = 0;
        int j;
        for (j = 0; j < MAX; j++)
        {
            if (Queue[j].value != 0)
            {
                max = j;
            }
        }

        int current_max_value = max;

        if (previous_max_value != current_max_value)
        {
            printf("%d %d ", building[i].x, current_max_value);
            previous_max_value = current_max_value;
        }
    }
}
void Rearange()
{
	int i;
    for (i = 0; i < MAX; i++)
    {
        if (building[i].x == 0 && building[i].y == 0 && building[i].start == 0) break;
        int j;
        for (j = i + 1; j < MAX ; j++)
        {
        	//variaveis auxiliares, servem para trocar valores entre structs "buildings" 
            int aux1 = 0, aux2 = 0, aux3 = 0;
            if (building[j].x == 0 && building[j].y == 0 && building[j].start == 0) break;
            if (building[i].x > building[j].x)
            {
                aux1 = building[j].x;
                aux2 = building[j].y;
                aux3 = building[j].start;
                building[j].x = building[i].x;
                building[j].y = building[i].y;
                building[j].start = building[i].start;
                building[i].x = aux1;
                building[i].y = aux2;
                building[i].start = aux3;
            }
            
            // se ambos os edificios tiverem a mesma abcissa, verifica qual deles é o começo de um edificio
            else if (building[i].x == building[j].x)
            {
                if (building[i].start < building[j].start)
                {
                    aux1 = building[j].x;
                    aux2 = building[j].y;
                    aux3 = building[j].start;
                    building[j].x = building[i].x;
                    building[j].y = building[i].y;
                    building[j].start = building[i].start;
                    building[i].x = aux1;
                    building[i].y = aux2;
                    building[i].start = aux3;
                }
            }
        }
    }
}
int main()
{
    unsigned int count = 0;
    
    //input
    do
    {
        scanf("%d", &building[count].x);
        scanf("%d", &building[count].y);
        building[count].start = TRUE;
        scanf("%d", &building[count + 1].x);
        building[count + 1].start = FALSE;
        building[count + 1].y = building[count].y;
        
        //limite de 5.000 no x e y
        if(building[count].x > MAX * 2 || building[count].y > MAX*2 || building[count + 1].x > MAX * 2 || building[count + 1].y > MAX*2 ) break;
        
        count+=2;
    } while (getchar() != '\?' || count >= MAX);

    Rearange();
    
    SkyLine();

    return 0;
}
