#include "robot_simulator.h"

robot_status_t robot_create(robot_direction_t direction, int x, int y)
{
    return (robot_status_t) 
    { 
        direction, 
        { x, y } 
    };
}

void robot_move(robot_status_t *robot, const char *commands)
{
    if (robot == NULL)
    {
        return;
    }

    if (commands == NULL)
    {
        return;
    }

    size_t len = strlen(commands);

    for (size_t i = 0; i < len; i++)
    {
        switch(commands[i])
        {
            case 'A':
            {
                switch(robot->direction)
                {
                    case DIRECTION_NORTH:
                    {
                        robot->position.y += 1;
                        break;        
                    }
                        
                    case DIRECTION_EAST:
                    {
                        robot->position.x += 1;
                        break;        
                    }
                        
                    case DIRECTION_SOUTH:
                    {
                        robot->position.y -= 1;
                        break;        
                    }
                        
                    case DIRECTION_WEST:
                    {
                        robot->position.x -= 1;
                        break;        
                    }
                }
                
                break;
            }
                
            case 'L':
            {
                switch(robot->direction)
                {
                    case DIRECTION_NORTH:
                    {
                        robot->direction = DIRECTION_WEST;
                        break;        
                    }
                        
                    case DIRECTION_EAST:
                    {
                        robot->direction = DIRECTION_NORTH;
                        break;        
                    }
                        
                    case DIRECTION_SOUTH:
                    {
                        robot->direction = DIRECTION_EAST;
                        break;        
                    }
                        
                    case DIRECTION_WEST:
                    {
                        robot->direction = DIRECTION_SOUTH;
                        break;        
                    }
                }

                break;
            }   
                
            case 'R':
            {
                switch(robot->direction)
                {
                    case DIRECTION_NORTH:
                    {
                        robot->direction = DIRECTION_EAST;
                        break;        
                    }
                        
                    case DIRECTION_EAST:
                    {
                        robot->direction = DIRECTION_SOUTH;
                        break;        
                    }
                        
                    case DIRECTION_SOUTH:
                    {
                        robot->direction = DIRECTION_WEST;
                        break;        
                    }
                        
                    case DIRECTION_WEST:
                    {
                        robot->direction = DIRECTION_NORTH;
                        break;        
                    }
                }

                break;
            }
        }
    }
}
