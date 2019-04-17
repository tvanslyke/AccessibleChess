import chess

def main(comm):
	comm.make_move("a2a4")
	comm.make_move("h7h5")
	comm.make_move("d2d3")
	comm.make_move("h8h6")
	attacker_set = set(chess.query_attackers(comm.board_fen(), "h6"))
	expect = {
		(chess.position_to_indices("g6"), "p"),
		(chess.position_to_indices("g8"), "n"),
		(chess.position_to_indices("c1"), "B")
	}
	assert attacker_set == expect
	
