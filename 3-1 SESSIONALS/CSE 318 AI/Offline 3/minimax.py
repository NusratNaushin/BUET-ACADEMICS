from board import *

class MinimaxAgent:
    def __init__(self, max_depth_to_search, player_colour, heuristic_function):
        self.max_depth_to_search = max_depth_to_search
        self.player_colour = player_colour
        self.heuristic_function = heuristic_function
        
    
    def opponent_player(self):
        return 'red' if self.player_colour == 'green' else 'green'
    
    def minimax(self,board,depth,alpha,beta,maximizing_player):
        if depth == 0 or board.is_last_grid():
            return self.heuristic_function(board, self.player_colour), None # heuritic value dicchi ar no move return kortesi cause leaf node e achi

        legal_moves = board.get_legal_moves(
            self.colour_into_turn(self.player_colour) if maximizing_player else self.colour_into_turn(self.opponent_player())
        )
        if not legal_moves:
            return self.heuristic_function(board, self.player_colour), None # heuritic value dicchi ar no move return kortesi cause leaf node e achi

        best_move = None
        if maximizing_player:
            
            max_eval = -float('inf')
            for move in legal_moves:
                player_turn = self.colour_into_turn(self.player_colour)
                new_board = board.make_move(move,self.player_colour)    
                eval,_ = self.minimax(new_board,depth-1,alpha,beta,False)    # ekta move korar por ager player er kache jay so turn false ar depth ek komaye dilam
                if eval > max_eval:
                    max_eval = eval
                    best_move = move
                alpha = max(alpha,eval)
                if(beta <= alpha):
                    break
            return max_eval, best_move
        else: # maximizing player na hoile minimizing hobe tahle ekhane shob ager block er opposite hobe
            min_eval = float('inf')
            for move in legal_moves:
                opponent_turn = self.colour_into_turn(self.opponent_player())
                new_board = board.make_move(move, self.opponent_player())    
                eval,_ = self.minimax(new_board,depth-1,alpha,beta,True)
                if eval < min_eval:
                    min_eval = eval
                    best_move = move
                beta = min(beta,eval)
                if beta <= alpha:
                    break    # etai holo shei pruning step , beta ar value aplha er cheye kom hole oi branch ar check eri dorkar nei
            return min_eval, best_move
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    def colour_into_turn(self,colour):
        if colour == 'red':
            return 0;
        elif colour == 'green':
            return 1; 
    def get_move(self,board):
        _,best_move = self.minimax(board,self.max_depth_to_search,-float('inf'),float('inf'),True)
        return best_move
    
