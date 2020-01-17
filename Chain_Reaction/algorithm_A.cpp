#include <iostream>
#include "board.h"
#include "player.h"
#include "algorithm.h"

using namespace std;

void algorithm_A(Board board, Player player, int index[]) {
    int final_x = 0;
    int final_y = 0;
    int lose_rate= 100000;
    
    Board original_board = board;
    
    for (int row = 0; row < ROW; row++) {
        for (int column = 0; column < COL; column++) {
            if (board.get_cell_color(row, column) == player.get_color() || board.get_orbs_num(row, column) == 0) {
                board.place_orb(row, column, &player);
                int temp_lose_rate = 0;
                
                for (int i = 0; i < ROW; i++) {
                    for (int j = 0; j < COL; j++) {
                        if (board.get_cell_color(i, j) != player.get_color()) {
                            if ((board.get_capacity(i, j) - board.get_orbs_num(i, j)) % 2 == 1) {
                                temp_lose_rate += board.get_capacity(i, j);
                            }
                        }
                    }
                }
                
                board = original_board;
                
                if (temp_lose_rate < lose_rate) {
                    lose_rate = temp_lose_rate;
                    final_x = row;
                    final_y = column;
                }
            }
        }
    }

    index[0] = final_x;
    index[1] = final_y;
}
