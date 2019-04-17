import chess

def main(comm):
	comm.make_move("d2d4")
	comm.make_move("e7e5")
	comm.make_move("d4e5")
	material = chess.query_material(chess.DecodedFen(comm.board_fen()).board)
	assert all(material[kind] == (1 if kind == "p" else 0)  for kind in material)
	
