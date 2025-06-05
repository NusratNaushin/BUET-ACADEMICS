from board import *
def heuristic(board,player_colour):
    opponent_colour = 'red' if player_colour == 'green' else 'green'
    player_score_based_on_orbs_present = 0
    opponent_score_based_on_orbs_present = 0
    
    for orb in board.grid.values():
        if orb["colour"] == player_colour:
            player_score_based_on_orbs_present += orb["count"]
        elif orb["colour"] == opponent_colour:
            opponent_score_based_on_orbs_present += orb["count"]
    
    return player_score_based_on_orbs_present - opponent_score_based_on_orbs_present