# Example file showing a circle moving on screen
import pygame
import time
from board import *
from filehandling import *
from minimax import *
from heuristic import *
from sys import exit 

# This is a simple pygame program that implements a grid-based game where a player can click to place orbs.

# pygame setup

print_debug_flag = False 
pygame.init()
screen_width = 1000
screen_height = 1000
screen = pygame.display.set_mode((screen_width, screen_height))
clock = pygame.time.Clock()
running = True
dt = 0

ai_move_delay = 100
ai_move_timer = 0
ai_move = False

# orb_position = []
player_pos = pygame.Vector2(screen.get_width() / 2, screen.get_height() / 2)

cell_width = 120
cell_height = 80
grid_width = 6*cell_width
grid_height = 9*cell_height

grid_offset_x = (screen_width - grid_width) // 2
grid_offset_y = (screen_height - grid_height) // 2



board = Board(rows=9,cols=6,cell_width=cell_width,cell_height=cell_height,offset_x=grid_offset_x, offset_y=grid_offset_y)

game_over = False

flag = 0

#critical_mass=4

ai_image = pygame.image.load("images/ai.png")
human_image = pygame.image.load("images/human.png")
Game_state_txt = "/home/nidhi/3-1/LABS/BUET-ACADEMICS/3-1 SESSIONALS/CSE 318 AI/Offline 3/gamestate.txt"

font = pygame.font.SysFont("couriernew", 32)
game_title_font =  pygame.font.SysFont("couriernew", 36 , bold=True)
game_title_text = game_title_font.render("CHAIN REACTION", True , (0,255,255))

def drawGrid(colour="red"):
    for x in range(board.cols + 1):
        pygame.draw.line(screen, colour,
                         (grid_offset_x + x * cell_width, grid_offset_y),
                         (grid_offset_x + x * cell_width, grid_offset_y + board.rows * cell_height),width=5)
    for y in range(board.rows + 1):
        pygame.draw.line(screen, colour,
                         (grid_offset_x, grid_offset_y + y * cell_height),
                         (grid_offset_x + board.cols * cell_width, grid_offset_y + y * cell_height))

max_depth_to_search = 3
heuristic_function = my_heuristic
AI_PLAYER = MinimaxAgent(max_depth_to_search=max_depth_to_search, player_colour='blue', heuristic_function=heuristic_function)

while running: 

    board_data , turn = read_game_current_state(Game_state_txt)
    
    if print_debug_flag:
        print(f"[DEBUG] Start of loop. Turn: {turn}, Awaiting player: {'HUMAN' if turn % 2 == 1 else 'AI'}")


    # poll for events
    # pygame.QUIT event means the user clicked X to close your window
    for event in pygame.event.get():

        if event.type == pygame.QUIT:
            running = False

    # fill the screen with a color to wipe away anything from last frame
   
        elif event.type == pygame.MOUSEBUTTONDOWN and event.button == 1:  # Left mouse button
            if(turn == 0 and not game_over and not ai_move):
                mouse_click_x , mouse_click_y  = event.pos

                column_that_is_clicked = (mouse_click_x - grid_offset_x) // cell_width  # inetegr division korlam jaate column number ta pai
                row_that_is_clicked = (mouse_click_y - grid_offset_y) // cell_height
                if 0 <= row_that_is_clicked < board.rows and 0 <= column_that_is_clicked < board.cols:
                    if print_debug_flag:
                        print(f"Human clicked at pixel ({mouse_click_x}, {mouse_click_y}) => grid cell ({row_that_is_clicked}, {column_that_is_clicked})")
                    winning_flag=board.clicks(row_that_is_clicked,column_that_is_clicked,"red")
                    if winning_flag is not None:
                        win_flag_collection_for_rendering = winning_flag
                        game_over = True
                        if print_debug_flag:
                            print("Game Over! Winner:", "Red" if winning_flag == 0 else "Blue")
                        #running = False
                    else:
                        ai_move = True
                        ai_move_timer = pygame.time.get_ticks()
                        turn = 1
                    if print_debug_flag:
                        print(f"After human click, grid state:")
                        for (r, c), orb in sorted(board.grid.items()):
                            print(f"  Cell ({r},{c}) - Count: {orb['count']}, Colour: {orb['colour']}")
                        print("turn:\n",turn)
                    if print_debug_flag:
                        print(f"before writing in human")
                    write_game_current_state("/home/nidhi/3-1/LABS/BUET-ACADEMICS/3-1 SESSIONALS/CSE 318 AI/Offline 3/gamestate.txt", board, turn)
                
    if turn == 1 and not game_over and ai_move:
        current_time = pygame.time.get_ticks()
        if current_time - ai_move_timer >= ai_move_delay:
            best_move = AI_PLAYER.get_move(board)
            if best_move is not None:
                board,winning_flag = board.make_move(best_move, AI_PLAYER.player_colour)
                turn = 0  # AI er move korar por turn change kore dilam
                if winning_flag is not None:
                    win_flag_collection_for_rendering = winning_flag
                    game_over = True
                    if print_debug_flag:
                        print("Game Over! Winner:", "Red" if winning_flag == 0 else "Blue")
                    #running = False
                if print_debug_flag:
                    print(f"before writing in ai loop")        
                write_game_current_state("/home/nidhi/3-1/LABS/BUET-ACADEMICS/3-1 SESSIONALS/CSE 318 AI/Offline 3/gamestate.txt", board, turn)
            else :
                if print_debug_flag:
                    print("AI has no legal moves")
            
            ai_move = False
            
    screen.fill("black")
    screen.blit(game_title_text, (350,15))
    pygame.draw.rect(screen, (0,255,255), (0, 0, screen_width, screen_height), 5)

    drawGrid("red" if board.turn == 0 else "blue")
    for colour,pos in board.draw_orbs():
        adjusted_pos = (pos[0] + grid_offset_x, pos[1] + grid_offset_y)
        pygame.draw.circle(screen,colour, adjusted_pos , radius=10)

        
    if ai_move and board.turn == 1 and not game_over:
        move_text = font.render("AI MOVE...", True, (255, 255, 0))
        screen.blit(move_text, (140, 100))
    elif not ai_move and board.turn == 0 and not game_over:   
        move_text = font.render("HUMAN MOVE...", True, (255, 255, 0))
        screen.blit(move_text, (140, 100))

    if game_over:
        if win_flag_collection_for_rendering == 0:
            #screen.blit(human_image, (screen_width // 2 - human_image.get_width() // 2, grid_offset_y // 2))
            win_txt = font.render("Game Over! Winner: Human ", True , (124, 252, 0))
        else:
            #screen.blit(ai_image, (screen_width // 2 - ai_image.get_width() // 2, grid_offset_y // 2))
            win_txt = font.render("Game Over! Winner: AI ", True , (124, 252, 0))
        screen.blit(win_txt, (screen_width // 2 - win_txt.get_width() // 2, grid_offset_y // 2))
    pygame.display.flip()

    # limits FPS to 60
    # dt is delta time in seconds since last frame, used for framerate-
    # independent physics.
    dt = clock.tick(60) / 1000

pygame.quit()






        # clicked = True
        # orb_exists = False

        # for orb in orb_position:
        #     if orb["pos"] == center_coordinates:
        #         orb_exists = True
        #         if orb["colour"] == ("red" if flag == 0 else "green"):
        #             orb["count"] += 1
        #             if orb["count"] >= critical_mass :
        #                 pass
        #             else:
        #                 flag = 1 - flag # jodi orb ager theke exist kore but colour ta ager moton na so 
        #                                 #if e na dhuke else e dhukbo and then flag change krobo jaate onno colour er turn ashe 
        #         break
         
        # if not orb_exists:
        #     orb_colour = "red" if flag == 0 else "green"
        #     orb_position.append({"pos":center_coordinates,"colour":orb_colour,"count":1})

        #     flag = 1 - flag


    
    # grid_colour = "green" if flag == 1 else "red"
        
    # drawGrid(grid_colour)
    
    # for orb in orb_position:
    #     for i in range(orb["count"]):
    #         offset_angle = i* (360 // orb["count"])
    #         offset_x = 10*i
    #         pygame.draw.circle(screen, orb["colour"], (orb["pos"][0] + offset_x, orb["pos"][1]), 10)

    # flip() the display to put your work on screen
# Human Move:

# 0 0 0 0 0 0
# 0 0 0 0 0 0
# 0 0 0 0 0 0
# 0 0 0 0 0 0
# 0 0 0 0 0 0
# 0 0 0 0 0 0
# 0 0 0 0 0 0
# 0 0 0 0 0 0
# 0 0 0 0 0 0