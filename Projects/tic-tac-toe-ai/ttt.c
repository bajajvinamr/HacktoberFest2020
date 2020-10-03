#include<stdio.h>

//Player ======  X    -----   -1
//Computer ====  O    -----   +1

char character(int status){
  //function to return a character based on the status(1, 0, -1)
  switch (status){
    case 1:
      return 'O';
    case 0:
      return ' ';
    case -1:
      return 'X';
  }
}

void gridPrint(int status[]){
    //function to print the grid;
    printf("   %c | %c | %c\n", character(status[0]), character(status[1]), character(status[2]));
    printf("  ---+---+---\n");
    printf("   %c | %c | %c\n", character(status[3]), character(status[4]), character(status[5]));
    printf("  ---+---+---\n");
    printf("   %c | %c | %c\n", character(status[6]), character(status[7]), character(status[8]));
}

int win(int status[]){
  //function to check if someone won or not
    int combos[8][3] = {{0,1,2}, {3,4,5}, {6,7,8}, {0,3,6}, {1,4,7}, {2,5,8}, {0,4,8}, {2,4,6}};
    for(int i=0; i<8; i++){
      if(status[combos[i][0]] != 0 &&
      status[combos[i][0]] == status[combos[i][1]] &&
      status[combos[i][0]] == status[combos[i][2]]){
            return status[combos[i][0]];
        }
    }
    return 0;
}

int minimax(int status[], int player){
  //function to check the max utility
  int winner = win(status);

  if(winner != 0){
    return win(status)*player;
  }

  int move = -1;
  int utility = -3;
  
  for(int i=0; i<9; ++i){
    if(status[i] == 0){
      status[i] = player;
      int check = -minimax(status, player*-1);
      if(check > utility){
        utility = check;
        move = i;
      }
      status[i] = 0;
    }
  }
  if(move == -1) return 0;
  return utility;
}

void computer(int status[]){
  //function for the computer to play
  int move = -1;
  int utility = -3;
  int i;

  for(i=0; i<9; i++){
    if(status[i]==0){
      status[i] = 1;
      int test = -minimax(status,-1);
      status[i]=0;
      if(test>utility){
        utility = test;
        move = i;
      }
    }
  }
  status[move] = 1;
}

void input(int status[]){
  //function to take input from the user
    int updater = 0;
    printf("Enter the position [1...9] : ");
    scanf("%d", &updater);
    updater--;
    if(status[updater] == 0){
        status[updater] = -1;
    }
    else{
        printf("Place already occupied!!\n");
        input(status);
    }
}


int main(){
  int status[9] = {0,0,0,0,0,0,0,0,0}, first = 0;
  printf("Welcome to Tic-Tac-Toe!!!\n");
  printf("Computer == 'O'  ||  Player == 'X'\n");
  printf("You'll start(1) or computer should start(0) : ");
  scanf("%d", &first);

  for(int turn=0; turn<9 && win(status) == 0; ++turn){
    if((turn+first)%2==0){
      computer(status);
    }
    else {
      gridPrint(status);
      input(status);
    }
  }

  gridPrint(status);

  switch(win(status)){
    case 0:
      printf("It's a draw.\n");
      break;
    case 1 :
      printf("You Lose.\n");
      break;
    case -1 :
      printf("You win!!!");
      break;
  }

  printf("\n");
  return 0;
}
