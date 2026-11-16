#include "queen_attack.h"


bool is_queen_off_bounds(position_t *queen)
{
    return queen->row > BOARD_LIMIT || queen->column > BOARD_LIMIT;
}

attack_status_t can_attack(position_t queen_1, position_t queen_2)
{
    if (is_queen_off_bounds(&queen_1) || 
        is_queen_off_bounds(&queen_2) || 
        (queen_1.row == queen_2.row && 
            queen_1.column == queen_2.column))
    {
        return INVALID_POSITION;
    }

    if (queen_1.row == queen_2.row || 
        queen_1.column == queen_2.column)
    {
        return CAN_ATTACK;
    }

    int8_t vertical_factor = queen_1.row < queen_2.row ? 1 : -1;
    int8_t horizontal_factor = queen_1.column < queen_2.column ? 1 : -1;

    uint8_t row_check = queen_1.row + vertical_factor;
    uint8_t column_check = queen_1.column + horizontal_factor;

    while(row_check <= BOARD_LIMIT && 
         column_check <= BOARD_LIMIT)
    {                    
        if (queen_2.row == row_check && 
            queen_2.column == column_check)
        {
            return CAN_ATTACK;
        }
        
        row_check += vertical_factor;
        column_check += horizontal_factor;
    }
    
    return CAN_NOT_ATTACK;
}