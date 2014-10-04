.PHONY: clean All

All:
	@echo "----------Building project:[ TicTacToe - Debug ]----------"
	@$(MAKE) -f  "TicTacToe.mk"
clean:
	@echo "----------Cleaning project:[ TicTacToe - Debug ]----------"
	@$(MAKE) -f  "TicTacToe.mk" clean
