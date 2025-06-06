import pygame
import copy
class Board:
    def __init__(self,rows,cols,cell_width,cell_height,offset_x, offset_y):
        self.rows = rows
        self.cols = cols
        self.cell_width = cell_width
        self.cell_height = cell_height
        self.grid = {}
        self.turn = 0 # first e 0 thakle red grid dekhabe
        self.offset_x = offset_x
        self.offset_y = offset_y

    def cell_center(self,row_that_is_clicked ,column_that_is_clicked):
        x_dsitance_from_beginning_to_the_selected = column_that_is_clicked * self.cell_width
        y_distance_from_beginning_to_the_selected = row_that_is_clicked * self.cell_height

        single_cell_center_x = self.cell_width // 2
        single_cell_center_y = self.cell_height // 2

        center_x = x_dsitance_from_beginning_to_the_selected + single_cell_center_x
        center_y = y_distance_from_beginning_to_the_selected + single_cell_center_y        
        return (center_x,center_y)
    

    def get_critical_mass(self, row, col):
        if (row == 0 or row == self.rows - 1) and (col == 0 or col == self.cols - 1):#corner cell gula nicchi ekhane
            return 2
        elif row == 0 or row == self.rows - 1 or col == 0 or col == self.cols - 1:#edge cell gula nicchi ekhane 
            return 3
        else: #edge corner baade baki shob cell 
            return 4


    def clicks(self,row,col,player_colour): # jei row col select kortesi ogla passing
        
        if self.isWinner() is not None:
            print("Game Over! Winner:", "Red" if self.isWinner() == 0 else "Green")
            return self.isWinner()
        if(row < 0 or row >= self.rows or col < 0 or col >= self.cols):
            return None
        
        center = self.cell_center(row,col)
        key = (row,col)

        orb = self.grid.get(key)
        current_colour_of_the_orb = "red" if self.turn == 0 else "green"


        if orb:
            if orb["colour"] == player_colour: #orb ager theke ase ekhn onno colour er orb er upor to ar kora jabe na so ei check dilam
                orb["count"] += 1
                if orb["count"] >= self.get_critical_mass(row,col):
                    self.handle_explosion()
                    #orb["count"] = 0 # critical mass er poriman komiye dilam
                    #print("After explosion:", row, col, "Grid:", self.grid.get((row, col)))
                   # print("Critical mass : ", orb["count"],self.get_critical_mass(row,col))
                    #pass
                self.turn = 1 - self.turn
        else:
            self.grid[key] = {"pos": center , "colour": player_colour , "count": 1}
            self.turn = 1 - self.turn
        winning_flag = self.isWinner()
        if winning_flag is not None:
            return winning_flag
        return None

    
    def draw_orbs(self):
        what_to_draw = []

        for orb in self.grid.values():
            for i in range(orb["count"]):
                #offset_angle = i* (360 // orb["count"])
                offset_x = 10*i
                what_to_draw.append((orb["colour"], (orb["pos"][0] + offset_x, orb["pos"][1])))       
                # pygame.draw.circle(screen, orb["colour"], (orb["pos"][0] + offset_x, orb["pos"][1]), 10)
                                                  
        return what_to_draw
    
    
    def get_legal_moves(self,player):
        legal_moves_array = []
        player_colour = "red" if player == 0 else "green"
        for row in range(self.rows):
            for col in range(self.cols):
                key = (row,col)
                orb = self.grid.get(key)
                if orb is None or orb["colour"] == player_colour: #hoy cell faka chilo or oine same colour er ball/s chilo
                    legal_moves_array.append((row,col))
        return legal_moves_array 
    
    
    def make_move(self,move,player):
        new_board = copy.deepcopy(self)
        new_board.turn =  0 if player == "red" else 1 #jei player er turn shei player ke set korlam
        row,col = move # move is basically kon row and kon column e assigned hocche by the player
        winning_flag=new_board.clicks(row,col,player) # click method diye ball place kortesilam
        new_board.handle_explosion()
        return new_board,winning_flag # kahini kiccha korar pore new board er obostha return korbo
    
    
    def is_last_grid(self):
        
        if len(self.grid) < 2:  # ekhono shudhu ekta ball ba kono cell ei ball nai
            return False
        else:
            orbs_colour_present_on_the_grid = set() # set nibo karon set shdhu unique material e rakhe
            
            for orbs in self.grid.values():
                orbs_colour_present_on_the_grid.add(orbs["colour"])
            
            #amader duita colour ase so last giye board e shob ek colour er ball thaka manei oita wins and last gird eta tahole set er element matro ekta hobe if last terminal
            
            if(len(orbs_colour_present_on_the_grid)==1):
                return True
            else:
                return False
            
            
            
    def isWinner(self):
        if self.is_last_grid():
            return 0 if "red" in self.grid.values() and len(self.grid) > 0 else 1
        return None
            
            
            
            
    def handle_explosion(self):
        to_explode = []
        seen = set()
        # print("Checking cells for initial explosion...")
        for (row,col) , orb in self.grid.items():
            # print(f"Cell ({row},{col}) - Count: {orb['count']}, Colour: {orb['colour']}, Critical: {self.get_critical_mass(row, col)}")
            if orb["count"] >= self.get_critical_mass(row,col):
                # print(f">>> Cell ({row},{col}) will explode.")
                to_explode.append((row,col))
                seen.add((row,col))
        while to_explode:
            # print(f"\nExploding cell ({row},{col}) - Count: {orb['count']}, Colour: {orb['colour']}")
            row,col = to_explode.pop()
            orb = self.grid.get((row,col))
            if not orb:
                continue
           # orb = self.grid[(row,col)] #jei tar critical mass hoyeche sheta r row ar col number collect korlam
            exploding_colour = orb["colour"]
            critical = self.get_critical_mass(row,col)
            
            orb["count"] -= critical  # ekhane jehetu oi cell ta explode korbo to critical mass poriman komiye dilam karon jaate kore ekhon abar ekhane orbs newa jay
            # if orb["count"] <= 0:
            del self.grid[(row,col)]
            
            
            directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]   
            for dr, dc in directions:
                new_row,new_column = row + dr , col + dc
                
                if (0 <= new_row < self.rows) and( 0 <= new_column < self.cols):
                    key = (new_row,new_column)
                    center = self.cell_center(new_row,new_column)
                    # print(f"  -> Adding orb to neighbor ({new_row},{new_column})")
                    if key in self.grid:
                        # print(f"     - Previous count: {self.grid[key]['count']-1}")
                        # print(f"     - New count: {self.grid[key]['count']}")
                        # print(f"     - Colour changed to: {self.grid[key]['colour']}")
                        self.grid[key]["count"] += 1
                        #if self.grid[key]["colour"] != exploding_colour:
                        self.grid[key]["colour"] = exploding_colour
                        self.grid[key]["pos"] = center
                    else:
                        # print(f"     - New cell created at ({new_row},{new_column}) with 1 orb and colour {exploding_colour}")
                        self.grid[key] = {"pos": center , "colour": exploding_colour , "count": 1}
                    if self.grid[key]["count"] >= self.get_critical_mass(new_row,new_column):
                        to_explode.append(key)
                        seen.add((key))
                        # print(f"     >>> Neighbor ({new_row},{new_column}) scheduled to explode next!")
                        
                        
    # def getWinner(self):
        
        
    #     orbs_colour_present_on_the_grid = set() # set nibo karon set shdhu unique material e rakhe
        
    #     for orbs in self.grid.values():
    #         orbs_colour_present_on_the_grid.add(orbs["colour"])
        
    #     if len(orbs_colour_present_on_the_grid) == 1:
    #         return 0 if "red" in orbs_colour_present_on_the_grid else 1
    #     else:
    #         return None