import threading
import sys


def print_help():
	print("Type 'move <start> <end>' to execute a move.")
	print("Type 'resign' to resign.")
	print("Type 'save' to save the game.")
	print("Type 'new' to start a new game.")
	print("Type 'active' to check if there's an active game.")
	print("Type 'fen' to show the FEN string for the current game.")
	print("Type 'help' to see this message again.")

def main(comm):
	def show_messages():
		queue = comm.messages
		while True:
			if queue.message_count() > 0:
				print("New message: '{}'".format(queue.pop_message()))
	
	print_help()
	thrd = threading.Thread(target=show_messages)
	thrd.start()
	while True:
		try:
			cmd = input("> ")
			if cmd == "help":
				print_help()
			if cmd == "exit" or cmd == "quit":
				break
			elif cmd.startswith("move "):
				print("Making move {}".format(cmd[5:]))
				comm.make_move(cmd[5:])
			elif cmd == "resign":
				print("Resigning game")
				comm.resign_game()
			elif cmd == "save":
				print("Saving game")
				comm.save_game()
			elif cmd == "new":
				print("Creating new game")
				comm.new_game()
			elif cmd == "fen":
				print(comm.board_fen())
			elif cmd == "active":
				if comm.active_game():
					print("yes")
				else:
					print("no")
		except RuntimeError as e:
			print("Error: {}".format(e))
		except TypeError as e:
			print("Error: {}".format(e))
		except ValueError as e:
			print("Error: {}".format(e))

