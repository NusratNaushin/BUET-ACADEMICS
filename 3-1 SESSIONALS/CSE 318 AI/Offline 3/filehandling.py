def write_game_current_state(filepath,board,turn):
    header = "Human Move:\n" if turn == 0 else "AI Move:\n"
    lines = [header]
    for r in range(board.rows):
        row = []
        for c in range(board.cols):
            orb_position = board.grid.get((r,c))
            if orb_position:
                count = orb_position["count"]
                colour = 'R' if orb_position["colour"] == "red" else 'G'
                row.append(f"{count}{colour}")
            else:
                row.append("0")
            
        lines.append(" ".join(row))
            
    with open(filepath,"w") as f:
        f.write("\n".join(lines))
def read_game_current_state(filepath):
    with open(filepath, "r") as f:
        lines = f.read().splitlines()
        
    header = lines[0]
    turn = 0 if "Human Move:" in header else 1
    
    raw_grid_lines_only = lines[1:] # first line baade baki row nilam karon first line e to ai naki human sheta bola ota kaajer na for parsing thhe grid
    board_data = {}
    
    
    for row_index,line in enumerate(raw_grid_lines_only):
        cell_values = line.strip().split() # prottekta row te jei ceel gula ache ogula alada kortesi ekhn 
        for column_index , cell in enumerate(cell_values):
            if cell == "0":
                continue
            
            
            orb_count = int(cell[0]) # text file e first character ta orb er count tai jonne ekhane cell[0] nilam
            orb_colour = "red" if cell[1] == "R" else "green"
            board_data[(row_index, column_index)] = {
                "count": orb_count,
                "colour": orb_colour
            }
            
    return board_data, turn