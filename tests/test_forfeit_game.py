
	

def main(comm):
	comm.forfeit_game()
	try:
		comm.forfeit_game()
		assert False, "Game forfeited, but an exception should have been thrown."
	except ValueError:
		# good
		pass
	comm.new_game()
	comm.forfeit_game()
	try:
		comm.forfeit_game()
		assert False, "Game forfeited, but an exception should have been thrown."
	except ValueError:
		# good
		pass
	comm.new_game()
	


