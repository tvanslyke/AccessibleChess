
	

def main(comm):
	
	comm.forfeit_game()
	assert not comm.is_creating_new_game()
	assert not comm.active_game()
	comm.new_game()
	assert comm.is_creating_new_game()
	assert not comm.active_game()
	comm.set_player_type("black", "cpu");
	comm.set_player_type("white", "cpu");
	comm.set_player_type("white", "human");
	assert comm.is_creating_new_game()
	assert not comm.active_game()
	comm.start_game()
	assert not comm.is_creating_new_game()
	assert comm.active_game()
	
	
	


