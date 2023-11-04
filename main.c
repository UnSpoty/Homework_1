#include <stdio.h>
#include <string.h>

int binary[32];

// 1. Вывести двоичное представление целого положительного числа,
// используя битовые операции (число вводится с клавиатуры).

// 2. Вывести двоичное представление целого отрицательного числа,
// используя битовые операции (число вводится с клавиатуры).

// 3. Найти количество единиц в двоичном представлении целого
// положительного числа (число вводится с клавиатуры).

// 4. Поменять в целом положительном числе (типа int) значение третьего
// бита на введенное пользователем число (изначальное число также
// вводится с клавиатуры).


//note: - integger_to_binary() функция отвечает на 1 и 2 задачу.

int integger_to_binary()
{
    int user_num;
    int mask;


   printf("Please, enter integer value\n");
   scanf("%i", &user_num);
 
    for (int i = 31; i >= 0; i--) {
        
        mask = (1 << i);

        binary[i] = (user_num & mask) ? 1 : 0;

        printf("%i",binary[i]);        
    }

    return 0;
}

int count_ones_in_binary()
{
    int count_ones = 0;

    integger_to_binary();

    for (int i = 31; i >= 0; i--) {
        if(binary[i] == 1){

            count_ones++;

        }      
    }
    printf("\n%i \n", count_ones);

    return count_ones;
}

int change_third_bit()
{
    int third_bit = 0;

    integger_to_binary();

    printf("\nPlease, enter 1 or 0 value\n");
    scanf("%i", &third_bit);

    if(third_bit > 1 || third_bit < 0){
        printf("bit value can be only 1 or 0\n");
        return 0;
    }

    for (int i = 31; i >= 0; i--) {
        
        binary[2] = third_bit;
        printf("%i",binary[i]);

    }

    return 0;
}

int main(void) 
{
   unsigned int task_num;

   printf("Please, select task from 1..3\n");
   scanf("%u", &task_num);
   printf("Task: %u\n", task_num);

  switch(task_num)
  {
    case 1:
     integger_to_binary();
    break;
    case 2:
     count_ones_in_binary();
    break;
    case 3:
     change_third_bit();
    break;

   default:
    printf("Selected task %u does not exist\n", task_num);
  }

 return 0;
}