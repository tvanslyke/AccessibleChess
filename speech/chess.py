

class DecodedFen:
	
	def __init__(self, fen):
		board, turn, castle, en_passant, half_move, full_move = fen.strip().split()
		self.board                  = board_from_fen(board)
		self.en_passant_pos         = None if en_passant == "-" else position_to_indices(en_passant)
		self.white_kingside_castle  = "K" in castle
		self.white_queenside_castle = "Q" in castle
		self.black_kingside_castle  = "k" in castle
		self.black_queenside_castle = "q" in castle
		self.half_move_clock        = int(half_move)
		self.full_move_number       = int(half_move)
		
def board_from_fen(fen):
	board = tuple(["",] * 8 for i in range(8))
	row = 7
	col = 0
	pieces = {"P", "p", "K", "k", "R", "r", "Q", "q", "B", "b", "N", "n"}
	for ch in fen:
		if row < 0:
			break
		if ch in pieces:
			board[row][col] = ch
			col += 1
		elif ch == '/':
			assert col == 8
			row -= 1
			col = 0
		else:
			col += int(ch)
	return board

def name(piece, include_color=True):
	color = "black" if piece.lower() == piece else "white"
	pieces = {"p": "pawn", "k": "king", "r": "rook", "q": "queen", "b": "bishop", "n": "knight"}
	if include_color:
		return " ".join((color, pieces[piece.lower()]))
	else:
		return pieces[piece.lower()]

def query_position(board, pos_str):
	row, col = position_to_indices(pos_str)
	return board[row][col]

def query_material(board):
	material = {"P": 8, "p": 8, "K": 1, "k": 1, "R": 2, "r": 2, "Q": 1, "q": 1, "B": 2, "b": 2, "N": 2, "n": 2}
	for row in board:
		for piece in row:
			if not piece:
				continue
			material[piece] -= 1
	return material

def indices_to_position(row, col):
	return ('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h')[row] + str(col + 1)

def position_to_indices(pos_str):
	assert len(pos_str) == 2
	col = {
		"A": 0, "a": 0,
		"B": 1, "b": 1,
		"C": 2, "c": 2,
		"D": 3, "d": 3,
		"E": 4, "e": 4,
		"F": 5, "f": 5,
		"G": 6, "g": 6,
		"H": 7, "h": 7,
	}[pos_str[0]]
	row = int(pos_str[1]) - 1
	return (row, col)

def diagonal_attackers(board, row, col):
	for r_step, c_step in ((1, 1), (1, -1), (-1, -1), (-1, 1)):
		r, c = row + r_step, col + c_step
		if board[r][c] in {"K", "k"}:
			yield ((r, c), board[r][c])
			continue
		while r < 8 and c < 8 and r >= 0 and c >= 0:
			if board[r][c] in {"B", "b", "Q", "q"}:
				yield ((r, c), board[r][c])
				break
			elif board[r][c]:
				break
			r += r_step
			c += c_step
	if row != 7 and col != 7 and board[row + 1][col + 1] == 'p':
		yield ((row + 1, col + 1), 'p')
	if row != 7 and col != 0 and board[row + 1][col - 1] == 'p':
		yield ((row + 1, col - 1), 'p')
	if row != 0 and col != 7 and  board[row - 1][col + 1] == 'P':
		yield ((row - 1, col + 1), 'P')
	if row != 0 and col != 0 and board[row - 1][col - 1] == 'P':
		yield ((row - 1, col - 1), 'P')

def direct_attackers(board, row, col):
	for r_step, c_step in ((1, 0), (-1, 0), (0, 1), (0, -1)):
		r, c = row + r_step, col + c_step
		if board[r][c] in {"K", "k"}:
			yield ((r, c), board[r][c])
			continue
		while r < 8 and c < 8 and r >= 0 and c >= 0:
			if board[r][c] in {"R", "r", "Q", "q"}:
				yield ((r, c), board[r][c])
				break
			elif board[r][c]:
				break
			r += r_step
			c += c_step

def knight_attackers(board, row, col):
	for (r_step, c_step) in ((2, 1), (2, -1), (-2, 1), (-2, -1), (1, 2), (1, -2), (-1, 2), (-1, -2)):
		r, c = (row + r_step, col + c_step)
		if r >= 0 and r <= 7 and c >= 0 and c <= 7:
			piece = board[r][c]
			if piece == 'n' or piece == 'N':
				yield ((r, c), piece)

def en_passant_attackers(fen, row, col):
	if not fen.en_passant_pos:
		return
	r, c = fen.en_passant_pos
	if row == 3 and r == 2 and c == col:
		for c in (col - 1, col + 1):
			if c < 0 or c > 7:
				continue
			if fen.board[row][c] == 'p':
				yield ((r, c), 'p')
	elif row == 4 and r == 5 and c == col:
		for c in (col - 1, col + 1):
			if c < 0 or c > 7:
				continue
			if fen.board[row][c] == 'P':
				yield ((r, c), 'p')
		

def query_attackers(fen, position):
	fen = DecodedFen(fen) if not isinstance(fen, DecodedFen) else fen
	row, col = position_to_indices(position) if isinstance(position, str) else position
	yield from   diagonal_attackers(fen.board, row, col)
	yield from     direct_attackers(fen.board, row, col)
	yield from     knight_attackers(fen.board, row, col)
	yield from en_passant_attackers(fen, row, col)


def paint(board):
	print("+---+---+---+---+---+---+---+---+")
	for row in reversed(board):
		fmt = "| {} | {} | {} | {} | {} | {} | {} | {} |"
		print(fmt.format(*(item if item else " " for item in row)))
		print("+---+---+---+---+---+---+---+---+")


material_values = {"P": 1, "p": 1, "R": 5, "r": 5, "Q": 9, "q": 9, "B": 3, "b": 3, "N": 3, "n": 3, "K": 0, "k": 0}

	
