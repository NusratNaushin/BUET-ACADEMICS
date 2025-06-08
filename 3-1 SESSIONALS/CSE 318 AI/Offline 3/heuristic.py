from board import *
def heuristic(board,player_colour):
    opponent_colour = 'red' if player_colour == 'blue' else 'blue'
    player_score_based_on_orbs_present = 0
    opponent_score_based_on_orbs_present = 0
    
    for orb in board.grid.values():
        if orb["colour"] == player_colour:
            player_score_based_on_orbs_present += orb["count"]
        elif orb["colour"] == opponent_colour:
            opponent_score_based_on_orbs_present += orb["count"]
    
    return player_score_based_on_orbs_present - opponent_score_based_on_orbs_present

def my_heuristic(board, player_colour):
    opponent_colour = 'red' if player_colour == 'blue' else 'blue'
    score = 0
    
    for (row,col), orb in board.grid.items():
        if orb["colour"] == player_colour:
            surrounding_mass = board.get_surrounding_total_mass(row,col,opponent_colour)
            