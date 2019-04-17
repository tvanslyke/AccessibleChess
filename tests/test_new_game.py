
	

def main(comm):
	
	try:
		comm.new_game()
		assert False, "New game created, but an exception should have been thrown."
	except Exception:
		# good
		pass
	assert not comm.is_creating_new_game()
	assert comm.active_game()
	comm.forfeit_game()
	assert not comm.is_creating_new_game()
	assert not comm.active_game()
	comm.new_game()
	assert comm.is_creating_new_game()
	assert not comm.active_game()
	try:
		comm.new_game()
		assert False, "New game created, but an exception should have been thrown."
	except Exception:
		pass
	comm.set_player_type("black", "cpu");
	comm.set_player_type("black", "human");
	comm.set_player_type("white", "cpu");
	assert comm.is_creating_new_game()
	assert not comm.active_game()
	comm.start_game()
	assert not comm.is_creating_new_game()
	assert comm.active_game()
	
	
	


