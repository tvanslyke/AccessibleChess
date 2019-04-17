

def main(comm):
	comm.forfeit_game()
	comm.new_game()
	comm.set_player_type("black", "cpu")
	comm.set_player_type("black", "human")
	comm.set_player_type("white", "cpu")
	comm.cancel_new_game()
