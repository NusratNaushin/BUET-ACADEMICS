# Example file showing a circle moving on screen
import pygame
from board import *
from filehandling import *
from minimax import *
from heuristic import *

# pygame setup
pygame.init()
screen = pygame.display.set_mode((720, 720))
clock = pygame.time.Clock()
running = True
dt = 0


# orb_position = []
player_pos = pygame.Vector2(screen.get_width() / 2, screen.get_height() / 2)

cell_width = 120
cell_height = 80

board = Board(rows=9,cols=6,cell_width=cell_width,cell_height=cell_height)



flag = 0

#critical_mass=4



def drawGrid(colour="red"):

    for x in range(0, screen.get_width(), cell_width):
        pygame.draw.line(screen, colour, (x, 0), (x, screen.get_height()))
    for y in range(0, screen.get_height(), cell_height):
        pygame.draw.line(screen, colour, (0, y), (screen.get_width(), y))
        
        
max_depth_to_search = 3
heuristic_function = heuristic
AI_PLAYER = MinimaxAgent(max_depth_to_search=max_depth_to_search, player_colour='green', heuristic_function=heuristic_function)

while running: 

    # poll for events
    # pygame.QUIT event means the user clicked X to close your window
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # fill the screen with a color to wipe away anything from last frame
    screen.fill("black")
    drawGrid("red" if board.turn == 0 else "green")


    if(board.turn == 0 and pygame.mouse.get_pressed()[0]):
        mouse_click_x , mouse_click_y  = pygame.mouse.get_pos()

        column_that_is_clicked = mouse_click_x // cell_width  # inetegr division korlam jaate column number ta pai
        row_that_is_clicked = mouse_click_y // cell_height
        print(f"Human clicked at pixel ({mouse_click_x}, {mouse_click_y}) => grid cell ({row_that_is_clicked}, {column_that_is_clicked})")
        board.clicks(row_that_is_clicked,column_that_is_clicked,"red")
        print(f"After human click, grid state:")
        for (r, c), orb in sorted(board.grid.items()):
            print(f"  Cell ({r},{c}) - Count: {orb['count']}, Colour: {orb['colour']}")
        write_game_current_state("/home/nidhi/3-1/LABS/BUET-ACADEMICS/3-1 SESSIONALS/CSE 318 AI/Offline 3/gamestate.txt", board, board.turn)

    elif board.turn == 1:
        best_move = AI_PLAYER.get_move(board)
        if best_move is not None:
            board = board.make_move(best_move, AI_PLAYER.player_colour)
            board.turn = 0  # AI er move korar por turn change kore dilam
            write_game_current_state("/home/nidhi/3-1/LABS/BUET-ACADEMICS/3-1 SESSIONALS/CSE 318 AI/Offline 3/gamestate.txt", board, board.turn)
        else :
            print("AI has no legal moves")
    for colour,pos in board.draw_orbs():
        pygame.draw.circle(screen,colour, pos , radius=10)

        



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
    pygame.display.flip()

    # limits FPS to 60
    # dt is delta time in seconds since last frame, used for framerate-
    # independent physics.
    dt = clock.tick(60) / 1000

pygame.quit()





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