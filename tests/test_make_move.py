
def main(comm):
	comm.make_move("a2a4")
	try:
		comm.make_move("a2a4")
		assert False, "Invalid move made but an exception should have been thrown."
	except Exception:
		pass
	comm.make_move("h7h5")
	comm.make_move("b2b3")
	comm.make_move("h8h6")
	
	
