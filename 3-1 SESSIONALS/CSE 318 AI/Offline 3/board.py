import pygame

class Board:
    def __init__(self,rows,cols,cell_width,cell_height):
        self.rows = rows
        self.cols = cols
        self.cell_width = cell_width
        self.cell_height = cell_height
        self.grid = {}
        self.turn = 1 # first e 1 thakle red grid dekhabe

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


    def clicks(self,row,col): # jei row col select kortesi ogla passing
        if(row < 0 or row >= self.rows or col < 0 or col >= self.cols):
            return
        
        center = self.cell_center(row,col)
        key = (row,col)

        orb = self.grid.get(key)
        current_colour_of_the_orb = "red" if self.turn == 0 else "green"


        if orb:
            if orb["colour"] == current_colour_of_the_orb: #orb ager theke ase ekhn onno colour er orb er upor to ar kora jabe na so ei check dilam
                orb["count"] += 1
                if orb["count"] >= self.get_critical_mass(row,col):
                    print("Critical mass : ", orb["count"],self.get_critical_mass(row,col))
                    pass
                else:
                    self.turn = 1 - self.turn
        else:
            self.grid[key] = {"pos": center , "colour": current_colour_of_the_orb , "count": 1}
            self.turn = 1 - self.turn

    
    def draw_orbs(self):
        what_to_draw = []

        for orb in self.grid.values():
            for i in range(orb["count"]):
                #offset_angle = i* (360 // orb["count"])
                offset_x = 10*i
                what_to_draw.append((orb["colour"], (orb["pos"][0] + offset_x, orb["pos"][1])))       
                # pygame.draw.circle(screen, orb["colour"], (orb["pos"][0] + offset_x, orb["pos"][1]), 10)
                                                  
        return what_to_draw