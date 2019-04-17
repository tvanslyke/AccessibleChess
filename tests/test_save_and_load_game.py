

def main(comm):
	comm.make_move("a2a4")
	comm.make_move("h7h5")
	comm.make_move("b2b4")
	comm.make_move("h8h6")
	comm.save_game()
	comm.forfeit_game()
	comm.new_game()
	comm.load_game()
	comm.start_new_game()
	
